import psycopg2
import os


print("Trying to connect to db")
conn = psycopg2.connect(
    database="piscineds",
    user="ggobert",
    password="mysecretpassword",
    host=0
)
print("Connection success!")
cur = conn.cursor()

folder_path = '/mnt/nfs/homes/ggobert/Downloads/subject/customer'

for file_name in os.listdir(folder_path):
    if file_name == 'data_2022_dec.csv':
        table_name = os.path.splitext(file_name)[0]

columns = [
    "event_time TIMESTAMP",
    "event_type TEXT",
    "product_id INTEGER",
    "price MONEY",
    "user_id DECIMAL",
    "user_session VARCHAR"
]


conn.close()
