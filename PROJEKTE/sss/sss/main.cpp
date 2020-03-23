//
//  main.cpp
//  sss
//
//  Created by Mark on 2020/3/23.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int> tmp, int pos, int cnt){
        if(cnt == nums.size()){
            ans.push_back(tmp);
            tmp.clear();
            cnt = 0;
            return;
        }
        else{
            if(pos == nums.size() - 1){
                tmp.push_back(nums[pos]);
                solve(nums, tmp, 0, cnt++);
                tmp.pop_back();
            }
            else{
                tmp.push_back(nums[pos]);
                solve(nums, tmp, pos + 1, cnt++);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        solve(nums, tmp, 0, 0);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> digit = {1,2,3,4,5,6};
    vector<int> tmp;
    Solution s;
    s.solve(digit, tmp, 0, 0);
    for(int i = 0; i < s.ans.size(); i++){
        for(int j = 0; j < s.ans[0].size(); j++){
            cout<<s.ans[i][j]<<endl;
        }
    }
    return 0;
}
