#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <=0 || n <=0) return 0;
        //对path初始化，均为0。
        //优化算法，发现当前列的值用完即可扔掉。
        int* dp = new int [n];
        //初始化第一行。
        for(int i = 0; i < n; i++){
            dp[i] = 1;
        }
        for(int i = 1; i < m; i++){
            dp[0] = 1; //初始化每行的第一列。
            for(int j = 1; j < n; j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};


int main(int argc, const char* argv[]){
    Solution solution;
    int m, n;
    cin>>m>>n;
    cout<<solution.uniquePaths(m, n)<<endl;
    return 0;
}