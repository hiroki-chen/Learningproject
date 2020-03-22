//
//  main.cpp
//  f
//
//  Created by Mark on 2020/3/19.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int> &nums, int i, int j){
    if(i != j){ //如果传入就是i == j那么就是说明分割到了一个单位。
        int left = i;
        int right = j;
        int pivot = nums[left]; //初始值为某数组的最左边的数。
        while(left != right){
            while(left != right && nums[right] >= pivot) right--;
            if(left != right) nums[left++] = nums[right];
            while(left != right && nums[left] <= pivot) left++;
            if(left != right) nums[left] = nums[right--];
        }
        nums[left] = pivot;
        quicksort(nums, i, left - 1);
        quicksort(nums, left + 1, j);
    }
}

int main(int argc, const char* argv[]){
    vector<int> nums = {8,5,2,0,3,5,2};
    quicksort(nums, 0, 6);
    for(vector<int>::iterator i : nums) cout<<*i<<endl;
    return 0;
}
