/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode * head) {
    
    if( !head || !(head->next) ) return false;
    
    struct ListNode * slow = head, * fast = head->next;
    
    while(slow!=fast){
        if(!fast) return false;
        slow = slow->next;
        if(fast->next && fast->next->next) fast = fast->next->next;
        else fast = fast->next;
    }
    return true;
}