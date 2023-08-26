int main() {

    // 0. Déclaration des variables
    int compteur, indice;
    // 1. Début du code
    compteur = 10;                  // compteur = 10
    indice = compteur;              // indice = 10
    ++compteur;                     // compteur = 11
    compteur++;                     // compteur = 12
    indice*=2;                      // indice = 20
    compteur = ++compteur *4;       // compteur = 52
    indice = indice*7+45/5;         // indice = 149
    compteur = compteur*(3-54/6);   // compteur = -312

    return 0;
}