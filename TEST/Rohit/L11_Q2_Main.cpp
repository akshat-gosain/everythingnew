// #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <queue>
#include "header.h"
#include "./L11_Q2_2022A7PS0157G.cpp"
using namespace std;

Node *constructTree(vector<int> &arr)
{
    if (arr.empty() || arr[0] == -1)
        return nullptr;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> inp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> inp[i];
        }
        Node *root = constructTree(inp);
        cout << solve(root);
        cout << endl;
    }

    return 0;
}
