#include <stack>

class MyQueue {
public:
    // properties
    stack<int> one;
    stack<int> two;
    
    // constructor
    MyQueue() {}
    // pushing all elmnts in one stack only
    void push(int x) { one.push(x); }
    // when popping then stack reversal and then pop
    int pop() {
        if(two.empty()){
            while(!one.empty()){
                two.push(one.top());
                one.pop();
            }
        }
        int ans = two.top();
        two.pop();
        return ans;
    }
    int peek() {
        if(two.empty()){
            while(!one.empty()){
                two.push(one.top());
                one.pop();
            }
        }
        int ans = two.top();
        return ans;
    }

    bool empty() { return one.empty() && two.empty(); }
};
