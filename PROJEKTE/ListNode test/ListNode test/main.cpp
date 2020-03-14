//
//  main.cpp
//  ListNode test
//
//  Created by Mark on 2020/3/14.
//  Copyright © 2020 Mark. All rights reserved.
//

//这是一个单向链表的样例。

#include <iostream>
#include "List.h"
using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"请输入你想要创建的链表的节点个数：";
    int N, first_value;
    cin>>N;
    cout<<endl;
    cout<<"请输入链表的第一个值：";
    cin>>first_value;
    ListNode* head = new ListNode;
    head -> data = first_value;
    create_ListNode(head, N);
    int add;
    cout<<"请输出要删除的值：";
    cin>>add;
    list_delete_function(add, head);
    ListNode* temp_ptr = head;
    for (int i = 1; i <= N - 1; i++) {
        cout<<temp_ptr -> data<<" ";
        temp_ptr = temp_ptr -> next;
    }
    return 0;
}
