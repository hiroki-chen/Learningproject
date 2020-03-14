#include <iostream>
#include <cstring>
using namespace std;

class User{
    string Name = "";
    string Pass = "";
    public:
    void SetName(string s){
        Name = s;
    }
    void SetPass(string s){
        Pass = s;
    }
    string GetName(){
        return Name;
    }
    string GetPass(){
        return Pass;
    }
};

int main(int argc, const char * argv[]) {
    string name,pass;
    User user[10];
    for(int i = 0; i < 10; i++){
        cin>>name>>pass;
        user[i].SetName(name);
        user[i].SetPass(pass);
    }
START:
    cout<<"Now please search:";
    string search;
    cin>>search;
    bool flag = true;
        if(search.find_last_of("END", search.length()-1) == string::npos) flag = false;
        else search.erase(search.find_last_of("END", 3));
    int i = 0;
    while(i <= 9){
        if(strcmp(user[i].GetName().c_str(), search.c_str()) != 0) i++;
        else break;
    }
        if(i > 9) cout<<"404";
        else cout<<user[i].GetPass()<<endl;
    if(flag == false){
        goto START;
    }
    else return 0;
}
