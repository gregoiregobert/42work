#!/bin/sh

# wait for mysql
while ! mariadb -h$MYSQL_HOST -u$WP_DATABASE_USR -p$WP_DATABASE_PWD $WP_DATABASE_NAME &>/dev/null; do
    sleep 1
done

if [ ! -f "/var/www/html/index.php" ]; then

    # static website
    mv /tmp/index.php /var/www/html/index.php
fi

echo "Wordpress started on :9000"
/usr/sbin/php-fpm7 -F -R