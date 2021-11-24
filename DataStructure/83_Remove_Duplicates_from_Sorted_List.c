
typedef struct ListNode node_t;

node_t * deleteDuplicates(node_t * head){

    //if(!head || !head->next) return head;
    
    node_t * curr = head, * check;    
    while(curr){
        check = curr->next;
        while(check && check->val == curr->val)
            check = check->next;
        curr->next = check;
        curr = check;
    }
    
    return head;
}