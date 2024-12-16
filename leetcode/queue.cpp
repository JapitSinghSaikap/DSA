#include <bits/stdc++.h>

using namespace std;

class MyQueue {
  public:
    stack < int > input, output;//one is there to store the elements top get them back
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
//   void push(int x) {
//     cout << "The element pushed is " << x << endl;
//     input.push(x);
//   }
void push(int x){
    while(input.size()){//jb tk ismein element hoga
        output.push(input.top());
        input.pop();
    }
    input.push(x);
    while(output.size()){
        input.push(output.top());
        output.pop();
    }
}

  /** Removes the element from in front of queue and returns that element. */
//   int pop() {
//     // shift input to output 
//     if (output.empty())
//       while (input.size())
//         output.push(input.top()), input.pop();

//     int x = output.top();
//     output.pop();
//     return x;
//   }
int pop(){
    int n = input.top();
    input.pop();
    return n;
}
  /** Get the front element. */
  int top(){
    int n=input.top();
    return n;
  }
//   int top() {
//     // shift input to output 
//     if (output.empty())
//       while (input.size())
//         output.push(input.top()), input.pop();
//     return output.top();
//   }

  int size() {
    return (output.size() + input.size()); 
  }

};
int main() {
  MyQueue q;
  q.push(3);
  q.push(4);
  cout << "The element poped is " << q.pop() << endl;
  q.push(5);
  cout << "The top of the queue is " << q.top() << endl;
  cout << "The size of the queue is " << q.size() << endl;

}