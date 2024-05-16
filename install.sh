#!/bin/bash


scp -r config/* root@192.168.1.237:/usr/share/fusiondirectory/plugins/config
scp contrib/openldap/* root@192.168.1.237:/etc/ldap/schema/fusiondirectory/
scp -r locale/* root@192.168.1.237:/usr/share/fusiondirectory/locale/plugins
scp -r personal/* root@192.168.1.237:/usr/share/fusiondirectory/plugins/personal

ssh root@192.168.1.237 "fusiondirectory-setup --update-cache; fusiondirectory-insert-schema -i /etc/ldap/schema/fusiondirectory/bolkdata-fd.schema -o \"-H ldap://192.168.1.236 -D 'cn=admin,cn=config' -w openLDAP2023! -x\"; fusiondirectory-insert-schema -i /etc/ldap/schema/fusiondirectory/bolkdata-avg-fd.schema -o \"-H ldap://192.168.1.236 -D 'cn=admin,cn=config' -w openLDAP2023! -x\"; fusiondirectory-insert-schema -i /etc/ldap/schema/fusiondirectory/bolkdata-fd-conf.schema -o \"-H ldap://192.168.1.236 -D 'cn=admin,cn=config' -w openLDAP2023! -x\"; fusiondirectory-insert-schema -i /etc/ldap/schema/fusiondirectory/bolkdata-mail-fd.schema -o \"-H ldap://192.168.1.236 -D 'cn=admin,cn=config' -w openLDAP2023! -x\""
