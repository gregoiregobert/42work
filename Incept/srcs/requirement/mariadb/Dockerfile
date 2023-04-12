
FROM		debian:buster

RUN			apt-get update -y && apt-get install -y \
			mariadb-server \
			mariadb-client

RUN			mkdir -p /run/mysqld /var/lib/mysql && \
			chown -R mysql:mysql /run/mysqld /var/lib/mysql

RUN			mysql_install_db --user=mysql --datadir=/var/lib/mysql --auth-root-authentication-method=normal --skip-test-db

COPY		./conf/50-server.cnf /etc/mysql/my.cnf
COPY		./conf/conf.sh /

ENTRYPOINT 	["bash", "conf.sh"]

EXPOSE 		3306

CMD 		/usr/bin/mysqld_safe