#include <iostream>
#include <stdio.h>                                                                          
#include <vector>                                                                                                               
#include <algorithm>                                                                
                                                                                
using namespace std;

unsigned long long int val[100000];                                                        
vector<int> nb[100000];                                                        
bool odw[100000];                                                              
                                                                                
void DFS(int a){                                                               
    odw[a] = true;                                                             
    int x;                                                                      
    for (size_t i = 0; i < nb[a].size(); i++)                                  
    {                                                                          
        x = nb[a][i];                                                          
        if(!odw[x]){                                                           
            DFS(x);                                                            
        }  
        if (val[a] < val[x]){                                                   
            val[a] = val[x];                                                   
        }                                                                     
    }                                                                        
    return;                                                                     
}                                                                               
                                                                                
                                                                                
                                                                                
int main() {                                                                   
    int n, m, k; 
    scanf("%d %d %d", &n, &m, &k);                                                              
    //cin >> n >> m >> k; 

    unsigned long long int pom;

    for (int i = 0; i < n; ++i)                                                 
    {             
        scanf(" %llu", &pom); 
        val[i] = pom;                                                          
        //cin >> val[i];                                                      
    }     

    int a, b; 

    for (int i = 0; i < m; ++i)                                                 
    {   
        scanf(" %d %d", &a, &b);                                                                        
        // cin >> a >> b;                                                          
        nb[a-1].push_back(b-1);                                                
    }                                                                         
                                                                                
    for (int i = 0; i < n; ++i)                                                 
    {                                                                           
        if(!odw[i]){                                                            
            DFS(i);                                                            
        }                                                                       
    }                                                            
                                                                                
    sort(val, val+n); 

    cout << val[k-1];                                                           
                                                                              
    return 0;   
}