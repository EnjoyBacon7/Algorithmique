#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/// Hello los zigotos, voici le sujet du tp de je sais plus quel td le 14/03/22 en algo. Je me suis posé le challenge de le faire sous les 2h imparties,
/// et j'ai plutot bien réussi, mis à part une petite erreur de m*rde qui refusait de s'en aller (l.244) et qui m'a bouffé 20 minutes. Le
/// tp est donc largement faisable (surtout en groupe, du coup), mais il faut vraiment bien comprendre le cours, et etre à l'aise avec l'algo en général.
/// Venant du majorant du partiel, (oui, je flex :) j'espere que mes mots ont du poids. Si une matière doit etre négligée, choisis l'elec.

/// Pour la moindre erreur ou bug:
/// Discord: EnjoyBacon7#1390

// Des "-" séparent les exos et les parties
// Certaines fonctions développées dans une autre partie sont réutilisées dans les parties ultérieures (attention)
// Chaque partie/exercice possède un main numéroté. le premier exercice peut etre executé en appelant "main1();" dans le main tout en bas du code
//      (De meme pour les autres exos: "main2();" pour la deuxieme partie, etc...)


///------------------------------------------------------------------------------------------------
/// EXERCICE 1
///------------------------------------------------------------------------------------------------

// Prototypes de mes fonctions (leur définition, en quelque sorte) ils sont placés dans le fichier ".h" quand on fait du multifichier
int main1();
int modifier(int tablEntiers[], int tablTaille, int v, int compte);
void charger(char* fpName, int tablCharge[10]);

/// Ici la fonction à appeler dans le "main()" pour voir l'exercice 1. Je vais pas macher tout le travail non plus
int main1() {

    // On crée un tableau de 10 entiers tout bete et on appelle la fonction "charger()" qui remplit le tableau avec les valeurs
    // dans le fichier dont le nom est le premier parametre (je sais que t'as rien compris a cette phrase)
    int tablCharge[10];
    charger("fichier",tablCharge);

    // Impression rapide de mon tableau (pour vérifier que la fonction précédente aie bien fonctionnée
    for(int i = 0; i < 10; i++) {
        printf("%d\n", tablCharge[i]); // un printf()... fun fact: le "f" veut dire "format".
    }

    // Je demande la valeur de v à remplacer et je la stocke
    printf("Entrez la valeur a mettre a zero: ");
    int valeur;
    scanf("%d", &valeur);

    // Ici, compte représente le nombre de valeurs qui ont été remplacées par 0 dans la fonction "modifier"
    // Puisqu'il s'agit d'une fonction récursive, je dois lui donner un moyen de compter le nombre d'itérations
    // (d'ou le 0 en quatrieme parametre)
    int compte = modifier(tablCharge, 10, valeur, 0);

    // Encore un affichage de mon tableau, afin de voir les valeurs modifiées et j'indique le nombre de cases modifiées
    for(int i = 0; i < 10; i++) {
        printf("%d\n", tablCharge[i]); // D'ailleurs lorsqu'un "format" est présent, on va retrouver des parametres comme : ("%d", variable)
    }
    printf("\nLe nombre de cases modifiees est %d", compte);
    return 0;
}

// Aaaah une belle fonction. Pour ceux qui ne l'auraient pas compris, l'avantage de la récursivité est sa compacité. On peut faire
// un code bien plus compact pour une meme opération.
int modifier(int* tablEntiers, int tablTaille, int v, int compte) {

    // Ma condition de terminaison de récursivité (lorsque la variable "tablTaille" atteint 0
    if(tablTaille == 0) {
        return compte;
    }

    // On remplace la valeur par 0 pour chaque itération de la fonction + incrémentation du compteur
    if (tablEntiers[tablTaille] == v) {
        tablEntiers[tablTaille] = 0;
        compte++;
    }

    // On relance la fonction avec les memes parametres sauf au niveau de "tabTaille" qui baisse de un à chaque répétition
    return modifier(tablEntiers, tablTaille - 1, v, compte);
}

