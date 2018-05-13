//
//  SortFile.cpp
//  c++
//
//  Created by 韩智杰 on 2018/4/11.
//  Copyright © 2018年 hahaha. All rights reserved.
//

#include "SortFile.hpp"
#include <iostream>

using namespace std;

void quick_sort(int * data, int low, int high){
    int left = low, right = high;
    int temp = data[low];
    while (left < right) {
        while (left < right && data[right] > temp) {
            right --;
        }
        if (left < right) {
            swap(data[right], data[left ++]);
        }
        while (left < right && data[left] < temp) {
            left ++;
        }
        if (left < right) {
            swap(data[right --], data[left]);
        }
    }
    data[left] = temp;
    if (left > low) {
        quick_sort(data, low, left - 1);
    }
    if (right < high) {
        quick_sort(data, right + 1, high);
    }
}

void quick_sort(int * data, int count){
    quick_sort(data, 0, count - 1);
}

void bubble_sort(int * data, int count){
    for (int i = 0; i < count - 1; i ++) {
        for (int j = 0; j < count - i - 1; j ++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void select_sort(int * data, int count){
    for (int i = 0; i < count; i ++) {
        int position = i;
        for (int j = 1 + i; j < count; j ++) {
            if (data[position] > data[j]) {
                position = j;
            }
        }
        swap(data[i], data[position]);
    }
}

void pullDown(int * data, int position, int count){
    int child;
    for (int i = position; i * 2 + 1 < count; i = child) {
        child = i * 2 + 1;
        if (child < count - 1 && data[child] < data[child + 1]) {
            child ++;
        }
        if (data[child] > data[i]) {
            swap(data[child], data[i]);
        }else{
            break;
        }
    }
}

void heap_sort(int * data, int count){
    for (int i = count / 2 - 1; i >= 0; i --) {
        pullDown(data, i, count);
    }
    for (int i = count - 1; i > 0; i --) {
        swap(data[0], data[i]);
        pullDown(data, 0, i);
    }
}

void insert_sort(int * data, int count){
    for (int i = 1; i < count; i ++) {
        int j = i - 1, temp = data[i];
        for (j = i - 1; j >= 0 && data[j] > temp; j --) {
            data[j + 1] = data[j];
        }
        data[++ j] = temp;
    }
}

void shell_sort(int * data, int count){
    for (int group = count / 2; group > 0; group /= 2) {
        for (int i = group; i < count; i ++) {
            int temp = data[i];
            int j = i - group;
            for (j = i - group; j >= 0 && data[j] > temp; j -= group) {
                data[j + group] = data[j];
            }
            data[j + group] = temp;
        }
    }
}

void merge_sort(int * data, int left, int mid, int right, int * temp){
    int i = left, j = mid;
    int x = mid + 1, y = right;
    int temp_ptr = 0;
    while (i <= j && x <= y) {
        if (data[i] < data[x]) {
            temp[temp_ptr ++] = data[i ++];
        }else{
            temp[temp_ptr ++] = data[x ++];
        }
    }
    while (i <= j) {
        temp[temp_ptr ++] = data[i ++];
    }
    while (x <= y) {
        temp[temp_ptr ++] = data[x ++];
    }
    for (int i = 0; i < temp_ptr; i ++) {
        data[i + left] = temp[i];
    }
}

void merge_sort(int * data, int first, int end, int * temp){
    if (first < end) {
        int mid = (first + end) / 2;
        merge_sort(data, first, mid, temp);
        merge_sort(data, mid + 1, end, temp);
        merge_sort(data, first, mid, end, temp);
    }
}
