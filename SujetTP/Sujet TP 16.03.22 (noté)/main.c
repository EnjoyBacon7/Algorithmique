#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/// Hello los zigotos, voici le sujet du tp de je sais plus quel td le 14/03/22 en algo. Je me suis pos� le challenge de le faire sous les 2h imparties,
/// et j'ai plutot bien r�ussi, mis � part une petite erreur de m*rde qui refusait de s'en aller (l.244) et qui m'a bouff� 20 minutes. Le
/// tp est donc largement faisable (surtout en groupe, du coup), mais il faut vraiment bien comprendre le cours, et etre � l'aise avec l'algo en g�n�ral.
/// Venant du majorant du partiel, (oui, je flex :) j'espere que mes mots ont du poids. Si une mati�re doit etre n�glig�e, choisis l'elec.

/// Pour la moindre erreur ou bug:
/// Discord: EnjoyBacon7#1390

// Des "-" s�parent les exos et les parties
// Certaines fonctions d�velopp�es dans une autre partie sont r�utilis�es dans les parties ult�rieures (attention)
// Chaque partie/exercice poss�de un main num�rot�. le premier exercice peut etre execut� en appelant "main1();" dans le main tout en bas du code
//      (De meme pour les autres exos: "main2();" pour la deuxieme partie, etc...)


///------------------------------------------------------------------------------------------------
/// EXERCICE 1
///------------------------------------------------------------------------------------------------

// Prototypes de mes fonctions (leur d�finition, en quelque sorte) ils sont plac�s dans le fichier ".h" quand on fait du multifichier
int main1();
int modifier(int tablEntiers[], int tablTaille, int v, int compte);
void charger(char* fpName, int tablCharge[10]);

/// Ici la fonction � appeler dans le "main()" pour voir l'exercice 1. Je vais pas macher tout le travail non plus
int main1() {

    // On cr�e un tableau de 10 entiers tout bete et on appelle la fonction "charger()" qui remplit le tableau avec les valeurs
    // dans le fichier dont le nom est le premier parametre (je sais que t'as rien compris a cette phrase)
    int tablCharge[10];
    charger("fichier",tablCharge);

    // Impression rapide de mon tableau (pour v�rifier que la fonction pr�c�dente aie bien fonctionn�e
    for(int i = 0; i < 10; i++) {
        printf("%d\n", tablCharge[i]); // un printf()... fun fact: le "f" veut dire "format".
    }

    // Je demande la valeur de v � remplacer et je la stocke
    printf("Entrez la valeur a mettre a zero: ");
    int valeur;
    scanf("%d", &valeur);

    // Ici, compte repr�sente le nombre de valeurs qui ont �t� remplac�es par 0 dans la fonction "modifier"
    // Puisqu'il s'agit d'une fonction r�cursive, je dois lui donner un moyen de compter le nombre d'it�rations
    // (d'ou le 0 en quatrieme parametre)
    int compte = modifier(tablCharge, 10, valeur, 0);

    // Encore un affichage de mon tableau, afin de voir les valeurs modifi�es et j'indique le nombre de cases modifi�es
    for(int i = 0; i < 10; i++) {
        printf("%d\n", tablCharge[i]); // D'ailleurs lorsqu'un "format" est pr�sent, on va retrouver des parametres comme : ("%d", variable)
    }
    printf("\nLe nombre de cases modifiees est %d", compte);
    return 0;
}

// Aaaah une belle fonction. Pour ceux qui ne l'auraient pas compris, l'avantage de la r�cursivit� est sa compacit�. On peut faire
// un code bien plus compact pour une meme op�ration.
int modifier(int* tablEntiers, int tablTaille, int v, int compte) {

    // Ma condition de terminaison de r�cursivit� (lorsque la variable "tablTaille" atteint 0
    if(tablTaille == 0) {
        return compte;
    }

    // On remplace la valeur par 0 pour chaque it�ration de la fonction + incr�mentation du compteur
    if (tablEntiers[tablTaille] == v) {
        tablEntiers[tablTaille] = 0;
        compte++;
    }

    // On relance la fonction avec les memes parametres sauf au niveau de "tabTaille" qui baisse de un � chaque r�p�tition
    return modifier(tablEntiers, tablTaille - 1, v, compte);
}

