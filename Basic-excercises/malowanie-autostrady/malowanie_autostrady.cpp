#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

set<pair<pair<int, int>, int> > autostrada;
// set<pair<pair<int, int>, int> >::iterator it;
int wyn = 0;

// void dodaj(int a, int b, char c){
//     if(c == 'B'){
//         autostrada.insert(make_pair(make_pair(a, b), 1));
//         wyn = wyn + b - a + 1;
//     }
//     else
//         autostrada.insert(make_pair(make_pair(a, b), 0));
// }

void dodaj(int a, int b, int c){
    if(c == 1){
        autostrada.insert(make_pair(make_pair(a, b), 1));
        wyn = wyn + b - a + 1;
    }
    else
        autostrada.insert(make_pair(make_pair(a, b), 0));
}

void usun(set<pair<pair<int, int>, int> >::const_iterator iter){
    if(iter->second == 1)
        wyn = wyn - iter->first.second + iter->first.first - 1;
    autostrada.erase(iter);
}

int main()
{
    int n, k, a, b, a_pom, b_pom, c, c_pom;
    cin >> n >> k;
    autostrada.insert(make_pair(make_pair(1, n), 0));
    char cx;
    set<pair<pair<int, int>, int> >::const_iterator lower;
    set<pair<pair<int, int>, int> >::const_iterator upper;

    for(int i = 0; i < k; i++) {
        cin >> a >> b >> cx;
        if(cx == 'B')
            c = 1;
        else
            c = 0;
        lower = autostrada.upper_bound(make_pair(make_pair(a, n), 1));
        upper = autostrada.upper_bound(make_pair(make_pair(b, n), 1));
        lower--;
        upper--;
        a_pom = lower->first.first;
        b_pom = lower->first.second;
        c_pom = lower->second;
        if(b_pom >= b) {
            usun(lower);
            dodaj(a, b, c);
            if(a - a_pom > 0) {
                dodaj(a_pom, a - 1, c_pom);
                //cout << c_pom << endl;
            }
            if(b_pom - b > 0) {
                dodaj(b + 1, b_pom, c_pom);
                //cout << c_pom << endl;
                
            }
        }
        else{
            while(upper!=lower){
                usun(lower++);
            }
            if(a - a_pom > 0) {
                dodaj(a_pom, a - 1, c_pom);
            }
            b_pom = upper->first.second;
            c_pom = upper->second;
            usun(upper);
            if(b_pom - b > 0)
                dodaj(b+1, b_pom, c_pom);
            dodaj(a, b, c);
        }
        cout << wyn << endl;
    }
    return 0;

}