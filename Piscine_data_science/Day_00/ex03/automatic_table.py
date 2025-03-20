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
# folder_path = '/mnt/nfs/homes/ggobert/Downloads/subject/customer'
folder_path = '/Users/gregoiregobert/Downloads/42/subject/customer'


for file_name in os.listdir(folder_path):
    if file_name.endswith('.csv') and file_name != "Test.csv":
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
        print(f"Table {table_name} created succefully")

        # Open csv_files
        with open(folder_path +  '/' + file_name, 'r') as csv_file:
            cur.copy_expert(f"COPY {table_name} FROM STDIN CSV HEADER", csv_file)
        print(f"{file_name} copied succefully")

conn.commit()
cur.close()
conn.close()
