#include <stdio.h>
#include <stdlib.h>

#define DataType int
/*
����AVL���Ľṹ�壬��ʽ
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
//�����ĸ߶�
int Height(AvlTree T)
{
    if(NULL == T)
        return -1;
    else
        return T->height;
}

//����ת����
AvlTree singleRotateWithRight(AvlTree T)
{
    AvlTree L = T->m_pLeft;
    T->m_pLeft = L->m_pRight;
    L->m_pRight = T;
    T->height = Max( Height(T->m_pLeft),Height(T->m_pRight) ) + 1;
    L->height = Max( Height(L->m_pLeft),Height(L->m_pRight) ) + 1;
    return L;   //��ʱL��Ϊ���ڵ��ˣ��ɲο�AVL�Ĳ�����������������ͼ��
}

//����ת����
AvlTree singleRotateWithLeft(AvlTree T)
{
    AvlTree R = T->m_pRight;
    T->m_pRight = R->m_pLeft;
    R->m_pLeft = T;
    T->height = Max( Height(T->m_pLeft),Height(T->m_pRight) ) + 1;
    R->height = Max( Height(R->m_pLeft),Height(R->m_pRight) ) + 1;
    return R;    //��ʱR��Ϊ���ڵ��ˣ��ɲο�AVL�Ĳ�����������������ͼ��
}

//˫��ת���������
AvlTree doubleRotateWithLeft(AvlTree T)        //�������
{
    T->m_pLeft = singleRotateWithLeft(T->m_pLeft);
    return singleRotateWithRight(T);
}

//˫��ת�����Һ���
AvlTree doubleRotateWithRight(AvlTree T)    //���Һ���
{
    T->m_pRight = singleRotateWithRight(T->m_pRight);
    return singleRotateWithLeft(T);
}

AvlTree AvlTreeInsert(AvlTree T, DataType x)
{
    //�����Ϊ��
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
            printf("�ռ䲻��\n");
            exit(0);
        }
    }
    else if( x < T->data)        //������뵽T������������
    {
        T->m_pLeft = AvlTreeInsert(T->m_pLeft, x);  //�Ȳ��룬����ת
        if(Height(T->m_pLeft) - Height(T->m_pRight) == 2) //ֻ�п��������
        {
            if(x < T->m_pLeft->data)        //���������ֻ��Ҫ����ת
            {
                T = singleRotateWithRight( T );
            }
            else                            //���������˫��ת,����
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
            if(x > T->m_pRight->data )        //�����������������
            {
                T = singleRotateWithLeft( T );
            }
            else                            //���������˫��ת,����
            {
                T = doubleRotateWithRight( T );
            }
        }
    }

     //���������Ѿ����ڣ���ô�����в���
    T->height = Max(Height(T->m_pLeft),Height(T->m_pRight)) + 1;
    return T;
}

//�������
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
