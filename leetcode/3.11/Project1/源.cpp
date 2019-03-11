//976
//给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
//
//如果不能形成任何面积不为零的三角形，返回 0。
//
//int largestPerimeter(int* A, int ASize) {
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < ASize; i++){
//		int tmp = A[i];
//		for (j = i - 1; j >= 0 && A[j] > tmp; j--){
//			A[j + 1] = A[j];
//		}
//		A[j + 1] = tmp;
//	}
//	int m = 0;
//	int n = 0;
//	int l = 0;
//	for (i = 2; i < ASize; i++){
//		if (A[i - 2] + A[i - 1] > A[i]){
//			m = A[i - 2];
//			n = A[i - 1];
//			l = A[i];
//		}
//	}
//	return m + n + l;
//}