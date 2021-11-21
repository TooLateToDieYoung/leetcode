// Runtime = 0ms

typedef struct node_t node_t;
struct node_t{
    char     data;
    node_t * next;
};

typedef struct stack_t stack_t;
struct stack_t{
    node_t * top;
    size_t  size;
};

static node_t * CreateNewNode(const char data){
    node_t * newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode){
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

static stack_t * CreateNewStack(){
    stack_t * newStack = (stack_t*)malloc(sizeof(stack_t));
    if(newStack){
        newStack->size = 0;
        newStack->top  = NULL;
    }
    return newStack;
}

static void Push(stack_t * self, const char data){
    if(self){
        node_t * add = CreateNewNode(data);
        if(add){
            add->next = self->top;
            self->top = add;
            self->size++;
        }
    }
}

static char Pop(stack_t * self){
    if(self && self->top){
        char reslut = self->top->data;
        node_t * temp = self->top;
        self->top = self->top->next;
        self->size--;
        free(temp);
        return reslut;
    }
    return '\0';
}

static void DestroyStack(stack_t * self){
    if(self){
        while(self->top){
            node_t * temp = self->top;
            self->top = self->top->next;
            free(temp);
        }
        free(self);
    }
}

#define ISLEFT(X)   (((X)=='(')||((X)=='[')||((X)=='{'))
#define TURNLEFT(X) ( ((X)==')') ? '(' : (X)-2 )

bool isValid(char * s){
    
    int size = strlen(s);
    if(size & 1) return false;
    
    stack_t * stack = CreateNewStack();
    char * target = s;
    while(*target){
        if(ISLEFT(*target)) 
            Push(stack, *target);
        else if(Pop(stack) != TURNLEFT(*target)) {
            DestroyStack(stack);
            return false;
        }
        target++;
    }
    
    int reslut = stack->size;
    
    DestroyStack(stack);
    
    return reslut == 0;
}