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

table_names = []

# Find the table's name
folder_path = '/mnt/nfs/homes/ggobert/Downloads/subject/customer'

for file_name in os.listdir(folder_path):
    if file_name.endswith('.csv'):
        table_name = os.path.splitext(file_name)[0]
        table_names.append(table_name)

        
        # Creating the table
        cur.execute(f"""
            CREATE TABLE IF NOT EXISTS {table_name} (
                event_time DATETIME,
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
            next(csv_file)  # Skip header row
            cur.copy_expert(f"COPY {table_name} FROM STDIN CSV HEADER", csv_file)
        print(f"{file_name} copied succefully")

# Merging tables into one
merged_table_name = 'customers'
cur.execute(f"DROP TABLE IF EXISTS {merged_table_name}")
cur.execute(f"CREATE TABLE {merged_table_name} AS SELECT * FROM {table_names[0]} WHERE 1=0")
for table_name in table_names:
    cur.execute(f"INSERT INTO {merged_table_name} SELECT * FROM {table_name}")

print("Tables merged successfully")

conn.commit()
cur.close()
conn.close()
