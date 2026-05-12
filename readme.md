Next steps
•	Add a backend endpoint at /api/contact for the form
•	Replace images/about.jpg with your real image (consider WebP format)
•	Add a sitemap.xml for better SEO
•	Run through PageSpeed Insights to verify performance

Deployment Steps
1.	Install Nginx & Certbot (Ubuntu/Debian):

sudo apt update && sudo apt install nginx certbot python3-certbot-nginx

2.	Deploy files:
sudo mkdir -p /var/www/acmeco
sudo cp -r ./* /var/www/acmeco/
sudo chown -R www-data:www-data /var/www/acmeco

3.	Enable site:
sudo ln -s /etc/nginx/sites-available/acmeco /etc/nginx/sites-enabled/
sudo nginx -t && sudo systemctl reload nginx

4.	SSL Certificate:
sudo certbot --nginx -d yourdomain.com -d www.yourdomain.com
Performance Optimizations
•	✅ defer script loading
•	✅ Font preconnect hints
•	✅ loading="lazy" for images
•	✅ Gzip compression in Nginx
•	✅ Aggressive caching headers for static assets
•	✅ Security headers (CSP, HSTS, etc.)
•	✅ HTTP/2 enabled

5.	Firewall:
sudo ufw allow 'Nginx Full'

Performance Optimizations
•	✅ defer script loading
•	✅ Font preconnect hints
•	✅ loading="lazy" for images
•	✅ Gzip compression in Nginx
•	✅ Aggressive caching headers for static assets
•	✅ Security headers (CSP, HSTS, etc.)
•	✅ HTTP/2 enabled




