FROM alpine:3.16


RUN apt update; apt upgrade; \
	apt install -y mariadb-server

COPY /conf/mariadb.conf /etc/mysql/maria.conf.d/

RUN service mysql start

COPY /conf/conf.sh /tmp/conf.sh

ENTRYPOINT [ "sh", "/tmp/conf.sh" ]