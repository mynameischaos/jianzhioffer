#include <iostream>

using namespace std;


int MinInOrder(int num[], int start, int end) {
    int result = num[start];
    for (int i = start + 1; i <= end; i++) {
        if (num[i] < result) {
            result = num[i];
        }
    }
    return result;
}

int rotateNum(int num[], int length, int start, int end) {
    int index1 = start;
    int index2 = end;
    int midIndex = index1;
    while (num[index1] >= num[index2]) {
        if ((index2 - index1) == 1) {
            midIndex = index2;
            break;
        }
        midIndex = (index1 + index2) / 2;
        if (num[index1] == num[index2] && num[index2] == num[midIndex]) {
            return MinInOrder(num, index1, index2);
        }
        if (num[index1] <= num[midIndex]) {
            index1 = midIndex;
        } else if (num[index1] >= num[midIndex]){
            index2 = midIndex;
        }
    }
    return num[midIndex];
}

int main() {
    int arr[] = {2};
    cout << rotateNum(arr, 5, 0, 0) << endl;
    return 0;
}