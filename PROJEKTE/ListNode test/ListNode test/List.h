//
//  List.h
//  ListNode test
//
//  Created by Mark on 2020/3/14.
//  Copyright © 2020 Mark. All rights reserved.
//

#ifndef List_h
#define List_h
#include <iostream>
using namespace std;
class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(void): next(NULL){}
};

void list_delete_function(int, ListNode*&);
void list_add_function(int, ListNode*&);
void list_find_function(int, ListNode*);

void create_ListNode(ListNode* &head, int N){
    ListNode* temp_ptr = head;
    for(int i = 2; i <= N; i++){
        ListNode* new_node = new ListNode;
        cout<<"请输入第"<<i<<"个节点的值:";
        cin>>new_node -> data;
        temp_ptr -> next = new_node;
        temp_ptr = new_node;
        if(i == N) temp_ptr -> next = NULL;
    }
}

void list_add_function(int value, ListNode* &head){ //head记得引用！！！！因为是对它的直接修改。
    ListNode* new_node = new ListNode;
    new_node -> data = value;
    ListNode* temp_ptr = head;
    if(value <= head -> data) {
        new_node -> next = head;
        head = new_node;
    }
    else {
        while(temp_ptr -> next != NULL){
            if(temp_ptr -> next -> data >= value){
                new_node -> next = temp_ptr -> next;
                temp_ptr -> next = new_node;
                break; //找到了就退出循环。
            }
            temp_ptr = temp_ptr -> next;
        }
        if(temp_ptr -> next == NULL) {
            temp_ptr -> next = new_node;
            new_node -> next = NULL;
        }
    }
    
}

void list_delete_function(int value, ListNode* &head){
    ListNode* temp_ptr = head;
    while(temp_ptr -> next != NULL){
        if((temp_ptr -> next -> data) == (value)) break;
        temp_ptr = temp_ptr -> next;
    }
    if(temp_ptr -> next == NULL) cout<<"There is no such thing"<<endl;
    else{
        temp_ptr -> next = temp_ptr -> next -> next;
    }
}

void list_find_function(int value, ListNode* head){
    ListNode* temp_ptr = head;
    while(temp_ptr != NULL){
        if((temp_ptr -> data) == (value)) break;
        temp_ptr = temp_ptr -> next;
    }
    if(temp_ptr == NULL) cout<<"It seems that there is no such listnode"<<endl;
    else cout<<"FOUND!"<<endl;
}
#endif /* List_h */
