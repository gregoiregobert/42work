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

# cur.execute("""
#     SELECT column_name, data_type
#     FROM information_schema.columns
#     WHERE table_name = 'item'
# """)

# # Fetch the column names and data types
# item_columns = cur.fetchall()


# for column_name, data_type in item_columns:
#     cur.execute(f"""
#         ALTER TABLE customers
#         ADD COLUMN IF NOT EXISTS {column_name} {data_type}
#     """)

cur.execute("""
    CREATE TABLE IF NOT EXISTS fusion AS
    SELECT *
    FROM customers
    JOIN item
    USING(product_id)
""")

# cur.execute("""
#     DELETE FROM fusion
#     WHERE category_id IS NULL
# """)

conn.commit()
cur.close()
conn.close()
