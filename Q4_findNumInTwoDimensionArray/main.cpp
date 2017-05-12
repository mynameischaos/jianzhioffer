#include <iostream>

using namespace std;


bool Find(int* arr, int rows, int columns, int number) {
    int i = 0;
    int j = columns - 1;
    while (i <= rows - 1 && j >= 0) {
        if (arr[i * rows + j] == number)
            return true;
        else if (arr[i * rows + j] > number) {
            j--;
        }else {
            i++;
        }
    }
    return false;
}

int main() {
    int arr[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
    cout << Find(arr, 4, 4, 12) << endl;
    return 0;
}