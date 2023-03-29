FROM debian:buster

RUN apt update; \
    apt install -y php7.3 \
    php-mysqli \
    php-fpm \
    mariadb-client \
    wget \
    sendmail 

COPY conf/php-fpm.conf /etc/php/7.3/fpm/pool.d

#wp-cli : gerer wordpress depuis le terminal
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN cp wp-cli.phar /usr/local/bin/wp


COPY tools/configure.sh /tmp/configure.sh
ENTRYPOINT [ "sh", "/tmp/configure.sh" ]
# CMD ["php-fpm7", "-F"]