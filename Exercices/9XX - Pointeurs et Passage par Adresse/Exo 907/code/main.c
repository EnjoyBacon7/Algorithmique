// Exercice débile.
// l'énoncé est difficilement compréhensible en détail
// Les accompagnateurs n'ont pas été faits par manque de clarté. A revisiter
// L'histoire de senior est aussi difficilement faisable sans plus d'infos.
// Manque de blindage. Exercice baclé.

#include <stdio.h>

int calculPrix(int age, float* prix);
int calculPrixGroupe();

int main() {

    float prix = calculPrixGroupe();

    printf("La somme due est de %.2f\n", prix);

    return 0;
}

int calculPrix(int age, float* prix) {

    int prixBase = 50;
    float reduction;

    if (age < 5 && age >= 0) {
        reduction = 100;
    }
    else if (age >= 5 && age <= 17) {
        reduction = 75;
    }
    else if (age >= 18 && age <= 29) {
        reduction = 50;
    }
    else if (age >= 30 && age <= 60) {
        reduction = 0;
    }
    else if (age > 60) {
        return 1;
    }

    *prix = prixBase - prixBase * (reduction/100);
    return 0;

}

int calculPrixGroupe() {

    int trancheAge, nombre;
    float prix = 0, prixFinal = 0;
    int senior;

    printf("Entrez la tranche d'age: ");
    scanf("%d", &trancheAge);

    printf("Entrer le nombre d'entrants: ");
    scanf("%d", &nombre);

    senior = calculPrix(trancheAge, &prix);
    if (!senior) {
        prixFinal = prix * nombre;
    }
    
    return prixFinal;
}