#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector <vector<int> > wyn;



int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int currVal;
	wyn.reserve(n);

	int currMax = 0;
	int curPos = 0;

	wyn.push_back(vector<int>());

	for (int i = 0; i < n; i++){
		cin >> currVal;
		currMax = max(currMax, currVal);
		if(currMax == i + 1){
			wyn[curPos].push_back(currVal);
			sort(wyn[curPos].begin(), wyn[curPos].end());
			wyn.push_back(vector<int>());
			curPos++;
			currMax = 0;
		}
		else{
			wyn[curPos].push_back(currVal);

		}
	}

	sort(wyn.begin(), wyn.end());

	cout << wyn.size() - 1 << endl;

	int siz;

	for(int i = 1; i <= curPos; i++){
		siz = wyn[i].size();
		cout << siz << " ";
		for (int j = 0; j < siz; j++){
			cout << wyn[i][j] << " ";
		}
		cout << endl;
	}
}