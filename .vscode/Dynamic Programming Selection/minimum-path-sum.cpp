#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); //初始化
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j== 0) dp[0][0] = grid[0][0];
                else if(i == 0 && j != 0) dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(i != 0 && j == 0) dp[i][j] = grid[i][j] + dp[i-1][j];
                else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char* argv[]){
    //...insert whatever you like.
    return 0;
}