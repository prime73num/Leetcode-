



#include <iostream>
#include <vector>
#include <stack>



class MyQueue {
  public:
    std::stack<int> stain;
    std::stack<int> staout;
    MyQueue() {
      stain = std::stack<int>();
      staout = std::stack<int>();
    }

    void push(int x) {
      stain.push(x);
    }

    int pop() {
      if(staout.empty()){
        while (!stain.empty()) {
          staout.push(stain.top());
          stain.pop();
        }
      }
      int res = staout.top();
      staout.pop();
      return res;
    }

    int peek() {
      if(staout.empty()){
        while (!stain.empty()) {
          staout.push(stain.top());
          stain.pop();
        }
      }
      int res = staout.top();
      return res;
    }

    bool empty() {
      return stain.empty() && staout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
