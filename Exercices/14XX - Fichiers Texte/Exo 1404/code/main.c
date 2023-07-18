#include <stdio.h>  // printf, scanf, 
#include <stdlib.h> // malloc, free, ...
#include <string.h> // strcpy, strlen, ...

// Fonction principale
int main() {

    // Déclaration du tableau de chaines de caractères. L'étoile indique que c'est un tableau de pointeurs sur char.
    // L'utilisation de pointeurs ici se justifie par le fait que la taille des chaines de caractères est variable.
    char* chaines[10];
    // Déclaration d'un buffer qui stockera les chaines de caractères entrées par l'utilisateur.
    // La taille du buffer est arbitraire, mais doit être suffisamment grande pour contenir les chaines de caractères entrées.
    char buffer[100];

    // Pour chaque chaine de caractères à entrer
    for (int i = 0; i < 10; ++i) {
        printf("Entrez une chaine de caractères : ");       // Demande
        scanf("%s", buffer);                                // Lecture
        fflush(stdin);                                      // Vidage du buffer
        chaines[i] = malloc(sizeof(char) * strlen(buffer)); // Allocation de la mémoire nécessaire pour stocker la chaine de caractères avec le buffer
        strcpy(chaines[i], buffer);                         // Copie de la chaine de caractères du buffer vers la chaine de caractères du tableau
    }

    // Impression des chaines de caractères dans un fichier
    FILE* fp = fopen("stockage1.txt", "w");
    if (fp == NULL) {       // Blindage
        printf("Erreur d'ouverture de fichier.");
        exit(1);
    }
    // Pour chaque chaine dans la liste
    for (int i = 0; i < 10; ++i) {
        fprintf(fp, "%s\n", chaines[i]);    // On l'ajoute au fichier
    }

    // Cloture du programme. Libération du fichier et de la mémoire allouée
    fclose(fp);
    for (int i = 0; i < 10; ++i) {
        free(chaines[i]);
    }
}