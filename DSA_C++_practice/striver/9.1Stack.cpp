#include<bits/stdc++.h>

using namespace std;
class Stack {
  int size;
  int * arr;
  int top;
  public:
    Stack() {
      top = -1;
      size = 1000;
      arr = new int[size];
    }
  void push(int x) {
    top++;
    arr[top] = x;
  }
  int pop() {
    int x = arr[top];
    top--;
    return x;
  }
  int Top() {
    return arr[top];
  }
  int Size() {
    return top + 1;
  }
};

int largestRectangleArea(vector<int> &heights){
  int n = heights.size();
  stack<int> st;
  vector<int> left(n, -1);
  vector<int> right(n, n);
  
  //left
  for(int i=0; i<n; i++){
    while(!st.empty() && heights[st.top()] >= heights[i]){
      st.pop();
    }
    if(!st.empty()){
      left[i] = st.top();
    }
    st.push(i);
  }

  while(!st.empty()){
    st.pop();
  }

  //right
  for(int i=n-1; i>=0; i--){
    while(!st.empty() && heights[st.top()] >= heights[i]){
      st.pop();
    }
    if(!st.empty()){
      right[i] = st.top();
    }
    st.push(i);
  }

  //area
  int maxArea = 0;
  for(int i=0; i<n; i++){
    maxArea = max(maxArea, heights[i]*(right[i]-left[i]-1));
  }
  return maxArea;

}



int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}