#include <iostream>
using namespace std;

typedef struct listNode{
   int value;
   struct listNode *pNext;
   //struct listNode *pPrevious;
}lNode;

typedef struct treeNode{
    int value;
    struct treeNode *pLeft;
    struct treeNode *pRight;
}tNode;


int main() {
    //-- initialise linked list with first node
    //lNode *pList = NULL;
    //lNode *pNew = malloc(sizeof(lNode));
    //pNew->value = someNumber;//-- (*pNew).value dereference and access value
    //pNew->pNext = NULL;
    //pList = pNew
    //lNode *pLastNode = pNew
    //free(pNew)

    //-- insert new node in a stack (prepending)
    //lNode *pNew = malloc(sizeof(lNode));
    //pNew->value = someNumber;
    //pNew->pNext = pList;
    //pList = pNew;
    //free(pNew)

    //-- insert new node in a queue (appending)
    //lNode *pNew = malloc(sizeof(lNode));
    //pNew->value = someNumber;
    //pNew->pNext = NULL;
    //pLastNode->pNext = pNew;
    //pLastNode = pNew;
    //free(pNew)

    return 0;
}
