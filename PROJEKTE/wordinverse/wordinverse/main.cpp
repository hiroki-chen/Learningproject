#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string raw, * word = new string;
    unsigned long* pos = new unsigned long;
    cout<<"请输入一串字符：";
    getline(cin,raw);
    raw = raw + " ";
    string::size_type position = 0;
    int i = 1;
    while((position = raw.find(" ",position)) != string::npos){
        pos[i++] = position++;
    }
    pos[0] = -1; //不存在的空格是-1.
    for(int j = i; j >= 1; j--){
        word[j] = raw.substr(pos[j-1] + 1, pos[j] - pos[j-1]); //这样截取自带空格。
    }
    for (int j = i; j >= 1; j--) {
        bool flag = true;
        for(int k = j + 1; k <= i; k++){
            if(word[j] == word[k]) flag = false;
        }
        if(flag) cout<<word[j];
    }
    delete pos;
    return 0;
}
