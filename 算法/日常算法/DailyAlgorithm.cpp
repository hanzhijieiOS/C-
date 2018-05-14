//
//  DailyAlgorithm.cpp
//  c++
//
//  Created by 韩智杰 on 2018/4/21.
//  Copyright © 2018年 hahaha. All rights reserved.
//

#include "DailyAlgorithm.hpp"
#include <vector>
#include <map>
#include <algorithm>
/*两数之和*/
/*未完成*/
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i ++) {
            m[i] ++;
        }
        map<int, int>::iterator it = m.begin();
        while (it != m.end()) {
        //    int temp =
        }
        return result;
    }
};
