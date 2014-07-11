SMTP-prog-C
=========

RFC821 sur le protocole SMTP

Version
----

1.0

Source / Documents
----

- Liste des paramètres des principaux POP, IMAP et SMTP : [ICI](http://www.commentcamarche.net/faq/893-parametres-de-serveurs-pop-imap-et-smtp-des-principaux-fai)

Langage
-----------

Langage C

Cas de tests
--------------

* GMAIL

        email : projet.linux.esgi@gmail.com
        mdp   : Azerty95  
        smtp  : smtp.gmail.com
        port  : 587
	
* YAHOO
		email : projet_linux_esgi@yahoo.fr
		mdp   : Azerty95
		smtp  : smtp.mail.yahoo.com
		port  : 587
		

* YOPMAIL
		email : cequonveut@yomail.com
		mdp   : ?
		smtp  : smtp.yopmail.com
		port  : 25

* HOTMAIL
		email : projet.linux.esgi@hotmail.com
		mdp   : Azerty95
		smtp  : smtp.live.com  
        port  : 587

Running
--------------

Compilation:
```sh
make smtp
```

Lancement:
```sh
./smtp
```


Autres
----

None.  
