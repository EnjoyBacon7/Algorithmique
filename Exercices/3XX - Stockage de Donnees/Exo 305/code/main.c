int main() {

    char lettre1;
    char lettre2;

    lettre1 = 'm';
    lettre2 = 'c';

    char temporaire;

    temporaire = lettre1;
    lettre1 = lettre2;
    lettre2 = temporaire;

    return 0;
}