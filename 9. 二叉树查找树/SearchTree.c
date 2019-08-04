#include <stdio.h>
#include <stdlib.h>



typedef struct TreeNode * Position;
typedef struct TreeNode * SearchTree;
typedef int ElementType;


SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

struct TreeNode{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

struct TreeNode;


//Ê¹¶þ²æÊ÷Îª¿Õ
SearchTree MakeEmpty(SearchTree T) {
    if(T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
    }
}


Position Find(ElementType X, SearchTree T){
    if(T == NULL)
        return NULL;
    else if(X < T->Element){
        return Find(X, T->Left);
    } else if (X > T->Element){
        return Find(X, T->Right);
    }else
        return T;
}

Position FindMin(SearchTree T)
{
    if(T == NULL){
        return NULL;
    }else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T){
    if(T != NULL)
        while(T->Right != NULL)
            T = T->Right;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T){
    if(T == NULL){
        T = malloc(sizeof(struct TreeNode));
        if(T == NULL)
            printf("Out of space!!!");
        else{
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }  else if(X < T->Element)
        T->Left = Insert(X, T->Left);
      else if(X > T->Element)
        T->Right = Insert(X, T->Right);

    return T;
}

SearchTree Delete(ElementType X, SearchTree T){
    Position TmpCell;

    if(T == NULL)
        printf("Element Not Found\n");
    else if(X < T->Element)
        T->Left = Delete(X, T->Left);
    else if(X > T->Element)
        T->Right = Delete(X, T->Right);
    else if(T->Left && T->Right){
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(TmpCell->Element, T->Right);
    }
    else{
        TmpCell = T;
        if(!(T->Left))
            T = T->Right;
        else if(!(T->Right))
            T = T->Left;
        free(TmpCell);
    }
    return T;
}
int main()
{

    return 0;
}
