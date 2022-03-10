#include <iostream>                                                             
#include <string>                                                               
#include <algorithm>    
#include <array>
using namespace std;

int main()
{
	int n, k;
	cin >> n;
	cin >> k;

	long long arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}
	int inp;
	for (int j = 0; j < k; j++) {
		for (int i = 0; i < n; i++) {
			cin >> inp;
			if (i < n / 2) {
				arr[inp-1] *= 2;
			}
			else {
				arr[inp-1] = arr[inp-1] * 2 + 1;
			}
		}
	}
	bool tk = true;
	sort(&arr[0], &arr[0]+n);
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			tk = false;
		}
	}
 	if (tk) {
 		cout << "TAK";
 	}
 	else {
 		cout << "NIE";
 	}
    return 0;
}