







#include <iostream>
#include <vector>
#include <queue>


class MyStack {
  public:
    std::queue<int> q;
    std::queue<int> temp;
    MyStack() {
      q = std::queue<int>();
      temp = std::queue<int>();
    }

    void push(int x) {
      q.push(x);
    }

    int pop() {
      int size = q.size()-1;
      int count = size;
      while (count--) {
        temp.push(q.front());
        q.pop();
      }
      int res = q.front();
      q.pop();
      count = size;
      while (count--) {
        q.push(temp.front());
        temp.pop();
      }
      return res;
    }

    int top() {
      int size = q.size()-1;
      int count = size;
      while (count--) {
        temp.push(q.front());
        q.pop();
      }
      int res = q.front();
      q.pop();
      count = size;
      while (count--) {
        q.push(temp.front());
        temp.pop();
      }
      q.push(res);
      return res;
    }

    bool empty() {
      return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
