#include <stdio.h>  // printf, scanf, fopen, fscanf, feof

// Fonction principale
int main() {

    // Ouverture du fichier en mode "r" (donc lecture: r = read)
    FILE* fp = fopen("entiers.txt", "r");
    if (fp == NULL) {   // Blindage d'erreurs. Un fichier qui ne s'ouvre pas est souvent embêtant à débugger
        printf("Erreur lors de l'ouverture du fichier. Il n'existe peut-être pas ou vous n'avez pas les permissions nécessaires.");
        return 1;
    }

    int n;
    // Tant que le "curseur" virtuel du fichier n'est pas à la fin du fichier (EOF = End Of File) ...
    while (!feof(fp)) {
        fscanf(fp, "%d", &n);       // ... on lit un entier ...
        printf("%d\n", n);          // ... et on l'affiche
    }
   
}