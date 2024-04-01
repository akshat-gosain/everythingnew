#include<bits/stdc++.h>

using namespace std;
class Queue {
  int * arr;
  int start, end, currSize, maxSize;
  public:
    Queue() {
      arr = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }

  Queue(int maxSize) {
    ( * this).maxSize = maxSize;
    arr = new int[maxSize];
    start = -1;
    end = -1;
    currSize = 0;
  }
  void push(int newElement) {
    if (currSize == maxSize) {
      cout << "Queue is full\nExiting..." << endl;
      exit(1);
    }
    if (end == -1) {
      start = 0;
      end = 0;
    } else {
      end = (end + 1) % maxSize;}
    arr[end] = newElement;
    cout << "The element pushed is " << newElement << endl;
    currSize++;
  }
  int pop() {
    if (start == -1) {
      cout << "Queue Empty\nExiting..." << endl;
    }
    int popped = arr[start];
    if (currSize == 1) {
      start = -1;
      end = -1;
    } else
      start = (start + 1) % maxSize;
    currSize--;
    return popped;
  }
  int top() {
    if (start == -1) {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }
  int size() {
    return currSize;
  }

};


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator{
  public:
  NestedIterator(vector<NestedInteger> &nestedList){
    for(int i=nestedList.size()-1; i>=0; i--){
      st.push(nestedList[i]);
    }
  }
  int next(){
    NestedInteger t = st.top();
    st.pop();
    return t.getInteger();
  }
  bool hasNext(){
    while(!st.empty()){
      NestedInteger t = st.top();
      if(t.isInteger()){
        return true;
      }
      st.pop();
      for(int i=t.getList().size()-1; i>=0; i--){
        st.push(t.getList()[i]);
      }
    }
    return false;
  }
};

class MyCircularQueue{
  int * arr;
  int front, rear, size;
  bool isFull(){
    return (rear+1)%size == front;
  }
  bool isEmpty(){
    return front == -1;
  }
  public:
  MyCircularQueue(int k){
    size = k;
    arr = new int[size];
    front = -1;
    rear = -1;
  }
  bool enQueue(int value){
    if(isFull()){
      return false;
    }
    if(isEmpty()){
      front = 0;
    }
    rear = (rear+1)%size;
    arr[rear] = value;
    return true;
  }
  bool deQueue(){
    if(isEmpty()){
      return false;
    }
    if(front == rear){
      front = -1;
      rear = -1;
      return true;
    }
    front = (front+1)%size;
    return true;
  }
  int Front(){
    if(isEmpty()){
      return -1;
    }
    return arr[front];
  }
};

int shortestSubarray(vector<int> &A, int K){
  int n = A.size();
  vector<long> prefix(n+1, 0);
  for(int i=0; i<n; i++){
    prefix[i+1] = prefix[i] + A[i];
  }
  deque<int> dq;
  int ans = n+1;
  for(int i=0; i<=n; i++){
    while(!dq.empty() && prefix[i] - prefix[dq.front()] >= K){
      ans = min(ans, i-dq.front());
      dq.pop_front();
    }
    while(!dq.empty() && prefix[i] <= prefix[dq.back()]){
      dq.pop_back();
    }
    dq.push_back(i);
  }
  return ans == n+1 ? -1 : ans;
}

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}