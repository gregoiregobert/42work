NAME 	=	inception
IMAGE 	=	sudo docker images -a -q

all		:	inception

$(NAME)	:	volume build up

build	:
	sudo docker compose -f ./srcs/docker-compose.yml build

volume	:
	sudo mkdir -p /home/ggobert/data/mariadb_volume
	sudo mkdir -p /home/ggobert/data/wordpress_volume

up		:
	sudo docker compose -f ./srcs/docker-compose.yml up -d

down	:
	sudo docker compose -f ./srcs/docker-compose.yml down

clean 	:	down
	sudo docker container prune --force

fclean	: clean
	sudo rm -rf /home/ggobert/data
	sudo docker system prune --all --force --volumes

re		:	fclean all

.PHONY	: all volume up down clean fclean re