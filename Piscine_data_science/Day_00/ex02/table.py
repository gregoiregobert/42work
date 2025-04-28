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


# Folder location ( A CHANGER EN FONCTION DE LA CORRECTION )
# folder_path = "/Users/gregoiregobert/Downloads/subject/customer"
folder_path = '/mnt/nfs/homes/ggobert/Downloads/subject/customer'

for file_name in os.listdir(folder_path):
    if file_name == 'data_2022_dec.csv':
        table_name = os.path.splitext(file_name)[0]

# Creating the table
cur.execute(f"""
    CREATE TABLE IF NOT EXISTS {table_name} (
        event_time TIMESTAMP,
        event_type TEXT,
        product_id INTEGER,
        price MONEY,
        user_id DECIMAL,
        user_session VARCHAR
    )
""")
print("Table created succefully")

# Open CSV 
with open(folder_path + '/data_2022_dec.csv', 'r') as csv_file:
    next(csv_file)  # Skip header row
    cur.copy_expert(f"COPY {table_name} FROM STDIN CSV HEADER", csv_file)
print("Csv_file copied succefully")

conn.commit()
cur.close()
conn.close()
