// 剑指 Offer 30. 包含 min 函数的栈
#include <stack>
using namespace std;

class MinStack {
    stack<int>* baseStack;
    stack<int>* minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        this->baseStack = new stack<int>();
        this->minStack = new stack<int>();
    }
    
    void push(int x) {
        baseStack->push(x);
        if (minStack->empty() || minStack->top() >= x) {
            minStack->push(x);
        }
    }
    
    void pop() {
        if ( baseStack->empty() ) {
            return;
        }
        if (baseStack->top() == minStack->top()) {
            minStack->pop();
        }
        baseStack->pop();
    }
    
    int top() {
        if ( baseStack->empty() ) {
            return 0;
        }
        return baseStack->top();
    }
    
    int min() {
        if ( minStack->empty() ) {
            return 0;
        }
        return minStack->top();
    }

    ~MinStack() {
        delete this->baseStack;
        delete this->minStack;
    }
};