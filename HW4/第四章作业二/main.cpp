#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int i;
    char s[80],a[255];
    while(1){
        gets(s);
        if(strcmp(s,"END")==0)
            break;
        if(strlen(s)>50){
            cout<<"OUT";
            break;
        }
        memset(a,0,sizeof(a));
        for(i=static_cast<int>(strlen(s)-1);i>=0;i--)
            if(!a[s[i]]){
                a[s[i]]=1;
                putchar(s[i]);
            }
        putchar('\n');
    }
    return 0;
}
