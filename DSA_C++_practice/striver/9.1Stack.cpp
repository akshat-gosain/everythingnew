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

int trap(vector<int> &height){
  int n = height.size();
  if(n == 0){
    return 0;
  }
  stack<int> st;
  int ans = 0;
  for(int i=0; i<n; i++){
    while(!st.empty() && height[st.top()] < height[i]){
      int curr = st.top();
      st.pop();
      if(st.empty()){
        break;
      }
      int diff = i - st.top() - 1;
      ans += (min(height[st.top()], height[i]) - height[curr]) * diff;
    }
    st.push(i);
  }
  return ans;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
      int n = nums.size();
      int m = nums1.size();
      vector <int> nge(n, -1);
      stack <int> st;
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }
        if (!st.empty()) nge[i] = st.top();
        st.push(nums[i % n]);
        }

        vector<int> res;
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(nums1[i]==nums[j]) {
            res.push_back(nge[j]);
            break;
            }
        }
    }
      return res;
    }


vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> nge(n, -1);
        stack <int> st;

        for (int i = 2*n-1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        if (!st.empty()) nge[i%n] = st.top();
        st.push(nums[i % n]);
        }

        return nge;
    }

    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans = max(ans, i-st.top());
                }
            }
        }
        return ans;
    }

    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        for(int i=0; i<n; i++){
            string dir = "";
            while(i<n && path[i]!='/'){
                dir += path[i];
                i++;
            }
            if(dir == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }else if(dir != "." && dir != ""){
                st.push(dir);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans == ""){
            return "/";
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0){
            return 0;
        }
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }else{
                    height[j] += 1;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }

    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> count(26, 0);
        vector<int> visited(26, 0);
        for(char c: s){
            count[c-'a']++;
        }
        for(char c: s){
            count[c-'a']--;
            if(visited[c-'a']){
                continue;
            }
            while(!st.empty() && st.top() > c && count[st.top()-'a']>0){
                visited[st.top()-'a'] = 0;
                st.pop();
            }
            st.push(c);
            visited[c-'a'] = 1;
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        for(int i=0; i<=k; i++){
            if(i>n || k-i>m){
                continue;
            }
            vector<int> temp = merge(maxArray(nums1, i), maxArray(nums2, k-i));
            if(compare(temp, 0, ans, 0)){
                ans = temp;
            }
        }
        return ans;
    } 

    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c: num){
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            if(!st.empty() || c!='0'){
                st.push(c);
            }
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }

    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right = st.top();
            }
            curr->left = nullptr;
        }
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