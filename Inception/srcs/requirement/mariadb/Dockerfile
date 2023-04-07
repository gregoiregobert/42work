
FROM		debian:buster

RUN			apt-get update -y && apt-get install -y \
			mariadb-server 

RUN			mkdir -p /run/mysqld /var/lib/mysql && \
			chown -R mysql:mysql /run/mysqld /var/lib/mysql

COPY		./conf/50-server.cnf /etc/mysql/my.cnf
COPY		./conf/conf.sh /

ENTRYPOINT 	["bash", "conf.sh"]

EXPOSE 		3306

CMD 		/usr/bin/mysqld_safe