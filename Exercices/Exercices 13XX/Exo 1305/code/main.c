#include <stdio.h>

// Structure de date prenant en compte les jours, mois et années
typedef struct date {
    int jour;
    int mois;
    int annee;
} t_date;

// Structure d'article avec les champs de l'énoncé
typedef struct article {
    int numDesignation;         // Numéro de désignation
    int numCategorie;           // Numéro de catégorie
    t_date datePeremption;      // Date de péremption
    int stock;                  // Stock
    float prix;                 // Prix
} t_article;

// Fonction qui crée et remplit un article. L'exercice ne précise pas qu'un numéro de désignation doit être
// unique, et ne précise pas le besoin de blindage. Donc on ne fait pas de vérifications.
// Pour le blindage, se réferrer aux exercices précédents.
t_article remplissageNouveau() {
    t_article article;

    // Demande à l'utilisateur de remplir les champs de l'article
    printf("Numéro de désignation : ");
    scanf("%d", &article.numDesignation);
    fflush(stdin);
    
    printf("Numéro de catégorie : ");
    scanf("%d", &article.numCategorie);
    fflush(stdin);

    // Puisque la date est une structure dans une structure, on accède à ses champs avec un point
    printf("Date de péremption (jj/mm/aaaa) : ");
    // On peut faire un scanf avec plusieurs %d pour obtenir plusieurs valeurs à la fois
    scanf("%d/%d/%d", &article.datePeremption.jour, &article.datePeremption.mois, &article.datePeremption.annee);
    fflush(stdin);

    printf("Stock : ");
    scanf("%d", &article.stock);
    fflush(stdin);

    printf("Prix : ");
    scanf("%f", &article.prix);
    fflush(stdin);

    // On retourne le nouvel article à la fonction appelante
    return article;
}

// Fonction qui remplit tous les articles du tableau avec la fonction ci-dessus
void remplissageTous(t_article tableau[20]) {
    for (int i = 0; i < 20; i++) {
        tableau[i] = remplissageNouveau();
    }
}

// Fonction d'affichage d'un article 
void afficherArticle(t_article article) {
    printf("Numéro de désignation : %d\n", article.numDesignation);
    printf("Numéro de catégorie : %d\n", article.numCategorie);
    printf("Date de péremption : %d/%d/%d\n", article.datePeremption.jour, article.datePeremption.mois, article.datePeremption.annee);
    printf("Stock : %d\n", article.stock);
    printf("Prix : %.2f\n\n", article.prix);
}

// Fonction d'affichage de tous les articles
void afficherTous(t_article tableau[20]) {
    for (int i = 0; i < 20; i++) {
        afficherArticle(tableau[i]);
    }
}

// Fonction qui affiche tous les articles d'une catégorie donnée
void afficherCategorie(t_article tableau[20], int categorie) {
    for (int i = 0; i < 20; i++) {
        if (tableau[i].numCategorie == categorie) {
            afficherArticle(tableau[i]);
        }
    }
}

// Fonction qui compare années, mois, et jours pour savoir si une date est antérieure à une autre et afficher les articles concernés
void afficherPerimes(t_article tableau[20], t_date dateLimite) {
    for (int i = 0; i < 20; i++) {
        if (tableau[i].datePeremption.annee < dateLimite.annee) {
            afficherArticle(tableau[i]);
        } else if (tableau[i].datePeremption.annee == dateLimite.annee) {
            if (tableau[i].datePeremption.mois < dateLimite.mois) {
                afficherArticle(tableau[i]);
            } else if (tableau[i].datePeremption.mois == dateLimite.mois) {
                if (tableau[i].datePeremption.jour < dateLimite.jour) {
                    afficherArticle(tableau[i]);
                }
            }
        }
    }
}

int main() {

    // On crée le tableau d'articles
    t_article tableau[20];
    // On le remplit
    remplissageTous(tableau);
    // On l'affiche dans son entièreté
    afficherTous(tableau);
    printf("\n\n");

    // On demande une catégorie à afficher
    printf("Choisissez une catégorie : ");
    int categorie;
    scanf("%d", &categorie);
    fflush(stdin);
    // On affiche les articles concernés
    afficherCategorie(tableau, categorie);
    printf("\n\n");

    // On demande une date limite
    printf("Choisissez une date limite (jj/mm/aaaa) : ");
    t_date dateLimite;
    scanf("%d/%d/%d", &dateLimite.jour, &dateLimite.mois, &dateLimite.annee);
    fflush(stdin);
    // On affiche les articles périmés
    afficherPerimes(tableau, dateLimite);
    printf("\n\n");

    return 0;


}