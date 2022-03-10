#include <iostream>
#include <set>
#include <string>
using namespace std;

set<pair<int, int> > tree[262144];

int tree_size = 131072;

void delet(int i, pair<int, int> pr){
    while(i < tree_size){
        i <<= 1;
        if(tree[i].find(pr) == tree[i].end())
            i++;
    }
    while(i > 0) {
        tree[i].erase(pr);
        i >>= 1;
    }
}

bool check_in (int l, int b) {
    if(tree[l].empty())
        return false;
    auto it = tree[l].begin();
    if (it->first <= b){
        cout << it->second << " ";
        delet(l, *it);
        return true;
    }
    return false;
}

bool check_over (int l, int b) {
    if(tree[l].empty())
        return false;
    auto it = tree[l].end();
    it--;
    if (it->first >= b){
        cout << it->second << " ";
        delet(l, *it);
        return true;
    }
    return false;
}

bool parser (string s, int a, int b) {
    int l, r;
    if(s == "in") {
        l = a;
        r = b;
        if(check_in(l, b))
            return true;
        if(check_in(r, b))
            return true;
        while (l < r - 1) {
            if (l%2 == 0){
                if(check_in(l+1, b))
                    return true;
            }
            if (r%2 == 1){
                if(check_in(r-1, b))
                    return true;
            }
            l >>= 1;
            r >>= 1;
        }
    }
    if(s == "over") {
        l = tree_size;
        r = a;
        if(check_over(r, b))
            return true;
        while (l < r - 1) {
            if (l%2 == 0){
                if(check_over(l+1, b))
                    return true;
            }
            if (r%2 == 1){
                if(check_over(r-1, b))
                    return true;
            }
            l >>= 1;
            r >>= 1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, x, y, a, b;
    string s;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        tree[tree_size + a].insert(make_pair(tree_size + b, i));
    }

    for (int i = tree_size-1; i > 0; i--) {
        tree[i].insert(tree[2*i].begin(), tree[2*i].end());
        tree[i].insert(tree[2*i+1].begin(), tree[2*i+1].end());
    }

    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> s >> x >> y;
        x += tree_size;
        y += tree_size;
        if(s == "none" && !parser("in", tree_size, x - 1) && !parser("in", y+1, 2*tree_size-1)) {
            cout << -1 << " ";
        }
        else if(s == "some" && !parser("in", x, y) && !parser("over", x, x) && !parser("over", y, y)){
            cout << -1 << " ";
        }
        else if((s == "in" || s == "over") && !parser(s, x, y)){
            cout << -1 << " ";
        }
    }
    return 0;   
}