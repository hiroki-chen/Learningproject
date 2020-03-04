//
//  main.cpp
//  题目二
//
//  Created by Mark on 2020/2/27.
//  Copyright © 2020 Mark. All rights reserved.
//

#include <iostream>
using namespace std;

class Box{
    double m_a;
    double m_volume;
    double m_area;
public:
    void Seta(double a){
        m_a = a;
    }
    void Display(){
        double m_volume = m_a * m_a * 6;
        double m_area = m_a * m_a * m_a;
        cout<<m_volume<<" "<<m_area<<endl;
    }
};

int main(int argc, const char * argv[]) {
    double a;
    cin>>a;
    Box Cube;
    Cube.Seta(a);
    Cube.Display();
    return 0;
}
