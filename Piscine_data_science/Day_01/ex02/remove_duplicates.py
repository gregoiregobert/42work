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


query = """WITH customer_diff AS (
    SELECT *,
           LAG(event_time) OVER (PARTITION BY {list_of_group_columns} ORDER BY event_time) AS prev_event_time
    FROM customers
),
customer_with_diff AS (
    SELECT *,
           TIMESTAMPDIFF(SECOND, prev_event_time, event_time) AS time_diff
    FROM customer_diff
)
DELETE FROM customers;

INSERT INTO customers
SELECT * 
FROM customer_with_diff
WHERE time_diff IS NULL OR time_diff > 1;
"""
cur.execute(query)
print("Done")

conn.commit()
cur.close()
conn.close()
