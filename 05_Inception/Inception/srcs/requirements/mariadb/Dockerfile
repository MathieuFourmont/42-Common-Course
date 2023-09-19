FROM debian:buster

# MAJ de apt-get, pour avoir la dernière version des packages
RUN apt-get update -y && apt-get upgrade -y

# Installatº de  MariaDB server (MySQL)
RUN apt-get install -y mariadb-server

# Permet de dire à MariaDB d'écouter toutes les adresses IP
#RUN sed -i 's/bind-address/bind-address = 0.0.0.0 #/i' /etc/mysql/mariadb.conf.d/50-server.cnf

# Expose le port 3306 pour le réseau Docker
EXPOSE 3306

# Copie de mon fichier de config vers le répertoire de config de MariaDB à l'intérieur de l'image Docker en cours de création
COPY conf/my.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copie du script pour créer la db dans l'image Docker
COPY tools/runmdb.sh ./

# on s'assure que le script est exécutable
RUN chmod +x runmdb.sh

# Execute le script pour créer la db et le user
ENTRYPOINT ["bash", "./runmdb.sh"]
