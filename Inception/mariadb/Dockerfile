FROM debian:buster

RUN apt update; \
	apt install -y mariadb-server

COPY /conf/mariadb.conf /etc/mysql/maria.conf.d/
COPY /conf/createdb.sql /

RUN service mysql start && mysql < createdb.sql && rm -f createdb.sql

RUN echo "start mariadb"

CMD /usr/bin/mysqld_safe