// La fonction "charger()" a pour but de lire un fichier et de stocker les entiers dans le tableau.
// Ca date un peu, mais c'est quelque chose de base qui est toujours bon a savoir faire. (La preuve: c'est demandé ici)
void charger(char* fpName, int tablCharge[10]) {    // Note le "char* fpName", ca me permet de gérer un tableau de taille variable


    char fpPath[sizeof(fpName) + 4];    // On crée une chaine de caracteres de la taille de fpName + 4 (pour concaténer ".txt")
    strcpy(fpPath, fpName);             // On copie "fpName" dans "fpPath"
    strcat(fpPath, ".txt");             // On lui rajoute le ".txt" indiqué plus haut
    FILE* fp = fopen(fpPath, "r+");     // On peut enfin ouvrir le fichier en lecture/ecriture

    int buf;                        // Ce buffer permet de stocker temporairement chaque entier lu

    // Cette boucle while tourne jusqu'à ce que le charactere "EOF" (end of file) soit lu et stocke simplement les valeurs lues
    // dans le tableau "tablCharge"
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d", &buf);
        tablCharge[i] = buf;
        i++;
    }

    // On n'oublie pas, bien sur, de fermer le fichier (pour faire plaisir au correcteur, puisque celui-ci est libéré à la fin du ssprgm)
    fclose(fp);
}

// Enfin la fin!! Cet exo plutot simple devrait etre complété en une demi-heure par une personne. L'exercice 2 est 3-4 fois plus long.
// Donc faut vite aller aider ton binôme, flemmard.e (#MmeRerzki)

///------------------------------------------------------------------------------------------------
/// EXERCICE 2      -- Partie 1 --
///------------------------------------------------------------------------------------------------

// Yeessaïe, c'est tipar pour l'exo 2!

// Quoi?! Une structure sauvage apparaït? ouf... c'est pas un tableau dynamique
// (Si t'as pas capté la vanne, va lire ton cours... t'as v'la du retard :/ )
typedef struct carte {

    int suit;       // Du coup, simple structure avec un alias ("t_carteS") avec deux entiers "suits" et "value"
    int value;      // pour faire un peu d'anglais. suits = suite/couleur. value = valeur/chiffre/face

}t_carteS;

// Encore des prototypes. Ils sont mignons non?
void creerJeu(t_carteS tabl[52]);
void afficherCarte(t_carteS* carte);
void afficherJeu(t_carteS cartes[52]);
void melangerJeu(t_carteS tabl[52]);
void main2(); /// Le main à appeler pour tester cette partie de l'exercice 2


// Premiere fonction qui va simplement remplir les structures d'un tableau de structures avec
// des entiers de 1 à 13 pour les valeurs et 1 à 4 pour les couleurs
// L'absence de "*" dans le parametre s'explique par le fait qu'il s'agisse d'un tableau, qui, par
// définition eeeeeeeeest?  ...un pointeur!! bravo!
void creerJeu(t_carteS tabl[52]) {

    // Boucle for qui se répete 52 fois (une fois par carte pour les moins futés d'entre vous)
    for(int i = 0; i < 52; i++) {
        // La méthode de calcul est simple: je récupère la partie entière de la division par 13
        // pour avoir des valeurs de 0-3, d'ou le "+ 1" pour avoir les 4 couleurs
        tabl[i].suit = (i/13) + 1;
        // Ici, pour la valeur, je récupère le reste de la division par 13, ce qui donne une valeur
        // entre 0-12, d'ou le "+ 1"
        tabl[i].value = (i%13)+1;
    }
}

// Une simple fonction d'affichage qui affiche la couleur et la valeur d'une carte
void afficherCarte(t_carteS* carte) {

    // Le voici!!! Le misérable switch case! J'ai déja exprimé mon aversion à cette chose, mais
    // il s'agit d'une alternative plus intéréssante aux séries de if, else if.
    switch (carte->suit) {              // Ici on définit la variable à considérer
        case 1:                             // Et on considère les etats de la variable. Ici, si elle vaut 1 on entre dans le "case"
            printf("Trefle  : ");               // Donc si la couleur vaut 1, c'est un Trèfle
            break; // Ne pas oublier de sortir du switch
        case 2:                             // Si la variable vaut 2...
            printf("Coeur   : ");               // ... c'est un Coeur
            break;
        case 3:                             // Si la variable vaut 3...
            printf("Carreau : ");               // ... c'est un Carreau
            break;
        case 4:                             // Si la variable vaut 4...
            printf("Pique   : ");               // ... c'est un Pique
            break;
    }

    // Un deuxième switch case pour considérer la valeur de la carte (je te laisse comprendre)
    switch (carte->value) {
        case 11:
            printf("Valet\n");
            break;
        case 12:
            printf("Dame\n");
            break;
        case 13:
            printf("Roi\n");
            break;
        default:                // Sauf ici. "default:" est la condition générale. c'est une condition toujours vraie
                                // elle permet de traiter de la meme maniere toutes les cartes sans faces
            printf("%d\n", carte->value);
            break;
    }
}

// Fonction qui utilise la fonction précédente pour afficher toutes les cartes
void afficherJeu(t_carteS cartes[52]) {

    // Simple boucle for qui affiche toutes les cartes une a une
    for(int i = 0; i < 52; i++) {
        afficherCarte(&cartes[i]);
    }
}

