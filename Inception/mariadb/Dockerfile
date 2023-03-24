FROM alpine:3.13


RUN apk update && \
	apk upgrade && \
	apk add --no-cache mariadb mariadb-client

COPY /conf/mariadb.conf /etc/mysql/maria.conf.d/

COPY /conf/conf.sh /tmp/conf.sh

ENTRYPOINT [ "sh", "/tmp/conf.sh" ]