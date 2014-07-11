/**
* @auteur: Joey BRONNER (joeybronner@gmail.com)
*		   Clement CASAMAYOU
*		   Antonin CORNUT
*		   Matthieu POULIN
* @date  : 11/07/2014
* @name  : base64.c
*  
*/
#include "base64.h"

#include <stdlib.h>
#include <stdio.h>

#define BASE64_ENCODE_LEN 65
#define BASE64_DECODE_LEN 128

/* cartographie des caracteres : table de codage en base64.*/
static unsigned char base64_encode_table[BASE64_ENCODE_LEN] =
{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
  '2', '3', '4', '5', '6', '7', '8', '9', '+', '/', '=' };

static unsigned char base64_decode_table[BASE64_DECODE_LEN];




/* Cette methode permet d'ENCODER une chaine de caracteres en base64 */
int base64_encode(const unsigned char* input,		// donnees d'entree
                  int input_length,			        // longueur de l'input
                  unsigned char* output,            // donnees de sortie
                  int output_length                 // longueur de l'output
                 )
{
    int n;
    int index;
    int length2;
    int remainder;
    int encode_length;

    if (!input || input_length <= 0) return -1;

    encode_length = input_length / 3;
    length2 = encode_length * 3;
    remainder = input_length - length2;
    if (remainder) encode_length++;
    encode_length <<= 2;

    if(output_length < encode_length + 1) return -2;

    for (n = 0,index = 0; n < length2; n += 3,index += 4)
    {
        output[index] = base64_encode_table[input[n] >> 2];
        output[index + 1] = base64_encode_table[((input[n] & 0x3) << 4) | (input[n + 1] >> 4)];
        output[index + 2] = base64_encode_table[((input[n + 1] & 0xF) << 2)
                        | ((input[n + 2] & 0xC0) >> 6)];
        output[index + 3] = base64_encode_table[input[n + 2] & 0x3F];
    }

    switch (remainder)
    {
        case 1:
            output[index] = base64_encode_table[input[n] >> 2];
            output[index + 1] = base64_encode_table[(input[n] & 0x3) << 4];
            output[index + 2] = base64_encode_table[BASE64_ENCODE_LEN - 1];
            output[index + 3] = base64_encode_table[BASE64_ENCODE_LEN - 1];
            break;
        case 2:
            output[index] = base64_encode_table[input[n] >> 2];
            output[index + 1] = base64_encode_table[((input[n] & 0x3) << 4) | (input[n + 1] >> 4)];
            output[index + 2] = base64_encode_table[((input[n + 1] & 0xF) << 2)];
            output[index + 3] = base64_encode_table[BASE64_ENCODE_LEN - 1];
            break;
        default:
            break;
    }

    output[encode_length] = 0;

    return encode_length;
}

/* Cette methode permet de DECODER une chaine de caracteres en base64 */
int base64_decode(const unsigned char* input,	// donnees d'entree
                  int input_length,             // longueur de l'input
                  unsigned char* output,        // donnees de sortie
                  int output_length             // longueur de l'output
                  )
{
    int n;
    int index;
    int length2;
    int remainder;
    int decode_length;

    if (!input || input_length <= 0 || (input_length & 0x3))
	{
		return -1;
	}

    /* reinitialisation de la table de decodage si elle est erronee */
    if (base64_decode_table['='] != BASE64_ENCODE_LEN - 1)
    {
        for (n = 0; n < BASE64_ENCODE_LEN; n++) base64_decode_table[base64_encode_table[n]] = n;
    }

    decode_length = (input_length >> 2) * 3;
    if (input[input_length - 1] == base64_encode_table[BASE64_ENCODE_LEN - 1]) decode_length--;
    if (input[input_length - 2] == base64_encode_table[BASE64_ENCODE_LEN - 1]) decode_length--;

    if(output_length < decode_length + 1) return -2;

    length2 = decode_length / 3 * 3;
    remainder = decode_length - length2;

    for (n = 0,index = 0; n < length2; n += 3,index += 4)
    {
        output[n] = (base64_decode_table[input[index]] << 2) | (base64_decode_table[input[index + 1]] >> 4);
        output[n + 1] = (base64_decode_table[input[index + 1]] << 4) | (base64_decode_table[input[index + 2]] >> 2);
        output[n + 2] = (base64_decode_table[input[index + 2]] << 6) | base64_decode_table[input[index + 3]];
    }

    switch (remainder)
    {
        case 1:
            output[n] = (base64_decode_table[input[index]] << 2) | (base64_decode_table[input[index + 1]] >> 4);
            break;
        case 2:
            output[n] = (base64_decode_table[input[index]] << 2) | (base64_decode_table[input[index + 1]] >> 4);
            output[n + 1] = (base64_decode_table[input[index + 1]] << 4) | (base64_decode_table[input[index + 2]] >> 2);
            break;
    }

    output[decode_length] = 0;

    return decode_length;
}

