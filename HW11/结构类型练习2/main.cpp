//
//  main.cpp
//  结构类型练习2
//
//  Created by Mark on 2019/12/11.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct capital{
    int sum = 0;
};

struct letter{
    int sum = 0;
};

int main(int argc, const char * argv[]) {
    string sentence;
    capital alpha[27];
    letter beta[27];
    cout<<"Please now input a sentence."<<endl;
    cin>>sentence;
    for(int i = 0; i <= (sentence.length()-1); i++){
        if(sentence[i] >= 'A' && sentence[i] <='Z') alpha[static_cast<int>(sentence[i]-'A')+1].sum += 1;
        else if(sentence[i] >= 'a' && sentence[i] <= 'z') beta[static_cast<int>(sentence[i]-'a')+1].sum += 1;
    }
    for(int i = 1; i <= 26; i++){
        if(alpha[i].sum > 0) cout<<static_cast<char>(i+64)<<": "<<alpha[i].sum<<endl;
    }
    for (int i = 1; i <= 26; i++) {
        if(beta[i].sum > 0) cout<<static_cast<char>(i+96)<<": "<<beta[i].sum<<endl;
    }
    return 0;
}
