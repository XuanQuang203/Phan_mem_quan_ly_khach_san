#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int chiaNguyen = n / 1000;
	int chiaLayDu = n % 1000;
	
	cout << chiaNguyen << " " << chiaLayDu;
}
