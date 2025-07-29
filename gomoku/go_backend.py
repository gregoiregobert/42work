import socket
import threading
import json

HOST = 'localhost'
PORT = 65432


def rules(data):
    return False


def win(data):
    return False


def handle_client(conn):
    mode = None
    with conn:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            data = json.loads(data.decode())
            print("Reçu du client :", data)

            if "mode" in data:
                mode = data["mode"]
                print(f"Mode défini pour ce client : {mode}")
                continue 

            # Simule un coup IA (à droite du dernier et supprime le deux a gauche)
            ai_response = {
                "valid": rules(data),
                "win": win(data),
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
