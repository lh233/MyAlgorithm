void Merge(int r[],int r1[],int s,int m,int t)
{
    int i=s;
    int j=m+1;
    int k=s;
    while(i<=m&&j<=t)
    {
        if(r[i]<=r[j])
            r1[k++]=r[i++];
        else
            r1[k++]=r[j++];
    }
    while(i<=m)
        r1[k++]=r[i++];
    while(j<=t)
        r1[k++]=r[j++];
    for(int l=0; l<8; l++)
        r[l]=r1[l];
}
 
void MergeSort(int r[],int r1[],int s,int t)
{
    if(s==t)
        return;
    else
    {
        int m=(s+t)/2;
        MergeSort(r,r1,s,m);
        MergeSort(r,r1,m+1,t);
        Merge(r,r1,s,m,t);
    }
}
