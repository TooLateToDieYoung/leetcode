// First Trying RunTime = 0ms 

#define data_t  int
#define queue_t MyQueue

typedef struct node_t node_t;
struct node_t{
    data_t   data;
    node_t * next;
};

typedef struct {
    node_t * head;
    node_t * tail;
}MyQueue;

static node_t * CreateNewNode(const data_t data){
    node_t * newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode){
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}


queue_t * myQueueCreate() {
    queue_t * newQueue = (queue_t*)malloc(sizeof(queue_t));
    if(newQueue){
        newQueue->head = NULL;
        newQueue->tail = NULL;
    }
    return newQueue;
}

void myQueuePush(MyQueue* obj, const data_t x) {
    if(obj){
        node_t * add = CreateNewNode(x);
        if(add){
            if(!obj->head) obj->head = add;
            else obj->tail->next = add;
            obj->tail = add;
        }
    }
}

int myQueuePop(MyQueue* obj) {
    if(obj && obj->head){
        node_t * temp = obj->head;
        data_t reslut = obj->head->data;
        obj->head = obj->head->next;
        free(temp);
        return reslut;
    }
    return 0;
}

int myQueuePeek(MyQueue* obj) {
    return (obj && obj->head) ? obj->head->data : 0;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->head == NULL;
}

void myQueueFree(MyQueue* obj) {
    if(obj){
        while(obj->head){
            node_t * temp = obj->head;
            obj->head = obj->head->next;
            free(temp);
        }
        free(obj);
    }
}
