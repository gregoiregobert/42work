import psycopg2
import matplotlib.pyplot as plt
import pandas as pd

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

cur.execute("""
    SELECT DATE(event_time) AS purchase_date,
        COUNT(DISTINCT user_id) AS distinct_users
    FROM customers
    WHERE event_time BETWEEN '2022-10-01' AND '2023-02-28'
    AND event_type = 'purchase'
    GROUP BY DATE(event_time)
    ORDER BY purchase_date;
""")

# Fetch the results
results = cur.fetchall()
df = pd.DataFrame(results, columns=['purchase_date', 'distinct_users'])

# Plotting
plt.figure(figsize=(6, 4))
plt.plot(df['purchase_date'], df['distinct_users'], linestyle='-')

# Formatting the plot
plt.title('Number of Different Users Making a Purchase Each Day')
plt.xlabel('Date')
plt.ylabel('Number of Users')

month_names = df['purchase_date'].dt.strftime('%B').unique()
plt.xticks(df['purchase_date'].unique(), month_names, rotation=45)

# Show plot
plt.tight_layout()
plt.show()


# Close cursor and connection
cur.close()
conn.close()