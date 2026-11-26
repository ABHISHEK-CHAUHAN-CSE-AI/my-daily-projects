#include <stdio.h>

int main() {
    int a, b, c;
    float avg;

    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    avg = (a + b + c) / 3.0;
    printf("Average is %.2f\n", avg);

    return 0;
}
