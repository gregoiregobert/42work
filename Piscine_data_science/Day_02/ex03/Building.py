import psycopg2
import matplotlib.pyplot as plt
import pandas as pd
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

#--------- BART CHART ---------#
cur.execute("""
...
""")
results_from = cur.fetchall()


cur.close()
conn.close()