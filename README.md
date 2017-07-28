# GameMode LaVieRolePlay SAMP #

## Description ##

Mode de jeu développé en Pawn fonctionnant sous SA-MP. (http://sa-mp.com/)

## Requis ##
* [Mysql Plugin r41-2 ou plus](http://forum.sa-mp.com/showthread.php?t=56564)
* [Streamer Plugin 2.9.1 ou plus](http://forum.sa-mp.com/showthread.php?t=102865)
* [Encrypt Plugin](http://forum.sa-mp.com/showthread.php?t=152682)

## Documentation ##
https://sa-mp-fr.com/files/file/171-la-vie-roleplay-final/

## Installation ##
Télécharger ou cloner le repo.

Importer la base de données vers votre serveur SQL puis configurer la la base de données dans le GameMode 

```pawn
// Identifiants MySQL
#define MYSQL_HOST "127.0.0.1"                                  		
#define MYSQL_USER "root"                                                   
#define MYSQL_PASS ""                                  
#define MYSQL_DB   ""                                        
```
Lancez samp-server.exe
