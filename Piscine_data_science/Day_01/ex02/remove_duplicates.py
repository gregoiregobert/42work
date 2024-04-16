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
CREATE TABLE distinct_customers AS
SELECT DISTINCT *
FROM customers
"""
cur.execute(create_table_query)
print("New table created with distinct rows")

# Drop the original customers table
drop_table_query = "DROP TABLE customers"
cur.execute(drop_table_query)
print("Original customers table dropped")

# Rename the new table to customers
rename_table_query = "ALTER TABLE distinct_customers RENAME TO customers"
cur.execute(rename_table_query)
print("New table renamed to customers")

conn.commit()
cur.close()
conn.close()
