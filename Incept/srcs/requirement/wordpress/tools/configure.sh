#!/bin/sh

if [ ! -f /var/www/html/wp-config.php ]; then

	cd /var/www/html
	wp core download --allow-root

	until mysqladmin --user=${SQL_USER} --password=${SQL_PWD} --host=mariadb ping; do
		sleep 2
	done

	echo "Creation d'un fichier de configuration Wordpress avec User Mysql"
	wp config create	--allow-root \
						--dbname=${SQL_DATABASE} \
						--dbuser=${SQL_USER} \
						--dbpass=${SQL_PWD} \
						--dbhost=mariadb:3306
	echo "OK"

	echo "Installation de Wordpress"
	wp core install		--url=ggobert.42.fr \
						--title="Inception" \
						--admin_user=${WP_ADMIN_LOGIN} \
						--admin_password=${WP_ADMIN_PWD} \
						--admin_email=${WP_ADMIN_MAIL} \
						--skip-email \
						--allow-root
	echo "OK"

	echo "Creation d'un second user"
	wp user create 		${WP_USR} ${WP_MAIL} \
						--user_pass=${WP_PWD} \
						--role=author \
						--allow-root
	echo "OK"

	echo "Installation du theme"
	wp theme install twentytwentyone --activate --allow-root
	echo "OK"

fi;

echo "Starting PHP-FPM..."
exec "$@"