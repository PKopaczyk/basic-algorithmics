#include <iostream>                                                             
#include <string>                                                               
#include <algorithm>                                                            
#include <cmath>                                                                
#include <vector>                                                               
#include <queue>                                                                
using namespace std; 


bool comp(pair<pair<int, int>, int> i, pair<pair<int, int>, int> j){
	return i.first.second > j.first.second;
}

int main()                                                                      
{                                                                               
    ios_base::sync_with_stdio(0);                                               
    cin.tie(0);

    int n;
    cin >> n;

	priority_queue<pair<int, int> > not_visited;                        
    pair<pair<long long, long long>, int> inp[n];
    vector<pair<int, long long> > nb[n];
    bool odw[n];
    long long odl[n];

    for(int i = 0; i < n; i++){
    	odw[i] = 0;
    	odl[i] = 100000000000;
    }

    int a, b;

    for(int i = 0; i < n; i++){
    	cin >> a >> b;
    	inp[i] = make_pair(make_pair(a, b), i);
    }

    sort(inp, inp + n);

    nb[inp[0].second].push_back(make_pair(inp[1].second, min(abs(inp[1].first.first - inp[0].first.first), abs(inp[1].first.second - inp[0].first.second))));
    nb[inp[n-1].second].push_back(make_pair(inp[n-2].second, min(abs(inp[n-1].first.first - inp[n-2].first.first), abs(inp[n-2].first.second - inp[n-1].first.second))));

	for(int i = 1; i < n - 1; i++){
		nb[inp[i].second].push_back(make_pair(inp[i+1].second, min(abs(inp[i+1].first.first - inp[i].first.first), abs(inp[i+1].first.second - inp[i].first.second))));
		nb[inp[i].second].push_back(make_pair(inp[i-1].second, min(abs(inp[i].first.first - inp[i-1].first.first), abs(inp[i-1].first.second - inp[i].first.second))));
    }

    sort(inp, inp + n, comp);

    nb[inp[0].second].push_back(make_pair(inp[1].second, min(abs(inp[1].first.first - inp[0].first.first), abs(inp[1].first.second - inp[0].first.second))));
    nb[inp[n-1].second].push_back(make_pair(inp[n-2].second, min(abs(inp[n-1].first.first - inp[n-2].first.first), abs(inp[n-2].first.second - inp[n-1].first.second))));

	for(int i = 1; i < n - 1; i++){
		nb[inp[i].second].push_back(make_pair(inp[i+1].second, min(abs(inp[i+1].first.first - inp[i].first.first), abs(inp[i+1].first.second - inp[i].first.second))));
		nb[inp[i].second].push_back(make_pair(inp[i-1].second, min(abs(inp[i].first.first - inp[i-1].first.first), abs(inp[i-1].first.second - inp[i].first.second))));
    }

    // for(int i = 0; i < n; i++){
    // 	int z = nb[i].size();
    // 	for(int j = 0; j < z; j++) {
    // 		cout << nb[i][j].first << "." <<  nb[i][j].second << " ";
    // 	}
    // 	cout << endl;
    // }
                                            
    odl[0] = 0;                                                              
    not_visited.push(make_pair(0, 0)); 
    int od, num, od2, num2, siz;                           
    while (!not_visited.empty()) {                                              
        od = -not_visited.top().first;                                            
        num = not_visited.top().second;                                   
        not_visited.pop();                                                      
        if (odw[num] == false) {                                               
            if(num == n-1){                                                       
                cout<<odl[num]<<endl;                                         
                return 0;                                                       
            }                                                                   
            odw[num] = true;   
            siz = nb[num].size();                                            
            for (int i = 0; i < siz; ++i)                                       
            {                                                                   
                num2 = nb[num][i].first;                                 
                od2 = od + nb[num][i].second;                              
                if (odw[num2] == false && od2 < odl[num2]){                   
                    odl[num2] = od2;                                            
                    not_visited.push(make_pair(-od2, num2));          
                }                                                               
            }                                                                   
        }                                                                       
    }                                                                           
                                                                                
    cout<<-1<<endl;                                                             
}