FROM debian:8.1

ENV DEBIAN_FRONTEND noninteractive
ENV TIMEZONE Europe/Paris

ENV LANG en_US.UTF-8
ENV LC_ALL en_US.UTF-8
ENV LANGUAGE en_US.UTF-8

RUN apt-get update && apt-get install -y wget curl

RUN echo "deb http://packages.dotdeb.org jessie all" >> \
  /etc/apt/sources.list.d/dotdeb.list
RUN echo "deb-src http://packages.dotdeb.org jessie all" >> \
  /etc/apt/sources.list.d/dotdeb.list

RUN wget http://www.dotdeb.org/dotdeb.gpg && apt-key add dotdeb.gpg

# HHVM package
RUN apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0x5a16e7281be7a449
RUN echo deb http://dl.hhvm.com/debian jessie main | tee /etc/apt/sources.list.d/hhvm.list

RUN apt-get update
# Install HHVM, NGINX & PIP
RUN apt-get install --yes --fix-missing \
     hhvm-nightly \
     debconf \
     nginx \
     python-pip \
     ruby-sass \
     build-essential \
     patch \
     libxml2 \
     ruby-dev \
     zlib1g-dev \
     liblzma-dev

RUN apt-get install locales-all locales
# Reconfigure locales
RUN dpkg-reconfigure locales

RUN echo "$TIMEZONE" > /etc/timezone
RUN dpkg-reconfigure -f noninteractive tzdata


# Install SUPERVISOR
RUN mkdir -p /var/log/supervisor
RUN pip install supervisor supervisor-stdout
ADD supervisord.conf /etc/supervisord.conf

# Install composer for hhvm
RUN wget https://getcomposer.org/installer
RUN hhvm -v ResourceLimit.SocketDefaultTimeout=30 -v Http.SlowQueryThreshold=30000 installer
RUN mv composer.phar /usr/local/bin/composer
RUN rm installer

# NGINX config
RUN mkdir -p /var/log/nginx
RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf
ADD goul.conf /etc/nginx/sites-enabled/default
RUN mkdir /var/log/goul/
RUN touch /var/log/goul/access.log
RUN touch /var/log/goul/error.log
# HHVM FastCGI enabled
RUN /usr/share/hhvm/install_fastcgi.sh

# HHVM .ini configuration
RUN echo "date.timezone = $TIMEZONE" >> /etc/hhvm/php.ini

WORKDIR /opt/web/goul

EXPOSE 80
EXPOSE 443

RUN service hhvm restart

CMD supervisord -n -c /etc/supervisord.conf
