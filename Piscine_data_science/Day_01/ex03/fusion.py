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


cur.execute("""
    CREATE TABLE new_table AS
    SELECT 
        t1.event_time,
        t1.price,
        t1.user_id,
        t1.event_type,
        t1.user_session,
        t1.product_id,
        t2.category_id,
        t2.category_code,
        t2.brand
    FROM customers t1
    FULL OUTER JOIN item t2 ON t1.product_id = t2.product_id;

    DROP TABLE customers;
    ALTER TABLE new_table RENAME TO customers
""")
print("customers and item were merged each together")


conn.commit()
cur.close()
conn.close()
