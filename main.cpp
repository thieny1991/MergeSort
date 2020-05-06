#include<iostream>

void mergeSort(int num[],int left,int right);
void merge(int num[],int left, int mid,int right);
using namespace std;
int main() {

	int num[] = { 8,4,5,0,1, 9, 3, 9, 6, 2, 7 };
	mergeSort(num, 0, 10);

	for (int i = 0;i < 11;i++)
		cout << num[i] << endl;
	system("pause");
	return 0;
}

void mergeSort(int num[],int left, int right)
{
	if (left < right) {
		//find pivot 
		int mid = (left + right) / 2;
		mergeSort(num, left, mid);
		mergeSort(num, mid + 1, right);
		merge(num, left, mid, right);

	}
}

void merge(int num[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	int n = right - left + 1;
	int *temp = new int[n];

	while (i <= mid &&j <= right) {
		if (num[i] < num[j]) {
			temp[k] = num[i];
			k++;
			i++;
		}
		else {
			temp[k] = num[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		temp[k] = num[i];
		k++;
		i++;
	}
	while (j <= right) {
		temp[k] = num[j];
		k++;
		j++;
	}
	i = left;
	for (k = 0;k < n;k++) {
		num[i] = temp[k];
		i++;
	}
	delete[] temp;
	temp = nullptr;
}



