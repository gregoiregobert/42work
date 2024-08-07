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
cur.execute(""" SELECT event_type, price, user_id FROM  customers """)
results = cur.fetchall()

colnames = [desc[0] for desc in cur.description]

df = pd.DataFrame(results, columns=colnames)

cur.close()
conn.close()


df = df[df['event_type'] == 'purchase']
frequency = df.groupby(['user_id', 'event_type']).size().reset_index(name='frequency')
max_frequency = frequency['frequency'].max()

#--------- BART CHART ---------#

plt.figure(figsize=(10, 6))
plt.hist(frequency['frequency'], bins=20, edgecolor='black')
plt.ylim(max_frequency)
plt.show()
