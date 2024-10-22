#!/bin/bash

# install.sh <fusion ip> <ldap ip> <ldap passwd>

scp -r admin/* root@$0:/usr/share/fusiondirectory/plugins/admin
scp contrib/openldap/* root@$0:/etc/ldap/schema/fusiondirectory/
scp -r locale/* root@$0:/usr/share/fusiondirectory/locale/plugins
scp -r personal/* root@$0:/usr/share/fusiondirectory/plugins/personal

insert="fusiondirectory-schema-manager --ldapuri ldap://$1 --binddn cn=admin,cn=config --bindpwd $2 --simplebind --replace-schema"

ssh root@$0 "fusiondirectory-configuration-manager --update-cache; ${insert} /etc/ldap/schema/fusiondirectory/bolkdata-fd.schema; ${insert} /etc/ldap/schema/fusiondirectory/bolkdata-avg-fd.schema; ${insert} /etc/ldap/schema/fusiondirectory/bolkdata-mail-fd.schema"
