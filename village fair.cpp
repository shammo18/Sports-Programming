//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
		
#include<bits/stdc++.h>


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
#define pf(a)   printf("%lld\n",a)
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

using namespace std;

///********************************MY CODE STARTS HERE********************************///


#define mxn 100005

vector<int> adj[mxn];
ll cost[mxn];
ll joy[mxn];
set<ll> st[mxn];
ll lazy[mxn];
ll buck[mxn];
ll ans[mxn];
int n , root;


void dfs(int u , int p){
	    buck[u] = u;

      st[buck[u]].insert(joy[u]);
      
      for(auto v : adj[u]){
      	 if(v == p) continue;
      	 dfs(v , u);

      	 if(st[buck[u]].size() < st[buck[v]].size()){
            lazy[buck[v]] += cost[v];
            for(auto it : st[buck[u]]) st[buck[v]].insert(it + lazy[buck[u]] - lazy[buck[v]]); 
             
             swap(buck[u] , buck[v]);
      
          
          }else 
          for(auto it : st[buck[v]]) st[buck[u]].insert(it + cost[v] - lazy[buck[u]] + lazy[buck[v]]); 
               


      	 
      }
      // cout <<" u "  <<u << endl;
      // for(auto it : st[buck[u]]) cout << it <<" "; cout << endl;
      ans[u] = st[buck[u]].size();
}



int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/
    
    sci(n);
    for(int i = 1;i <= n;i++) scl(joy[i]);
    for(int i = 1 , x;i <= n;i++) {
    	sci(x);
    	if(x != 0){
    		//adj[i].pb(x);
    		adj[x].pb(i);
    	}else root = i;
    }

    for(int i = 1;i <= n;i++) scl(cost[i]);
    dfs(root , -1);
    for(int i = 1;i <= n;i++) pf(ans[i]);
    















return 0;}


