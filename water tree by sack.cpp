// By Sack

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


#define mxn 500005

vector<int> g[mxn] , one[mxn] , ask[mxn];

set<int> st[mxn];

set<int> fill_up;

ll lazy[mxn];
ll buck[mxn];
ll ans[mxn];


void dfs(int u , int p){
      buck[u] = u;

      for(auto i : one[u]) fill_up.insert(i); 
      
      for(auto v : g[u]){
         if(v == p) continue;
         dfs(v , u);

         if(st[buck[u]].size() < st[buck[v]].size()) swap(buck[u] , buck[v]);

         for(auto it : st[buck[v]]) st[buck[u]].insert(it); 
               


         
      }


      for(auto idx : ask[u]){
        auto itr = fill_up.lower_bound(idx);
        if(itr == fill_up.begin()) {ans[idx] = 0; continue;}
        itr--;
        auto itr2 = st[buck[u]].lower_bound(idx);
        if(itr2 == st[buck[u]].begin()) {ans[idx] = 1; continue;}
        itr2--;
        if(*itr > *itr2) ans[idx] = 1;
        else ans[idx] = 0;

      }

       for(auto i : one[u]) fill_up.erase(i); 


}


int main(){
       IOS;
    
    int n , u , v;
    cin >> n;
    for(int i = 1;i <= n - 1;i++){
        cin >>u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    


   mem(ans , -1);

    int q;
    cin >> q;
    for(int idx = 1;idx <= q;idx++){
    	int t , l , r;
    	cin >> t >> v;


    	if(t == 1){
        one[v].pb(idx);
       

    	}else if(t == 2){
        st[v].insert(idx);
        

    	}else{
        ask[v].pb(idx);
    	}

    }

    dfs(1 , 0);
   
    for(int i = 1;i <= q;i++){
      if(ans[i] != -1)cout << ans[i] << endl;
    }












return 0;}
