/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct node_t node_t;
struct node_t{
    int      data;
    bool     pick;
    node_t * next;
};

typedef struct{
    node_t * head;
    node_t * tail;
    size_t   pickedSize;
}list_t;

static node_t * CreateNewNode(const int data){
    node_t * newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode){
        newNode->data = data;
        newNode->pick = false;
        newNode->next = NULL;
    }
    return newNode;
}

static list_t * CreateNewList(){
    list_t * newList = (list_t*)malloc(sizeof(list_t));
    if(newList){
        newList->head = NULL;
        newList->tail = NULL;
        newList->pickedSize = 0;
    }
    return newList;
}

static void Push(list_t * self, const int data){
    if(self){
        node_t * add = CreateNewNode(data);
        if(!self->head){ self->head = add; }
        else { self->tail->next = add; }
        self->tail = add;
    }
}

static void Pick(list_t * self, const int data){
    if(self){
        node_t * curr = self->head;
        while(curr){
            if(!curr->pick && curr->data==data){
                curr->pick = true;
                self->pickedSize++;
                return;
            }
            curr = curr->next;
        }
    }
}

static void DestroyList(list_t * self){
    if(self){
        node_t * curr = self->head;
        while(curr){
            node_t * temp = curr;
            curr = curr->next;
            free(temp);
        }
        free(self);
    }
}

static int * AssignAnswerArray(const list_t * self, int * returnSize){
    int i, * ans = (int*)malloc(self->pickedSize * sizeof(int));
    node_t * curr = self->head;
    *returnSize = self->pickedSize;
    for(i=0; curr;){
        if(curr->pick){
            ans[i] = curr->data;
            i++;
        }
        curr = curr->next;
    }
    return ans;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    list_t * list = CreateNewList();
    
    int * sNums = (nums1Size<nums2Size) ? nums1 : nums2;
    int * lNums = (sNums==nums1) ? nums2 : nums1;
    int * sSize = (sNums==nums1) ? nums1Size : nums2Size;
    int * lSize = (lNums==nums1) ? nums1Size : nums2Size;
    int i;
    
    for(i=0; i<sSize; ++i) Push(list, sNums[i]);
    for(i=0; i<lSize; ++i) Pick(list, lNums[i]);

    int * ans = AssignAnswerArray(list, returnSize);
    
    DestroyList(list);
    
    return ans;
}