#include <stdio.h>    // printf, scanf, fflush, stdin
#include <stdlib.h>   // srand, rand
#include <time.h>     // time

int main() {

    // On initialise le générateur de nombres aléatoires
    // srand fonctionne comme une "seed" minecraft. Il définit le point de départ de la génération de nombres aléatoires.
    // En utilisant le temps qui est constemment en train de changer, on est sûr que la seed sera différente à chaque fois.
    srand(time(NULL));

    // On récupère les 15 entiers et on les stocke dans un tableau
    int entiersSaisis[15];
    for (int i = 0; i < 15; i++) {
        printf("Entrez l'entier n°%d : ", i + 1);
        scanf("%d", &entiersSaisis[i]);
        fflush(stdin);  // On vide le buffer pour éviter les problèmes
    }

    // On génère 20 entiers aléatoires et on les stocke dans un tableau
    int entiersAleatoires[20];
    for (int i = 0; i < 20; i++) {
        entiersAleatoires[i] = rand(); // Il n'est pas spécifié de borne maximale, donc on utilise rand() qui génère un entier entre 0 et RAND_MAX (soit 32767)
    }

    // On ouvre le fichier en mode "w" pour le creer si il n'éxiste pas (et l'écraser si oui)
    FILE* fp = fopen("entiers.txt", "w");
    if (fp == NULL) {   // Blindage d'erreurs. Au cas où il manque des permissions ou si le fichier ne peut pas être ouvert
        printf("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // On imprime les entiers saisis
    for (int i = 0; i < 15; i++) {
        fprintf(fp, "%d\n", entiersSaisis[i]);      // fprintf, ou "file printf", fonctionne comme printf mais écrit dans un fichier
    }                                               // On lui fournit le fichier (fp), ce qu'il faut écrire ("%d\n") et si besoin le format (entiersSaisis[i])
    // Puis les entiers générés aléatoirement
    for (int i = 0; i < 20; i++) {
        fprintf(fp, "%d\n", entiersAleatoires[i]);
    }

    // Et on n'oublie pas de fermer le fichier dans la mémoire
    fclose(fp);
}