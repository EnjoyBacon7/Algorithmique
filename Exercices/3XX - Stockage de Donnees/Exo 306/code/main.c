int main() {

    float mesure1;
    float mesure2;

    mesure1 = 0.5;
    mesure1 *= 3;

    float tmp;

    tmp = mesure1;
    mesure1 = mesure2;
    mesure2 = tmp;

    return 0;
}