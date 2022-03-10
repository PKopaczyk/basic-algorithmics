#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<pair<pair<int, int>, int> > graf[100000][17];
priority_queue<pair<int, pair<int, int> > > not_visited;
string inp;
int odl[100000][17];
bool odw[100000][17];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, u;
	cin >> n >> k >> u >> inp;
	int lo = log2(n)+1;

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < lo; ++j)
    	{
    		graf[i][j].reserve(2);
    		if (inp[i] == '>') {
    			if (i+k < n)
    				graf[i][j].push_back(make_pair(make_pair(i+k, j), 0));
    		}
    		else if (inp[i] == '<') {
    			if (i-k >= 0)
    				graf[i][j].push_back(make_pair(make_pair(i-k, j), 0));
    		}
    		else if (inp[i] == '.') {
    			if (i+1 < n)
    				graf[i][j].push_back(make_pair(make_pair(i+1, j), -1));
    			if (i+(1<<j+1) < n)
    				graf[i][j].push_back(make_pair(make_pair(i+(1<<j+1), j), -1));
    		}
    		else if (inp[i] == '*') {
    			if (i+1 < n)
    				if(j<lo-1)
    					graf[i][j].push_back(make_pair(make_pair(i+1, j+1), -1));
    				else
    					graf[i][j].push_back(make_pair(make_pair(i+1, j), -1));

    			if (i+(1<<j+2) < n){
    				graf[i][j].push_back(make_pair(make_pair(i+(1<<j+2), j+1), -1));
    			}
    		}
    		else if (inp[i] == 'U') {
    			if (i+1 < n)
    				graf[i][j].push_back(make_pair(make_pair(i+1, j), -u-1));
    			if (i+(1<<j+1) < n)
    				graf[i][j].push_back(make_pair(make_pair(i+(1<<j+1), j), -u-1));
    		}
    		else if (inp[i] == '#') {
    		}
    	}
    }


    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < lo; ++j)
    		odl[i][j] = -100000000;

    int maxi = -100000000;
    int a, x, y, ff, fs, s, siz;
    odl[0][0] = 0;
    not_visited.push(make_pair(0, make_pair(0, 0)));
    while (!not_visited.empty()) {
    	a = not_visited.top().first;
    	x = not_visited.top().second.first;
    	y = not_visited.top().second.second;
    	not_visited.pop();
    	if (odw[x][y] == false) {
    		if(x == n-1){
    			cout<<-odl[x][y]<<endl;
    			return 0;
    		}
    		odw[x][y] = true;
			siz = graf[x][y].size();
			for (int i = 0; i < siz; ++i)
			{
				ff = graf[x][y][i].first.first;
				fs = graf[x][y][i].first.second;
				s  = a + graf[x][y][i].second;
				if (odw[ff][fs] == false && s > odl[ff][fs]){
					odl[ff][fs] = s;
					not_visited.push(make_pair(s, make_pair(ff, fs)));
				}
			}
    	}
    }

    cout<<-1<<endl;
}