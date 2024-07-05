#include <stdio.h>

void print_result(int num1, char operator, int num2, int result) {
    printf("Your equation:\n\t%d %c %d = %d\n", num1, operator, num2, result);
}

int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2) {
    if (num2 == 0) {
        printf("MATH ERROR!\n");
        return 0;
    }
    return num1 / num2;
}
