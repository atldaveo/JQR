typedef struct StackNode 
{
    void* data;
    struct StackNode* next;
} StackNode;

// Create a new stack node
StackNode* createStackNode(void* data) 
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Push to the stack
void push(StackNode** top, void* data) 
{
    StackNode* newNode = createStackNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Pop from the stack
void* pop(StackNode** top) 
{
    if (*top == NULL) return NULL;

    StackNode* temp = *top;
    void* poppedData = temp->data;
    *top = temp->next;
    free(temp);
    return poppedData;
}

// Peek the top element
void* peek(StackNode* top) 
{
    if (top == NULL) return NULL;
    return top->data;
}
