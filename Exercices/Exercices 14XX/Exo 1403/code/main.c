#include <stdio.h>  // printf, scanf, fopen, fscanf, feof

// Fonction principale
int main() {

    // Ouverture du fichier d'entiers en mode "r" (donc lecture: r = read)
    FILE* fp = fopen("entiers.txt", "r");
    if (fp == NULL) {   // Blindage d'erreurs. Un fichier qui ne s'ouvre pas est souvent embêtant à débugger
        printf("Erreur lors de l'ouverture du fichier. Il n'existe peut-être pas ou vous n'avez pas les permissions nécessaires.");
        return 1;
    }

    // Overture des deux fichiers dans lesquels écrire (en mode "w" pour écraser les données si le fichier existe déjà)
    FILE* mult5 = fopen("mult5.txt", "w");
    FILE* mult7 = fopen("mult7.txt", "w");

    int n;
    // Tant que le "curseur" virtuel du fichier n'est pas à la fin du fichier (EOF = End Of File) ...
    while (!feof(fp)) {
        fscanf(fp, "%d", &n);       // ... on lit un entier ...
        n += 10;                    // ... on lui ajoute 10 ...

        if (n % 5 == 0) {           // ... si le nombre est un multiple de 5 ...
            fprintf(mult5, "%d\n", n);  // ... on l'écrit dans le fichier mult5.txt
        }
        if (n % 7 == 0) {           // ... si le nombre est un multiple de 7 ...
            fprintf(mult7, "%d\n", n);  // ... on l'écrit dans le fichier mult7.txt
        }
    }

    // On imprime pour indiquer la fin du programme
    printf("Termine");
   
}