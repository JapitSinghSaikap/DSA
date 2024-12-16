//Implementation of stack using queue
#include<bits/stdc++.h>

using namespace std;

class Stack {
    //a queue data structure
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      for (int i = 0; i < s; i++) {
        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};

int main() {
  Stack s;
  s.Push(3);//3
  s.Push(2);//3,2
  s.Push(4);//3,2,4
  s.Push(1);//3,2,4,1
  cout << "Top of the stack: " << s.Top() << endl;//1
  cout << "Size of the stack before removing element: " << s.Size() << endl;//4
  cout << "The deleted element is: " << s.Pop() << endl;//1 LIFO principle
  cout << "Top of the stack after removing element: " << s.Top() << endl;//4
  cout << "Size of the stack after removing element: " << s.Size();//3

}