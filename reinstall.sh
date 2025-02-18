#!/bin/bash

cp -r admin/* /usr/share/fusiondirectory/plugins/admin
cp -r contrib/openldap/* /etc/ldap/schema/fusiondirectory/
cp -r locale/* /usr/share/fusiondirectory/locale/plugins
cp -r personal/* /usr/share/fusiondirectory/plugins/personal


fusiondirectory-configuration-manager --update-cache
fusiondirectory-configuration-manager --update-locales

if [ -z "$1" ]; then
    exit 0
fi

replace="fusiondirectory-schema-manager --ldapuri ldap://$1 --binddn cn=admin,cn=config --bindpwd $2 --simplebind --replace-schema"

${replace} /etc/ldap/schema/fusiondirectory/bolkdata-fd.schema
${replace} /etc/ldap/schema/fusiondirectory/bolkdata-avg-fd.schema
${replace} /etc/ldap/schema/fusiondirectory/bolkdata-mail-fd.schema
