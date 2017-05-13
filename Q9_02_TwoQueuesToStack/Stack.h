//
// Created by 钟华松 on 17/5/13.
//

#include <queue>
#include <iostream>
using namespace std;

#ifndef Q9_02_TWOQUEUESTOSTACK_STACK_H
template <typename T> class Stack {
private:
    queue<T> queue1;
    queue<T> queue2;

public:
    Stack(void);
    ~Stack(void);
    T deleteHead();
    void appendTail(const T& node);
};
#define Q9_02_TWOQUEUESTOSTACK_STACK_H

#endif //Q9_02_TWOQUEUESTOSTACK_STACK_H

template <typename T> Stack<T>::Stack() {

}

template <typename T> Stack<T>::~Stack() {

}

template <typename T> void Stack<T>::appendTail(const T &node) {
    queue1.push(node);
}

template <typename T> T Stack<T>::deleteHead() {
    if (!queue1.empty()) {
        while (queue1.size() > 1) {
            T& data = queue1.front();
            queue1.pop();
            queue2.push(data);
        }
        T& data = queue1.front();
        queue1.pop();
        return data;
    } else {
        if (queue2.empty()) {
            cout << "don't have elements" << endl;
            return NULL;
        }
        else {
            while(!queue2.empty()) {
                T& data = queue2.front();
                queue2.pop();
                queue1.push(data);
            }
            while (queue1.size() > 1) {
                T& data = queue1.front();
                queue1.pop();
                queue2.push(data);
            }
            T& data = queue1.front();
            queue1.pop();
            return data;
        }
    }
}