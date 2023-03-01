# GameMode LaVieRolePlay SAMP #
Utilisé sous la version*San Andreas RolePlay v3*

## Description ##

Mode de jeu développé en Pawn fonctionnant sous SA-MP. (http://sa-mp.com/)

**Version Game Mode:** 5.0.2

**Version SAMP :** 0.3.7-R2

## Requis ##
* [Mysql Plugin r41-2 ou plus](http://forum.sa-mp.com/showthread.php?t=56564)
* [Streamer Plugin 2.9.1 ou plus](http://forum.sa-mp.com/showthread.php?t=102865)
* [Encrypt Plugin](http://forum.sa-mp.com/showthread.php?t=152682)

## Documentation ##
~~https://sa-mp-fr.com/files/file/171-la-vie-roleplay-final/~~

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


## Documentation

Ce GameMode est basé sur u2c (Vous retrouverez en creusant bien de petits de bouts de code restants)


 Je remercie Lurtz5, Jax' et Steven pour toutes les idées qu'ils ont apporté ainsi que pour leur mapping.

- Ce Gamemode est développé sur **les 14 villes de San Andreas**, son fonctionnement est dynamique.

- Ce Gamemode fonctionne avec **une base de donnée MySQL.**

- Ce Gamemode fonctionne avec des interactions de touches (Touche 'N', touche 'Y', touche 'ENTER', etc ..) et des bots (Dans les bizs, arrêts de bus, intérieurs, etc ...).

- Le mapping s'ajoute dans le filterscript **"mapping.pwn"**.


### Mapping
- Mapping à ne pas supprimer pour le bon fonctionnement du Gamemode, sauf si vous souhaitez les changer :

- Dans le filterscript "mapping.pwn"
   - Les intérieurs vides des maisons
   - L'intérieur de l'hopital
   - L'intérieur de l'école des langues
   - L'intérieur des opérateurs téléphoniques
   - L'intérieur du tribunal
   - L'intérieur de l'ANPE
   - L'intérieur de la poste
- Dans le gamemode
   - Le mapping situé dans la fonction (ini_Mapping() du gamemode)
   
### Entités dynamiques
- Véhicules
- Biz / Biz uniques
- Maisons
- Garages
- Radars
- ATMS
- Distributeurs
- Cabine téléphonique
- Arrêts de bus
- Panneaux publicitaires
- Panneaux (Ex : stop, écrire un message sur un panneau)
- Intérieurs (Auto-Ecole, ANPE, etc..)
- Factions légales (Polices (x4), Gouvernements (x4), San News, etc ..)
- Factions illégales (Gang et mafia)
- GPS/Cartes
- Sapin de noël
- Petites poubelles (Pour jeter des items)
- Grande poubelles (Nécessaire au job eboueur)
- Porte/Grille
- Tags
- Concessions (Prix des véhicules stockés dans la bdd, modification IG [/a vehprice <model> <prix>])

**Tous ces systèmes peuvent être ajoutés/modifiés/supprimés par un administrateur.** *[ /a creer <nom> - /a editer <nom> - /a supprimer <nom> ]*

### Paramètres

Les paramètres (table "lvrp_server_settings")
- Le champ "anticheat" correspond à l'activation de l'anticheat en jeu (0: NON - 1: OUI)
- Le champ "inscription" correspond à l'activation des inscriptions en jeu (0: NON - 1: OUI)
- Le champ "beta" correspond à l'activation des inscriptions en mode BETATEST (0: NON - 1: OUI) [Voir plus bas]
- Le champ "bot" correspond à l'activation des bots en jeu (0: NON - 1: OUI)

### Fonctionnalités

##### Système de maison (CMD: (/ma)ison)

- Un joueur peut disposer de 3 maisons
- Les intérieurs des maisons sont vides, ils doivent être meublés par le propriétaire (/ma mobi)
- Le propriétaire me gérer la location (Prix de location/virer les propriétaires/etc)
- Les maisons disposent d'un coffre pour stocker les objets/armes/armure (Stockage : Items/drogues/armes/argent/armue/etc...)


##### Système de biz (CMD: /biz)

- Le joueur peut disposer de 3 biz
- Choix du type de biz à l’achat
- Le propriétaire peut modifier le prix de chaque article
- Commandes traditionnelles (Prix d’entrée/porte/etc)


##### Système de Garage (CMD: /garage)

- Le joueur peut disposer de 3 garages
- Le joueur peut garer ses véhicules dans ses garages
- Utilisez les commande /entrer et /sortir pour entrer/sortir d'un garage


##### Système de véhicule (CMD: (/v)ehicule )

- Le joueur peut disposer de 3 véhicules (Non vip) jusqu’à 6 véhicules (VIP)
- Tuning standard + néons
- Commandes traditionnelles (/v …)
- Taille du coffre du véhicule en fonction de sa taille
- Coffre véhicule (Stockage : Items/drogues/armes/argent/armure/etc...)
- Régulateur de vitesse
- Système de bridage/debridage (/mecano debrider - /mecano brider)


##### Système de téléphone + opérateurs téléphoniques (CMDS: /tel - /forfait - etc..)

- Quatre opérateurs différents (Biz uniques : possibilité de modifier les prix)
- Téléphone interactif (TextDraw)
- Système de répertoire (10 contacts)
- Derniers SMS reçus
- Derniers SMS envoyés
- Sa consommation en cours / Radios / MP3 / Carte
- Commande /t sms et /t appel


##### Système de faim et soif + Système de mort

- Vous devez vous nourrir/boire (Biz, distributeur, items …)
- Si votre soif/faim atteint 0 vous perdez de la vie
- Si votre vie atteint 0 vous serrez en mode « gravement blessé »
1. les secours sont appelés pour vous si des médecins sont en service
2. vous pouvez /accepter mort
3. vous ne pouvez mourir qu’avec une arme au corps à corps
- A votre mort vous apparaissez à l’hopital le plus proche (en fonction de votre localisation et la position des hôpitaux créés)
- A votre mort vous perdez toutes les armes qui sont sur vous (Pas dans votre sac) ainsi qu'un peut d'argent sous forme de drop posés au sol (Ramassable avec la touche 'C')
- Un cadavre est crée à votre mort


##### La police (LSPD/SFPD/LVPD/FCPD) (CMD: (/p)olice)

- Script complet
- Le leader peut modifier le nom des rangs, skins, l’intérieur, etc …
- Le leader peut créer/modifier/supprimer les amendes


##### Le gouvernement (LS/SF/LV/SA) (CMD: (/gouv)ernement)

- Le maire de chaque ville peut modifier les salaires des factions légales de la ville (+ chômage)
- Le maire de chaque ville attribut les taxes de sa ville.
- Le Maire de SA attribut le salaire des jobs
- Le Maire de SA attribut le prix des douanes
- Le leader de la faction peut modifier le nom des rangs, les skins, etc ..


##### L’inventaire / Items (CMD: /sac)

- Vous disposez d’un sac, vous pouvez poser ce sac avec /sac poser
- Vous pouvez poser tous vos items/armes
- Les items/armes posés à terre sont sauvegardés
- Utilisé la touche ‘C’ pour récupérer un item à terre
- Vous pouvez déposer vos items dans votre voiture/maison
- Vous pouvez jeter vos items dans les poubelles


##### Les gangs (CMD: /gang)

- Les gangs sont à créer directement en jeu
- Le leader décide du nom des rangs, position du QG, position du coffre, couleur du gang, etc ..
- Les gangs peuvent taguer les murs /gang tag
- Les gangs peuvent voler les voitures/biz/atms/joueurs (Pied de biche nécessaire)
- Les gangs peuvent planter/recolter de la drogue (Weed)
- Les gang disposent d'un coffre pour stocker (Items/drogues/armes/argent/armue/etc...)


##### Les mafias (CMD: /mafia)

- Les mafias sont à créer directement en jeu
- Le leader décide du nom des rangs, position du QG, etc ..
- Le coffre de la mafia se trouve dans le qg (Stockage : Items/drogues/armes/argent/armue/etc...)
- La mafia peur créer des armes
- La mafia peut planter/créer de la drogue (Cocaïne/Héroïne/Ecstasy)


##### Les jobs (CMD: /job)

- Vous trouvez la localisation des jobs pour chaque ville dans les ANPE
- La plupart des jobs ont été travaillés, fini les checks points (Eboueur/pêcheur/ouvrier/etc …)
- Le joueur doit travailler 25 mins en jeu pour obtenir sa paye


##### Les accessoires (CMD: /accessoire)

- Le /accessoire vous permet de porter n’importe quel item de votre inventaire
- Vous pouvez choisir la position (Tête/bras/jambe/etc…)
- Vous pouvez modifier la position ou l’enlever l’accessoire
- Les accessoires portés sur le joueur sont sauvegardés à sa reconnexion


##### Les jobs

**Les jobs interactifs innovants : à vous de les tester !**

- Livreur de pizza (LS - SF - LV)
- Fermier (LS)
- Mineur (LV)
- Eboueur (LS - SF - LV)
- Ouvrier (LV)
- Facteur (LS - SF - LV)
- Pêcheur (LS - BS)
- Voiturier (LS - SF)
- Les jobs traditionnels : Pilote de ligne, Camionneur, Medecin et Mécanicien


##### Système de cadavre

- Un cadavre est créé à la mort d'un joueur
- Pour interagir avec un cadavre, utilisez la touche 'N', vous avez différents choix
1. Le brûler (Nécessite un jerrican et un briquet)
2. L'enterrer (Nécessite une pelle)
3. Le transporter avec vous
4. [Polices] Inspecter le cadavre
- Les cadavres peuvent être transportés dans le coffre des véhicules


##### Système de Carcasse de véhicule (Script à activer : OnVehicleDeath(...) )

- Une carcase se crée lorsque qu'un véhicule explose
- Les mécaniciens peuvent ramasser ces carcasses avec un DFT-30 (/mecano rem)
- Les mecaniciens en service sont informés lorsque qu'il y une carcasse


##### Système de BetaTest

- L'activation du mode betatest se fait en modifiant la variable "beta" à 1 dans la table "lvrp_server_settings"
- Lors de la connexion une clef betatest sera demandé au joueur pour s'inscrire
- Les clefs betatest sont à insérer dans la table "lvrp_server_betakeys"
- La clef ne peut être utilisée qu'une seule fois

##### Autres systèmes
 - /boombox - Lancer une boombox à partir d'un url

 - /pme - Poser un message à terre

 - /vme - Mettre un message au dessus du véhicule

 - /prefixe - Ajoute un préfixe devant votre message (Ex: /prefix [Acc. russe]  => "Salut" => [Acc. russe] Billy_Braxton : Salut)

 - /l1 et /l2 - Parler avec vos autres langues (Apprentissage en Ecole des Langues)

 - /laser - Afficher un laser sur votre arme

 - /marche - Choisir son style de marche

 - /comeback - Respawn à votre ancienne position (Disponible pendant une minute lors de votre connexion)

 - /spawn - Choix du spawn (Civil, faction, maison, etc..)

 - /fps - Passage en mode FPS (ON/OFF)

 - /membres - Affiche les membres connectés et déconnectés de votre faction

 - /piedbiche - Met votre pied de biche dans votre main

- /trailer - Retire tous les TextDraw

- Intérieur du Jet privé (Pour entrer, allez à côté d'un jet et appuyez sur la touche G) 

- Intérieur de l'andromada (Pour entrer, allez à côté d'un andromada et appuyez sur la touche G) 

-  Système de Biker non terminé (Script à activer)

-  Système de Pompier non terminé (Script à activer)

 - Système de clignotants

 - Système de FlashBall pour la police

 - Système San News avec système de jeu par SMS

 - Système de mariage à l'église et de divorce dans les Mairies

 - Système de faim + soif

 - Système de numéro d'inconnu

 - Système de Braquage de Banque (pirater le système => décoder la porte => prendre l'argent => etc)

 - Système de choix de payement : cash/carte bancaire/chèque (TextDraw interactif)

 - Système d’alcoolémie (Taux d'alcool dans sang en fonction du  nombre de boisson alcoolisé ingérer) - Alcootest pour la police (/p alcootest)

 - Système de drogue (Chaque drogue a un effet différent sur votre personnage)

 - Si je joueur a de l'armure, il sera juste protégé au niveau de son torse

 - etc ..

### Logs
Les logs enregistrées sur la base de données

- Logs admin
- Logs du chat
- Logs des commandes tapées
- Logs des connexions
- Logs des morts
- Logs des deconnexions
- Logs des actions du gouvernement 
- Logs des jails
- Logs des kicks
- Logs des payements en jeu
- Logs des renames
- Logs des achats boutique (site)
- Logs des achats tokens (site)

### Sites / UCP

#### Lvrp v1
- https://github.com/jdetroyes/LVRP_v1_web
[lvrp_v1](http://image.prntscr.com/image/c6bb56bc7a2346f1b71380feff3ead89.png)

#### Lvrp v2
- https://github.com/jdetroyes/LVRP_v2_web
[lvrp_v2](http://image.prntscr.com/image/db646b00840e4f8facc9748e6daaf568.png)

#### Lvrp v3
- https://github.com/jdetroyes/LVRP_v3_web
[lvrp_v3](http://image.prntscr.com/image/17ef7a585b79432abf45a7e7ddcd1116.png)

#### San Andreas RolePlay v3
- https://github.com/jdetroyes/SanAndreasRP_v3_web
[sarp_v3](http://image.prntscr.com/image/dc44b5b34a7443e9b5d5ead2de78fcac.png)
