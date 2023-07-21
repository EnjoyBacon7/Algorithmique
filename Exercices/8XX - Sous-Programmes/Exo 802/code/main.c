#include <stdio.h>

int menu();
int ajouter1(int valeur);
int multiplierPar2(int valeur);
int soustraire4(int valeur);
int sommeNpremiersEntiers(int valeur);

int main()
{

    int valeur;
    printf("Entrez un entier : ");
    scanf("%d", &valeur);

    int choix = menu();

    int resultat;
    switch (choix)
    {
    case 1:
        resultat = ajouter1(valeur);
        break;
    case 2:
        resultat = multiplierPar2(valeur);
        break;
    case 3:
        resultat = soustraire4(valeur);
        break;
    case 4:
        resultat = sommeNpremiersEntiers(valeur);
        break;
    case 5:
        return 0;
    default:
        printf("Choix invalide\n");
        return 0;
    }
}

int menu()
{

    printf("\nQue faire de cet entier :\n");
    printf("1. Ajouter 1\n");
    printf("2. Multiplier par 2\n");
    printf("3. Soustraire 4\n");
    printf("4. Somme de n premiers entiers");
    printf("5. Quitter\n");
    printf("Votre choix : ");
    int choix;
    scanf("%d", &choix);

    return choix;
}

int ajouter1(int valeur)
{
    return valeur + 1;
}

int multiplierPar2(int valeur)
{
    return valeur * 2;
}

int soustraire4(int valeur)
{
    return valeur - 4;
}

int sommeNpremiersEntiers(int valeur)
{
    int somme = 0;
    for (int i = 0; i <= valeur; i++)
    {
        somme += i;
    }
    return somme;
}
