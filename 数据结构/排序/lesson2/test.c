#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int *a, int *b){
	int ret = *a;
	*a = *b;
	*b = ret;
}
//÷±Ω”≤Â»Î≈≈–Ú
int* InsertionSort(int* a[], int length){
	for (int i = 0; i < length - 1; i++){
		int n = i;
		while (n >= 0){
			if (a[n] >= a[n + 1]){
				int ret = a[n];
				a[n] = a[n + 1];
				a[n + 1] = ret;
				n--;
			}
			else{
				break;
			}
		}
	}
	return a;
}

//œ£∂˚≈≈–Ú

int* ShellSort(int* a[], int length){
	int i = 0, j = 0;
	for (int gap = length / 2; gap > 0; gap /= 2){
		for (j = gap; j < length; j++){
			int temp = a[j];
			for (i = j - gap; i >= 0 && temp < a[i]; i -= gap){
				a[i + gap] = a[i];
			}
			a[i + gap] = temp;
		}
	}
	return a;
}
//int* ShellSort(int* a[], int length){
//	for (int gap = length / 2; gap > 0; gap /= 2){
//		for (int j = gap; j < length; j++){
//			for (int i = j - gap; i >= 0; i -= gap){
//				if (a[i] > a[j]){
//					int temp = a[j];
//					a[j] = a[i];
//					a[i] = temp;
//				}
//			}
//		}
//	}
//	return a;
//}

//÷±Ω”—°‘Ò≈≈–Ú
int* SelectSort(int* a, int length){
	for (int i = 0; i < length; i++){
		for (int j = i + 1; j < length; j++){
			if (a[i] >a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	return a;
}

//√∞≈›≈≈–Ú
int* BubbleSort(int* a, int length){
	for (int i = length - 1; i >= 0; i--){
		for (int j = i - 1; j >= 0; j--){
			if (a[i] < a[j]){
				Swap(a + i, a + j);
			}
		}
	}
	return a;
}

int patition(int*a, int left, int right){
	int d = left;
	for (int i = left; i < right; i++){
		if (a[i] < a[right]){
			Swap(a + d, a + i);
			d++;
		}
	}
	Swap(a + d, a + right);
	return d;
}
//øÏÀŸ≈≈–Ú
int* QSort(int* a, int left, int right){
	int* ret = a;
	int m;
	if(left < right){
		m = patition(a, left, right);
		QSort(a, left, m - 1);
		QSort(a, m + 1, right);
	}
	return ret;
}
int main(){
	int* a[] = { 1, 8, 2, 5, 9, 4, 6, 5, 2, 49, 5, 6, 64, 456, 2 };
	int length = sizeof(a) / sizeof(a[0]);
	printf("%d\n", length);
	//int* ret = InsertionSort(a, length);
	//int* ret = ShellSort(a, length);
	//int* ret = SelectSort(a, length);
	//int* ret = BubbleSort(a, length);
	int* ret = QSort(a, 0, length - 1);
	for (int i = 0; i < length; i++){
		printf("%d ", ret[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
