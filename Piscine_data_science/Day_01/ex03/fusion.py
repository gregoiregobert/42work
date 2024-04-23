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
    DELETE FROM item
    WHERE ctid IN (
        SELECT ctid
        FROM (
            SELECT ctid,
                   ROW_NUMBER() OVER (PARTITION BY product_id ORDER BY
                                      (CASE WHEN category_code IS NULL THEN 1 ELSE 0 END) +
                                      (CASE WHEN brand IS NULL THEN 1 ELSE 0 END)) AS row_num
            FROM item
        ) AS ranked_rows
        WHERE row_num > 1
    )
""")
print("Duplicates was removed from item")

cur.execute("""
    CREATE TABLE IF NOT EXISTS fusion AS
    SELECT *
    FROM customers
    LEFT JOIN item
    USING(product_id)
""")

cur.execute("""
    DROP TABLE IF EXISTS customers
""")

cur.execute("""
    ALTER TABLE IF EXISTS fusion RENAME TO customers
""")
print("customers and item were merged each together")


conn.commit()
cur.close()
conn.close()