// La fonction "charger()" a pour but de lire un fichier et de stocker les entiers dans le tableau.
// Ca date un peu, mais c'est quelque chose de base qui est toujours bon a savoir faire. (La preuve: c'est demand� ici)
void charger(char* fpName, int tablCharge[10]) {    // Note le "char* fpName", ca me permet de g�rer un tableau de taille variable


    char fpPath[sizeof(fpName) + 4];    // On cr�e une chaine de caracteres de la taille de fpName + 4 (pour concat�ner ".txt")
    strcpy(fpPath, fpName);             // On copie "fpName" dans "fpPath"
    strcat(fpPath, ".txt");             // On lui rajoute le ".txt" indiqu� plus haut
    FILE* fp = fopen(fpPath, "r+");     // On peut enfin ouvrir le fichier en lecture/ecriture

    int buf;                        // Ce buffer permet de stocker temporairement chaque entier lu

    // Cette boucle while tourne jusqu'� ce que le charactere "EOF" (end of file) soit lu et stocke simplement les valeurs lues
    // dans le tableau "tablCharge"
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d", &buf);
        tablCharge[i] = buf;
        i++;
    }

    // On n'oublie pas, bien sur, de fermer le fichier (pour faire plaisir au correcteur, puisque celui-ci est lib�r� � la fin du ssprgm)
    fclose(fp);
}

// Enfin la fin!! Cet exo plutot simple devrait etre compl�t� en une demi-heure par une personne. L'exercice 2 est 3-4 fois plus long.
// Donc faut vite aller aider ton bin�me, flemmard.e (#MmeRerzki)

///------------------------------------------------------------------------------------------------
/// EXERCICE 2      -- Partie 1 --
///------------------------------------------------------------------------------------------------

// Yeessa�e, c'est tipar pour l'exo 2!

// Quoi?! Une structure sauvage appara�t? ouf... c'est pas un tableau dynamique
// (Si t'as pas capt� la vanne, va lire ton cours... t'as v'la du retard :/ )
typedef struct carte {

    int suit;       // Du coup, simple structure avec un alias ("t_carteS") avec deux entiers "suits" et "value"
    int value;      // pour faire un peu d'anglais. suits = suite/couleur. value = valeur/chiffre/face

}t_carteS;

// Encore des prototypes. Ils sont mignons non?
void creerJeu(t_carteS tabl[52]);
void afficherCarte(t_carteS* carte);
void afficherJeu(t_carteS cartes[52]);
void melangerJeu(t_carteS tabl[52]);
void main2(); /// Le main � appeler pour tester cette partie de l'exercice 2


// Premiere fonction qui va simplement remplir les structures d'un tableau de structures avec
// des entiers de 1 � 13 pour les valeurs et 1 � 4 pour les couleurs
// L'absence de "*" dans le parametre s'explique par le fait qu'il s'agisse d'un tableau, qui, par
// d�finition eeeeeeeeest?  ...un pointeur!! bravo!
void creerJeu(t_carteS tabl[52]) {

    // Boucle for qui se r�pete 52 fois (une fois par carte pour les moins fut�s d'entre vous)
    for(int i = 0; i < 52; i++) {
        // La m�thode de calcul est simple: je r�cup�re la partie enti�re de la division par 13
        // pour avoir des valeurs de 0-3, d'ou le "+ 1" pour avoir les 4 couleurs
        tabl[i].suit = (i/13) + 1;
        // Ici, pour la valeur, je r�cup�re le reste de la division par 13, ce qui donne une valeur
        // entre 0-12, d'ou le "+ 1"
        tabl[i].value = (i%13)+1;
    }
}

// Une simple fonction d'affichage qui affiche la couleur et la valeur d'une carte
void afficherCarte(t_carteS* carte) {

    // Le voici!!! Le mis�rable switch case! J'ai d�ja exprim� mon aversion � cette chose, mais
    // il s'agit d'une alternative plus int�r�ssante aux s�ries de if, else if.
    switch (carte->suit) {              // Ici on d�finit la variable � consid�rer
        case 1:                             // Et on consid�re les etats de la variable. Ici, si elle vaut 1 on entre dans le "case"
            printf("Trefle  : ");               // Donc si la couleur vaut 1, c'est un Tr�fle
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

    // Un deuxi�me switch case pour consid�rer la valeur de la carte (je te laisse comprendre)
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
        default:                // Sauf ici. "default:" est la condition g�n�rale. c'est une condition toujours vraie
                                // elle permet de traiter de la meme maniere toutes les cartes sans faces
            printf("%d\n", carte->value);
            break;
    }
}

