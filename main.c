#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Permet d'utiliser les fonctions strlen() et strcat().
#include <ctype.h> //Permet d'utiliser les fonctions isalpha() et tolower().
#define TAILLE 30

//Laetitia Monnier
//BUT : Un programme demandant à l'utilisateur d'entrer un mot, puis deviner celui-ci lettre par lettre avec un nombre de vie déterminé.
//ENTREE : Le mot à deviner puis un caractère alphabétique pour deviner celui-ci.
//SORTIE : Affichage des bons caractères. Diminution de la vie si le caractère saisie n'existe pas dans le mot.
int main()
{
    int vie = 7, longMot = 0, i = 0, boolEstAlpha = 1, boolDansLeMot = 0, bonnesLettres = 0;
    char lettre;
    char tabMot[TAILLE] = "", tmpMot[TAILLE] = "", tabMotADeviner[TAILLE] = "", tabLettreMauvaise[TAILLE] = "", tmpLettre[3] = "  ";

    printf("Programme du pendu.\n");
    //Cette boucle va verifier si l'utilisateur entre des caractères.
    do {
        printf("Saisissez un mot :\n");
        gets(tmpMot);
        longMot = strlen(tmpMot);
        boolEstAlpha = 1;

        for (i = 0; i < longMot; i++){
            if (isalpha(tmpMot[i])) tabMot[i] = tolower(tmpMot[i]);
            else boolEstAlpha = 0;
        }
    } while (boolEstAlpha == 0);

    if (system("CLS")) system("clear");
    for (i = 0; i < longMot; i++){ tabMotADeviner[i] = '-'; }

   do {
        printf("%s\n", tabMotADeviner);
        printf("Entrez une lettre : ");
        fflush(stdin);
        lettre = getc(stdin);

        for (i = 0; i < longMot; i++){
            if ((tabMot[i] == lettre) && (tabMotADeviner[i] == '-')) {
                tabMotADeviner[i] = lettre;
                bonnesLettres++;
                boolDansLeMot = 1;
            }
        }

        if (boolDansLeMot == 0) {
            vie--;
            tmpLettre[0] = lettre;
            strncat(tabLettreMauvaise, tmpLettre, strlen(tmpLettre));
        }
        else boolDansLeMot = 0;

        printf("Lettres mauvaises : %s\n", tabLettreMauvaise);
        printf("\nIl vous reste %d vies.\n", vie);
    } while ((bonnesLettres != longMot) && (vie > 0));

    if (vie == 0) printf("Vous avez perdu !\n");
    else printf("Vous avez gagn\x82 !!\n");

    printf("Le mot \x82tait : %s\n", tabMot);

    system("pause");
    return 0;
}
