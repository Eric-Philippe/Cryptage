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
*  Nom du fichier :    launcher.c                                             *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "encodeurC.h"
#include "encodeurV.h"
#include "utils.h"

// Function to encode and decode a input message with the Ceasar cipher
void FullTryCeasar() {
    char message[100];
    int key;

    getMessage(message);
    key = getKey();

    printf("\n Message d'origine: %s\n", message);
    printf("\n Clef: %d\n", key);

    caesar(message, key);
    printf("\n Message encodé: %s\n", message);
    caesar_decode(message, key);
    printf("\n Message decodé: %s\n", message);
}

// Function to encode with the Ceasar methode a input message and save it in a file
void encodedToFileCeaser(){
    char message[100];
    int key;

    getMessage(message);
    key = getKey();

    caesar(message, key);

    FILE *fptr;
    fptr = fopen("mon_code.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    fprintf(fptr, "%s" ,message);
    fclose(fptr);

    printf("Message correctement sauvegardé !\n");
}

// Function to decode with the Ceasar methode a message from a file
void fileToDecodeCeaser() {
    char ch;
    int key;
    char finalCh[100];
    char decodedText[100];

    FILE* ptr;
    ptr = fopen("mon_code.txt", "r");
 
    if (NULL == ptr) {
        printf("Le fichier ne peut pas être ouvert !\n");
    }
  
    fscanf(ptr, "%s", finalCh); 
    fclose(ptr);

    printf("Code prélevé du fichier : %s\n", finalCh);
    key = getKey();
    caesar_decode(finalCh, key);
    printf("Code décodé avec la clé %i: %s\n", key, finalCh);
}

// Function to decode a input message with the Caesar methode
void decodeCeaser() {
    int key;
    char str[100];
    char decodedText[100];

    getMessage(str);
    key = getKey();
    caesar_decode(str, key);

    printf("Code décrypté : %s\n", str);
}

// Function to encode and decode a input message with the Vigenere methode
void FullTryVigenere() {
    char message[100];
    char out_e[100];
    char out_d[100];
    char key[100];

    getMessage(message);
    getKeyChar(key);

    printf("\n Message d'origine: %s\n", message);
    printf("\n Clef: %s\n", key);

    vigenere(message, key, out_e);
    printf("\n Message encodé: %s\n", out_e);
    vigenere_decode(out_e, key, out_d);
    printf("\n Message decodé: %s\n", out_d);
}

// Function to encode with the Vigenere methode a input message and save it in a file
void encodedToFileVigenere(){
    char message[100];
    char out_e[100];
    char key[100];

    getMessage(message);
    getKeyChar(key);

    vigenere(message, key, out_e);

    FILE *fptr;
    fptr = fopen("mon_code.txt","w");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    fprintf(fptr, "%s" ,out_e);
    fclose(fptr);

    printf("Message correctement sauvegardé !\n");
}

// Function to decode with the Vigenere methode a message from a file
void fileToDecodeVigenere() {
    char key[100];
    char out_f[100];
    char out_d[100];
 
    FILE* ptr;
    ptr = fopen("mon_code.txt", "r");
 
    if (NULL == ptr) {
        printf("Le Fichier ne peut pas être ouvert \n");
    }
  
    fscanf(ptr, "%s", out_f); 
    fclose(ptr);

    printf("Code prélevé du fichier : %s\n", out_f);
    getKeyChar(key);
    vigenere_decode(out_f, key, out_d);
    printf("Code décodé avec la clé %s: %s\n", key, out_d);
}

// Function to decode a input message with the Vigenere methode
void decodeVigenere() {
    char key[100];
    char str[100];
    char out_d[100];

    getMessage(str);
    getKeyChar(key);
    vigenere_decode(str, key, out_d);

    printf("Code décrypté : %s\n", out_d);
}