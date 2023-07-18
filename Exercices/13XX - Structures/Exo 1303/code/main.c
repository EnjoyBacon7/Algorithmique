#include <stdio.h>  // printf, scanf, fflush, stdin
#include <stdlib.h> // malloc, free

// On crée une nouvelle structure t_etudiant avec les champs demandés
typedef struct etudiant {
    int numeroEtudiant;     // Numéro de l'étudiant
    int codePostal;         // Code postal de l'étudiant
    int anneeNaissance;     // Année de naissance de l'étudiant
    float notes[5];         // Tableau de 5 notes de l'étudiant
} t_etudiant;

// Fonction chargée de remplir une structure étudiant avec un numéro d'étudiant fourni (pour éviter les doublons)
void remplissage(t_etudiant* etudiant, int numeroEtudiant) {

    // On assigne le numéro d'étudiant fourni à la structure
    etudiant->numeroEtudiant = numeroEtudiant;

    // On demande à l'utilisateur le code postal
    printf("Entrez le code postal de l'étudiant : ");
    scanf("%d", &etudiant->codePostal);
    fflush(stdin);  // Le fflush pour vider le buffer de scanf
    while (etudiant->codePostal < 10000 || etudiant->codePostal > 99999) {  // On blinde la saisie
        printf("Le code postal doit faire 5 chiffres.\n");
        printf("Entrez le code postal de l'étudiant : ");
        scanf("%d", &etudiant->codePostal);
        fflush(stdin);
    }

    // On demande à l'utilisateur l'année de naissance
    printf("Entrez l'année de naissance de l'étudiant : ");
    scanf("%d", &etudiant->anneeNaissance);
    fflush(stdin); // Le fflush pour vider le buffer de scanf
    while (etudiant->anneeNaissance < 1900 || etudiant->anneeNaissance > 2020) {    // On blinde la saisie
        printf("L'année de naissance doit être comprise entre 1900 et 2020.\n");
        printf("Entrez l'année de naissance de l'étudiant : ");
        scanf("%d", &etudiant->anneeNaissance);
        fflush(stdin);
    }

    // On demande à l'utilisateur les 5 notes
    for (int i = 0; i < 5; i++) {
        printf("Entrez la note %d de l'étudiant : ", i + 1);
        scanf("%f", &etudiant->notes[i]);
        fflush(stdin);  // Le fflush pour vider le buffer de scanf
        while (etudiant->notes[i] < 0 || etudiant->notes[i] > 20) { // On blinde la saisie
            printf("La note doit être comprise entre 0 et 20.\n");
            printf("Entrez la note %d de l'étudiant : ", i + 1);
            scanf("%f", &etudiant->notes[i]);
            fflush(stdin);
        }
    }
}

// Fonction chargée de remplir 20 structures étudiant avec la fonction remplissage
void remplissageMultiple(t_etudiant* etudiants[20]) {
    for (int i = 0; i < 20; i++) {
        remplissage(etudiants[i], i + 1);
    }
}

// Fonction d'affichage d'une structure étudiant
void affichage(t_etudiant* etudiant) {
    printf("Numéro de l'étudiant : %d\n", etudiant->numeroEtudiant);
    printf("Code postal de l'étudiant : %d\n", etudiant->codePostal);
    printf("Année de naissance de l'étudiant : %d\n", etudiant->anneeNaissance);
    for (int i = 0; i < 5; i++) {
        printf("Note %d de l'étudiant : %.2f\n", i + 1, etudiant->notes[i]);
    }
}

// Fonction d'affichage de 20 structures étudiant avec la fonction affichage
void affichageMultiple(t_etudiant* etudiants[20]) {
    for (int i = 0; i < 20; i++) {
        affichage(etudiants[i]);
    }
}

// Fonction principale
int main() {
    t_etudiant* etudiants[20];  // On crée un tableau de 20 pointeurs vers des structures étudiant
    for (int i = 0; i < 20; i++) {  // On alloue la mémoire pour chaque structure
        etudiants[i] = malloc(sizeof(t_etudiant));
    }
    // On remplit et affiche les structures
    remplissageMultiple(etudiants);
    // On affiche les structures
    affichageMultiple(etudiants);

    // On libère la mémoire allouée pour chaque structure
    for (int i = 0; i < 20; i++) {
        free(etudiants[i]);
    }

    return 0;
}
