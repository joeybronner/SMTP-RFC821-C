/**
* @auteur: Joey BRONNER (joeybronner@gmail.com)
*		   Clement CASAMAYOU
*		   Antonin CORNUT
*		   Matthieu POULIN
* @date  : 11/07/2014
* @name  : base64.h
*  
*/
#ifndef BASE64_H_
#define BASE64_H_

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @name : base64_encode 
* @job  : Cette methode permet d'ENCODER une chaine de caracteres en base64
*/
int base64_encode(const unsigned char* input,int input_length,unsigned char* output,int output_length);

/**
* @name : base64_decode 
* @job  : Cette methode permet de DECODER une chaine de caracteres encodee en base64
*/
int base64_decode(const unsigned char* input,int input_length,unsigned char* output,int output_length);

#ifdef __cplusplus
}
#endif

#endif /* BASE64_H_ */
