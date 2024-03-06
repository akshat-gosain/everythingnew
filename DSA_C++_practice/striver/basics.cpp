#include <bits/stdc++.h>
using namespace std;


void explainPair(){
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {3, 4}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[0].first << " " << arr[0].second << endl;
    cout << arr[1].first << " " << arr[1].second << endl;
}

void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.emplace_back(3);
    v.emplace_back(4);
    

    cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    cout << v.at(2) << endl;
    cout << v.back() << endl;
    cout << v.front() << endl;
    cout << v.size() << endl;
    
    

    vector<pair<int, int>> v_p = {{1, 2}, {2, 5}, {5, 1}};
    cout << v_p[0].first << " " << v_p[0].second << endl;
    cout << v_p[1].first << " " << v_p[1].second << endl;

    v_p.push_back({1,2});
    cout << v_p[3].first << " " << v_p[3].second << endl;
    cout << v_p.capacity() << endl;
    cout << v_p.max_size() << endl;

    vector<int> v1(10, 2);
    cout << v1[1] << endl;
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    cout << v1.max_size() << endl;

    vector<int> v2(10);
    cout << v2.size() << endl;
    cout << v2.capacity() << endl;
    cout << v2.max_size() << endl;

    vector<int> v3{1, 2, 3, 4, 5};
    cout << v3.size() << endl;
    cout << v3.capacity() << endl;
    cout << v3.max_size() << endl;

    vector<int> v4(v1);
    cout << v4[1] << endl;
}

//max heap using priority queue
void printpriorityqueue(priority_queue<int> pq)
{
    priority_queue<int> pq2=pq;
    while(!pq.empty())
    {
        cout<<pq.top()<<"\n";
        pq.pop();
    }
}

//min heap using priority queue
void printpriorityqueuemin(priority_queue<int,vector<int>,greater<int>> pq)
{
    priority_queue<int,vector<int>,greater<int>> pq2=pq;
    while(!pq.empty())
    {
        cout<<pq.top()<<"\n";
        pq.pop();
    }
}



int main(){
    
    explainPair();
    explainVector();



    priority_queue<int> pqr;
    for(int i=1;i<=5;i++)
    pqr.push(i);
    
    cout<<"The elements of the priority queue are:"<<endl;
    printpriorityqueue(pqr);
    
    cout<<"The size of the priority queue: "<<pqr.size()<<endl;
    cout<<"The top element of the priority queue: "<<pqr.top()<<endl;
    cout<<"Pop the top element: "<<endl;
    pqr.pop();
    printpriorityqueue(pqr);



    priority_queue<int,vector<int>,greater<int>> pqs;
    for(int i=1;i<=5;i++)
    pqs.push(i);
    
    cout<<"The elements of the priority queue are:"<<endl;
    printpriorityqueuemin(pqs);
    
    cout<<"The size of the priority queue: "<<pqs.size()<<endl;
    cout<<"The top element of the priority queue: "<<pqs.top()<<endl;
    cout<<"Pop the top element: "<<endl;
    pqs.pop();
    printpriorityqueuemin(pqs);




    map < int, int > mp;
  for (int i = 1; i <= 5; i++) {
    mp.insert({i , i * 10});
  }

  cout << "Elements present in the map: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;
  }

  int n = 2;
  if (mp.find(2) != mp.end())
    cout << n << " is present in map" << endl;

  mp.erase(mp.begin());
  cout << "Elements after deleting the first element: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;
  }

  cout << "The size of the map is: " << mp.size() << endl;

  if (mp.empty() == false)
    cout << "The map is not empty " << endl;
  else
    cout << "The map is empty" << endl;
  mp.clear();
  cout << "Size of the map after clearing all the elements: " << mp.size();

    set < int > s;
  for (int i = 1; i <= 10; i++) {
    s.insert(i);
  }

  cout << "Elements present in the set: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;
  int n = 2;
  if (s.find(2) != s.end())
    cout << n << " is present in set" << endl;

  s.erase(s.begin());
  cout << "Elements after deleting the first element: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;

  cout << "The size of the set is: " << s.size() << endl;

  if (s.empty() == false)
    cout << "The set is not empty " << endl;
  else
    cout << "The set is empty" << endl;
  s.clear();
  cout << "Size of the set after clearing all the elements: " << s.size();

    return 0;
   
}

// int main() {
//   unordered_multimap < int, int > mp;
//   for (int i = 1; i <= 5; i++) {
//     mp.insert({i , i * 10});
//   }
//   mp.insert({4,40});

//   cout << "Elements present in the unordered multimap: " << endl;
//   cout << "Key\tElement" << endl;
//   for (auto it = mp.begin(); it != mp.end(); it++) {
//     cout << it -> first << "\t" << it -> second << endl;
//   }

//   int n = 2;
//   if (mp.find(2) != mp.end())
//     cout << n << " is present in unordered multimap" << endl;

//   mp.erase(mp.begin());
//   cout << "Elements after deleting the first element: " << endl;
//   cout << "Key\tElement" << endl;
//   for (auto it = mp.begin(); it != mp.end(); it++) {
//     cout << it -> first << "\t" << it -> second << endl;
//   }

//   cout << "The size of the unordered multimap is: " << mp.size() << endl;

//   if (mp.empty() == false)
//     cout << "The unordered multimap is not empty " << endl;
//   else
//     cout << "The unordered multimap is empty" << endl;
//   mp.clear();
//   cout << "Size of the unordered multimap after clearing all the elements: " 
//   << mp.size();
// }