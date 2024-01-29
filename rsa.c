#include <stdio.h>
#include <stdlib.h>

void factorize(int n) {
    printf("Prime factors of %d are: ", n);
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number to factorize: ");
    scanf("%d", &n);
    factorize(n);
    return 0;
}
