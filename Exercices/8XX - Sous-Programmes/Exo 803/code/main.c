#include <stdio.h>
#include <unistd.h>

int minuteSuivante(int minute);
int heureSuivante(int heure);

int main() {

    int heure = 0, minute = 0;

    printf("Quelle heure est-il ?\n");
    printf("Entrez l'heure (format 24h) : ");
    scanf("%d", &heure);
    printf("Entrez les minutes : ");
    scanf("%d", &minute);

    if(heure < 0 || heure > 23 || minute < 0 || minute > 59) {
        printf("Erreur : heure ou minute invalide. Veuillez relancer le programme\n");
        return 1;
    }


    while(1) {
        sleep(1);

        minute = minuteSuivante(minute);
        if(minute == 0) {
            heure = heureSuivante(heure);
        }

        if (heure > 12) {
            printf("%02d:%02d PM\n", heure - 12, minute);
        } else if (heure == 12) {
            printf("%02d:%02d PM\n", 12, minute);
        } else {
            printf("%02d:%02d AM\n", heure, minute);
        }

    }

    return 0;
}

int minuteSuivante(int minute) {
    if (minute < 59) {
        minute++;
    } else {
        minute = 0;
    }
    return minute;
}

int heureSuivante(int heure) {
    if (heure < 23) {
        heure++;
    } else {
        heure = 0;
    }
    return heure;
}