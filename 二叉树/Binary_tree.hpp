//
//  Binary_tree.hpp
//  c++
//
//  Created by 韩智杰 on 2018/4/12.
//  Copyright © 2018年 hahaha. All rights reserved.
//

#ifndef Binary_tree_hpp
#define Binary_tree_hpp

#include <stdio.h>

#endif /* Binary_tree_hpp */

typedef struct node{
    struct node * Lchild;
    struct node * Rchild;
    char data;
}BiTree;

void creat_binary_tree(BiTree **);

void preface_traverse(BiTree *);

void preface_traverse_stack(BiTree *);

void order_traverse(BiTree *);

void order_traverse_stack(BiTree *);

void last_traverse(BiTree *);

void last_traverse_stack(BiTree *);

void level_traverse(BiTree *);

void mirror_binary_tree(BiTree *);

void creatBST(BiTree **);
