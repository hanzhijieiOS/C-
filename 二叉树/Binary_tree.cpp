//
//  Binary_tree.cpp
//  c++
//
//  Created by 韩智杰 on 2018/4/12.
//  Copyright © 2018年 hahaha. All rights reserved.
//

#include "Binary_tree.hpp"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void creat_binary_tree(BiTree ** root){
    char data;
    cin >> data;
    if (data != '*') {
        *root = (BiTree *)malloc(sizeof(BiTree));
        (*root)->data = data;
        creat_binary_tree(&((*root)->Lchild));
        creat_binary_tree(&((*root)->Rchild));
    }else{
        *root = NULL;
    }
}

void preface_traverse(BiTree * root){
    if (root) {
        cout << root->data << " ";
        preface_traverse(root->Lchild);
        preface_traverse(root->Rchild);
    }
}

void preface_traverse_stack(BiTree * root){
    BiTree * temp = root;
    stack<BiTree *> s;
    while (!s.empty() || temp) {
        while (temp) {
            cout << temp->data << " ";
            s.push(temp);
            temp = temp->Lchild;
        }
        if (!s.empty()) {
            temp = s.top();
            s.pop();
            temp = temp->Rchild;
        }
    }
}

void order_traverse(BiTree * root){
    if (root) {
        order_traverse(root->Lchild);
        cout << root->data << " ";
        order_traverse(root->Rchild);
    }
}

void order_traverse_stack(BiTree * root){
    BiTree * temp = root;
    stack<BiTree *> s;
    while (!s.empty() || temp) {
        while (temp) {
            s.push(temp);
            temp = temp->Lchild;
        }
        if (!s.empty()) {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->Rchild;
        }
    }
}

void last_traverse(BiTree * root){
    if (root) {
        last_traverse(root->Lchild);
        last_traverse(root->Rchild);
        cout << root->data << " ";
    }
}

void last_traverse_stack(BiTree * root){
    BiTree * temp = root;
    BiTree * last_ptr = NULL;
    stack<BiTree *> s;
    while (!s.empty() || temp) {
        while (temp) {
            s.push(temp);
            temp = temp->Lchild;
        }
        if (!s.empty()) {
            temp = s.top();
            if (temp->Rchild == NULL || temp->Rchild == last_ptr) {
                cout << temp->data << " ";
                s.pop();
                last_ptr = temp;
                temp = NULL;
            }else{
                temp = temp->Rchild;
            }
        }
    }
}

void level_traverse(BiTree * root){
    BiTree * temp = root;
    queue<BiTree *> q;
    q.push(temp);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->Lchild) {
            q.push(temp->Lchild);
        }
        if (temp->Rchild) {
            q.push(temp->Rchild);
        }
    }
}

void mirror_binary_tree(BiTree * root){
    BiTree * temp = root;
    if (!temp) {
        return;
    }
    if (temp->Lchild || temp->Rchild) {
        swap(temp->Lchild, temp->Rchild);
    }
    if (temp->Lchild) {
        mirror_binary_tree(temp->Lchild);
    }
    if (temp->Rchild) {
        mirror_binary_tree(temp->Rchild);
    }
}

void insertBST(BiTree ** bst, char data){
    BiTree * node;
    if (*bst == NULL) {
        node = (BiTree *)malloc(sizeof(BiTree));
        node->Lchild = NULL;
        node->Rchild = NULL;
        node->data = data;
        *bst = node;
    }else if (data < (*bst)->data){
        insertBST(&(*bst)->Lchild, data);
    }else{
        insertBST(&(*bst)->Rchild, data);
    }
}

void creatBST(BiTree ** node){
    char data;
    *node = NULL;
    cin >> data;
    while (data != '*') {
        insertBST(node, data);
        cin >> data;
    }
}
