#include <iostream>
using namespace std;
void Josephus(int* a, int n, int s, int m) {
	for (int i = n; i >= 2; i--) {
		s = (s + m - 1) % i;//mod
		int tmp = a[s];
		for (int j = s; j < i - 1; j++) {
			a[j] = a[j + 1];
		}
		a[i - 1] = tmp;
	}
	for (int i = 0; i < n / 2; i++) {
		int tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}
int main() {
	cout << "enter the length of array:" << endl;
	int n;
	cin >> n;
	cout << "enter the a:" << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "enter the s and m" << endl;
	int s, m;
	cin >> s;
	cin >> m;
	Josephus(a, n, s, m);
	cout << "input the a" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}