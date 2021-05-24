struct IntNode{
    int data;
    struct IntNode *top_child, *parent;

}; 

struct IntStack{
    IntNode *addNode(int x)
    {
	    IntNode *newNode = new IntNode;

        newNode->data = x;
        newNode->top_child = NULL;
        newNode->parent = NULL;
        return newNode;
        delete newNode;
    }

    IntNode* push(IntNode *parent, IntNode *child){
        parent -> top_child = child;
        child -> parent = parent;
        return child;
    }

    IntNode* pop(IntNode *poppedNode){
        return poppedNode->parent;
    }

    int peek(IntNode peekedNode){
        return peekedNode.data;
    }
};