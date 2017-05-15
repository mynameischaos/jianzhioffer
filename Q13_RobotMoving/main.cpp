#include <iostream>

using namespace std;

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int movingCount(int threshold, int rows, int cols);
int getDigitSum(int number);


int movingCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;

    bool* visited = new bool[rows * cols];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i * cols + j] = false;
    int result = movingCountCore(threshold, rows, cols, 0, 0, visited);

    delete[] visited;

    return result;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited) {
    int count = 0;
    if (check(threshold, rows, cols, row, col, visited)) {
        visited[row * cols + col] = true;
        count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row, col - 1, visited);

    }
    return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited) {
    return row >= 0 && col >= 0 && row < rows && col < cols
           && getDigitSum(row) + getDigitSum(col) <= threshold
           && !visited[row * cols + col] ? true : false;
}

int getDigitSum(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {

    return 0;
}