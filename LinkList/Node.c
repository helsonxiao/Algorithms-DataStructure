typedef int ElemType;
// 结点包含该结点的数据和一个指针域（存放后继结点地址）
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef Node *LinkList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
