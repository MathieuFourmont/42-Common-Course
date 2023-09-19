#!/bin/bash

# Démarage de MySQL
service mysql start;

sleep 10

# Crée une table si elle n'existe pas déjà, mysql -e fourni une instruct° SQL, ici CREATE DATABASE (instruct°) IF NOT EXISTS (clause)
mysql -e "CREATE DATABASE IF NOT EXISTS ${MYSQL_DB};"

# Crée un utilisateur s'il n'existe pas déjà, avec le mdp
mysql -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"

# Donne les droits d'administration à MYSQL_USER avec le mdp MYSQL_PASSWORD pour la table MYSQL_DATABASE (% = quel que soit l'hôte, pas seulement local)
mysql -e "GRANT ALL PRIVILEGES ON ${MYSQL_DB}.* TO '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}' WITH GRANT OPTION;"

# Rafraîchit la database
mysql -e "FLUSH PRIVILEGES;"

# Set le mdp de root dans le flag debian.cnf pour pouvoir redémarrer mysql avec root
sed -i "s/password = /password = ${MYSQL_ROOT_PASSWORD} #/" /etc/mysql/debian.cnf

# Change le mdp de root lorsqu'il se connecte depuis localhost
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"

# Redémarre mariadb pour que tout soit à jour
service mysql stop;

# commande recommandée par MySQL à son démarrage
mysqld_safe
