#include <iostream>
#include <cmath>

using namespace std;


// 动态规划的思想
int cutString(int length) {
    int* table = new int[length + 1];
    for (int i = 0; i <= length; i++)
        table[i] = i;

    for (int i = 1; i <= length; i++) {
        int sum = i;
        for (int j = 1; j <= i / 2; j++) {
            int tmp = table[j] * table[i - j];
            if (tmp > sum)
                sum = tmp;
        }
        table[i] = sum;
    }
    return table[length];
}

// 贪心的思想
// n>=5 的时候,尽可能多的剪成长度为3的绳子
// 至少剪一刀

int maxProductAfterCutting(int length) {
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;

    int timesOf3 = length / 3;
    if ((length - timesOf3 * 3) == 1)
        timesOf3 -= 1;
    int timesOf2 = (length - timesOf3 * 3) / 2;
    return int(pow(3, timesOf3) * pow(2, timesOf2));
}



int main() {
    cout << cutString(4) << endl;
    cout << maxProductAfterCutting(4) << endl;
    return 0;
}