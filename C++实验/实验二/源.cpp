#include <iostream>
#include <string>

using namespace std;

void BubbleSort(int* arr, int size){
	for (int i = 0; i < size; i++){
		int tmp = arr[i];
		for (int j = i + 1; j < size; j++){
			if (arr[i] > arr[j]){
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}
void deplay(int* arr, int size){
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(){
	int arr[10] = { 1, 2, 4, 5, 6, 4, 3, 1, 4, 9 };
	int size = sizeof(arr) / sizeof(arr[1]);
	BubbleSort(arr, size);
	deplay(arr, size);
	system("pause");
}