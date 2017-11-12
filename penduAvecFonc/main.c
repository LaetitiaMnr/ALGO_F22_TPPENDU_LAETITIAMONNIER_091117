#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLE 30
//Laetitia Monnier
//Prototype//
void verifAlpha(char*, char*, int*);
void affichage(int, char*);
void verifBonnesLettres(char*, char*, char*, char*, int*, int, int*, char);
void mauvaiseLettre(char*, char*, int*, char);


int main()
{
    char tmpMot[TAILLE] = "", tabMot[TAILLE] = "", tabMotADeviner[TAILLE] = "", tabLettreMauvaise[TAILLE] = "", tmpLettre[3] = "  ";
    char lettre;
    int longMot = 0, vie = 7, bonnesLettres = 0;

    printf("Programme du pendu.\n");

    verifAlpha(tmpMot, tabMot, &longMot);

    affichage(longMot, tabMotADeviner);

    if (system("CLS")) system("clear");

    do {
        printf("%s\n", tabMotADeviner);
        printf("Entrez une lettre : \n");
        fflush(stdin);
        lettre = getc(stdin);

        verifBonnesLettres(tabMot, tabMotADeviner, tabLettreMauvaise, tmpLettre, &bonnesLettres, longMot, &vie, lettre);

        printf("Lettres mauvaises : %s\n", tabLettreMauvaise);
        printf("\nIl vous reste %d vies.\n", vie);
    } while ((bonnesLettres != longMot) && (vie > 0));

    if (vie == 0) printf("Vous avez perdu !\n");
    else printf("Vous avez gagn\x82 !!\n");

    printf("Le mot \x82tait : %s\n", tabMot);

    system("pause");

    return 0;
}


//BUT : Procédure vérifiant si l'utilisateur entre bien un caractère alphabétique.
//ENTREE : Une chaine.
//SORTIE : Si tous les caractères entrés sont alphabétique, on sort de la boucle.
void verifAlpha(char tmpMot[TAILLE], char tabMot[TAILLE], int* longMot)
{
    int i = 0, boolAlpha = 0;

    do{
        printf("Saisissez un mot :\n");
        scanf("%s", tmpMot);
        *longMot = strlen(tmpMot);
        boolAlpha = 1;

        for (i = 0; i < *longMot; i++){
            if (isalpha(tmpMot[i]))
                tabMot[i] = tolower(tmpMot[i]);
            else
                boolAlpha = 0;
        }

    } while(boolAlpha == 0);
}


//BUT : Cette procédure permet d'afficher le mot à deviner et indique le nombre de lettre.
void affichage(int longMot, char tabMotADeviner[TAILLE])
{
    int i = 0;

    for (i = 0; i < longMot; i++) tabMotADeviner[i] = '-';
}

//BUT : Verifie que la lettre entrée par l'utilisateur existe dans le mot.
void verifBonnesLettres(char tabMot[TAILLE], char tabMotADeviner[TAILLE], char tabLettreMauvaise[TAILLE], char tmpLettre[3], int *bonnesLettres, int longMot, int *vie, char lettre)
{
    int i = 0, boolDansLeMot = 0;

    for (i = 0; i < longMot; i++){
        if ((tabMot[i] == lettre)&& (tabMotADeviner[i] == '-')){
            tabMotADeviner[i] = lettre;
            (*bonnesLettres)++;
            boolDansLeMot = 1;
        }
    }

    if (boolDansLeMot == 0) mauvaiseLettre(tabLettreMauvaise, tmpLettre, vie, lettre);
}

//BUT : Si la lettre entrée par l'utilisateur n'existe pas dans le mot, on enlève de la vie et on stock la mauvaise lettre dans un tableau.
void mauvaiseLettre(char tabLettreMauvaise[TAILLE], char tmpLettre[3], int *vie, char lettre)
{
    (*vie)--;
    tmpLettre[0] = lettre;
    strncat(tabLettreMauvaise, tmpLettre, strlen(tmpLettre));
}
