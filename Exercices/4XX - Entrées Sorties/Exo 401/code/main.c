// Lorsque le programme est compilé par l'ordinateur, quand il voit un "#include", il va chercher le fichier dont le nom suit
// Et va remplacer la ligne où est le "#include" avec ce fichier. Ici, en ajoutant le fichier "stdio.h" ("standard input/output" en long)
// on obtient accès à des fonctions d'entrées et sorties qui permettent, en bref, d'afficher des choses à l'écran et de lire des choses
// au clavier. On peut aussi lire et écrire dans des fichiers, mais c'est un peu plus compliqué.
#include <stdio.h>

// La fonction main() est la fonction principale du programme. C'est elle qui est appelée en premier lorsque le programme est lancé.
// (fonction = sous programme = bloc de code qui peut être exécuté)
// "int" indique ce que la fonction va rendre (la réponse, en quelque sorte) (note le "return 0;" à la fin de la fonction)
// "()" dans ces parenthèses on va fournir les variables que le sous programme pourrait utiliser, on appelle ça des paramètres
// "{" ici on ouvre le bloc de code de la fonction, c'est à dire tout ce qui va être exécuté lorsque la fonction est appelée
int main() {

    // printf est une fonction qui permet d'afficher des choses à l'écran. Elle est définie dans le fichier stdio.h
    // Elle prend en paramètre une chaîne de caractères qui contient le texte à afficher
    // "\n" est un caractère spécial qui indique un retour à la ligne. C'est comme si on appuyait sur "Entrée" sur le clavier
    // Dès que l'on voit "\" dans une chaîne de caractères, on sait que c'est un caractère spécial
    printf("Bonjour\n");

    // Ci-suit une déclaration d'une variable en tant qu'entier (int). Cette ligne va réserver quelque part dans la mémoire de l'ordinateur
    // 4 octets (ou 32 bits). Sur 32 bits, on peut stocker 2^32 valeurs différentes, soit 4 294 967 296 valeurs différentes.
    // Donc de -2 147 483 648 à 2 147 483 647. Pour stocker des nombres plus grands, il faut utiliser des longs (long) ou des longs longs (long long)
    // Comme ceci: 
    // long long monGrandEntier;
    // qui réserve 8 octets (64 bits) pour stocker des nombres de -9 223 372 036 854 775 808 à 9 223 372 036 854 775 807
    int annee;

    // Une impression à l'écran pour demander à l'utilisateur d'entrer une année
    printf("Entrez l'annee en cours : ");

    // scanf est une fonction dans stdio.h qui permet d'écouter les entrées au clavier jusqu'à ce que l'utilisateur appuie sur "Entrée"
    // scanf veut dire "scan formatted" (scan formaté). Il prend en paramètre une chaîne de caractères qui indique le format de ce que l'on veut lire
    // Ici, on dit "%d", ce qui veut dire que l'on veut lire un nombre. On peut utiliser "%c" pour un caractère ou "%f" pour un nombre à virgule.
    // Il faut ensuite préciser où on veut stocker cet entier. Le C est un langage de bas niveau, donc il faut souvent tout faire soi-même.
    // En l'occurence on veut stocker l'entrée de l'utilisateur à l'endroit où on a réservé la mémoire quand on a fait "int annee;"
    // D'où le "&" qui indique l'endroit mémoire plutôt que la valeur.
    scanf("%d", &annee);

    // On peut aussi mélanger des chaînes de caractères et des variables dans un printf.
    // On ne met pas de "&" ici car on ne veut pas imprimer l'adresse (l'endroit mémoire) mais la valeur de la variable.
    printf("L'annee en cours est %d\n", annee);

    // Annee est bien un entier. On peut donc faire des opérations dessus.
    // Pour obtenir l'opposé, il suffit de multiplier par -1
    annee = annee * -1;
    printf("L'opposé est %d\n", annee);

    // Comme pour annee, on déclare trois variables de type entier
    // En les séparant par des virgules, on peut déclarer plusieurs variables du même type en même temps
    int note1, note2, note3;
    // La moyenne n'est pas forcément un entier, on la déclare donc en tant que nombre à virgule (float)
    float moyenne;

    // On demande à l'utilisateur d'entrer trois notes, séparées par des tirets
    printf("Entrez les trois notes ainsi: 1-2-3\n");
    // Un scanf peut aussi lire plusieurs variables en même temps. Il suffit de mettre autant de "%d" que de variables à lire
    // Ici, il va ignorer les tirets et stocker les trois nombres dans les variables note1, note2 et note3
    scanf("%d-%d-%d", &note1, &note2, &note3);

    // Il y a ici une petite astuce. On veut calculer la moyenne, mais on ne peut pas faire "moyenne = (note1 + note2 + note3) / 3;"
    // parce que le C va faire une division entière, c'est à dire qu'il va ignorer les chiffres après la virgule.
    // Explication : (note1 + note2 + note3) est une somme de trois entiers. Le résultat de cette opération est donc un entier.
    // En C, diviser un entier par un entier va rendre un entier (donc avec 3, 4 et 6, il rend 5, ce qui est faux)
    // Pour éviter ça, on peut forcer le C à faire une division à virgule en transformant au moins un des entiers en nombre à virgule
    // Cela explique le "(float)" devant la somme. On dit au C de transformer la somme en nombre à virgule avant de la diviser par 3.
    // On appelle cette opération un "cast", soit une conversion de type.
    moyenne = (float)(note1 + note2 + note3) / 3;

    // Une fois la moyenne calculée, on imprime les notes...
    printf("Les notes sont %d, %d et %d\n", note1, note2, note3);
    // ... et la moyenne. Cependant, avec un détail:
    // printf est un "print formatté". C'est à dire qu'on peut formatter le texte que l'on imprime.
    // En faisant "%f" on affiche un réel. En faisant "%.2f", on affiche un réel en limitant l'affichage à 2 chiffres après la virgule.
    printf("La moyenne est %.2f\n", moyenne);

    // Le return 0 est plus une convention qu'une obligation. Lorsqu'un programme rend 0 à la fin, c'est qu'il s'est bien déroulé.
    // Si il rend autre chose, c'est un code d'erreur que l'on peut utiliser pour identifier la source d'un crash.
    return 0;
}