// La ca devient intéressant. On commence à jouer avec l'aléatoire
// Cette fonction prend le tableau de 52 cartes et le mélange
void melangerJeu(t_carteS tabl[52]) {

    // Le fonctionnement de cette boucle est très simple:
    for(int i = 0; i < 52; i++) {
        int alea1 = rand()%52;          // 1. On génère une valeur aléatoire de 0 à 52
        int alea2 = rand()%52;          // 2. On génère une deuxieme valeur aléatoire de 0 à 52
        t_carteS buf = tabl[alea1];     // 3. On crée une variable temporaire eton lui associe une des cartes du tableau (selon l'aléatoire)
        tabl[alea1] = tabl[alea2];      // 4. On remplace cette valeur avec celle correspondante à la deuxième valeur aléatoire
        tabl[alea2] = buf;              // 5. On remplace la seconde valeur par la premiere, qu'on a stocké plus tot
    }
    // Simple, non?
}

// Si tu lis ce commentaire, t'es vrmt trop chaud (envoie "Les broccolis c'est pas bon" sur le groupe de promo whatsapp)
// Le main qui fait fonctionner cet exo
void main2() {
    srand(time(NULL));        // Initialisation de l'aléatoire
    t_carteS tablJeu[52];     // Création du tableau
    creerJeu(tablJeu);        // Remplissage du tableau
    afficherJeu(tablJeu);     // Affichage initial du tableau
    printf("\n---- Melange ------\n\n");    // Séparateur visuel
    melangerJeu(tablJeu);     // Mélangeage des cartes
    afficherJeu(tablJeu);     // Réaffichage des cartes
}

///--------------------------------------------------------------------------------
///         -- Partie 2 --


// Oh crotte de bique... la difficulté monte. Mais on est ing non?
typedef struct pile{        // Structure pile qui va pouvoir contenir une pile de carte
    int tailleMax;          // La taille maximale de la pile
    t_carteS * tab;         // Le tableau dynamique de cartes
    int sommet;             // L'indice de sortie et d'entrée qui indique ou rajouter ou enlever des éléments
}t_pile;

// Encore et toujours des prototypes
void initialiserPile(t_pile* pile, int taille);
void ajouterCarte(t_pile* pile, t_carteS carte);
void afficherPile(t_pile* pile);
int main3();    /// La fonction à appeler dans le main tout en bas pour cet partie d'exo

// Fonction d'initialisation qui va simplement prendre une pile, lui allouer de la mémoire, et initialiser les variables
void initialiserPile(t_pile* pile, int taille) {

    pile->tailleMax = taille;   // Taille max fournie en parametre
    //pile->tab = malloc(pile->tailleMax*4);              /// Voici l'ancienne ligne
    // Le 4 vient de la mémoire que prend un "int", 4 octets, mais je n'ai pas reflechi au fait qu'il ne s'agit pas la
    // d'un int, mais d'un "t_carteS" qui prend plus de mémoire. Donc problème...
    pile->tab = malloc(pile->tailleMax*sizeof(t_carteS)); /// Ici l'erreur qui m'a saoulé
    pile->sommet = 0;   // On place l'indice d'ajout à 0 et on est pret a lancer le reste
}

// Fonction d'empilage simple
void ajouterCarte(t_pile* pile, t_carteS carte) {

    pile->tab[pile->sommet] = carte;    // On place la nouvelle carte au sommet
    pile->sommet++;                     // On déplace le sommet a sa nouvelle place
}

// Fonction d'affichage d'une pile
void afficherPile(t_pile* pile) {   // Beaucoup de "pile" en une ligne...

    // Impression de "???" pour chaque carte qui n'est pas "retournée" (comme au solitaire... Chuis seul ptn...)
    for(int i = 0; i < pile->sommet-1; i++) {
        printf("??? ");
    }
    // Seule la derniere carte de la pile est affichée
    afficherCarte(&pile->tab[pile->sommet-1]);
}

