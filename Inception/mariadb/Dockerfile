FROM debian:buster

RUN apt update; \
	apt install -y mariadb-server

COPY /conf/50-server.conf /etc/mysql/maria.conf.d/50-server.conf
COPY /conf/config.sh /tmp/config.sh

ENTRYPOINT [ "sh", "/tmp/config.sh" ]