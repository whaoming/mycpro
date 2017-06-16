typedef char ElemType;

/**
 * 单链表结构
 */
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LinkList;


/**
 * 双链表结构
 */
typedef struct DNode{
	ElemType data;
	struct DNode *prior;
	struct DNode *next;
}DLinkList;
