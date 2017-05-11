#include <iostream>
#include <vector>

using namespace std;

int countNum(vector<int>& vec, int start, int end) {
    int count = 0;
    for (int i : vec) {
        if (i >= start && i <= end) {
            count++;
        }
    }
    return count;
}

int findNum(vector<int>& vec) {
    int start = 1;
    int end = vec.size() - 1;

    while(end >= start) {
        int middle = (start + end) / 2;
        int count = countNum(vec, start, middle);
        if (end == start) {
            if (count > 1)
                return start;
            else
                break;
        }
        if (count > (middle - start + 1)) {
            end = middle;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 5, 4, 3, 2, 6, 7};
    vector<int> tmp(arr, arr + 8);
    cout << findNum(tmp) << endl;

    return 0;
}