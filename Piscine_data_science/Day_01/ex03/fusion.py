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
CREATE TABLE item_dedup AS
SELECT DISTINCT ON (product_id) *
FROM item
ORDER BY 
  product_id,
  brand ASC NULLS LAST,
  category_code ASC NULLS LAST,
  category_id ASC NULLS LAST;

CREATE TABLE a AS
SELECT 
    c.*,
    i.category_id,
    i.category_code,
    i.brand
FROM customers c
LEFT JOIN item_dedup i ON c.product_id = i.product_id;
""")
print("customers and item were merged each together")


conn.commit()
cur.close()
conn.close()
