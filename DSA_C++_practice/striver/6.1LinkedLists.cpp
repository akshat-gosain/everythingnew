#include <bits/stdc++.h>
using namespace std;


void printVector(const std::vector<int>& vec) {
    for (int num : vec){
        cout << num << " ";}
        cout << std::endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }   

};

void printLL(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insert(int data, Node* next){
        Node* newNode = new Node(data, next);
        return newNode;
    }

Node* deleteLast(Node* head){
    // if(head == nullptr){
    //     return nullptr;
    // }
    // if(head->next == nullptr){
    //     delete head;
    //     return nullptr;
    // }
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    // delete temp->next;
    temp->next = nullptr;
    return head;
}


Node* insertAtEnd(int data, Node* head){
    Node* newNode = new Node(data);
    if(head == nullptr){
        return newNode;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int lengthLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
        }
    return count;
}

int checkLL(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// void deleteNode(ListNode* node) {
//     ListNode* temp = node->next;
//     node->val = temp->val;
//     node->next = temp->next;
//     delete temp;
// }

void deleteNode(Node* node, int key){
    Node* temp = node;
    Node* prev = nullptr;

    while(temp != nullptr && temp->data!=key){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
}

Node* middleNode(Node* head) {
        int n = lengthLL(head);
        for(int i=0; i<n/2; i++){
            head = head->next;
        }
        return head;

    }

Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool hasCycle(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    int carry = 0;
    while(l1!=nullptr || l2!=nullptr || carry){
        int sum = 0;
        if(l1!=nullptr){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2!=nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Cycle detected
            ListNode* meetingPoint = head;
            while (meetingPoint != slow) {
                meetingPoint = meetingPoint->next;
                slow = slow->next;
            }
            return meetingPoint; // Return the start of the cycle
        }
    }

    // No cycle found
    return nullptr;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    ListNode* next = nullptr;
    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    ListNode* first = head;
    ListNode* second = prev;
    while(second!=nullptr){
        if(first->val != second->val){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}

ListNode* mergeKlists(vector<ListNode*> &lists){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<lists.size(); i++){
        ListNode* temp = lists[i];
        while(temp!=nullptr){
            pq.push(temp->val);
            temp = temp->next;
        }
    }
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while(!pq.empty()){
        ListNode* newNode = new ListNode(pq.top());
        pq.pop();
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}

class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};

class AllOne{
    public:
    AllOne(){
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    void inc(string key){
        if(m.find(key) == m.end()){
            m[key] = new Node(0);
            m[key]->keys.insert(key);
            insert(m[key], head);
        }
        Node* curr = m[key];
        Node* next = curr->next;
        if(next == tail || next->val > curr->val+1){
            Node* newnode = new Node(curr->val+1);
            insert(newnode, curr);
        }
        next = curr->next;
        next->keys.insert(key);
        m[key] = next;
        curr->keys.erase(key);
        if(curr->keys.size() == 0){
            remove(curr);
        }
    }
    void dec(string key){
        if(m.find(key) == m.end()){
            return;
        }
        Node* curr = m[key];
        Node* prev = curr->prev;
        m.erase(key);
        if(curr->val > 1){
            if(curr == head || prev->val < curr->val-1){
                Node* newnode = new Node(curr->val-1);
                insert(newnode, prev);
            }
            prev = curr->prev;
            prev->keys.insert(key);
            m[key] = prev;
        }
        curr->keys.erase(key);
        if(curr->keys.size() == 0){
            remove(curr);
        }
    }
    string getMaxKey(){
        return tail->prev == head ? "" : *(tail->prev->keys.begin());
    
}
    string getMinKey(){
        return head->next == tail ? "" : *(head->next->keys.begin());
    }
    private:
    class Node{
        public:
        int val;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int val){
            this->val = val;
        }
    };
    Node* head;
    Node* tail;
    unordered_map<string, Node*> m;
    void insert(Node* newnode, Node* prev){
        Node* next = prev->next;
        newnode->next = next;
        newnode->prev = prev;
        prev->next = newnode;
        next->prev = newnode;
    }
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
    }
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* slow = dummy;
    ListNode* fast = dummy;
    for(int i=1; i<=n+1; i++){
        fast = fast->next;
    }
    while(fast!=nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* temp = dummy;
    while(temp->next!=nullptr && temp->next->next!=nullptr){
        ListNode* first = temp->next;
        ListNode* second = temp->next->next;
        first->next = second->next;
        temp->next = second;
        second->next = first;
        temp = first;
    }
    return dummy->next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode* reverseKgroup(ListNode* head, int k){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* begin = dummy;
    int i = 0;
    while(head!=nullptr){
        i++;
        if(i%k == 0){
            begin = reverse(begin, head->next);
            head = begin->next;
        } else {
            head = head->next;
        }
    }
    return dummy->next;

}

ListNode* reverse(ListNode* begin, ListNode* end){
    ListNode* prev = begin;
    ListNode* curr = begin->next;
    ListNode* first = curr;
    while(curr!=end){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    begin->next = prev;
    first->next = curr;
    return first;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* temp = dummy;
    while(temp->next!=nullptr && temp->next->next!=nullptr){
        if(temp->next->val == temp->next->next->val){
            int val = temp->next->val;
            while(temp->next!=nullptr && temp->next->val == val){
                temp->next = temp->next->next;
            }
        } else {
            temp = temp->next;
        }
    }
    return dummy->next;
}

ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    int n = 1;
    ListNode* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
        n++;
    }
    temp->next = head;
    k = k%n;
    k = n-k;
    while(k--){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}


/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

// /Sample Input 1 :
// 4
// 3
// 1 2 3
// 3
// 8 10 15
// 2
// 18 22
// 1
// 29

// Sample Output 1 :
//1 2 3 8 10 15 18 22 29

Node* flattenLinkedList(Node* head){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* last = temp;
    while(head!=last){
        if(head->child!=nullptr){
            temp->next = head->child;
            Node* temp1 = head->child;
            while(temp1->next!=nullptr){
                temp1 = temp1->next;
            }
            last = temp1;
        }
        head = head->next;
    }
    return head;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    Node* head = convertArr2LL(arr);
    // cout << head->data << endl;
    // deleteLast(head);

    // int m;
    // cin >> m;
    // deleteNode(head, m);

    printLL(reverseLL(head));
    // cout << lengthLL(head) << endl;

    // cout << middleNode(head)->data << endl;

    return 0;
}