#include <iostream>
#include "Stack.h"


using namespace std;


void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main() {
    Stack<char> myStack;
    myStack.appendTail('a');
//    myStack.appendTail('b');
//    myStack.appendTail('c');

    char head = myStack.deleteHead();
    Test(head, 'a');

    myStack.appendTail('d');
    myStack.appendTail('e');
//    myStack.appendTail('f');

    char head2 = myStack.deleteHead();
    Test(head2, 'e');

    char head3 = myStack.deleteHead();
    Test(head3, 'd');

    char head4 = myStack.deleteHead();
    Test(head4, NULL);

    return 0;
}