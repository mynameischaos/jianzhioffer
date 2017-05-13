//
// Created by 钟华松 on 17/5/13.
//

#include <stack>
#include <iostream>
using namespace std;

#ifndef Q9_TWOSTACKSTOQUEUE_QUEUE_H

template <typename T> class CQueue {
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

#define Q9_TWOSTACKSTOQUEUE_QUEUE_H

#endif //Q9_TWOSTACKSTOQUEUE_QUEUE_H

template <typename T> CQueue<T>::CQueue(void) {

};
template <typename T> CQueue<T>::~CQueue(void) {

};


template <typename T> void CQueue<T>::appendTail(const T& node) {
    stack1.push(node);
}

template <typename T>  T CQueue<T>::deleteHead() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T& node = stack1.top();
            stack1.pop();
            stack2.push(node);
        }
    }
    if (stack2.empty())
        cout << "queue is empty" << endl;
    else {
        T& head = stack2.top();
        stack2.pop();
        return head;
    }

};

