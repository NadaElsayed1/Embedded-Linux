#include <iostream>
#include <cmath>

class Calculator
{
private:
    double num1;
    double num2;
    double result;

    double add(double n1, double n2)
    {
        return n1 + n2;
    }

    double sub(double n1, double n2)
    {
        return n1 - n2;
    }

    double mult(double n1, double n2)
    {
        return n1 * n2;
    }

    double div(double n1, double n2)
    {
        if (n2 != 0)
            return n1 / n2;
        else
        {
            std::cerr << "Error: Division by zero" << std::endl;
            return 0;
        }
    }

    double sqrt(double n)
    {
        if (n >= 0)
            return std::sqrt(n);
        else
        {
            std::cerr << "Error: Square root of negative number" << std::endl;
            return 0;
        }
    }

    double pow(double base, double exponent)
    {
        return std::pow(base, exponent);
    }

public:
    Calculator() : num1(0), num2(0), result(0) {}

    void operation_handling(double n1, double n2, char op)
    {
        switch (op)
        {
        case '+':
            result = add(n1, n2);
            break;
        case '-':
            result = sub(n1, n2);
            break;
        case '*':
            result = mult(n1, n2);
            break;
        case '/':
            result = div(n1, n2);
            break;
        case '^':
            result = pow(n1, n2);
            break;
        default:
            std::cerr << "Error: Invalid operator" << std::endl;
            return;
        }
        std::cout << "Result: " << result << std::endl;
    }

    void operation_handling(double n, char op)
    {
        if (op == 'S')
        {
            result = sqrt(n);
            std::cout << "Result: " << result << std::endl;
        }
        else
        {
            std::cerr << "Error: Invalid operator for this method" << std::endl;
        }
    }

    void get_input_and_calc()
    {
        std::cout << "Enter operator (+, -, *, /, ^, S for sqrt): ";
        char op;
        std::cin >> op;

        if (op != 'S')
        {
            std::cout << "Enter first number: ";
            std::cin >> num1;
            std::cout << "Enter second number: ";
            std::cin >> num2;
            operation_handling(num1, num2, op);
        }
        else
        {
            std::cout << "Enter a number to get the square root: ";
            std::cin >> num1;
            operation_handling(num1, op);
        }
    }

    ~Calculator() {}
};

int main()
{
    Calculator c1;
    c1.get_input_and_calc();

    return 0;
}
