FROM	alpine:3.13

COPY	conf/nginx.conf /etc/nginx/conf.d/nginx.conf

RUN apk update && \
    apk add nginx && \
    apk add openssl && \
    openssl dhparam -out /etc/nginx/dhparam.pem 2048 && \
    openssl req -new -newkey rsa:4096 -days 365 -nodes -x509 \
        -subj "/C=FR/ST=FR/L=Paris" \
		-out /etc/nginx/server.crt \
        -keyout /etc/nginx/server.key 

EXPOSE	443

CMD [ "nginx", "-g", "daemon off;" ]