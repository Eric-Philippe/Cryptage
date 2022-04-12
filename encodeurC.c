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
*  Nom du fichier :     encodeurC.c                                           *
*                                                                             *
******************************************************************************/

#include "encodeurC.h"

// Encode a message with the Caesar cipher
void caesar(char *message, int shift)
{
    int i;
    for (i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

// Decode a message with the Caesar cipher
void caesar_decode(char *message, int shift)
{
    int i;
    for (i = 0; message[i] != '\0'; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = (message[i] - 'a' - shift) % 26 + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = (message[i] - 'A' - shift) % 26 + 'A';
        }
    }
}