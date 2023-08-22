#include <stdio.h>
#include <string.h>

int menu();
void saisieAffichage();
void nombreVoyelles();
void concatMiroir();
void nombreConsonnes();

int verifAlpha(char lettre);

int main()
{

    int choix;
    while (1)
    {
        choix = menu();
        switch (choix)
        {
        case 1:
            saisieAffichage();
            break;
        case 2:
            nombreVoyelles();
            break;
        case 3:
            concatMiroir();
            break;
        case 4:
            nombreConsonnes();
            break;
        case 5:
            return 0;
        default:
            printf("L'entree n'est pas valide. Reessayez.");
            break;
        }
    }
}

int menu()
{

    int choix;
    printf("Choisissez une action:\n");
    printf("1. Saisir et afficher\n");
    printf("2. Nombre de voyelles\n");
    printf("3. Concatenation miroir\n");
    printf("4. Nombre de consonnes\n");
    printf("5. Quitter\n\n");
    scanf("%d", &choix);
    fflush(stdin);
    return choix;
}

void saisieAffichage()
{

    char chaine[51];

    printf("Entrez la chaine a afficher: ");
    fgets(chaine, 51, stdin);
    chaine[strlen(chaine) - 1] = '\0';

    printf("La chaine saisie est: %s\n\n", chaine);
}

void nombreVoyelles()
{

    char chaine[100];
    int nombre = 0;

    printf("Entrez la chaine dont il faut compter les voyelles: ");
    fgets(chaine, 100, stdin);
    chaine[strlen(chaine) - 1] = '\0';

    int i = 0;
    while (chaine[i] != '\0')
    {
        if (verifAlpha(chaine[i]) == 1)
        {
            nombre++;
        }
        i++;
    }

    printf("Le nombre total de voyelles est %d\n\n", nombre);
}

void concatMiroir()
{

    char chaine[100];
    char inverse[100];
    char concat[200];
    int nombre = 0;

    printf("Entrez la chaine qu'il faut concatener: ");
    fgets(chaine, 100, stdin);
    chaine[strlen(chaine) - 1] = '\0';

    for (int i = 0; i < strlen(chaine); i++)
    {
        inverse[i] = chaine[strlen(chaine) - i - 1];
    }
    strcpy(concat, chaine);
    strcat(concat, " : ");
    strcat(concat, inverse);

    printf("La chaine concatenee est: %s\n\n", concat);
}

void nombreConsonnes()
{

    char chaine[100];
    int nombre = 0;

    printf("Entrez la chaine dont il faut compter les consonnes: ");
    fgets(chaine, 100, stdin);
    chaine[strlen(chaine) - 1] = '\0';

    int i = 0;
    while (chaine[i] != '\0')
    {
        if (verifAlpha(chaine[i]) == 2)
        {
            nombre++;
        }
        i++;
    }

    printf("Le nombre total de consonnes est %d\n\n", nombre);
}

// Rend 1 pour voyelle, 2 pour consonne, -1 pour symbole
int verifAlpha(char lettre) {

    if((lettre >= 65 && lettre <= 90) || (lettre >= 97 && lettre <= 122)) {
        if(lettre == 'a' || lettre == 'e' || lettre == 'i' || lettre == 'o' || lettre == 'u' || lettre == 'y' || lettre == 'A' || lettre == 'E' || lettre == 'I' || lettre == 'O' || lettre == 'U' || lettre == 'Y') {
            return 1;
        }
        else {
            return 2;
        }
    } else {
        return -1;
    }

}