import psycopg2
import os

# Connecting to the Database
print("Trying to connect to db")
conn = psycopg2.connect(
    database="piscineds",
    user="ggobert",
    password="mysecretpassword",
    host=0
)
print("Connection success!")
cur = conn.cursor()

cur.execute("DROP TABLE IF EXISTS customers;")

merge_query = "CREATE TABLE customers AS "

# Find the table's name
folder_path = '/home/ggobert/Downloads/subject/customer'

for file_name in os.listdir(folder_path):
    if file_name.endswith('.csv') and file_name.startswith("data_"):
        table_name = os.path.splitext(file_name)[0]
        merge_query += f"SELECT * FROM {table_name} UNION ALL "

merge_query = merge_query.rsplit(' UNION ALL ', 1)[0]
cur.execute(merge_query)

print("Tables merged successfully")

conn.commit()
cur.close()
conn.close()
