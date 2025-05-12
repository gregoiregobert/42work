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


cur.execute("""BEGIN;

    CREATE TEMP TABLE temp_customers AS 
    WITH customer_diff AS (
        SELECT *,
               LAG(event_time) OVER (PARTITION BY event_type, product_id, price, user_id, user_session ORDER BY event_time) AS prev_event_time
        FROM customers
    ),
    customer_with_diff AS (
        SELECT *,
               EXTRACT(EPOCH FROM (event_time - prev_event_time)) AS time_diff
        FROM customer_diff
    )
    SELECT event_time, event_type, product_id, price, user_id, user_session
    FROM customer_with_diff
    WHERE time_diff IS NULL OR time_diff > 1;

    DELETE FROM customers;

    INSERT INTO customers 
    SELECT * FROM temp_customers;

    COMMIT;
""")

print("Done")

conn.commit()
cur.close()
conn.close()


# WITH customer_diff AS (
#     SELECT *,
#            LAG(event_time) OVER (PARTITION BY event_type, product_id, price, user_id, user_session ORDER BY event_time) AS prev_event_time
#     FROM customers
# ),
# customer_with_diff AS (
#     SELECT *,
#            EXTRACT(EPOCH FROM (event_time - prev_event_time)) AS time_diff
#     FROM customer_diff
# )
# SELECT *
# FROM customer_with_diff
# WHERE time_diff IS NOT NULL AND time_diff <= 1 
# limit 1000