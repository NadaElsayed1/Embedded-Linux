#include <iostream>
#include <cmath>

using namespace std;

int binaryToDecimal(int num) {
    int temp, result = 0, i = 0;
    while (num != 0) {
        temp = num % 10;
        num /= 10;
        result += (pow(2, i)) * temp;
        i++;
    }
    return result;
}

string decimalToBinary(int num) {
    string binary = "";
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num /= 2;
    }
    return binary;
}

int main() {
    int num;
    cout << "Please enter a binary number: ";
    cin >> num;

    int decimalValue = binaryToDecimal(num);
    cout << "Its decimal value: " << decimalValue << endl;

    cout << "Please enter a decimal number: ";
    cin >> num;

    string binaryValue = decimalToBinary(num);
    cout << "Its binary value: " << binaryValue << endl;

    return 0;
}
