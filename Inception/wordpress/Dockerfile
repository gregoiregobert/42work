FROM alpine:3.13

RUN apk update && apk upgrade && apk add --no-cache \
    wget \
    tar \
    php7 \
    php7-fpm \
    php7-mysqli \
    php7-json \
    php7-openssl \
    php7-curl \
    php7-zlib \
    php7-xml \
    php7-phar \
    php7-intl \
    php7-dom \
    php7-xmlreader \
    php7-ctype \
    php7-session \
    php7-mbstring

COPY conf/php-fpm.conf /etc/php7/php-fpm.conf

CMD ["php-fpm7", "-F"]

# "-F" : foreground, utiliser pour le debogage caril affiche les erreurs sur le term.
