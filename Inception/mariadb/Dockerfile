FROM alpine:3.13

RUN apk update && \
	apk upgrade && \
	apk add --no-cache mariadb-client 

COPY /conf/mariadb.conf /etc/mysql/maria.conf.d/
COPY /tool/configure.sh /tmp/configure.sh

ENTRYPOINT [ "sh", "/tmp/configure.sh" ]