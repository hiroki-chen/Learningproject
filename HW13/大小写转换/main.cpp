//
//  main.cpp
//  大小写转换
//
//  Created by Mark on 2019/12/17.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
struct Word{
    int start;
    int end;
} word[100];

string finalword[100];
string combination(char* sentence,int start, int end){
    string temp;
    int count = 0;
    for(int i = start; i <= end; i++){
        temp[count++] = sentence[i];
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    char sentence[100];
    cin.getline(sentence,sizeof(sentence),'\n');
    auto length = strlen(sentence); //求char数组的长度。
    int sum = 0;
    for(int i = 0; i <= length; i++){
        if(sentence[i] == ' ' || sentence[i] == '\0'){
            word[sum].end = i-1;
            finalword[sum] = combination(sentence, word[sum].start, word[sum].end);
          /*  if(sum != 0){
                for(int i = 0; i <= sum-1; i++){
                    if(finalword[i] == finalword[sum]) continue;
                }
            } */
                sum += 1;
                word[sum].start = i+1;
        }
    }
    cout<<finalword[0];
    for (int i = 0; i <= sum; i++) {
        i == sum ? cout<<finalword[i]:cout<<finalword[i]<<" ";
    }
    return 0;
}
