#include<iostream>

using namespace std;

int main() {
	int i;
	cin >> i;

	if (i == 2){
		cout << "NO";
		return 0;
	}
	if (i%2 == 0)
		cout << "YES";
	else 
		cout << "NO";
}
