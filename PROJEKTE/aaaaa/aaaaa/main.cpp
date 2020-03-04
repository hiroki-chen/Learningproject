#include <iostream>
using namespace std;

int main(int argc, const char* argv[]){
    long long m;
    cin>>m;
    char weishu[10] = {'0','0','0','0','0','0','0','0','x','0'};
    int m_weishu = 0;
    if(m <= 9) weishu[0] = static_cast<char>(m + static_cast<int>('0'));
    else if(10 <= m && m <= 15) weishu[0] = static_cast<char>(static_cast<int>('A')+m-10);
    else{
        long long temp = m;
        while(m >= 16){
            m = m / 16;
            m_weishu += 1;
        }
        long long mod = 0;
        for(int i = 0; i <= m_weishu; i++){
            mod = temp % 16;
            temp = temp / 16;
            if(mod <= 9) weishu[i] = static_cast<char>(mod + static_cast<int>('0'));
            else if(10 <= mod && mod <= 15) weishu[i] = static_cast<char>(static_cast<int>('A') + mod - 10);
        }
    }
    for(int i = 9; i >= 0; i--){
        cout<<weishu[i];
    }
    return 0;
}
