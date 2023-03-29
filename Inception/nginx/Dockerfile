FROM	debian:buster

COPY	conf/nginx.conf /etc/nginx/conf.d/nginx.conf

RUN apt update; apt upgrade; \
    apt install -y nginx openssl 

    # openssl dhparam -out /etc/nginx/dhparam.pem 2048 && \
RUN openssl req -new -newkey rsa:4096 -days 365 -nodes -x509 \
        -subj "/C=FR/ST=FR/L=Paris" \
		-out /etc/nginx/server.crt \
        -keyout /etc/nginx/server.key 

EXPOSE	443

CMD [ "nginx", "-g", "daemon off;" ]