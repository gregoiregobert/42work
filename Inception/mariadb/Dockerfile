FROM debian:buster

RUN apt update; \
	apt install -y mariadb-server

COPY /conf/mariadb.conf /etc/mysql/maria.conf.d/

RUN service mysql start && mysql<

COPY /conf/conf.sh /tmp/conf.sh

ENTRYPOINT [ "sh", "/tmp/conf.sh" ]