//
//  Permutation.cpp
//  c++
//
//  Created by 韩智杰 on 2018/5/13.
//  Copyright © 2018年 hahaha. All rights reserved.
//

#include "Permutation.hpp"
#include <iostream>
using namespace std;

void Permutation(char * str, char * pBegin){
    if (*pBegin == '\0') {
        cout << str << " ";
    }else{
        for (char * ch = pBegin; *ch != '\0'; ch ++) {
            swap(*ch, *pBegin);
            Permutation(str, pBegin + 1);
            swap(*ch, *pBegin);
        }
    }
    
}

void Permutation(char * str){
    if (str == NULL) {
        return;
    }
    Permutation(str, str);
}