// Fonction qui utilise la fonction pr�c�dente pour afficher toutes les cartes
void afficherJeu(t_carteS cartes[52]) {

    // Simple boucle for qui affiche toutes les cartes une a une
    for(int i = 0; i < 52; i++) {
        afficherCarte(&cartes[i]);
    }
}

// La ca devient int�ressant. On commence � jouer avec l'al�atoire
// Cette fonction prend le tableau de 52 cartes et le m�lange
void melangerJeu(t_carteS tabl[52]) {

    // Le fonctionnement de cette boucle est tr�s simple:
    for(int i = 0; i < 52; i++) {
        int alea1 = rand()%52;          // 1. On g�n�re une valeur al�atoire de 0 � 52
        int alea2 = rand()%52;          // 2. On g�n�re une deuxieme valeur al�atoire de 0 � 52
        t_carteS buf = tabl[alea1];     // 3. On cr�e une variable temporaire eton lui associe une des cartes du tableau (selon l'al�atoire)
        tabl[alea1] = tabl[alea2];      // 4. On remplace cette valeur avec celle correspondante � la deuxi�me valeur al�atoire
        tabl[alea2] = buf;              // 5. On remplace la seconde valeur par la premiere, qu'on a stock� plus tot
    }
    // Simple, non?
}

// Si tu lis ce commentaire, t'es vrmt trop chaud (envoie "Les broccolis c'est pas bon" sur le groupe de promo whatsapp)
// Le main qui fait fonctionner cet exo
void main2() {
    srand(time(NULL));        // Initialisation de l'al�atoire
    t_carteS tablJeu[52];     // Cr�ation du tableau
    creerJeu(tablJeu);        // Remplissage du tableau
    afficherJeu(tablJeu);     // Affichage initial du tableau
    printf("\n---- Melange ------\n\n");    // S�parateur visuel
    melangerJeu(tablJeu);     // M�langeage des cartes
    afficherJeu(tablJeu);     // R�affichage des cartes
}

///--------------------------------------------------------------------------------
///         -- Partie 2 --


// Oh crotte de bique... la difficult� monte. Mais on est ing non?
typedef struct pile{        // Structure pile qui va pouvoir contenir une pile de carte
    int tailleMax;          // La taille maximale de la pile
    t_carteS * tab;         // Le tableau dynamique de cartes
    int sommet;             // L'indice de sortie et d'entr�e qui indique ou rajouter ou enlever des �l�ments
}t_pile;

// Encore et toujours des prototypes
void initialiserPile(t_pile* pile, int taille);
void ajouterCarte(t_pile* pile, t_carteS carte);
void afficherPile(t_pile* pile);
int main3();    /// La fonction � appeler dans le main tout en bas pour cet partie d'exo

// Fonction d'initialisation qui va simplement prendre une pile, lui allouer de la m�moire, et initialiser les variables
void initialiserPile(t_pile* pile, int taille) {

    pile->tailleMax = taille;   // Taille max fournie en parametre
    //pile->tab = malloc(pile->tailleMax*4);              /// Voici l'ancienne ligne
    // Le 4 vient de la m�moire que prend un "int", 4 octets, mais je n'ai pas reflechi au fait qu'il ne s'agit pas la
    // d'un int, mais d'un "t_carteS" qui prend plus de m�moire. Donc probl�me...
    pile->tab = malloc(pile->tailleMax*sizeof(t_carteS)); /// Ici l'erreur qui m'a saoul�
    pile->sommet = 0;   // On place l'indice d'ajout � 0 et on est pret a lancer le reste
}

// Fonction d'empilage simple
void ajouterCarte(t_pile* pile, t_carteS carte) {

    pile->tab[pile->sommet] = carte;    // On place la nouvelle carte au sommet
    pile->sommet++;                     // On d�place le sommet a sa nouvelle place
}

// Fonction d'affichage d'une pile
void afficherPile(t_pile* pile) {   // Beaucoup de "pile" en une ligne...

    // Impression de "???" pour chaque carte qui n'est pas "retourn�e" (comme au solitaire... Chuis seul ptn...)
    for(int i = 0; i < pile->sommet-1; i++) {
        printf("??? ");
    }
    // Seule la derniere carte de la pile est affich�e
    afficherCarte(&pile->tab[pile->sommet-1]);
}

