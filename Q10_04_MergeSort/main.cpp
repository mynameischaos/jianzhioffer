#include <iostream>

using namespace std;

void Merge(int num[], int p, int q, int r) {
    int LeftLength = q - p + 1;
    int RightLength = r - q;
    int* L = new int[LeftLength + 1];
    int* R = new int[RightLength + 1];
    L[LeftLength] = INT_MAX;
    R[RightLength] = INT_MAX;

    for (int i = 0; i < LeftLength; i++) {
        L[i] = num[p + i];
    }
    for (int j = 0; j < RightLength; j++) {
        R[j] = num[q + 1 + j];
    }

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] < R[j]) {
            num[k] = L[i];
            i++;
        } else {
            num[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int num[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(num, p, q);
        MergeSort(num, q + 1, r);
        Merge(num, p, q, r);
    }
}

int main() {
    int num[] = {1, 2, 3, 6, 5, 4, 8, 7, 9};
    MergeSort(num, 0, 8);
    for (int i : num)
        cout << i << endl;
    return 0;
}