// Le fameux main de cette partie
int main3() {

    srand(time(NULL));      // Initialisation de l'aléatoire
    t_carteS tablJeu[52];   // Création d'un tableau de cartes
    creerJeu(tablJeu);      // Remplissage du tableau
    melangerJeu(tablJeu);   // Mélange des cartes


    t_pile pile[7];         // Création des 7 piles à cacher

    // Boucle d'initialisation des 7 piles
    for(int i = 0; i < 7; i++) {
        initialiserPile(&pile[i], i+1); // Initialisation avec une carte de plus par pile que la dernière
    }

    // Remplissage des piles avec les cartes de "tablJeu"
    int compte=0;
    for(int i = 0; i < 7; i++) {                        // Première boucle for pour chaque pile
        for(int j = 0; j < pile[i].tailleMax; j++) {    // Deuxieme boucle for pour chaque élément des piles
            ajouterCarte(&pile[i], tablJeu[compte]);    // Ajout de la carte (note l'esperluette: un tableau est en effet un pointeur
                                                                // mais un élément du tableau ne l'est pas
            compte++;                                   // Variable qui garde en tete combien de cartes ont été tirées
        }
    }

    // Affichage bete de chaque pile
    for(int i = 0; i < 7; i++) {
        afficherPile(&pile[i]); // avec une fonction plus haut
    }

    return 0;
}

///--------------------------------------------------------------------------------
///         -- Partie 3 --

// Alléééé plus que deux fonctions!! (les prototypes survivent encore)
void depilerEmpiler(t_pile* p1, t_pile* p2);
int main4();    /// La fonction à appeler dans le main pour effectuer cette partie de l'exo
// C'est le dernier main, donc celui qui met tout ensemble

// Cette fonction est un peu plus compliquées que les autres. En principe, elle est simple: déplacer la carte d'une pile vers une autre
// quand certaines conditions sont remplies
void depilerEmpiler(t_pile* p1, t_pile* p2) {

    // Le if qui fache:
        // Si la pile1 n'est pas vide et...
        // ... si la pile2 n'est pas pleine et...
        // ... si la valeur de la carte sur la pile1 est supérieur à celle de la pile2 OU si la pile2 est vide...
        // On peut entrer dans le if
    if(p1->sommet != 0 && p2->sommet < p2->tailleMax && (p1->tab[p1->sommet-1].value > p2->tab[p2->sommet-1].value || p2->sommet == 0)) {

        // En théorie, un appel de "ajouterCarte devrait etre possible, mais je n'ai pas réussi à le
        // faire fonctionner, sachant que j'ai 2h pour finir et la il est 2h du mat, donc pouet pouet
        p2->tab[p2->sommet] = p1->tab[p1->sommet-1]; // On copie la carte de la pile1 vers la pile2
        p2->sommet++;   // On incrémente l'indice d'ajout de la pile2
        p1->sommet--;   // et on diminue de 1 l'indice d'ajout de la pile1
        printf("\n");   // Petit retour à la ligne des familles
    }
    // Et si le if n'est pas validé, on affiche "impossible ouesh"
    else {
        printf("Impossible!!\n\n");
    }
}

// Le main final!
int main4() {

    srand(time(NULL));                                  // Initialisation de l'aléatoire
    t_carteS tablJeu[52];                               // Déclaration du tableau de cartes
    creerJeu(tablJeu);                                  // Remplissage du tableau de cartes
    melangerJeu(tablJeu);                               // Mélangeage du tableau

    t_pile pile[7];                                     // Création des 7 piles de carte

    // Initialisation des piles comme dans la partie 2
    for(int i = 0; i < 7; i++) {
        initialiserPile(&pile[i], i+1);
    }

    // Remplissage des piles comme dans la partie 2
    int compte=0;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < pile[i].tailleMax; j++) {
            ajouterCarte(&pile[i], tablJeu[compte]);
            compte++;
        }
    }

    // Affichage des 7 piles avec leur nom
    for(int i = 0; i < 7; i++) {
            printf("Pile %d\n", i+1);
            afficherPile(&pile[i]);
    }

    t_pile pileFinale;                                      // Création de la pile finale
    initialiserPile(&pileFinale, 13);                       // Son initialisation

    // Boucle for pour s'occuper du déplacage de cartes
    for(int i = 0; i < 3; i++) {
        printf("\nEntrez un numero de pile: ");             // Selection des cartes
        int numPile;
        scanf("%d", &numPile);
        depilerEmpiler(&pile[numPile-1], &pileFinale);      // dépilation empilation selon la pile choisie

        // Boucle for pour réafficher les piles
        for(int i = 0; i < 7; i++) {
            printf("Pile %d\n", i+1);
            afficherPile(&pile[i]);
        }
        // Affichage à part de la pile finale
        printf("Pile Finale\n");
        afficherPile(&pileFinale);
    }

    return 0;
}

///------------------------------------------------------------------------------------------------
/// FIN + MAIN
///------------------------------------------------------------------------------------------------


int main() {

    main4();

    return 0;
}


/// Enfin terminé! Matière à connaitre: Files et Piles (quelles soient dynamiques ou statiques), et les LISTES CHAINEES



