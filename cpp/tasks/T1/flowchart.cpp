#include <iostream>

using namespace std;

void readNumber(int& number) {
    cout << "Please enter Number: ";
    cin >> number;
}

void accumulateSum(int number, int& result) {
    while (number != 0) {
        result += number;
        cout << "Please enter new number: ";
        cin >> number;
    }
}

void printResult(int result) {
    cout << "Result: " << result << endl;
}

int main() {
    int number, result = 0;
    readNumber(number);
    accumulateSum(number, result);
    printResult(result);
    return 0;
}