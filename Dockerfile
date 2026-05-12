FROM nginx:alpine

# Copy your website files
COPY index.html      /var/www/acmeco/
COPY css/            /var/www/acmeco/css/
COPY js/             /var/www/acmeco/js/
COPY robots.txt      /var/www/acmeco/

# Copy nginx config
COPY nginx/nginx.conf /etc/nginx/conf.d/default.conf

EXPOSE 80 443