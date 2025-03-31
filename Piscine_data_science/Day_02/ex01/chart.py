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
plt.ylabel('Number of customers')

# gca = get current axe, permet de manipuler le label.
ax = plt.gca()

# Permet d'avoir pour le label la précision d'un mois à la place de la date pour chaques point
ax.xaxis.set_major_locator(MonthLocator())
ax.xaxis.set_major_formatter(DateFormatter('%b'))

# Show plot
plt.grid()
plt.show()

#------- BAR GRAPH --------#

cur.execute("""
    SELECT 
        CONCAT(EXTRACT(YEAR FROM event_time), '-', EXTRACT(MONTH FROM event_time)) AS date_,
        COUNT(*) AS purchase_count
    FROM 
        customers
    WHERE 
        event_type IN ('purchase')
    GROUP BY 
        date_;
""")

results = cur.fetchall()
df2 = pd.DataFrame(results, columns=['date', 'purchase_count'])

def month_number_to_name(month_number):
    return calendar.month_name[int(month_number)]

# Extract month number from date and convert it to month name
df2['date'] = df2['date'].apply(lambda x: month_number_to_name(x.split('-')[1])[:3])

df2['purchase_count_m'] = df2['purchase_count'] / 1000000

# Plotting
plt.figure(figsize=(6, 4))
plt.bar(df2['date'], df2['purchase_count_m'])

# Formatting the plot
plt.ylabel('total sales in million of A')
plt.xlabel('month')

# Show plot
plt.grid()
plt.show()

#------- STACK GRAPH --------#

cur.execute("""
    SELECT 
        event_time::date AS event_date, 
        AVG(price::numeric) AS average_spending
    FROM 
        customers
    WHERE 
        event_type = 'purchase'
    GROUP BY 
        event_time::date
    ORDER BY 
        event_time::date;
""")

results = cur.fetchall()
df3 = pd.DataFrame(results, columns=['date', 'average_spending'])

# Plotting
fig, ax = plt.subplots()
ax.stackplot(df3['date'], df3['average_spending'])
plt.ylabel('Average spend/customers in A')
plt.xlabel('month')

# Ordering by month on the x axis
ax = plt.gca()
ax.xaxis.set_major_locator(MonthLocator())
ax.xaxis.set_major_formatter(DateFormatter('%b'))

ax.set_xlim(df3['date'].min(), df3['date'].max())

# Show plot
plt.grid()
plt.show()

# Close cursor and connection
cur.close()
conn.close()