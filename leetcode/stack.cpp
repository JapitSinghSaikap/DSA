
// Implementation of stack using queue
#include <bits/stdc++.h>

using namespace std;

class Stack
{
  // a queue data structure
  queue<int> q;

public:
  void Push(int x)
  {
    int s = q.size();
    q.push(x);
    for (int i = 0; i < s; i++)
    {
      q.push(q.front());
      q.pop();
    }
  }
  int Pop()
  {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top()
  {
    return q.front();
  }
  int Size()
  {
    return q.size();
  }
};

// Stack using array
class StackArr
{
  int arr[1000];
  int top;

public:
  StackArr() { top = -1; }
  void push(int x)
  {
    if (top < 999)
      arr[++top] = x;
  }
  int pop()
  {
    if (top == -1)
      return -1;
    return arr[top--];
  }
  int peek()
  {
    if (top == -1)
      return -1;
    return arr[top];
  }
  bool empty() { return top == -1; }
  int size() { return top + 1; }
};

// Stack using STL
void stlStackDemo()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout << "STL stack top: " << s.top() << endl;
  s.pop();
  cout << "STL stack size: " << s.size() << endl;
}

// Delete middle element
void deleteMiddle(stack<int> &s)
{
  int n = s.size();
  int mid = n / 2;
  vector<int> temp;
  for (int i = 0; i < n; ++i)
  {
    int x = s.top();
    s.pop();
    if (i != mid)
      temp.push_back(x);
  }
  for (int i = temp.size() - 1; i >= 0; --i)
    s.push(temp[i]);
}

// String reversal using stack
string reverseStr(const string &str)
{
  stack<char> s;
  for (char c : str)
    s.push(c);
  string res;
  while (!s.empty())
  {
    res += s.top();
    s.pop();
  }
  return res;
}
}


// String reversal using stack
string reverseStr(const string &str)
{
  stack<char> s;
  for (char c : str)
    s.push(c);
  string res;
  while (!s.empty())
  {
    res += s.top();
    s.pop();
  }
  return res;
}

// Min stack (get min in O(1))
class MinStack
{
  stack<int> s, minS;

public:
  void push(int x)
  {
    s.push(x);
    if (minS.empty() || x <= minS.top())
      minS.push(x);
  }
  void pop()
  {
    if (s.top() == minS.top())
      minS.pop();
    s.pop();
  }
  int top() { return s.top(); }
  int getMin() { return minS.top(); }
};

int main()
{
  // Stack using queue
  Stack s;
  s.Push(3);                                                                 // 3
  s.Push(2);                                                                 // 3,2
  s.Push(4);                                                                 // 3,2,4
  s.Push(1);                                                                 // 3,2,4,1
  cout << "Top of the stack: " << s.Top() << endl;                           // 1
  cout << "Size of the stack before removing element: " << s.Size() << endl; // 4
  cout << "The deleted element is: " << s.Pop() << endl;                     // 1 LIFO principle
  cout << "Top of the stack after removing element: " << s.Top() << endl;    // 4
  cout << "Size of the stack after removing element: " << s.Size() << endl;  // 3

  // Stack using array
  StackArr sa;
  sa.push(5);
  sa.push(7);
  sa.push(9);
  cout << "Array stack top: " << sa.peek() << endl;
  sa.pop();
  cout << "Array stack size: " << sa.size() << endl;

  // STL stack
  stlStackDemo();

  // Min stack
  MinStack ms;
  ms.push(4);
  ms.push(2);
  ms.push(5);
  ms.push(1);
  cout << "Min stack min: " << ms.getMin() << endl;
  ms.pop();
  cout << "Min stack min after pop: " << ms.getMin() << endl;
}