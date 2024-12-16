#include <bits/stdc++.h>
#include<iostream>


using namespace std;

class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int minn;
      if (st.empty()) {
        min = x;
      } else {
        minn = min(st.top().second, x);
      }
      st.push({x,minn});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

int main(){
    MinStack stk;
}