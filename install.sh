#!/bin/bash

cp -r admin/* /usr/share/fusiondirectory/plugins/admin
cp -r contrib/openldap/* /etc/ldap/schema/fusiondirectory/
cp -r locale/* /usr/share/fusiondirectory/locale/plugins
cp -r personal/* /usr/share/fusiondirectory/plugins/personal

insert="fusiondirectory-schema-manager --ldapuri ldap://$1 --binddn cn=admin,cn=config --bindpwd $2 --simplebind --insert-schema"

fusiondirectory-configuration-manager --update-cache
fusiondirectory-configuration-manager --update-locales
${insert} /etc/ldap/schema/fusiondirectory/bolkdata-fd.schema
${insert} /etc/ldap/schema/fusiondirectory/bolkdata-avg-fd.schema
${insert} /etc/ldap/schema/fusiondirectory/bolkdata-mail-fd.schema
