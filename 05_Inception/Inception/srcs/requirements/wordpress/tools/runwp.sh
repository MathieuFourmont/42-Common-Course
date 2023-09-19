#!/bin/bash

# Pour laisser le temps à MariaDB de se lancer
#sleep 15;

#wp core download --allow-root

if [ ! -e /var/www/html/wordpress/wp-config.php ]; then
	sleep 15
	while ! mysql -h mariadb --user=${MYSQL_USER} --password=${MYSQL_PASSWORD} -e "SELECT schema_name FROM information_schema.schemata WHERE schema_name='$MYSQL_DB'"; do
  		echo "Waiting for database to be created..."
		# legacy sleep useless now
  		sleep 5
	done	
	
	echo "Installing wordpress";

	wp config create \
		--allow-root \
		--dbname=${MYSQL_DB} \
		--dbuser=${MYSQL_USER} \
	       	--dbpass=${MYSQL_PASSWORD} \
		--dbhost=${MARIADB_HOST} \
		--force
		#--path='/var/www/html/wordpress' \

	#sleep 10;
	wp core install	\
		--allow-root \
		--url=${DOMAIN_NAME} \
		--title=${SITE_TITLE} \
		--admin_user=${ADMIN_USER} \
		--admin_email=${ADMIN_EMAIL} \
		--admin_password=${ADMIN_PASSWORD}
		#--path='/var/www/html/wordpress' \

	wp user create \
		${WP_USER_LOGIN} \
		${WP_USER_EMAIL} \
		--role=subscriber \
		--user_pass=${WP_USER_PASSWORD} \
		--allow-root

#	wp theme install inspiro --allow-root --activate
fi

# Création du rep /run/php s'il n'existe pas -> utile pour stocker des fichiers temp + des sockets de comm associés au serveur PHP-FPM
#if [ ! -d /run/php ]; then
#	mkdir ./run/php
#fi

service php7.3-fpm start && service php7.3-fpm stop

# Démarrage du service PHP-FPM en mode daemon -> va exécuter des scripts PHP de manière efficace et séparée du serveur web = meilleures perf et stabilité
php-fpm7.3 -F
# -F pour le mode daemon
