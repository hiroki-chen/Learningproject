#include <iostream>
#include <string>
using namespace std;
void reverse(string &raw, string::size_type pos){
    bool flag = true; //初始值一定要true或者不设，否则第一次不会输出。
    for(string::size_type j = pos; j >= 1; j--){ //注意一下这个j一定大于等于0，所以小于0的时候这个循环是跳不出来的，所以需要”曲线救国“。
                for(string::size_type i = pos - 1; i >= j; i--){
                    if(raw.find(raw[j-1],i) != string::npos) flag = false;
                    else flag = true; //每次需要重新设定flag的值，否则flag后来会始终等于false...
                }
                if(flag) cout<<raw[j-1];
        }
}

int main(int argc, const char * argv[]) {
    string raw;
    getline(cin,raw);
    string::size_type pos = raw.find("END");
    if (pos >= 50){
        if(pos == string::npos) cout<<"你似乎没有输入END!!!请重试~"<<endl;
        else cout<<"OUT OF RANGE"<<endl;
    }
    else reverse(raw,pos);
    return 0;
}
