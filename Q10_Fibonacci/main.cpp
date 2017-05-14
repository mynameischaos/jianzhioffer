#include <iostream>

using namespace std;

// 递归
long long Fibonacci(unsigned int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 循环
// 0, 1, 1, 2, 3, 5, 8
long long FibonacciFor(unsigned int n) {
    int results[2] = {0, 1};
    if (n < 2)
        return results[n];
    int numberOne = 0;
    int numberTwo = 1;
    int total = 0;
    for (int i = 2; i <= n; i++) {
        total = numberOne + numberTwo;
        numberOne = numberTwo;
        numberTwo = total;
    }
    return total;
}

int main() {

    cout << Fibonacci(10) << endl;
    cout << FibonacciFor(10) << endl;
    return 0;
}