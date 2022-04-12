/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet :  3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :    Chiffrement de messages                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 :      PHILIPPE Eric                                           *
*                                                                             *
*  Nom-prénom2 :      SOUBAIGNE Brandon                                       *
*                                                                             *
*  Nom-prénom3 :    (MOURCACOS Alexandre)                                     *
*                                                                             *                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :   encodeurV.c                                             *
*                                                                             *
******************************************************************************/

#include "encodeurV.h"

// Encode a message with the Vigenere cipher
void vigenere(char *text, char *key, char *out) {
    int i, length = strlen(key);
    for (i = 0; text[i] != '\0'; i++) {
        if ( text[i] >= 'A' && text[i] <= 'Z' ) {
            int indice = (text[i] + key[i % length] - 6) % 26;
            out[i] = 'A' + indice;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            int indice = (text[i] + key[i % length] - 12) % 26;
            out[i] = 'a' + indice;
        } else {
            out[i] = text[i];
        }
    }
    out[i] = '\0';
}

// Decode a message with the Vigenere cipher
void vigenere_decode(char *text, char *key, char *out) {
    int i, length = strlen(key);
    int indice;
    for (i = 0; text[i] != '\0'; i++) {
        if ( text[i] >= 'A' && text[i] <= 'Z' ) {
            indice = ((text[i] - key[i % length]) % 26) + 6;
            out[i] = 'A' + indice;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            indice = (text[i] - key[i % length] + 26) % 26;
            out[i] = 'a' + indice;
        } else {
            out[i] = text[i];
        }
    }
    out[i] = '\0';
}