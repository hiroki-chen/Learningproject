/*
题目三
有两组数据分别是{10,15,2,8,22,11}、{1,5,10,22,4,8,33,6}，
将这两组数据分别存储在list容器中，并将两个链表合并，合并之后删除重复元素，对链表中的值从小到大排序。
*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, const char** argv) {
    list<int> l1 = {10, 15, 2, 8, 22, 11};
    list<int> l2 = {1, 5, 10, 22, 4, 8, 33, 6};
    l1.sort([](const int& a, const int& b) mutable -> bool {return a <= b;});
    l2.sort([](const int& a, const int& b) mutable -> bool {return a <= b;});
    l1.merge(l2);
    int pre = -1;
    for (auto item : l1) {
        if (pre == item) continue;
        pre = item;
        cout << item << " ";
    }
    cout << endl;
    return 0;
}