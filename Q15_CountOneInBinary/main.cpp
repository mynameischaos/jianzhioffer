#include <iostream>

using namespace std;

// 这种解法有一个问题就是负数的时候怎么办
int CountOneInBinary(int num) {
    int sum = 0;
    while (num > 0) {
        if (num % 2 != 0)
            sum++;
        num = num >> 1;
    }
    return sum;
}

// 负数的解法, 不要直接移动num,去移动一个flag
// 然后num和flag做与运算
// 但是这种做法有一个问题就是32位的机器需要循环32次, 64位的需要64次。
int CountOneInBinary2(int num) {
    int sum = 0;
    int flag = 1;
    while (flag) {
        if (num & flag) {
            sum++;
        }
        flag = flag << 1;
    }
    return sum;
}

// 下面这种解法就是一个数中有多少个1,仅需要循环多少次
// 一个非0的数如果减去1,那么最右边的1会变成0, 如果这个1的右边还有0,那么他们会变成1
// 得到的结果再和原来的数做与操作, 那么最右边的那个1会变成0
// 比如1100, 1100 - 1 = 1011, 1100 & 1011 = 1000, 有多少这样的操作就有多少1
int CountOneInBinary3(int num) {
    int sum  = 0;
    while (num > 0) {
        sum++;
        num = (num - 1) & num;
    }
    return sum;
}

int main() {
    cout << CountOneInBinary(9) << endl;
    cout << CountOneInBinary2(9) << endl;
    cout << CountOneInBinary3(9) << endl;
    return 0;
}