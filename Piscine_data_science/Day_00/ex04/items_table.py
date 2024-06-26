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


# Find the table's name
folder_path = '/mnt/nfs/homes/ggobert/Downloads/subject/item'

for file_name in os.listdir(folder_path):
    if file_name.endswith('.csv'):
        table_name = os.path.splitext(file_name)[0]

        # Creating the table
        cur.execute(f"""
            CREATE TABLE IF NOT EXISTS {table_name} (
                product_id INT,
                category_id BIGINT,
                category_code TEXT,
                brand TEXT
            )
        """)
        print(f"Table {table_name} execute succefully")

        # Open csv_files
        with open(folder_path +  '/' + file_name, 'r') as csv_file:
            next(csv_file)  # Skip header row
            cur.copy_expert(f"COPY {table_name} FROM STDIN CSV HEADER", csv_file)
        print(f"{file_name} copied succefully")

conn.commit()
cur.close()
conn.close()
