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
*  Nom du fichier :    menus.c                                                *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menus.h"
#include "launcher.h"

int getCMD(int page);

// Display the given menu
void displayMenu(int page) {
    char path[255] = "Menus/";
    char fileName[40];
    switch (page)
    {
    case 1:
        strcpy(fileName, "menu.txt");
        break;
    case 2:
        strcpy(fileName, "menuCesar.txt");
        break;
    case 3:
        strcpy(fileName, "menuVigenere.txt");
        break;
    }

    strcat(path, fileName);

    FILE* ptr;
    char ch;
 
    // Opening file in reading mode
    ptr = fopen(path, "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    //system("clear");
    printf("\033[0;36m");


    do {
        ch = fgetc(ptr);
        printf("%c", ch);
 
    } while (ch != EOF);

    fclose(ptr);
    printf("\n ");

    int cmd = getCMD(page);
}

// Get the user choice and move to the chosen page
int getCMD(int page) {

    printf("\033[1;31m");
    printf(">>> ");
    int x;
    x = getchar();

    switch (page)
    {
    // Main menu
    case 1:
        switch (x)
        {
        case 48:
            exit(1);
            break;
        case 49:
            displayMenu(2);   
            break; 
        case 50:
            displayMenu(3);   
            break;     
        }
        break;
        // Caesar menu
    case 2: 
        switch (getchar())
        {
        case 48:
            displayMenu(0);
            break;
        case 49:
            FullTryCeasar();
            break;
        case 50:
            encodedToFileCeaser();
            break;
        case 51:
            fileToDecodeCeaser();
            break;
        case 52:
            decodeCeaser();
            break;   
        }
        break;
    // Vigenere menu
    case 3:
        switch (getchar())
        {
        case 48:
            displayMenu(0);
            break;
        case 49:
            FullTryVigenere();
            break;
        case 50:
            encodedToFileVigenere();
            break;
        case 51:
            fileToDecodeVigenere();
            break;
        case 52:
            decodeVigenere();
            break;   
        }
        break;
    }
}