#include<iostream>
#include<cstdlib>
int main(){
    using namespace std;
    int i=0,n,m,num[100];
    char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    cout<<"please input a number."<<endl;
    cin>>n;
    while(n>0){
        num[i++]=n%16;
        n=n/16;
    }
    for(i=i-1;i>=0;i--){
        m=num[i];
        cout<<hex[m];
    }
    return 0;
}
