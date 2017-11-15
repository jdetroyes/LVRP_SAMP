# GameMode LaVieRolePlay SAMP #

## Description ##

Mode de jeu développé en Pawn fonctionnant sous SA-MP. (http://sa-mp.com/)

**Version Game Mode:** 5.0.2

**Vesion SAMP :** 0.3.7-R2

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

## F.A.Q ##

1. __Il n'y a aucun véhicule, biz, maison, garage etc ...__

La base de données est vierge, c'est à dire qu'aucun véhicule/biz/maison/garage/etc .. n'est créé. C'est à vous de les créer/modifier en jeu en utilisant les commandes d'administrateur :
  * /a creer
  * /a editer
  * /a supprimer
```pawn
msg_Client(playerid, COLOR_WHITE, "{FF6347}� Admin �{FFFFB2} voiture - biz - maison - garage - arret - atm - sapin - panneau - radar - interieur - porte - pub");
> msg_Client(playerid, COLOR_WHITE, "{FF6347}� Admin �{FFFFB2} gps - faction - g_poubelle - p_poubelle - cabine - carte - distributeur - zone - concession");
```

2. __Inscription depuis la site__

* Vous avez mal connecter la GameMode à la base de données
* Rendez-vous dans la base données dans la table "_lvrp_server_setting_" et modifier le champ "_inscription_" à __1__.
  
3. __"Ce joueur n'est pas connecté"__

Vous êtes en possession de la première version publiée du GameMode.
* Vous téléchargez la dernière version du GameMode
* Vous modifiez les lignes suivantes 
```pawn
//Dans OnPlayerConnect et OnPlayerDisconnect, remplacez ça :
MAX_PLAYERS_CURRENT = GetPlayerPoolSize();
//par :
MAX_PLAYERS_CURRENT = GetPlayerPoolSize() + 1;
```
4. __Créer un biz et mettre à l'Etat__

La création d'un biz et le mettre à l'Etat est spécial.
* Création de l'entreprise en /a creer biz
* /a edit biz => changer le propriétaire => Mettre à l'Etat
* Exécuter le commande /bizz type (En admin service si le biz appartient à l'état) => choisir le type de biz
* /a edit biz (En admin service) pour modifier le biz appartenant à l'Etat

5. __"Il n'y a pas de porte sur le serveur ?"__

Les portes sont dynamiques et doivent être créée directement en jeu.
Utilisez les commandes /a creer porte, /a editer porte et //a supprimer porte pour utiliser le système.

6. __Comment être administrateur ?__

* Créez votre compte en jeu ou sur l'un des ucp.
* Rendez-vous dans la table "_lvrp_users_" et modifier le champ "_AdminLevel_" de votre compte à __7__.


