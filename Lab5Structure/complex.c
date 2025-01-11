#include <stdio.h>

struct complex {
    int real;
    int img;
};

void sum(struct complex c1, struct complex c2, struct complex *add);

void main() {
    struct complex c1, c2, add;

   printf("Real: ");
    scanf("%d", &c1.real);
    printf("Imaginary: ");
    scanf("%d", &c1.img);

    printf("Real: ");
    scanf("%d", &c2.real);
    printf("Imaginary: ");
    scanf("%d", &c2.img);

    sum(c1, c2, &add);

    printf("sum is: %d + %di\n", add.real, add.img);
}

void sum(struct complex c1, struct complex c2, struct complex *add) {
    add->real = c1.real + c2.real;
    add->img = c1.img + c2.img;
}
