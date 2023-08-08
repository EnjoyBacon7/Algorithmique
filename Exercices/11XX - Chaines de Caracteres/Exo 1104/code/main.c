#include <stdio.h>
#include <string.h>

int menu();
void saisirChaine(char* chaine);
void convertirMajuscule(char* chaine);
void compterVoyelles(char* chaine);
void convertirMinuscule(char* chaine);
void comparerChaines(char* chaine1);
void concatenerChaines(char* chaine1);
void crypterChaine(char* chaine);
void decrypterChaine(char* chaine);
void afficherChaine(char* chaine);


int main() {


    while (menu()) {}
    
    return 0;
    
}

int menu() {

    int choix;
    printf("Choisissez une action :\n");
    printf("1 - Saisir une chaine\n");
    printf("2 - Convertir en majuscule\n");
    printf("3 - Compter le nombre de voyelles\n");
    printf("4 - Convertir en minuscule\n");
    printf("5 - Comparer 2 chaines\n");
    printf("6 - Concatener 2 chaines a une troisieme\n");
    printf("7 - Crypter une chaine\n");
    printf("8 - Decrypter une chaine\n");
    printf("9 - Quitter\n");

    fflush(stdin);
    scanf("%d", &choix);

    char chaine[100];

    switch(choix) {
        case 1:
            saisirChaine(chaine);
            break;
        case 2:
            convertirMajuscule(chaine);
            break;
        case 3:
            compterVoyelles(chaine);
            break;
        case 4:
            convertirMinuscule(chaine);
            break;
        case 5:
            comparerChaines(chaine);
            break;
        case 6:
            concatenerChaines(chaine);
            break;
        case 7:
            crypterChaine(chaine);
            break;
        case 8:
            decrypterChaine(chaine);
            break;
        case 9:
            return 0;
        default:
            printf("Choix invalide\n");
            break;
    }
    return 1;
}

void saisirChaine(char* chaine) {

    printf("Saisissez une chaine : ");
    fflush(stdin);
    gets(chaine);
}

void convertirMajuscule(char* chaine) {

    int i = 0;
    int dif = 'a' - 'A';
    while(chaine[i] != '\0') {
        if(chaine[i] >= 'a' && chaine[i] <= 'z') {
            chaine[i] -= dif;
        }
        i++;
    }
    printf("Chaine en majuscule : ");
    afficherChaine(chaine);
}

void compterVoyelles(char* chaine) {

    int i = 0;
    int nbVoyelles = 0;
    while(chaine[i] != '\0') {
        if(chaine[i] == 'a' || chaine[i] == 'e' || chaine[i] == 'i' || chaine[i] == 'o' || chaine[i] == 'u' || chaine[i] == 'y') {
            nbVoyelles++;
        }
        i++;
    }
    
    printf("Il y a %d voyelles\n", nbVoyelles);
}

void convertirMinuscule(char* chaine) {

    int i = 0;
    int dif = 'a' - 'A';
    while(chaine[i] != '\0') {
        if(chaine[i] >= 'A' && chaine[i] <= 'Z') {
            chaine[i] += dif;
        }
        i++;
    }

    printf("Chaine en minuscule : ");
    afficherChaine(chaine);
}

void comparerChaines(char* chaine1) {

    char chaine2[100];
    printf("Entrez la deuxieme chaine a comparer : ");
    fflush(stdin);
    gets(chaine2);

    int resultat = strcmp(chaine1, chaine2);

    printf("Chaine 1 : %s\n", chaine1);
    printf("Chaine 2 : %s\n", chaine2);

    if(resultat == 0) {
        printf("Les chaines sont identiques\n");
    } else if(resultat < 0) {
        printf("La chaine 1 est inferieure a la chaine 2\n");
    } else {
        printf("La chaine 1 est superieure a la chaine 2\n");
    }
}

void concatenerChaines(char* chaine1) {

    char chaine2[100];
    printf("Entrez la deuxieme chaine a concatener : ");
    fflush(stdin);
    gets(chaine2);

    char chaine3[200];
    printf("Entrez la troisieme chaine : ");
    fflush(stdin);
    gets(chaine3);

    strcat(chaine1, chaine2);
    strcat(chaine1, chaine3);

    printf("Chaine Concatenee :");
    afficherChaine(chaine1);
}

void crypterChaine(char* chaine) {

    int i = 0;
    while(chaine[i] != '\0') {
        if(chaine[i] >= 'a' && chaine[i] <= 'z') {
            chaine[i] += 1;
            if(chaine[i] > 'z') {
                chaine[i] = 'a';
            }
        }
        i++;
    }

    printf("Chaine cryptee : ");
    afficherChaine(chaine);
}

void decrypterChaine(char* chaine) {

    int i = 0;
    while(chaine[i] != '\0') {
        if(chaine[i] >= 'a' && chaine[i] <= 'z') {
            chaine[i] -= 1;
            if(chaine[i] < 'a') {
                chaine[i] = 'z';
            }
        }
        i++;
    }

    printf("Chaine decryptee : ");
    afficherChaine(chaine);
}

void afficherChaine(char* chaine) {

    printf("%s\n", chaine);
}