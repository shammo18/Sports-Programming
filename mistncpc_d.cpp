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
#define CASE(a) printf("Case %d:\n",a)
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


#define mxn 100005

vector<int> adj[mxn];
int st[mxn] , et[mxn] , T = -1;
vector<int> arr;
int pos[mxn];
set<int> s;
int vis[mxn];

void dfs(int u , int p){
    
    st[u] = ++T;

	for(auto v : adj[u]){
		if(v == p) continue;
		dfs(v , u);
	}

	arr.pb(u);
	pos[u] = (int)arr.size() - 1;
	et[u] = T;

}


void solve(){


    int n;
    sci(n);
    int u , v;

    for(int i = 0;i < n - 1;i++){
    	scii(u , v);
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    for(int i = 1;i <= n;i++){
    	sort(all(adj[i]));
    }



    T = -1;
    dfs(1 , -1);

    // for(auto w : arr) cout << w <<" "; cout << endl;
    for(int i = 0;i < arr.size();i++) s.insert(i);

   

    int q;
    sci(q);

    while(q--){
    	int type , x , lo , hi;
    	
    	sci(type);

    	if(type == 1){                // update
           
           scii(u , x);
           
           hi = pos[u];
           lo = hi - (et[u] - st[u]);

           auto itr = s.lower_bound(lo);
           if(itr == s.end() || *itr > hi) continue;

           auto itr2 = itr;

           while(x--){
              if(itr2 == s.end() || *itr2 > hi) break;
              vis[arr[*itr2]] = 1;
              itr2++;
           }

           s.erase(itr , itr2);

    	}else{                         // query
           sci(u);
           printf("%d\n", vis[u]);
           


    	}
    }

    for(int i = 0;i <= n;i++){         // clear all
    	adj[i].clear();
    	vis[i] = st[i] = et[i] = pos[i] = 0;
    }

    arr.clear();
    s.clear();



}


int main(){
       //IOS;
    
    int t;
    sci(t);
    int ca = 1;

    while(t--){
    	CASE(ca++);
    	solve();
    }

   




return 0;}
