#include <stack>
#include <iostream>
using namespace std;

// 剑指 Offer 09. 用两个栈实现队列

class CQueue {
    stack<int>* tailStack;
    stack<int>* headStack;
public:
    CQueue() {
        tailStack = new stack<int>();
        headStack = new stack<int>();
    }
    
    void appendTail(int value) {
        tailStack->push(value);
    }
    
    int deleteHead() {
        if ( headStack->empty() ) {
            while( !tailStack->empty() ) {
                headStack->push( tailStack->top() );
                tailStack->pop();
            }
        }
        if ( headStack->empty() ) {
            return -1;
        }
        else {
            int tempt = headStack->top();
            headStack->pop();
            return tempt;
        }
    }

    ~CQueue() noexcept {
        delete tailStack;
        delete headStack;
    }
};