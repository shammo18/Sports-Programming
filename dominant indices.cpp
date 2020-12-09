//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
		
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define xx first
#define yy second
#define sci(n) scanf("%d",&n)
#define scii(n,m) scanf("%d%d",&n,&m)
#define sciii(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define sclll(n,m,w) scanf("%lld%lld%lld",&n,&m,&w)
#define pf(a)   printf("%d\n",a)
#define CASE(a) printf("Case %d: ",a)
#define dbg(i) printf("yo %d\n", i)
#define endl '\n'
#define READ  freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout);
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define inf INT_MAX
#define eps 1e-9

using namespace __gnu_pbds;
using namespace std;



///********************************MY CODE STARTS HERE********************************///


#define mxn 1000005

#define maxn 1000005


vector<int> g[mxn];
int col[mxn];
int ans[mxn];


int cnt[maxn];
bool big[maxn];
vector<pii> ask[mxn];

set<pii> st;
int n , q;

int sz[maxn];
void getsz(int v, int p){
    sz[v] = 1;  // every vertex has itself in its subtree
    col[v] = col[p] + 1;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
}

void add(int v, int p, int x){
     
     if(x == -1){
          st.erase({-cnt[col[v]] , col[v]});
          cnt[col[v]]--;
          if(cnt[col[v]] != 0)st.insert({-cnt[col[v]] , col[v]});
     }else{
        
        if(cnt[col[v]] == 0){
          cnt[col[v]]++;
          st.insert({-cnt[col[v]] , col[v]});
        }else{
      //    auto it = st.lower_bound({cnt[col[v]] , col[v]});
          st.erase({-cnt[col[v]] , col[v]});
          cnt[col[v]]++;
          st.insert({-cnt[col[v]] , col[v]});
        }
     }



    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}

void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
        if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    auto itr = st.begin();

    ans[v] = (*itr).yy - col[v];


    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}



int main(){
      // IOS;


  int n;
  sci(n);
  int u , v;
  for(int i = 0;i < n - 1;i++){
     scii(u , v);
     g[u].pb(v);
     g[v].pb(u);
  }

  col[0] = -1;
  getsz(1 , 0);
  dfs(1 , 0 , 0);

  for(int i = 1;i <= n;i++){
  	cout << ans[i] << endl;
  }















return 0;}
