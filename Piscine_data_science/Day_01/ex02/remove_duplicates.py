import psycopg2

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

# Create a new table with distinct rows from the customers table
create_table_query = """
CREATE TABLE distinct_data_2023_jan AS
SELECT DISTINCT *
FROM data_2023_jan
"""
cur.execute(create_table_query)
print("New table created with distinct rows")

# Drop the original customers table
drop_table_query = "DROP TABLE data_2023_jan"
cur.execute(drop_table_query)
print("Original data_2023_jan table dropped")

# Rename the new table to customers
rename_table_query = "ALTER TABLE distinct_data_2023_jan RENAME TO data_2023_jan"
cur.execute(rename_table_query)
print("New table renamed to data_2023_jan")

conn.commit()
cur.close()
conn.close()
