FROM	debian:buster


RUN apt update; \
    apt install -y nginx openssl 

RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
        -subj "/C=FR/ST=FR/L=Paris" \
		-out /etc/ssl/certs/nginx.crt \
        -keyout /etc/ssl/private/nginx.key 

COPY	conf/default /etc/nginx/sites-enabled/default

RUN		chown -R www-data:www-data /var/www/html
RUN		chmod 755 /var/www/html

EXPOSE	443

CMD [ "nginx", "-g", "daemon off;" ]