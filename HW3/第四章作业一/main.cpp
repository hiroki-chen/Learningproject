#include <iostream>
using namespace std;
int main(){
    int n = 30;
    int count;
    cin>>count;
    int x[count],y[count];
    for (int k = 1; k<=count; k++) {
        cin>>x[k]>>y[k];
        x[k]--;
        y[k]--;
    }
    int a[n][n];
    for (int i=0;i<n;i++)
        a[i][0]=1;
    for (int i=0;i<n;i++)
        a[i][i]=1;
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
    for (int k = 1; k<=count; k++) {
        if((x[k]<0 || x[k]>30)||(y[k] > x[k]|| y[k]<0)){
            cout<<"0"<<endl;
        }
        else cout<<a[x[k]][y[k]]<<endl;
    }
    return 0;
}
