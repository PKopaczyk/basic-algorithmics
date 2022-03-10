#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1000][1000];
    int inp[1000];
    if (n == 1) {
        cout<<"1\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (inp[i] < inp[i+1]){
            arr[i+1][i] = 1;
            arr[i][i+1] = 1;
        }
        else {
            arr[i+1][i] = 0;
            arr[i][i+1] = 0;
        }
    }
    for (int i = 2; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            arr[j][j+i] = 0;
            arr[j+i][j] = 0;
            if (inp[j] < inp[j+i]) {
                arr[j][j+i] += arr[j+i-1][j];
                arr[j+i][j] += arr[j+1][j+i];
            }
            if(inp[j] < inp[j+1]){
                arr[j+i][j] += arr[j+i][j+1];
            }
            if(inp[j+i-1] < inp[j+i]){
                arr[j][j+i] += arr[j][j+i-1];
            }
            arr[j][j+i] %= 1000000000;
            arr[j+i][j] %= 1000000000;
        }
    }
    cout<<(arr[0][n-1]+arr[n-1][0])%1000000000;
    return 0;
}