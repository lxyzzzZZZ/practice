//976
//������һЩ�����������ȣ���ɵ����� A����������������������ɵġ������Ϊ��������ε�����ܳ���
//
//��������γ��κ������Ϊ��������Σ����� 0��
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