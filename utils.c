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
*  Nom du fichier : utils.c                                                   *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"

void getMessage(char* str);
void getKeyChar(char* str);
int getKey();
int isAlphaNum(char* str);

// Function that input a string as a key
void getKeyChar(char* myKey) {
    char key[100];
    int valid = 0;

    while(valid != 1) {
        printf("Entrer une clé texte: ");
        scanf(" %[^\n]", key);
        if (isAlphaNum(key) == 1) {
            strcpy(myKey, key);
            valid = 1;
        } else {
            printf("\nVeuillez entrer uniquement des lettres ou des chiffres.\n");
        }
    }

    strcpy(myKey, key);
}

// Function that input a int key and check if it's a valid int
int getKey() {
    int key;

    printf("Entrer une clé positive: ");
    scanf("%d", &key);

    return key;
}

// Function that input a string as a message
void getMessage(char* myMessage) {
    char message[100];
    int valid = 0;

    while(valid != 1) {
        printf("Entrer un message: ");
        scanf(" %[^\n]", message);
        if (isAlphaNum(message) == 1) {
            strcpy(myMessage, message);
            valid = 1;
        } else {
            printf("\nVeuillez entrer uniquement des lettres ou des chiffres.\n");
        }
    }
}

// Function to check if a given strinf is alphanumeric
int isAlphaNum(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}
