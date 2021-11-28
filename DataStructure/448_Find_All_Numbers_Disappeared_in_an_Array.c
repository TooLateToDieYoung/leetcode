
/* First Trying Runtime = 140ms */
int cmp(const void * a, const void * b) { return *((int*)a) - *((int*)b); }

bool IsBelong(const int * const arr, const int target, const int left, const int right){
    if(left > right) return false;
    
    int middle = (left + right) >> 1;
    
    if(arr[middle] > target) return IsBelong(arr, target, left,  middle - 1);
    if(arr[middle] < target) return IsBelong(arr, target, middle + 1, right);
    
    return true;
}

typedef struct node_t node_t;
struct node_t{
    int      data;
    node_t * next;
};

typedef struct list_t list_t;
struct list_t{
    node_t * head;
    node_t * tail;
    size_t   size;
};

list_t * CreateNewList();
void DestroyList(list_t * self);
void Push(list_t * const self, const int value);
int * ConvertListToArray(const list_t * const self);

int* findDisappearedNumbers(int * nums, int numsSize, int * returnSize){
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    list_t * list = CreateNewList();
    
    for(int i=0; i<numsSize; ++i)
        if( !IsBelong(nums, i+1, 0, numsSize - 1) )
            Push(list, i + 1);
    
    *returnSize = list->size; 
    int * res = ConvertListToArray(list);
    DestroyList(list);
        
    return res;
}

node_t * CreateNewNode(const int value){
    node_t * newNode = (node_t*)calloc(1, sizeof(node_t));
    if(newNode){
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}
    
list_t * CreateNewList(){
    list_t * newList = (list_t*)calloc(1, sizeof(list_t));
    if(newList){
        newList->size = 0;
        newList->head = NULL;
        newList->tail = NULL;
    }
    return newList;
}
    
void DestroyList(list_t * self){
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
    
void Push(list_t * const self, const int value){
    node_t * add = CreateNewNode(value);
    if(add){
        if(!self->head){ self->head = add; }
        else { self->tail->next = add; }
        self->tail = add;
        self->size++;
    }
}
    
int * ConvertListToArray(const list_t * const self){
    node_t * curr = self->head;
    int * arr = (int*)calloc(self->size, sizeof(int));
    
    for(int i=0; i<self->size; ++i){
        arr[i] = curr->data;
        curr = curr->next;
    }
    
    return arr;
}

/* Second Trying Runtime = 1400ms */
int cmp(const void * a, const void * b) { return *((int*)a) - *((int*)b); }

bool IsBelong(const int * const arr, const int target, const int left, const int right){
    if(left > right) return false;
    
    int middle = (left + right) >> 1;
    
    if(arr[middle] > target) return IsBelong(arr, target, left,  middle - 1);
    if(arr[middle] < target) return IsBelong(arr, target, middle + 1, right);
    
    return true;
}

int * ReallocArray(int * arr, const int oldSize, const int newSize){
    
    if(oldSize > newSize) return arr;
    
    int * newArr = (int*)calloc(newSize, sizeof(int));
    
    if(newArr) for(int i=0; i<oldSize; ++i) newArr[i] = arr[i];
        
    int * temp = arr;
    free(arr);
    
    return newArr;
}

int* findDisappearedNumbers(int * nums, int numsSize, int * returnSize){
    
    qsort(nums, numsSize, sizeof(int), cmp);
    
    *returnSize = 0;
    int * res = (int*)calloc(0, sizeof(int));
    
    for(int i=0; i<numsSize; ++i){
        if( !IsBelong(nums, i + 1, 0, numsSize - 1) ){
            res = ReallocArray(res, *returnSize, (*returnSize) + 1);
            res[*returnSize] = i + 1;
            (*returnSize)++;
        }
    }
        
    return res;
}

/* Third Trying Runtime = 92ms */

// 1. The value of input array (nums) is between [1 : numsSize]
// 2. Make an array to check each value in input array (nums)
// 3. Search for those "Unassigned" position in "check array" to count for "returnSize"
// 4. Assign the result array with unassigned position in check array

int* findDisappearedNumbers(int * nums, int numsSize, int * returnSize){
    
    int * check = (int*)calloc(numsSize, sizeof(int));
    
    for(int i=0; i<numsSize; ++i)
        check[nums[i]-1] = nums[i];
    
    *returnSize = 0;
    for(int i=0; i<numsSize; ++i)
        if(check[i] == 0) (*returnSize)++;
    
    int j = 0, * res = (int*)malloc( (*returnSize) * sizeof(int) );
    for(int i = 0; i < numsSize && j < *returnSize; ++i)
        if(check[i] == 0) res[j++] = i + 1;
    
    free(check);
    
    return res;
}