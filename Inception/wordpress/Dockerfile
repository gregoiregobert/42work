FROM alpine:3.17

RUN apk update && apk upgrade && apk add --no-cache \
    php7-fpm \
    php7-mysqli \
    php7-json \
    php7-openssl \
    php7-curl \
    php7-zlib \
    php7-gd \
    php7-xml \
    php7-dom \
    php7-phar \
    php7-iconv \
    php7-mbstring \
    php7-session \
    wordpress

COPY php-fpm.conf /etc/php7/php-fpm.conf

CMD ["php-fpm7", "-F"]

# "-F" : foreground, utiliser pour le debogage caril affiche les erreurs sur le term.
