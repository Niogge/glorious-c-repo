#include <stdio.h>
#include "maths.h"
#include "circle.h"

int sum(int a, int b) {
    return a + b;
}

int main() {
    int result = sum(2, 3);
    printf("Result: %d\n", result);

    float squared = sqr(4.f);
    printf("squared: %f\n", squared);

    float area = circle_area(4.f);
    printf("area: %f\n", area);
}