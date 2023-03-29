#!/bin/sh

mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid

if [ ! -f "/var/www/html/index.php" ]; then

    # static website
    mv /tmp/index.php /var/www/html/index.php
fi

echo "Wordpress started on :9000"
/usr/sbin/php-fpm7.3 -F -R