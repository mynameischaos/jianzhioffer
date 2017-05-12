#include <iostream>

using namespace std;

void ReplaceBlank(char string[], int length) {

}

// 相关题目
// A1 和 A2 两个排序数组, A1后面有足够的空间容纳A2;

void copySortedArray(int A1[], int length1, int A2[], int length2) {
    int i = length1 - 1;
    int j = length2 - 1;
    int p = length1 + length2 - 1;

    while(i >= 0 && j >= 0) {
        if (A1[i] > A2[j]) {
            A1[p--] = A1[i];
            i--;
        } else {
            A1[p--] = A2[j];
            j--;
        }
    }
    while (i >= 0)
        A1[p--] = A1[i--];
    while (j >= 0)
        A2[p--] = A2[j--];
}


int main() {
    const int length = 1000;
    int A1[length] = {1};
    int A2[0] = {};
    copySortedArray(A1, 1, A2, 0);
    for (int i = 0; i < 1 + 0; i++) {
        cout << A1[i] << ",";
    }
    return 0;
}