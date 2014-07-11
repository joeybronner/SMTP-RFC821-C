/**
* @auteur: Joey BRONNER (joeybronner@gmail.com)
*		   Clement CASAMAYOU
*		   Antonin CORNUT
*		   Matthieu POULIN
* @date  : 11/07/2014
* @name  : main.c
* @role  : point d'entree du fichier 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "smtp.h"

int main(int argc,char** argv)
{
	/* destinataire */
    const char* to[] = {"joeybronner@gmail.com"};	// adresse(s)
    int to_len = 1;									// nombre d'adresse(s)

	/* methode smtp_send pour envoi du mail */
    smtp_send		(	"smtp.live.com",					// serveur smtp distant 
						587,								// port smtp distant 
						"projet.linux.esgi@hotmail.com",	// adresse email d'envoi 
						"Azerty95",							// mot de passe 
						"sujet",							// sujet du mail 
						"contenu",							// corps du mail 
						to,									// adresse(s) du ou des destinat. 
						to_len								// nombre de destinataires 
			);

    return EXIT_SUCCESS;
}
