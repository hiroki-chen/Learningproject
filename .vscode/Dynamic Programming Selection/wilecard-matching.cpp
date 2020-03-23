#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1;
        int n = p.size() + 1;
        vector<vector<bool> > dp(m, vector<bool>(n, 0));
        dp[0][0] = 1;
        for(int j = 1; j < n; j++){
            if(p[j-1] == '*') dp[0][j] = 1;
            else break;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(p[j-1] == '?' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1]; //数组下标的1对应字符串的下标0
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1]; //如果前方匹配了的话，对于s来说后面加上什么东西都是没关系的了，关键在于带有星号的时候的初始状态是什么。
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char* argv[]){
    string s, p;
    cin>>s>>p;
    Solution solution;
    cout<<solution.isMatch(s, p)<<endl;
    return 0;
}