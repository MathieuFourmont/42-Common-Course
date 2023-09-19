PATH_YML = ./srcs/docker-compose.yml

all:
	@mkdir -p /home/mmaxime-/data
	@mkdir -p /home/mmaxime-/data/wordpress
	@mkdir -p /home/mmaxime-/data/mariadb
	@sudo docker-compose -f $(PATH_YML) up -d --build

re: clean all

stop:
	@sudo docker-compose -f $(PATH_YML) stop

clean: stop
	@sudo docker-compose -f $(PATH_YML) down -v

fclean: clean
	@sudo rm -rf /home/mmaxime-/data/wordpress
	@sudo rm -rf /home/mmaxime-/data/mariadb
	@sudo docker system prune -af

.PHONY: all re stop clean fclean
