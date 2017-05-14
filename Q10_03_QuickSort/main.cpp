#include <iostream>

using namespace std;

int Partition (int num[], int length, int start, int end) {
    int small = start - 1;
    for (int i = start; i < end; i++) {
        if (num[i] < num[end]) {
            small++;
            if (small != i) {
                int tmp = num[i];
                num[i] = num[small];
                num[small] = tmp;
            }
        }
    }
    small++;
    int tmp = num[end];
    num[end] = num[small];
    num[small] = tmp;
    return small;
}

void QuickSort(int num[], int length, int start, int end) {
    if (start == end)
        return;
    int index = Partition(num, length, start, end);
    if (index > start) {
        QuickSort(num, length, start, index - 1);
    }
    if (index < end) {
        QuickSort(num, length, index + 1, end);
    }
}


int main() {
    int num[] = {1, 2, 7, 5, 4, 3, 6};
    QuickSort(num, 7, 0, 6);
    for (int i : num) {
        cout << i << endl;
    }
    return 0;
}