/*
 * @Descripttion: 
 * @version: 
 * @Author: linhao
 * @Date: 2022-02-19 17:14:57
 * @LastEditors: linhao
 * @LastEditTime: 2022-05-04 10:25:29
 */
/*
    https://blog.csdn.net/weixin_55267022/article/details/116736849
    算法复杂度：
    合并排序的复杂度要分成两部分来看，一部分是分治，另一部分则是合并，
    其中合并部分，最差执行n-1次比较，最优执行n/2次比较，都是O(n)，
    因此得到如下公式：
    T(n)={ 0，n=1
           2T(n/2)+O(n)，n>1
​	 所以我们也可以马上知道合并排序的空间复杂度也为O(nlogn)。

    由此我们也可以发现，虽然合并排序的时间复杂度比较好，但是空间复杂度确实太高了，相比冒泡排序、选择排序这些在位排序而言，占用的额外空间实在是太多了。

    因此针对合并排序的改进方向便是减小空间复杂度。  

*/

void merge(int* B, int lenB, int* C, int lenC, int* A, int lenA) {
	int i = 0, j = 0, k = 0;
	while (i < lenB && j < lenC) {
		if (B[i] <= C[j]) A[k++] = B[i++];
		else A[k++] = C[j++];
	}
	if (i == lenB) {
		while (j < lenC) A[k++] = C[j++];
	} else {
		while (i < lenB)A[k++] = B[i++];
	}
}

void mergeSort(int* A, int lenA) {
	if (lenA > 1) {
		int n1 = lenA / 2;
		int n2 = lenA - n1;
		int* B = (int*)malloc(sizeof(int) * n1);
		int* C = (int*)malloc(sizeof(int) * n2);
		for (int i = 0; i < n1; i++) {
			B[i] = A[i];
		}
		for (int i = 0; i < n2; i++) {
			C[i] = A[n1 + i];
		}
		mergeSort(B, n1);
		mergeSort(C, n2);
		merge(B, n1, C, n2, A, lenA);
		free(B);
		free(C);
	}
}


int main() {
	cout << "排序前的数组:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}cout << endl;

	mergeSort(A, 10);

	cout << "排序后的数组:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << A[i] << " ";
	}cout << endl;
	return 0;
}