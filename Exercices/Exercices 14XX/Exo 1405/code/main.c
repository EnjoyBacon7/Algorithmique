#include <stdio.h>      // printf, scanf, ...
#include <stdlib.h>     // malloc, free, ...

// Structure d'un film
typedef struct film {
    int identifiant;        // Identifiant unique du film
    char* titre;            // Titre du film
    char* realisateur;      // Nom du realisateur
    int annee;              // Annee de sortie du film
    char* genre;            // Genre du film
} t_film;
// L'énoncé ne précise pas les types des champs, j'ai donc choisi les types les plus appropriés

// Fonction de sauvegarde des structures dans un fichier. Ce fichier peut ne pas exister. Elle le crée dans ce cas.
// t_film** films : tableau de pointeurs donc 2 étoiles
// int* films est un pointeur pour que la fonction appelante puisse récupérer le nombre de films modifié (dans sauvegarde. Ici il n'est pas modifié)
void sauvegarde(t_film** films, int* nbFilms, char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "w");         // Ouverture du fichier en écriture (création si il n'existe pas)
    if (fichier != NULL) {                    // Si l'ouverture s'est bien passée
        fprintf(fichier, "%d\n", *nbFilms);     // Ecriture du nombre de films
        for (int i = 0; i < *nbFilms; i++) {        // Pour chaque film
            fprintf(fichier, "%d\n", films[i]->identifiant);        // Ecriture de chaque champ
            fprintf(fichier, "%s\n", films[i]->titre);              // "->" car les structures sont des pointeurs
            fprintf(fichier, "%s\n", films[i]->realisateur);
            fprintf(fichier, "%d\n", films[i]->annee);
            fprintf(fichier, "%s\n", films[i]->genre);
        }
        fclose(fichier);    // Fermeture du fichier
    } else {
        printf("Erreur lors de l'ouverture du fichier (warning)");  // Affichage d'un message d'erreur si l'ouverture a échoué
    }
}

// Fonction de chargement qui lit un fichier (dont le nom est entré en parametre) et remplit un tableau de pointeurs de structures
void chargement(t_film*** films, int* nbFilms, char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");     // Ouverture du fichier en lecture (pas de modification)
    if (fichier != NULL) {            // Si l'ouverture s'est bien passée
        fscanf(fichier, "%d\n", nbFilms);       // Lecture du nombre de films (la premiere ligne)
        *films = (t_film**)calloc(*nbFilms, sizeof(t_film*));   // Allocation dynamique du tableau de pointeurs de structures
        // ^ Explication ^ : Cette ligne alloue à l'adresse de films un tableau de pointeurs de structures de taille nbFilms
        // C'est super important de mettre sizeof(t_film*) et pas sizeof(t_film) car on alloue des pointeurs et pas des structures
        // calloc(), contrairement à malloc(), intialise les valeurs des octets alloués à 0

        for (int i = 0; i < *nbFilms; i++) {
            (*films)[i] = (t_film*)malloc(sizeof(t_film));
            // ^ Explication ^ : Plutôt, on a alloué le tableau de pointeurs sur les structures, mais pas les structures elles-mêmes
            // On alloue donc chaque structure une par une

            // Les champs qui sont du texte, doivent être alloués (char* : tableau de char)
            (*films)[i]->titre = (char*)malloc(sizeof(char) * 100);
            (*films)[i]->realisateur = (char*)malloc(sizeof(char) * 100);
            (*films)[i]->genre = (char*)malloc(sizeof(char) * 100);

            // Lecture de chaque champ
            fscanf(fichier, "%d\n", &((*films)[i]->identifiant));
            fscanf(fichier, " %[^\n]", (*films)[i]->titre);
            fscanf(fichier, " %[^\n]", (*films)[i]->realisateur);
            fscanf(fichier, "%d\n", &((*films)[i]->annee));
            fscanf(fichier, " %[^\n]", (*films)[i]->genre);

            // Le %[^\n] permet de lire une ligne entière (jusqu'au retour à la ligne) et de la stocker dans la variable
            // Sinon le fscanf va considérer que le champ s'arrête au premier espace. En gros, au lieu de stocker "James Cameron"
            // Il va stocker "James" dans un premier fscanf et "Cameron" dans un second fscanf, ce qui casse tout

        }
        fclose(fichier);    // Fermeture du fichier
    } else {
        printf("Erreur lors de l'ouverture du fichier (warning)");      // Affichage d'un message d'erreur si l'ouverture a échoué
    }
}


// Fonction d'affichage des films
void affichage(t_film** films, int nbFilms) {
    for (int i = 0; i < nbFilms; i++) {     // Parcours et affichage de chaque élément
        printf("%d\n", films[i]->identifiant);
        printf("%s\n", films[i]->titre);
        printf("%s\n", films[i]->realisateur);
        printf("%d\n", films[i]->annee);
        printf("%s\n", films[i]->genre);
        printf("\n");
    }
}

// Fonction principale
int main() {

    // Déclaration des variables
    t_film** films;
    int* nbFilms = (int*)malloc(sizeof(int));

    // Etape 1: Chargement des données (pas de blindage, on suppose que le fichier existe et est correctement formaté. ex: "fichier.txt")
    printf("A partir de quel fichier voulez-vous charger les films ? ");
    char nomFichier[100];
    scanf("%s", nomFichier);
    fflush(stdin);
    chargement(&films, nbFilms, nomFichier);
    affichage(films, *nbFilms);

    // Etape 2: Sauvegarde des données (pas de blindage, le fichier est créé s'il n'existe pas, sinon il est écrasé)
    printf("Dans quel fichier voulez-vous sauvegarder les films ? ");
    scanf("%s", nomFichier);
    fflush(stdin);
    sauvegarde(films, nbFilms, nomFichier);

    // Print pour se sentir bien et informer l'utilisateur
    printf("Sauvegarde effectuee !\n");

    // Libération de la mémoire
    for (int i = 0; i < *nbFilms; i++) {
        free(films[i]->titre);
        free(films[i]->realisateur);
        free(films[i]->genre);
        free(films[i]);
    }
    free(films);
    free(nbFilms);

    return 0;
}
