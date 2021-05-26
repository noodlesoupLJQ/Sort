#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& arr, int l, int r);
int main()
{
	int array[] = { 34,65,12,43,67,5,78,10,3,70 }, k;
	int len = sizeof(array) / sizeof(int);
	cout << "The orginal arrayare:" << endl;
	vector<int> arr(array, array + len);
	for (k = 0; k < arr.size(); k++)
		cout << arr[k] << ",";
	cout << endl;
	quickSort(arr, 0, len - 1);
	cout << "The sorted arrayare:" << endl;
	for (k = 0; k < arr.size(); k++)
		cout << arr[k] << ",";
	cout << endl;
	system("pause");
	return 0;
}
void quickSort(vector<int>& arr, int l, int r)
{
	if (l >= r)
		return;
	int i = l, j = r, x = arr[l];
	while (i < j)
	{
		while (i < j && arr[j] >= x)
			j--;
		if (i < j)
			arr[i++] = arr[j];//填坑之后i++
		while (i < j && arr[j] <= x)
			i++;
		if (i < j)
			arr[j--] = arr[i];
	}
	arr[i] = x;
	quickSort(arr, l, i - 1);//以i为中间值，分左右两部分递归调用
	quickSort(arr, i + 1, r);
}
