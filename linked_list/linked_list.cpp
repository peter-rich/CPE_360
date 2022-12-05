/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<vector>
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

ListNode* merge2Lists(ListNode* list_a, ListNode* list_b) {
    ListNode* res;
    return res;
}

int main() {
    
    ListNode *list_a = new ListNode(1);
    list_a->next = new ListNode(4);
    ListNode *tmp = list_a->next;
    tmp->next = new ListNode(5);
    
    ListNode *list_b = new ListNode(1);
    list_b->next = new ListNode(3);
    tmp = list_b->next;
    tmp->next = new ListNode(4);
    
    ListNode *list_c = merge2Lists(list_a, list_b);
    return 0;
}
