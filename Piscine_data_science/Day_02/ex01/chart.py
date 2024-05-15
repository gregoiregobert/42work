import psycopg2
import matplotlib.pyplot as plt
import pandas as pd
from matplotlib.dates import DateFormatter, MonthLocator
import calendar

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

#--------- LINEAR GRAPH ---------#
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
df['purchase_date'] = pd.to_datetime(df['purchase_date'])


# Plotting
plt.figure(figsize=(6, 4))
plt.plot(df['purchase_date'], df['distinct_users'])

# Formatting the plot
plt.ylabel('Number of customers')

ax = plt.gca()
ax.xaxis.set_major_locator(MonthLocator())
ax.xaxis.set_major_formatter(DateFormatter('%b'))

# Show plot
plt.grid()
plt.show()

#------- BAR GRAPH --------#

df['date'] = df['purchase_date'].dt.strftime('%Y-%m')
# df['date'] = df['date'].apply(lambda x: calendar.month_name[int(x.split('-')[1])][:3])
distinct_users_by_month = df.groupby('date')['distinct_users'].sum()

# Plotting
plt.figure(figsize=(6, 4))
plt.bar(distinct_users_by_month.index, distinct_users_by_month.values)

# Formatting the plot
plt.ylabel('total sales in million of A')

# Show plot
plt.grid()
plt.show()

# Close cursor and connection
cur.close()
conn.close()