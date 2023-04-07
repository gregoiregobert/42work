FROM debian:buster


RUN apt-get update -y && apt-get upgrade -y

RUN apt-get install -y php7.3 \
    php7.3-mysql \
    php7.3-fpm \
    php7.3-curl \
    php7.3-mbstring \
    php7.3-xml \
    php7.3-zip \
    php7.3-gd \
    php7.3-imap \
    mariadb-client \
    wget 

RUN		mkdir -p /var/www/html ; mkdir -p /run/php

COPY conf/php-fpm.conf /etc/php/7.3/fpm/pool.d/www.conf

#wp-cli : gerer wordpress depuis le terminal
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN cp wp-cli.phar /usr/local/bin/wp

EXPOSE 9000

COPY tools/configure.sh /tmp/configure.sh
ENTRYPOINT [ "sh", "/tmp/configure.sh" ]

CMD ["php-fpm7.3", "-F"]