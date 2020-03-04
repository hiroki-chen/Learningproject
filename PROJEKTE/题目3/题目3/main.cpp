//
//  main.cpp
//  题目3
//
//  Created by Mark on 2020/2/27.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

class Rectangle{
    double m_length = 1;
    double m_width = 1;
    double c = 0, s = 0;
public:
    void Area(){
        s = m_width * m_length;
    }
    void Perimeter(){
        c = 2 * ( m_length + m_width);
    }
    void SetWidth(double x){
        if(0.0 < x && x <= 20.0) m_width = x;
        else return;
    }
    void SetLength(double x){
        if(0.0 < x && x <= 20.0) m_length = x;
        else return;
    }
    void Print(){
        cout<<c<<" "<<s<<endl;
    }
};

int main(int argc, const char * argv[]) {
    double x,y;
    cin>>x>>y;
    Rectangle r;
    r.SetWidth(x);
    r.SetLength(y);
    r.Area();
    r.Perimeter();
    r.Print();
    return 0;
}
