#include <stdio.h>

int main()
{

    int Nlv, Nf, Nm, Np;

    printf("Entrez les 4 notes entre 0 et 20:\n");
    printf("Nlv : ");
    scanf("%d", &Nlv);
    printf("Nf : ");
    scanf("%d", &Nf);
    printf("Nm : ");
    scanf("%d", &Nm);
    printf("Np : ");
    scanf("%d", &Np);

    if(Nlv < 0 || Nlv > 20 || Nf < 0 || Nf > 20 || Nm < 0 || Nm > 20 || Np < 0 || Np > 20)
    {
        printf("Une des notes est incorrecte\n");
        return 1;
    }

    float moyenneG = (float)(Nlv + Nf + Nm + Np) / 4;
    printf("Moyenne generale : %.2f\n", moyenneG);

    if (Nm > moyenneG)
    {
        printf("La note de mathematique est superieur à la moyenne generale\n");
    }
    else
    {
        printf("La note de mathematique est inferieur à la moyenne generale\n");
    }

    if (Nf > moyenneG)
    {
        printf("La note de francais est superieur à la moyenne generale\n");
    }
    else
    {
        printf("La note de francais est inferieur à la moyenne generale\n");
    }

    if (Nlv > 10 || Np > 10 || Nf > 10 || Nm > 10)
    {
        printf("L'eleve a une note superieur à 10\n");
    }
    else
    {
        printf("L'eleve n'a pas de note superieur à 10\n");
    }

    if (Nlv > 10 && Np > 10 && Nf > 10 && Nm > 10)
    {
        printf("L'eleve a toutes ses notes superieur à 10\n");
    }
    else
    {
        printf("L'eleve n'a pas toutes ses notes superieur à 10\n");
    }

    float moyenneLit = (float)(Nlv + Nf) / 2;

    if (moyenneLit > 10)
    {
        printf("L'eleve a la moyenne en litteraire\n");
    }
    else
    {
        printf("L'eleve n'a pas la moyenne en litteraire\n");
    }

    float moyenneScient = (float)(Nm + Np) / 2;

    if (moyenneScient > 10)
    {
        printf("L'eleve a la moyenne en scientifique\n");
    }
    else
    {
        printf("L'eleve n'a pas la moyenne en scientifique\n");
    }

    if (moyenneG >= 10 && (moyenneLit >= 10 || moyenneScient >= 10))
    {
        printf("L'eleve a au moins un module superieur a 10 et la moyenne generale superieur a 10\n");
    }
    else
    {
        printf("L'eleve n'a pas au moins un module superieur a 10 et la moyenne generale superieur a 10\n");
    }

        
    return 0;
}