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

// Fonction d'affichage d'une structure étudiant. Ne l'affiche que si le numero etudiant est différent de -1
void affichage(t_etudiant* etudiant) {
    if(etudiant->numeroEtudiant == -1) { // On vérifie que le numéro d'étudiant est différent de -1 (si oui, la structure n'a pas été remplie et on return pour quitter)
        return;
    }
    printf("Numéro de l'étudiant : %d\n", etudiant->numeroEtudiant);
    printf("Code postal de l'étudiant : %d\n", etudiant->codePostal);
    printf("Année de naissance de l'étudiant : %d\n", etudiant->anneeNaissance);
    for (int i = 0; i < 5; i++) {
        printf("Note %d de l'étudiant : %.2f\n", i + 1, etudiant->notes[i]); // On affiche la note de l'étudiant avec 2 chiffres apres la virgule
    }
}

// Fonction d'affichage de toutes les structures étudiant avec la fonction affichage
void affichageMultiple(t_etudiant* etudiants[20]) {
    for (int i = 0; i < 20; i++) {
        affichage(etudiants[i]);
    }
}

// Initialise au démarrage toutes le structures du tableau avec des valeurs par défaut
void initStructures(t_etudiant* etudiants[20]) {
    for (int i = 0; i < 20; i++) {
        etudiants[i] = malloc(sizeof(t_etudiant));
        etudiants[i]->numeroEtudiant = -1;
        etudiants[i]->codePostal = -1;
        etudiants[i]->anneeNaissance = -1;
        for (int j = 0; j < 5; j++) {
            etudiants[i]->notes[j] = -1;
        }
    }
}

// Fonction qui permet de modifier une structure étudiant
void modifierStruct(t_etudiant* etudiants[20]) {

    // On demande à l'utilisateur le numéro de l'étudiant à modifier
    int numeroEtudiant;
    printf("Entrez le numéro de l'étudiant à modifier : ");
    scanf("%d", &numeroEtudiant);
    fflush(stdin);  // Le fflush pour vider le buffer de scanf
    int numeroValide = 0;   // Booléen qui permet d'enregistrer la validité du numéro entré
    int indexEtudiant = 0;  // Stocke l'indice de la structure qui prendra les valeurs du nouvel étudiant
    // Boucle de blindage qui vérifie que le numéro entré est valide
    while(numeroValide == 0) {
        // Comparaison du numero avec ceux dans la liste (et que le numéro soit positif)
        for(int i = 0; i < 20; i++) {
            if (etudiants[i]->numeroEtudiant == numeroEtudiant && numeroEtudiant >= 0) {
                numeroValide = 1;
                indexEtudiant = i;
            }
        }
        // Tant que, après le parcours de la liste, le numéro n'est toujours pas valide, on redemande à l'utilisateur
        if (numeroValide == 0) {
            printf("Le numéro entré n'est pas valide.\n");
            printf("Entrez le numéro de l'étudiant à modifier : ");
            scanf("%d", &numeroEtudiant);
            fflush(stdin);  // Le fflush pour vider le buffer de scanf
        }
    }

    // On demande à l'utilisateur le nouveau code postal
    printf("Entrez le nouveau code postal de l'étudiant : ");
    scanf("%d", &etudiants[indexEtudiant]->codePostal);
    fflush(stdin);  // Le fflush pour vider le buffer de scanf
    while (etudiants[indexEtudiant]->codePostal < 0 || etudiants[indexEtudiant]->codePostal > 99999) {    // On blinde la saisie
        printf("Le code postal doit faire 5 chiffres.\n");
        printf("Entrez le nouveau code postal de l'étudiant : ");
        scanf("%d", &etudiants[indexEtudiant]->codePostal);
        fflush(stdin);
    }
}

// Fonction qui permet d'ajouter une structure étudiant (ou plutot remplir une structure vide)
void ajoutEtudiant(t_etudiant* etudiants[20]) {

    int numeroEtudiant;
    int numeroPris = 1;     // Booléen qui permet de savoir si le numéro entré est déjà pris

    while (numeroPris == 1) {
        numeroPris = 0;     // On met le booléen à 0

        printf("Entrez le numéro de l'étudiant : ");
        scanf("%d", &numeroEtudiant);
        fflush(stdin);  // Le fflush pour vider le buffer de scanf

        for(int i = 0; i < 20; i++) {   // Si le numéro entré est déjà pris, on met le booléen à 1 pour redemander un numéro
            if (etudiants[i]->numeroEtudiant == numeroEtudiant) {
                printf("Un étudiant existe déjà avec ce numéro.\n");
                numeroPris = 1;
            }
        }
    }

    // On parcourt le tableau pour trouver la première structure vide
    int indexEtudiant = 0;
    while (etudiants[indexEtudiant]->numeroEtudiant != -1) {
        indexEtudiant++;
    }
    // On remplit la structure vide
    remplissage(etudiants[indexEtudiant], numeroEtudiant);
}

// Fonction de menu à l'écran
void menu(t_etudiant* etudiants[20]) {

    printf("\n1. Ajouter un étudiant\n");
    printf("2. Afficher les étudiant\n");
    printf("3. Modifier un étudiant\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
    int choix;
    scanf("%d", &choix);   // Obtention du choix de l'utilisateur
    printf("\n");

    // Switch case. En fonction du choix, on appelle la fonction correspondante
    switch (choix)
    {
    case 1:                             // Dans le cas où l'utilisateur entre 1
        ajoutEtudiant(etudiants);           // La fonction ajoutEtudiant est appelée
        break;                              // On sort du switch case
    case 2:                             // Dans le cas où l'utilisateur entre 2
        affichageMultiple(etudiants);       // La fonction affichageMultiple est appelée
        break;                              // On sort du switch case
    case 3:                             // Dans le cas où l'utilisateur entre 3
        modifierStruct(etudiants);          // La fonction modifierStruct est appelée
        break;                              // On sort du switch case
    case 4:                             // Dans le cas où l'utilisateur entre 4
        for (int i = 0; i < 20; i++) {      // On parcours le tableau de structures
            free(etudiants[i]);             // On libère la mémoire allouée pour chaque structure
        }       
        exit(0);                            // On quitte le programme
    default:                            // Dans le cas où l'utilisateur entre autre chose
        printf("Choix invalide.\n");        // On affiche un message d'erreur
        break;                              // On sort du switch case
    }
}

// Fonction principale
int main() {
    t_etudiant* etudiants[20];  // On crée un tableau de 20 pointeurs vers des structures étudiant
    initStructures(etudiants);  // On initialise les pointeurs à NULL

    // Boucle infinie qui permet d'afficher le menu à l'écran tant que l'utilisateur ne quitte pas le programme
    while (1) {
        menu(etudiants);
    }

    return 0;
}
