// #include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <queue>
#include "header.h"
using namespace std;


int maxm = 0;
void countNodes(Node* root, int &cnt){
    if(root == NULL){
        return;
    }
    cnt++;
    countNodes(root->left, cnt);
    countNodes(root->right, cnt);
}

bool checkValid(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    return checkValid(root->left, min, root->data) && checkValid(root->right, root->data, max);
}

int solve(Node *root)
{
    if(root == NULL){
        return maxm;
    }
    if(checkValid(root, INT_MIN, INT_MAX) == true){
        int cnt = 0;
        countNodes(root, cnt);
        maxm = max(maxm, cnt);
    }
    else{
        solve(root->left);
        solve(root->right);
    }
}
