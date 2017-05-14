#include <iostream>

using namespace std;

int BinarySearch(int num[], int start, int end, int target) {
    if (start < end) {
        int middle = (start + end) / 2;
        if (num[middle] == target)
            return middle;
        else if (num[middle] > target) {
            return BinarySearch(num, start, middle - 1, target);
        } else
            return BinarySearch(num, middle + 1, end, target);
    }
    return -1;
}


int main() {
    int num[] = {1, 2, 3, 4, 5, 8, 9, 11};
    int result = BinarySearch(num, 0, 7, 7);
    if (result != -1)
        cout << "Found, position is " << result << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}