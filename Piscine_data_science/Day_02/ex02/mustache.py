import psycopg2
import matplotlib.pyplot as plt
import numpy as np

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

#--------- MEDIAN, AVERAGE, ETC... ---------#
cur.execute("""
    SELECT REPLACE(price::TEXT, '$', '')::FLOAT AS price 
    FROM customers
    WHERE event_type = 'purchase'
""")
results_from = cur.fetchall()
results = [float(row[0]) for row in results_from]

mean_result = np.mean(results)
median_result = np.median(results)
standard_result = np.std(results)
min_result = np.min(results)
max_result = np.max(results)
quartiles = np.percentile(results, [25, 50, 75])
first_quartile = quartiles[0]
second_quartile = quartiles[1]
third_quartile = quartiles[2]

# Print the results
print(f"\ncount    {len(results):.6f}")
print(f"mean     {mean_result:.6f}")
print(f"median   {median_result:.6f}")
print(f"std      {standard_result:.6f}")
print(f"min      {min_result:.6f}")
print(f"25%      {first_quartile:.6f}")
print(f"50%      {second_quartile:.6f}")
print(f"75%      {third_quartile:.6f}")
print(f"max      {max_result:.6f}")


#--------- BOXPLOT GRAPH ---------#
plt.figure(figsize=(8, 6))
flierprops = dict(linewidth=2, color='red', marker='D', markersize=2, markerfacecolor='green', markeredgecolor='green')
plt.boxplot(results, vert=False, patch_artist=True, boxprops=dict(facecolor='green', color='green'), flierprops=flierprops)   
plt.xlabel('price')
plt.ylim(0.9, 1.1)
plt.show()

#--------- ZOOM BOXPLOT GRAPH ---------#
plt.figure(figsize=(8, 6))
flierprops = dict(markersize=0)
plt.boxplot(results, vert=False, patch_artist=True, boxprops=dict(facecolor='green', color='black'), flierprops=flierprops)   
plt.xlabel('price')
plt.xlim(-1, 13)
plt.ylim(0.9, 1.1)
plt.show()

#--------- BASKETBOXPLOT GRAPH ---------#
cur.execute("""
    SELECT 
        AVG(session_total) AS average_basket_price
    FROM (
        SELECT 
            user_id, 
            user_session, 
            SUM(REPLACE(REPLACE(price::TEXT, '$', ''), ',', '')::FLOAT) AS session_total
        FROM 
            customers
        WHERE 
            event_type = 'purchase'
        GROUP BY 
            user_id, user_session
    ) AS session_totals
    GROUP BY 
        user_id;
""")

results_from2 = cur.fetchall()
results2 = [float(row[0]) for row in results_from2]

plt.figure(figsize=(8, 6))
flierprops = dict(linewidth=1, color='red', marker='D', markersize=2, markerfacecolor='green', markeredgecolor='magenta')
plt.boxplot(results2, vert=False, patch_artist=True, boxprops=dict(facecolor='magenta', color='black'), flierprops=flierprops)   
plt.ylim(0.9, 1.1)
plt.xlim(-100, 430)
plt.show()


cur.close()
conn.close()