// Le fameux main de cette partie
int main3() {

    srand(time(NULL));      // Initialisation de l'al�atoire
    t_carteS tablJeu[52];   // Cr�ation d'un tableau de cartes
    creerJeu(tablJeu);      // Remplissage du tableau
    melangerJeu(tablJeu);   // M�lange des cartes


    t_pile pile[7];         // Cr�ation des 7 piles � cacher

    // Boucle d'initialisation des 7 piles
    for(int i = 0; i < 7; i++) {
        initialiserPile(&pile[i], i+1); // Initialisation avec une carte de plus par pile que la derni�re
    }

    // Remplissage des piles avec les cartes de "tablJeu"
    int compte=0;
    for(int i = 0; i < 7; i++) {                        // Premi�re boucle for pour chaque pile
        for(int j = 0; j < pile[i].tailleMax; j++) {    // Deuxieme boucle for pour chaque �l�ment des piles
            ajouterCarte(&pile[i], tablJeu[compte]);    // Ajout de la carte (note l'esperluette: un tableau est en effet un pointeur
                                                                // mais un �l�ment du tableau ne l'est pas
            compte++;                                   // Variable qui garde en tete combien de cartes ont �t� tir�es
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

// All���� plus que deux fonctions!! (les prototypes survivent encore)
void depilerEmpiler(t_pile* p1, t_pile* p2);
int main4();    /// La fonction � appeler dans le main pour effectuer cette partie de l'exo
// C'est le dernier main, donc celui qui met tout ensemble

// Cette fonction est un peu plus compliqu�es que les autres. En principe, elle est simple: d�placer la carte d'une pile vers une autre
// quand certaines conditions sont remplies
void depilerEmpiler(t_pile* p1, t_pile* p2) {

    // Le if qui fache:
        // Si la pile1 n'est pas vide et...
        // ... si la pile2 n'est pas pleine et...
        // ... si la valeur de la carte sur la pile1 est sup�rieur � celle de la pile2 OU si la pile2 est vide...
        // On peut entrer dans le if
    if(p1->sommet != 0 && p2->sommet < p2->tailleMax && (p1->tab[p1->sommet-1].value > p2->tab[p2->sommet-1].value || p2->sommet == 0)) {

        // En th�orie, un appel de "ajouterCarte devrait etre possible, mais je n'ai pas r�ussi � le
        // faire fonctionner, sachant que j'ai 2h pour finir et la il est 2h du mat, donc pouet pouet
        p2->tab[p2->sommet] = p1->tab[p1->sommet-1]; // On copie la carte de la pile1 vers la pile2
        p2->sommet++;   // On incr�mente l'indice d'ajout de la pile2
        p1->sommet--;   // et on diminue de 1 l'indice d'ajout de la pile1
        printf("\n");   // Petit retour � la ligne des familles
    }
    // Et si le if n'est pas valid�, on affiche "impossible ouesh"
    else {
        printf("Impossible!!\n\n");
    }
}

// Le main final!
int main4() {

    srand(time(NULL));                                  // Initialisation de l'al�atoire
    t_carteS tablJeu[52];                               // D�claration du tableau de cartes
    creerJeu(tablJeu);                                  // Remplissage du tableau de cartes
    melangerJeu(tablJeu);                               // M�langeage du tableau

    t_pile pile[7];                                     // Cr�ation des 7 piles de carte

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

    t_pile pileFinale;                                      // Cr�ation de la pile finale
    initialiserPile(&pileFinale, 13);                       // Son initialisation

    // Boucle for pour s'occuper du d�placage de cartes
    for(int i = 0; i < 3; i++) {
        printf("\nEntrez un numero de pile: ");             // Selection des cartes
        int numPile;
        scanf("%d", &numPile);
        depilerEmpiler(&pile[numPile-1], &pileFinale);      // d�pilation empilation selon la pile choisie

        // Boucle for pour r�afficher les piles
        for(int i = 0; i < 7; i++) {
            printf("Pile %d\n", i+1);
            afficherPile(&pile[i]);
        }
        // Affichage � part de la pile finale
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


/// Enfin termin�! Mati�re � connaitre: Files et Piles (quelles soient dynamiques ou statiques), et les LISTES CHAINEES



