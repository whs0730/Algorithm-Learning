#include<iostream>
using namespace std;
void quicksort(int* a, int left, int right) {
	int l = left, r = right, temp = a[left];
	while (l < r) {
		while (l<r && a[r]>temp) {
			r--;
		}
		a[l] = a[r];
		while (l < r && a[l] < temp) {
			l++;
		}
		a[r] = a[l];
	}
	a[l] = temp;
	if (left < right) {
		quicksort(a, left, l - 1);
		quicksort(a, l + 1, right);
	}
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quicksort(a, 0, n - 1);
	cout << "******************************" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete[]a;
	return 0;

}