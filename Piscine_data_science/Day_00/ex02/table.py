import psycopg2



print("Trying to connect to db")
conn = psycopg2.connect(
    database="piscineds",
    user="ggobert",
    password="mysecretpassword",
    host="0.0.0.0",
)
print("Connection success!")
cur = conn.cursor()

folder_path = '/mnt/nfs/homes/ggobert/Downloads/subject/customer'


conn.close()