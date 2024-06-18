#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Russian");
    FILE *f_input, *f_output;
    int R, x = 0;

    f_input = fopen("R.txt", "r");

    if (f_input == NULL) {
        printf("Не удалось открыть файл\n");
        return 1;
    }

    fscanf(f_input, "%d", &R);
    fclose(f_input);

    printf("Исходные данные: %d\n", R);

    f_output = fopen("stepen.txt", "w");

    while (pow(3, x) < R) {
        ++x;
        fprintf(f_output, "Результат: %d\n", x);
    }

    fclose(f_output);
    printf("Результат записан\n");

    return 0;
}