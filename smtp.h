/**
* @auteur: Joey BRONNER (joeybronner@gmail.com)
*		   Clement CASAMAYOU
*		   Antonin CORNUT
*		   Matthieu POULIN
* @date  : 11/07/2014
* @name  : smtp.h
* @role  : declaration des methodes du fichier smtp.c
*/

#ifndef SMTP_H_
#define SMTP_H_



#ifdef __cplusplus
extern "C"
{
#endif

/* pour voir un exemple de lancement de la methode smtp_send, voir fichier README.md */
int smtp_send(const char* domain,int port,const char* user_name,const char* password,
              const char* subject,const char* content,const char** to,int to_len);


#ifdef __cplusplus
}
#endif /* end of extern "C" */

#endif /* SMTP_H_ */
