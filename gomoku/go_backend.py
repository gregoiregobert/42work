import socket
import threading
import json

HOST = 'localhost'
PORT = 65432


def handle_move(msg):
    x, y = msg['x'], msg['y']
    # traiter le coup joué
    print(f"Move reçu en {x}, {y}")

def handle_game_over(msg):
    winner = msg['winner']
    print(f"Partie terminée, gagnant: {winner}")

def handle_mode(msg):
    mode = msg['mode']
    print(f"Mode de jeu: {mode}")

handlers = {
    'move': handle_move,
    'game_over': handle_game_over,
    'mode': handle_mode,
}

def handle_message(msg):
    msg_type = msg.get('type')
    handler = handlers.get(msg_type)
    if handler:
        handler(msg)
    else:
        print("Message inconnu:", msg)


def handle_client(conn):
    with conn:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            data = json.loads(data.decode())
            print("Reçu du client :", data)

            # template du json :
            # ai_response = {
            #   "to_place": [ { "x": 1, "y":2 }, "color": "white" ]
            #   "to_redata": [ { "x":2, "y":5 }, { "x": 1, "y":2 } ]
            # }

            # Simule un coup IA (à droite du dernier et supprime le deux a gauche)
            ai_response = {
                "to_place": [
                    {"x": data["x"] + 1 if data["x"] + 1 < 19 else data["x"], "y": data["y"], "color": "white"}
                ],
                "to_remove": [
                    {"x": data["x"] - 1, "y": data["y"]},
                    {"x": data["x"] - 2, "y": data["y"]}
                ]
            }
            conn.sendall(json.dumps(ai_response).encode())

def run_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        print(f"Serveur IA en écoute sur {HOST}:{PORT}")
        while True:
            conn, _ = s.accept()
            threading.Thread(target=handle_client, args=(conn,), daemon=True).start()


if __name__ == "__main__":
    run_server()
