#include <iostream>

using namespace std;

void convertTime(int total_seconds, int* hours, int* minutes, int* seconds) {
    *hours = total_seconds / 3600;
    total_seconds %= 3600;
    *minutes = total_seconds / 60;
    *seconds = total_seconds % 60;
}

void printTime(int* hours, int* minutes, int* seconds) {
    cout << "H:M:S - " << *hours << ":" << *minutes << ":" << *seconds << endl;
}

int main() {
    int total_seconds, hours, minutes, seconds;
    cout << "Please enter time in seconds: ";
    cin >> total_seconds;

    convertTime(total_seconds, &hours, &minutes, &seconds);
    printTime(&hours, &minutes, &seconds);

    return 0;
}
