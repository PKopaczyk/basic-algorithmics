#include <iostream>                                                             
#include <string>                                                               
#include <algorithm>                                                            
#include <cmath>                                                                
#include <vector>                                                               
#include <queue>                                                                
using namespace std; 


int n;
pair<int, pair<int, int> > tree[600000]; //parent, children(left, right)
int depth[600000];
int links[19][600000];
pair<int, int> far[600000];
bool odw[600000];

void countdepth(int pos, int acc){
    if(tree[pos].second.first > 1) {
        countdepth(tree[pos].second.first, acc+1);
    }
    if(tree[pos].second.second > 1){
        countdepth(tree[pos].second.second, acc+1);
    }
    depth[pos] = acc;
}

int ancestor(int v, int h){
    int res = v;
    int i = 31-__builtin_clz(n);
    int p = 1 << i;
    while(h > 0){
        if(p > h){
            i = i-1;
            p >>= 1;
        }
        else{
            res = links[i][res];
            h = h - p;
        }
    }
    return res;
}

int lca(int u, int v){
    int du = depth[u];
    int dv = depth[v];
    if(du < dv) {
        v = ancestor(v, dv - du);
        dv = depth[v];
    }
    else if (du > dv) {
        u = ancestor(u, du - dv);
        du = depth[u];
    }
    if(u == v){
        return u;
    }

    int i = log2(n);
    while(i >= 0){
        if(links[i][u] != links[i][v]){
            u = links[i][u];
            v = links[i][v];
        }
        i--;
    }
    return tree[u].first;
}

int findOneEnd(){
    int max = 1;
    for (int i = 1; i <= n; i++){
        if(depth[max] < depth[i]){
            max = i;
        }
    }
    return max;
}

void fromOneEnd(int start, int v, int acc){
    odw[v] = true;
    if(!odw[tree[v].first]){
        fromOneEnd(start, tree[v].first, acc+1);
    }
    if(tree[v].second.first > 0){
        if(!odw[tree[v].second.first]){
            fromOneEnd(start, tree[v].second.first, acc+1);
        }
    }
    if(tree[v].second.second > 0){
        if(!odw[tree[v].second.second]){
            fromOneEnd(start, tree[v].second.second, acc+1);
        }
    }
    if(acc > far[v].first){
        far[v].first = acc;
        far[v].second = start;
    }
}

void setFalse(){
    for (int i = 1; i <= n; i++){
        odw[i] = false;
    }
}

void linki(int j){
    for (int i = 1; i <= n; i++){
        if(j == 0){
            links[0][i] = tree[i].first;
        }
        else{
            if(links[j-1][i] != -1){
                links[j][i] = links[j-1][links[j-1][i]];
            }
            else{
                links[j][i] = -1;
            }
        }
    }
}

int main()                                                                      
{     
    ios_base::sync_with_stdio(0);                                               
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        far[i].first = 0;
    }


    int a, b;

    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        tree[i].second.first = a;
        tree[i].second.second = b;
        if(a > 1) {
            tree[a].first = i;
        }
        if(b > 1) {
            tree[b].first = i;
        }
    }

    tree[1].first = 1;

    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <=18; j++){
            links[j][i] = -1;
        }
    }

    countdepth(1, 0);

    for(int j = 0; j <=18; j++){
        linki(j);
    }

    setFalse();

    int x = findOneEnd();

    fromOneEnd(x, x, 0);

    x = 0;
    int xw = 0;

    for(int i = 1; i <= n; i++){
        if(far[i].first > x){
            x = far[i].first;
            xw = i;
        }
    }
    setFalse();

    fromOneEnd(xw, xw, 0);


    int m;
    cin >> m;
    int a2, b2;

    int v2, d_max, l2;

    for(int i = 0; i< m; i++){
        cin >> a2 >> b2;
        v2 = far[a2].second;
        d_max = far[a2].first;
        if(b2 > d_max){
            cout << -1 << endl;
        }
        l2 = lca(a2, v2);
        if(b2 <= d_max){
            if(b2 <= depth[a2] - depth[l2]){
                cout << ancestor(a2, b2) << endl;
            }
            else{
                cout << ancestor(v2, d_max - b2) << endl;
            }
        }
    }
}