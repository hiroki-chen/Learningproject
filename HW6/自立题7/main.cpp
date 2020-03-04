//重点在于计数器sum和首尾相接的问题：①有人的时候sum要加；②sum=死亡之数的时候就重置并且该人c剔除。
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int *person = new int[n];
    for (int i = 1; i <= n; i++) {
        person[i] = 1;
    }
    int k,j,sum;
    cin>>k;
    j = 0;
    sum = 0;
    int dead = 0;
    do{
        ++j;
        if(j>n)
            j = 1;
        if(person[j])
            sum++;
        if(sum == k){
            person[j] = 0;
            sum = 0;
            if(dead == 0) cout<<j;
            else if(dead == n-2) cout<<" "<<j<<endl;
            else cout<<" "<<j;
            dead++;
            /*for (int h = 1;h<=n;h++){
                if(person[h]==1){
                    cout<<h<<" ";
                    if(h==n) cout<<endl;
                }
                else if (person[h]==0){
                    cout<<0<<" ";
                }
                if(h==12) cout<<endl;
            }*/
        }
    }while(dead <= n-2);
    for(j=1;j<=n;j++){
        if(person[j]) break;
    }
    cout<<j;
    return 0;
}
