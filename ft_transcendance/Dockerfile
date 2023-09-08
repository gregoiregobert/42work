FROM alpine:latest

RUN apk add nodejs npm
RUN npm i -g @angular/cli
WORKDIR /home/trans_volume/snapface
# RUN npm install

COPY ../snapface home/trans_volume/snapface


EXPOSE 8080
