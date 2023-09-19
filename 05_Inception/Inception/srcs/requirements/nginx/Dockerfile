FROM debian:buster

# verifie les MAJ, installe Nginx
RUN apt-get update -y && apt-get upgrade -y
RUN apt install nginx -y

# télécharge OpenSSL (outil principal de gestion/création de certificats SSL)
RUN apt-get install openssl -y

# crée un dossier pour stocker certificat et connexion sécurisée
RUN mkdir -p /etc/nginx/ssl

# req = commande OpenSSL pour générer une demande de certif 
RUN openssl req \
# x509 = certif self-signed
-x509 \
# validité du certif
-days 365 \
# sans mdp
-nodes \
# crée une nvelle clé qui sera utilisée pour signer le certif
-newkey \
# précise l'algo à utiliser pour la génératº de clé ainsi que le nb de bytes utilisé pour cet algo
rsa:2048 \
# subj permet de pré-remplir le prompt qui requiert certaines infos
-subj "/C=FR/ST=Rhône/L=Lyon/O=42Lyon/OU=42Lyon/CN=www.mmaxime-.42.fr/UID=mmaxime-" \
# où sera stockée le certif
-out /etc/nginx/ssl/inception.crt \
# et la clé
-keyout /etc/nginx/ssl/inception.key

# expose le port 443 au réseau Docker
EXPOSE 443

# Copie du fichier de ma machine dans l'image Docker en cours de construction, conf.d étant l'emplacement pour appliquer les param communs à ts les sites
COPY conf/nginx.conf /etc/nginx/conf.d

# droits sur ce dont on a besoin (root principal et utilisateur principal)
#RUN chmod 755 /var/www/html
#RUN chown -R www-data:www-data /var/www/html

# Lance nginx en premier plan et non en background pour que le container ne se stop pas
CMD [ "nginx", "-g", "daemon off;" ]
