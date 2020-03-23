#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(!s.size()) return 0;
        int max = 0;
        s = '$' + s;
        int l = s.size();
        vector<int> dp(l, 0);
        for(int i = 1; i < l; i++){
             if(s[i] == ')'){
                 if(s[i-1] == '('){
                      dp[i] = 2 + dp[i-2];
                 }
                 else if(s[i - 1 - dp[i-1]] == '(' && i - 1 - dp[i-1] >= 0){
                     dp[i] = 2 + dp[i-1] + dp[i - 2 - dp[i-1]]; 
                 }
             }
             max = dp[i] > max ? dp[i] : max;
         }
         return max;
    }
};

int main(int argc, const char* argv[]){
    Solution solution;
    string s;
    cin>>s;
    cout<<solution.longestValidParentheses(s)<<endl;
    return 0;
}