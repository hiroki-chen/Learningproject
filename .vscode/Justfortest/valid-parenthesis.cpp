#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> ans;
public:
    void backtrack(string tmp, int n, int left_p, int right_p){
        if(left_p == n && right_p == n){
            ans.push_back(tmp);
            return;
        }
        if(right_p > left_p || left_p > n || right_p > n) return;
        backtrack(tmp + '(', n, left_p + 1, right_p);
        backtrack(tmp + ')', n, left_p, right_p + 1);
        return ;
    }
    vector<string> generateParenthesis(int n) {
        string tmp;
        backtrack(tmp, n, 0, 0);
        return ans;
    }
};

int main(int argc, const char* argv[]){
    int n;
    cin>>n;
    Solution solution;
    vector<string> answer = solution.generateParenthesis(n);
    for(int i = 0; i < answer.size(); i++){
        cout<<answer[i]<<endl;
    }
}