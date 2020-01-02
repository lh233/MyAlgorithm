void swap(int K[], int i, int j)
{
    int temp = K[i];
    K[i] = K[j];
    K[j] = temp;
}

//大顶堆的构造，传入的i是父节点
void HeapAdjust(int k[],int p,int n)
{
    int i,temp;
    temp = k[p];
    for (i = 2 * p; i <= n;i*=2)    //逐渐去找左右孩子结点
    {
        //找到两个孩子结点中最大的
        if (i < n&&k[i] < k[i + 1])
            i++;
        //父节点和孩子最大的进行判断，调整，变为最大堆
        if (temp >= k[i])
            break;
        //将父节点数据变为最大的，将原来的数据还是放在temp中，
        k[p] = k[i];    //若是孩子结点的数据更大，我们会将数据上移，为他插入的点提供位置
        p = i;
    }
    //当我们在for循环中找到了p子树中，满足条件的点，我们就加入数据到该点p,注意：p点原来数据已经被上移动了
    //若没有找到，就是相当于对其值不变
    //插入
    k[p] = temp;
}

//大顶堆排序
void HeapSort(int k[], int n)
{
    int i;
    //首先将无序数列转换为大顶堆
    for (i = n / 2; i > 0;i--)    //注意由于是完全二叉树，所以我们从一半向前构造，传入父节点
        HeapAdjust(k, i, n);

    //上面大顶堆已经构造完成，我们现在需要排序，每次将最大的元素放入最后
    //然后将剩余元素重新构造大顶堆，将最大元素放在剩余最后
    for (i = n; i >1;i--)
    {
        swap(k, 1, i);
        HeapAdjust(k, 1, i - 1);
    }
}


int main()
{
    int i;
    int a[11] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4, 8 };
    HeapSort(a, 10);

    for (i = 1; i <= 10; i++)
        printf("%d ", a[i]);

    system("pause");
    return 0;
}