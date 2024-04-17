import psycopg2

# Connecting to the Database
print("Trying to connect to db:     ", end='')
conn = psycopg2.connect(
    database="piscineds",
    user="ggobert",
    password="mysecretpassword",
    host=0
)
print("Connection success!")
cur = conn.cursor()

# Create a new table with distinct rows from the customers table
print("New table created with distinct rows:    ", end="")
create_table_query = """
CREATE TABLE distinct_customers AS
SELECT DISTINCT *
FROM customers
"""
cur.execute(create_table_query)
print("Done")

# Drop the original customers table
print("Original customers table dropped:    ", end="")
drop_table_query = "DROP TABLE customers"
cur.execute(drop_table_query)
print("Done")

# Rename the new table to customers
print("New table renamed to customers:  ", end="")
rename_table_query = "ALTER TABLE distinct_customers RENAME TO customers"
cur.execute(rename_table_query)
print("Done")

# Delete duplicates with 1 second interval
print("Duplicates with 1sec interval deleted:   ", end="")
delete_query = """DELETE FROM customers x
                  USING customers y
                  WHERE x.event_time = y.event_time + INTERVAL '1 second'
                  AND x.event_type = y.event_type
                  AND x.product_id = y.product_id
                  AND x.price = y.price
                  AND x.user_id = y.user_id
                  AND x.user_session = y.user_session"""
cur.execute(delete_query)
print("Done")

conn.commit()
cur.close()
conn.close()
