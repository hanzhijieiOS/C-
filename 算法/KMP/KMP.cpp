//
//  KMP.cpp
//  c++
//
//  Created by 韩智杰 on 2018/4/15.
//  Copyright © 2018年 hahaha. All rights reserved.
//

#include "KMP.hpp"
#include <cstring>
#include <iostream>
using namespace std;

void get_next(char * data, int * next){
    unsigned int length = (int)strlen(data);
    next[0] = 0; next[1] = 0;
    int p = 0;
    for (int i = 2; i <= length; i ++) {
        while (p != 0 && data[i - 1] != data[p]) {
            p = next[p];
        }
        if (data[i - 1] == data[p]) {
            p ++;
        }
        next[i] = p;
    }
}

void KMP(char * parent, char * child, int * next){
    int c_length = (int)strlen(child);
    int p_length = (int)strlen(parent);
    int c_ptr = 0, p_ptr = 0;
    while (p_ptr < p_length) {
        if (child[c_ptr] == parent[p_ptr]) {
            c_ptr ++;
            p_ptr ++;
            if (c_ptr == c_length) {
                cout << "Find position is " << p_ptr - c_ptr << endl;
                c_ptr = next[c_ptr];
            }
        }else{
            if (c_ptr == 0) {
                p_ptr ++;
            }else{
                c_ptr = next[c_ptr];
            }
        }
    }
}
