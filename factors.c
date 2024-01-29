#include <stdio.h>

void factorize(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        if (number <= 1) {
            printf("Error: Invalid number %d\n", number);
            continue;
        }
        factorize(number);
    }

    fclose(file);
    return 0;
}
