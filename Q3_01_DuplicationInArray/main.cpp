#include <iostream>
#include <vector>
#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif
using namespace std;

// 排序 O(nlgn)
int fun1(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] == vec[i + 1])
            return vec[i];
    }
    return -1;  // 未找到
}

// 哈希 O(n), O(n)的空间复杂度
int fun2(vector<int>& vec) {
    using namespace __gnu_cxx;
    hash_map<int, int> table;
    for (int i : vec) {
        if (table.find(i) != table.end()) {
            return i;
        } else {
            table[i] = i;
        }

    }
    return -1;
}

// O(n), O(1)的空间复杂度
int fun3(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        while(1) {
            if (i != vec[i]) {
                if (vec[i] == vec[vec[i]]) {
                    return vec[i];
                } else {
                    int tmp = vec[i];
                    vec[vec[i]] = tmp;
                    vec[i] = vec[vec[i]];
                }
            } else {
                break;
            }
        }
    }
    return -1;
}
int main() {
    int arr[] = {0, 1, 2, 2, 3, 4, 5};
    vector<int> vec(arr, arr + 7);
    cout << fun1(vec) << endl;
    cout << fun2(vec) << endl;
    cout << fun3(vec) << endl;
    return 0;
}