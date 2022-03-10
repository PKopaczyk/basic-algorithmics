#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    char last = ' ';
    int poz_1 = -1;
    int min_len = 1000003;
    for (int i = 0; i < s.length(); i++) {
        if(last == ' ' && (s[i] > 64 && s[i] < 91)){
            last = s[i];
            poz_1 = i;
        }
        else{
            if((s[i] > 64 && s[i] < 91) && s[i] != last){
                min_len = min(min_len, i - poz_1 - 1);
                poz_1 = i;
                last = s[i];
            }
            else if(s[i] == last){
                poz_1 = i;
            }
        }
    }
    if(min_len == 1000003)
        cout << 1;
    else
        cout << s.length() - min_len;
    return 0;
}