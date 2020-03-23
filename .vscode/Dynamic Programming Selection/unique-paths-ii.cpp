#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else{
                    if(i == 0 && j == 0) dp[i][j] = 1;
                    else if(i == 0) dp[i][j] = dp[i][j-1];
                    else if(j == 0) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char* argv[]){
    Solution solution;
    int m, n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    matrix[2][5] = 1;
    matrix[1][2] = 1;
    cout<<solution.uniquePathsWithObstacles(matrix)<<endl;
    return 0;
}