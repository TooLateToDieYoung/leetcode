
typedef struct ListNode node_t;

/* First Trying Runtime = 12ms */
node_t * removeElements(node_t * head, int val){
    
    if(!head) return NULL; // 本來就空
    
    while(head && head->val == val) head = head->next; // 前幾個就不要
    
    if(!head || !head->next) // 檢查[刪到沒東西]，跟[刪到剩一個]
        return ( !head || head->val == val ) ? NULL : head;
        
    node_t * front = head, * curr = front->next;
    
    while(curr){
        if(curr->val == val) front->next = curr->next;
        else front = front->next;
        curr = front->next;
    }
    
    return head;
}


/* Second Trying Runtime = 8ms */
node_t * removeElements(node_t * head, int val){
    if(!head) return NULL;
    if(head->val == val) return removeElements(head->next, val);
    head->next = removeElements(head->next, val);
    return head;
}