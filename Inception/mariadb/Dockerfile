FROM alpine:3.17

RUN apk add --no-cache mariadb mariadb-client

COPY mariadb.cnf /etc/mysql/mariadb.cnf

CMD ["mysqld"]