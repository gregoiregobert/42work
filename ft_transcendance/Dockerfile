FROM alpine:latest

RUN apk add nodejs npm
RUN npm i -g @angular/cli
RUN npm install

COPY ../snapface home/snapface

EXPOSE 8080