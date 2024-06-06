#ifndef HEADER_H
#define HEADER_H
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
#endif