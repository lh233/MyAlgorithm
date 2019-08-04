#include <stdio.h>
#include <stdlib.h>

#define DataType int
/*
定义AVL树的结构体，链式
*/
typedef struct AvlNode {
    DataType data;
    AvlTree m_pLeft;
    AvlTree m_pRight;
    int height;
}* AvlTree, *Position, AvlNode;


int max(int a, int b)
{
    return a>b?a:b;
}
//求树的高度
int Height(AvlTree T)
{
    if(NULL == T)
        return -1;
    else
        return T->height;
}

//单旋转右旋
AvlTree singleRotateWithRight(AvlTree T)
{
    AvlTree L = T->m_pLeft;
    T->m_pLeft = L->m_pRight;
    L->m_pRight = T;
    T->height = Max( Height(T->m_pLeft),Height(T->m_pRight) ) + 1;
    L->height = Max( Height(L->m_pLeft),Height(L->m_pRight) ) + 1;
    return L;   //此时L成为根节点了（可参考AVL的插入的左左情况的右旋图）
}

//单旋转左旋
AvlTree singleRotateWithLeft(AvlTree T)
{
    AvlTree R = T->m_pRight;
    T->m_pRight = R->m_pLeft;
    R->m_pLeft = T;
    T->height = Max( Height(T->m_pLeft),Height(T->m_pRight) ) + 1;
    R->height = Max( Height(R->m_pLeft),Height(R->m_pRight) ) + 1;
    return R;    //此时R成为根节点了（可参考AVL的插入的左左情况的左旋图）
}

//双旋转，先左后右
AvlTree doubleRotateWithLeft(AvlTree T)        //先左后右
{
    T->m_pLeft = singleRotateWithLeft(T->m_pLeft);
    return singleRotateWithRight(T);
}

//双旋转，先右后左
AvlTree doubleRotateWithRight(AvlTree T)    //先右后左
{
    T->m_pRight = singleRotateWithRight(T->m_pRight);
    return singleRotateWithLeft(T);
}

AvlTree AvlTreeInsert(AvlTree T, DataType x)
{
    //如果树为空
    if(T == NULL)
    {
        T = (AvlNode *)malloc(sizeof(struct AvlNode));
        if(T)
        {
            T->data = x;
            T->m_pLeft  = NULL;
            T->m_pRight = NULL;
            T->height = 0;
        }
        else
        {
            printf("空间不够\n");
            exit(0);
        }
    }
    else if( x < T->data)        //如果插入到T结点的左子树上
    {
        T->m_pLeft = AvlTreeInsert(T->m_pLeft, x);  //先插入，后旋转
        if(Height(T->m_pLeft) - Height(T->m_pRight) == 2) //只有可能是这个
        {
            if(x < T->m_pLeft->data)        //左左情况，只需要右旋转
            {
                T = singleRotateWithRight( T );
            }
            else                            //左右情况，双旋转,先左
            {
                T = doubleRotateWithLeft( T );
            }
        }
    }
    else if( x > T->data )
    {
        T->m_pRight = AvlTreeInsert(T->m_pRight,x);
        if(Height(T->m_pRight) - Height(T->m_pLeft) == 2)
        {
            if(x > T->m_pRight->data )        //右右情况，进行左旋
            {
                T = singleRotateWithLeft( T );
            }
            else                            //左右情况，双旋转,先右
            {
                T = doubleRotateWithRight( T );
            }
        }
    }

     //如果这个数已经存在，那么不进行插入
    T->height = Max(Height(T->m_pLeft),Height(T->m_pRight)) + 1;
    return T;
}

//中序遍历
void inOrderVisitUseRecur(const AvlTree pCurrent)
{

    if(pCurrent)
    {
        inOrderVisitUseRecur(pCurrent->m_pLeft);
        printf("%d\t", pCurrent->data);
         if(pCurrent->m_pLeft)
            printf(" leftChild: %d\t", pCurrent->m_pLeft->data);
        else
            printf(" leftChild is NULL");
        if(pCurrent->m_pRight)
            printf(" rightChild: %d\t", pCurrent->m_pRight->data);
        else
            printf(" rightChild is NULL");
        printf("\n");
        inOrderVisitUseRecur(pCurrent->m_pRight);
    }
}

int main()
{
    AvlTree root = NULL;
    root = AvlTreeInsert(root,1);
    root = AvlTreeInsert(root,2);
    root = AvlTreeInsert(root,3);
    root = AvlTreeInsert(root,4);
    root = AvlTreeInsert(root,5);
    root = AvlTreeInsert(root,6);
    root = AvlTreeInsert(root,7);
    root = AvlTreeInsert(root,8);
    root = AvlTreeInsert(root,9);
    root = AvlTreeInsert(root,10);
    root = AvlTreeInsert(root,11);
    root = AvlTreeInsert(root,12);
    root = AvlTreeInsert(root,13);
    root = AvlTreeInsert(root,14);
    root = AvlTreeInsert(root,15);
    inOrderVisitUseRecur(root);
    return 0;
}
