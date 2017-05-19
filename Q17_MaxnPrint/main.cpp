#include <iostream>

using namespace std;

// 将打印的问题转换成排列的问题

void PrintNumber(char* number) {
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; i++) {
        if (isBeginning0 && number[i] != '0') {
            isBeginning0 = false;
        }

        if (!isBeginning0) {
            cout << number[i];
        }
    }
    cout << endl;
}

void Print1ToMaxOfDigitsRecursively(char* number, int length, int index) {
    if (index == length - 1) {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; i++) {
        number[index + 1] = i + '0';
        Print1ToMaxOfDigitsRecursively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits(int n) {
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; i++) {
        number[0] = i + '0';
        Print1ToMaxOfDigitsRecursively(number, n, 0);
    }

}


int main() {
    Print1ToMaxOfNDigits(3);
    return 0;
}