#include<iostream>
#include"Array.h"
#include<time.h>
#include<algorithm>
using namespace std;


int main() {
	Array<int> arr(8, 2);
	cout << arr;
	puts("");
	arr.Resize(9);
	cout << arr;
	puts("");
	if (arr.DeleteAllValue(0)) {
		cout << "All value have been deleted";
	}
	cout << arr;
	//cout << arr2;
	//puts("");
	//Array<int> arr3(7);
	//cin >> arr3;
	//puts("");
	//arr3.DeleteElementValue(2);
	//cout << arr3;
	//puts("");
	//arr3.DeleteElementIndex(2);
	//cout << arr3;
	//puts("");
	//arr3.InsertValue(2, 5);
	//cout << arr3;
	//puts("");
	//arr3.DeleteAllValue(5);
	//cout << arr3;
	//puts("");
	//arr.Swap(arr3);
	//cout << arr3;
	//puts("");
	//cout << arr.Min() << " " << arr.Max();
	//puts("");
	//cout << arr[0];
	//puts("");
	//cout << arr3;
	//arr3 = arr3 + 11;
	//cout << arr3;
	//puts("");
	//arr3 = arr3 + arr;
	//cout << arr3;
	return 0;
}