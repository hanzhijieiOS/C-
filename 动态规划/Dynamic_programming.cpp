//
//  Dynamic_programming.cpp
//  c++
//
//  Created by 韩智杰 on 2018/4/12.
//  Copyright © 2018年 hahaha. All rights reserved.
//

#include "Dynamic_programming.hpp"
#include <iostream>
#include <map>
#define K_COUNT 9
#define K_WEIGHT 15

#define K_MAXLENGTH 100
using namespace std;

/* 0-1背包 */
void backpack(){
    int weight[] = {0,1,5,8,3,4,7,2,6,9}; //物品重量(下标从1开始)
    int value[] = {0,4,1,6,8,7,2,9,3,5};  //物品价值(下标从1开始)
    int dpArray[K_COUNT + 1][K_WEIGHT + 1] = {0}; //dpArray[i][j]表示i个物品放入质量为j的背包中的最优解
    for (int i = 1; i <= K_COUNT; i ++) {
        for (int j = 1; j <= K_WEIGHT; j ++) {
            if (j < weight[i]) {
                dpArray[i][j] = dpArray[i - 1][j];
            }else{
                dpArray[i][j] = max(dpArray[i - 1][j], dpArray[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dpArray[K_COUNT][K_WEIGHT] << endl;
}

/*最长公共子串*/
void longest_common_substring(){
    char string[] = {'0','a','b','c','d','e','f','g','h'};
    char anotherString[] = {'0','d','e','f','g','h','i','j','k'};
    int data[10][10] = {0};
    for (int i = 1; i < 9; i ++) {
        for (int j = 1; j < 9; j ++) {
            if (string[i] == anotherString[j]) {
                data[i][j] = data[i - 1][j - 1] + 1;
            }else{
                data[i][j] = 0;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            result = max(result, data[i][j]);
        }
    }
    cout << result << endl;
}

/*最长公共子序列*/

void longest_common_subsequence(){
    char string[] = {'0','a','w','c','x','e','y','g','z'};
    char anotherString[] = {'0','a','b','c','d','e','f','g','h'};
    int data[10][10] = {0};
    for (int i = 1; i < 9; i ++) {
        for (int j = 1; j < 9; j ++) {
            if (string[i] == anotherString[j]) {
                data[i][j] = data[i - 1][j - 1] + 1;
            }else{
                data[i][j] = max(data[i - 1][j], data[i][j - 1]);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            result = max(result, data[i][j]);
        }
    }
    cout << result << endl;
}

/*最优子串(尺取)*/
/*求出包含'x','y','3','g'的最短子串的长度*/

void shortest_substring(){
    char data[] = "Ifromxiyou3gclass";
    map<char,int> m = {
        {'x',0},
        {'y',0},
        {'3',0},
        {'g',0}
    };
    int num = 0;
    int head = 0, tail = 0;
    int result = INT_MAX;
    while (true) {
        while (num < 4 && head < strlen(data)) {
            if (data[head] == 'x' || data[head] == 'y' || data[head] == '3' || data[head] == 'g') {
                if (m[data[head]] ++== 0) {
                    num ++;
                }
            }
            head ++;
        }
        if (num < 4) {
            break;
        }
        result = min(result, head - tail);
        if (data[tail] == 'x' || data[tail] == 'y' || data[tail] == '3' || data[tail] == 'g') {
            m[data[tail]] --;
            if (m[data[tail]] == 0) {
                num --;
            }
        }
        tail ++;
    }
    cout << result << endl;
}





