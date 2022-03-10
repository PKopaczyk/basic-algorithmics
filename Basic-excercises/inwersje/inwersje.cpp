#include <iostream>
using namespace std;

int tree[65536][10];
int main()
{

    int inp[20000];
    int n, k;
    cin >> n >> k;
    int tree_size = 1;

    while (tree_size < n) {
        tree_size <<= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> inp[i];
        inp[i]--;
    }
    int cur, l, r, wyn;
    for (int i = 0; i < n; i++) {
        cur = tree_size + inp[i];
        while (cur > 0) {
            tree[cur][0]++;
            cur >>= 1;
        }
        for (int j = 1; j < k; ++j) {
            cur = tree_size + inp[i];
            l = cur;
            r = tree_size*2-1;
            if(l == r)
                wyn = 0;
            else
                wyn = tree[r][j-1];

            while (l < r - 1) {
                if(l%2 == 0)
                    wyn += tree[l+1][j-1];
                wyn=wyn%1000000000;
                if(r%2 == 1)
                    wyn += tree[r-1][j-1];
                wyn=wyn%1000000000;
                l >>= 1;
                r >>= 1;
            }
            while (cur > 0) {
                tree[cur][j] += wyn;
                tree[cur][j]=tree[cur][j]%1000000000;
                cur >>= 1;
            }
        }
    }
    cout << tree[1][k-1] << endl;

}