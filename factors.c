#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

void factorize(int n) {
    int orig = n;
    if (n < 0) {
        printf("%d is negative.\n", n);
        return;
    }
    if (n <= 1) {
        printf("%d=%d\n", n, n);
        return;
    }
    printf("%d=", n);
    int divisor = 2;
    while (n > 1) {
        if (n % divisor == 0) {
            printf("%d", divisor);
            n /= divisor;
            if (n > 1) printf("*");
        } else {
            divisor++;
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        factorize(num);
    }

    fclose(file);
    return 0;
}
