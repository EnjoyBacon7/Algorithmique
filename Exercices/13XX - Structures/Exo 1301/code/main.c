#include <stdio.h>  // Bibliothèque pour printf & scanf

// Voici le sujet de cette série d'exercices. La structure. Les structures seront vos meilleures amies.
// Il faut savoir les maitriser
// Une structure est un ensemble de variables de types différents. Ce qui est intéressant, c'est qu'on peut
// créer des structures comme on veut. On peut donc créer une structure qui contient un ou plusieurs entiers, caractères,
// flottants, tableaux, d'autres structures, etc...
// On peut aussi en créer autant qu'on veut comme on ferait avec les autres types de variables.

typedef struct film { // On crée un nouveau "schéma" de structure qui s'appelle film. A l'intérieur, on a...
    int numero;           // ... un numero de film
    int annee;            // ... une année de sortie
    char realisateur;     // ... l'initiale du réalisateur
    int duree;            // ... la durée du film
    char vu;              // ... si on a vu le film ou pas
    int note;             // ... la note qu'on donne au film
} t_film; // On donne à cette nouvelle structure un surnom: "t_film" (le t_ permet au lecteur de savoir que c'est une structure, il n'est pas necessaire)

// Note que dans la déclaration, le "typedef" et "t_film" ne sont pas obligatoires. On peut très bien faire:

// struct film {
//     int numero;
//     int annee;
//     char realisateur;
//     int duree;
//     char vu;
//     int note;
// };

// MAIS! Dans ce cas, il faudra toujours mettre "struct film" pour déclarer une instance de cette structure, plutôt que "t_film".

// Initialisation d'une structure t_film
t_film initFilm() {

    // On déclare une nouvelle instance comme pour un int lambda
    t_film film;

    // Pour chaque valeur, on demande à l'utilisateur de la saisir
    printf("Entrez le numero du film : ");
    // On attend sa réponse. Pour accéder aux variables de la structure, on utilise un ".": "film.numero = 5" par exemple
    scanf("%d", &film.numero);
    // On vide le buffer d'entrée (voir l.120)
    fflush(stdin);
    // On vérifie que la valeur entrée est correcte et on refait les trois dernières lignes tant qu'elle ne l'est pas
    while(film.numero <= 0) {
        printf("Numero non valide, veuillez en entrer un correct : ");
        scanf("%d", &film.numero);
        fflush(stdin);
    }

    printf("Entrez l'année du film : ");
    scanf("%d", &film.annee);
    fflush(stdin);
    while(film.annee <= 1930 || film.annee >= 2022) { // On vérifie que l'année est bien entre 1930 et 2022 (puisque c'est demandé dans l'énoncé)
        printf("Valeur impossible. Veuillez retenter la saisie : ");
        scanf("%d", &film.annee);
        fflush(stdin);
    }

    // Pas besoin de blindage pour le réalisateur, on ne peut pas se tromper
    printf("Entrez l'initiale du réalisateur : ");
    scanf("%c", &film.realisateur);
    fflush(stdin);
    
    printf("Entrez la durée du film (en minutes): ");
    scanf("%d", &film.duree);
    fflush(stdin);
    while(film.duree < 20 || film.duree > 300) {
        printf("Valeur impossible. Veuillez retenter la saisie : ");
        scanf("%d", &film.duree);
        fflush(stdin);
    }

    printf("Avez vous déjà vu le film ? (O/N) : ");
    scanf("%c", &film.vu);
    fflush(stdin);
    while(film.vu != 'O' && film.vu != 'N') {
        printf("Valeur impossible. Veuillez retenter la saisie (O/N): ");
        scanf("%c", &film.vu);
        fflush(stdin);
    }

    // On ne peut noter le film que si on l'a vu
    if(film.vu == 'O') {
        printf("Entrez la note du film (entre 0 et 10) : ");
        scanf("%d", &film.note);
        fflush(stdin);
        while(film.note < 0 || film.note > 10) {
            printf("Valeur impossible. Veuillez retenter la saisie (entre 0 et 10): ");
            scanf("%d", &film.note);
            fflush(stdin);
        }
    } else {
        film.note = -1; // On met la note à -1 quand on ne l'a pas vu
    }

    // Une fois la structure remplie, on la rend au sous-programme appelant
    return film;

}

// Fonction d'affichage d'une structure
void afficherFilm(t_film film) {
    printf("Numero : %d\n", film.numero);
    printf("Année : %d\n", film.annee);
    printf("Réalisateur : %c\n", film.realisateur);
    printf("Durée : %d\n", film.duree);
    printf("Vu : %c\n", film.vu);
    printf("Note : %d\n", film.note);
}

// main() principal
int main() {
  
    // On déclare une nouvelle instance de la structure t_film et on l'initialise avec la fonction initFilm()
    t_film film = initFilm();

    printf("\n\n");
    // On affiche les variables de la structure  t_film avec la fonction afficherFilm()
    afficherFilm(film);

    return 0;
}

// Pour le "fflush(stdin)": Toutes les entrées clavier sont enregistrées dans une liste d'attente. Quand on fait un scanf,
// on va chercher la première valeur de cette liste d'attente. (Ca veut dire que les touches sur lesquelles on appuie entre les scanf
// sont vus par le scanf suivant). Le problème est le suivant:
// Si on fait un scanf("%d", &a) et qu'on entre "5" puis qu'on appuie sur "Entrée", deux choses sont mises dans la liste d'attente:
// "5" et "Entrée". Donc ayant fait "Entrée" le scanf va bien voir le 5 et le retirer de la file. Cependant, il y a toujours un "Entrée"
// dans la liste d'attente. Donc si on fait un scanf("%c", &b) juste après, il va voir l'entrée "Entrée" et va la prendre comme valeur
// (en la traitant comme un int). Pour éviter ca, on fait un "fflush(stdin)" qui va effacer la file d'attente pour pas que le "Entrée"
// soit pris en compte.