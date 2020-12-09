#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define sl(n) scanf("%lld", &n)
 
vector <ll> ed[100100];
 
bool vis[100100];
 
bool tree;
 
void dfs(ll n, ll p)
{
    vis[n] = 1;
    
    for (ll i = 0; i < ed[n].size(); i++)
    {
        if (vis[ed[n][i]] == 0)
        {
            dfs(ed[n][i], n);
        }
        else if (ed[n][i] != p)
        {
            tree = 0;
        }
    }
}
 
int main ()
{
    ll n, m, x, y, i;
    
    cin >> n >> m;
    
    while(m--)
    {
        sl(x);
        sl(y);
        
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    
    x = 0;
    
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            tree = 1;
            dfs(i, 0);
            if (tree == 1)
                x++;
        }
    }
    
    cout << x << endl;
    
    return 0;
}