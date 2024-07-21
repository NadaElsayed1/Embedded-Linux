#include <stdio.h>
#include "calc.h"
int main() {
    int num1, num2, result;
    char operator;

    printf("This is a simple calculator application\nusing operators (+, -, /, *)\n");
    printf("Please enter 1st number: ");
    scanf("%d", &num1);
    printf("Please enter the operator: ");
    scanf(" %c", &operator);
    printf("Please enter 2nd number: ");
    scanf("%d", &num2);

    switch (operator) {
        case '+':
            result = add(num1, num2);
            print_result(num1, operator, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            print_result(num1, operator, num2, result);
            break;
        case '*':
            result = multiply(num1, num2);
            print_result(num1, operator, num2, result);
            break;
        case '/':
            result = divide(num1, num2);
            if (num2 != 0) {
                print_result(num1, operator, num2, result);
            }
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }
    return 0;
}
