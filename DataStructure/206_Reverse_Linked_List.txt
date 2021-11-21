/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node_t;
node_t * reverseList(node_t * head){
    
    if(!head || !head->next) return head;
    if(!head->next->next) {
        node_t * temp = head->next;
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    node_t * n1 = head, * n2 = n1->next, * n3 = n2->next;
    while(1){
        n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        if(n3) n2 = n3;
        else break;
    }
    head->next = NULL;
    
    return n2;
}