#include <iostream>

using namespace std;

// 青蛙跳问题,
int FrogJump(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n >= 3) {
        return FrogJump(n - 1) + FrogJump(n - 2);
    }
}

int main() {
    cout << FrogJump(8) << endl;
    return 0;
}