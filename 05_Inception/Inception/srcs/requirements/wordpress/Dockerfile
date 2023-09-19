FROM debian:buster

RUN apt-get update -yq && apt-get upgrade -yq

# installe wget pour installer WP
RUN apt-get -yqq install wget

# installe PHP 
RUN apt-get install -yq php7.3 php-fpm php-mysql mariadb-client

# Crée de les dossiers
RUN mkdir /var/www
RUN mkdir /var/www/html

# indique dans quel dossier on veut telecharger le fichier en utilisant -P
RUN wget https://wordpress.org/wordpress-6.0.tar.gz -P /var/www/html

# décompresse le fichier pour obtenir le dossier WP puis supprime le .tar (compressé) qui ne sert plus à rien
RUN cd /var/www/html && tar -xzf wordpress-6.0.tar.gz && rm wordpress-6.0.tar.gz

# donne les droits à root d'écrire dans ce dossier
RUN chown -R root:root /var/www/html/wordpress

# installe la CLI de WP(interface textuelle qui traite les commandes vers un programme informatique -> pratique pour la config automatique -mdp, nom, host)
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	--output-document=/usr/local/bin/wp \
	&& chmod +x /usr/local/bin/wp

# copie le fichier de config dans le container 
COPY ./conf/php.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY tools/runwp.sh ./runwp.sh

# on s'assure que le script est exécutable
RUN chmod +x ./runwp.sh

# on place dans le dossier wordpress
WORKDIR /var/www/html/wordpress

EXPOSE 9000

ENTRYPOINT ["bash", "/runwp.sh"]
