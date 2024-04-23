import psycopg2
import matplotlib.pyplot as plt

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

# Execute SQL query to get counts of each event type
cur.execute("SELECT event_type, COUNT(*) FROM customers GROUP BY event_type")
rows = cur.fetchall()

# Extract event types and counts from the query result
event_types = [row[0] for row in rows]
counts = [row[1] for row in rows]

# Plot pie chart
plt.figure(figsize=(8, 6))
plt.pie(counts, labels=event_types, autopct='%1.1f%%')
plt.show()

# Close cursor and connection
cur.close()
conn.close()
