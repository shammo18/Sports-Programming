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

using namespace std;


///********************************MY CODE STARTS HERE********************************///


#define mxn 100005

int val[mxn];

const int  LG = 20;
int lvl[mxn] , P[mxn][LG];
vector<int> g[mxn];

int n , q;   // Global node value***

void dfs(int u, int par){
    if(par != -1)lvl[u] = 1 + lvl[par];
    P[u][0] = par;
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

void init(){
	
    for(int i = 0;i < LG;i++){
        for(int j = 0;j < n + 1;j++) P[j][i] = -1;
    }

    lvl[0] = 0;
    dfs(0,-1);

    for(int  i=1; i < LG; i++){
        for(int j = 1;j < n + 1;j++)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}

}



// Get the Kth parent from u
int getkthpar(int u , int dis){   

     // dis = lvl[u] - dis;
    int i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++); lg--;
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= dis)
            u = P[u][i];
    }
    return u;

}





void solve(){

	scii(n , q);
	val[0] = 1;

	for(int i = 1;i < n;i++){
		int u , v;
	    scii(u , v);
	    g[i].pb(u);
	    g[u].pb(i);
	    val[i] = v;
	}
    
    init();

    while(q--){
    	int u , v;
    	scii(u , v);
        
        int lo = 0 , hi = lvl[u] , res = -1;
        //cout << hi << endl;
        while(lo <= hi){
        	int mid = (lo + hi) / 2;
        	int id = getkthpar(u , mid);
        	int cur = val[id];
        	if(cur >= v){
                hi = mid - 1;
                res = id;
        	}else{
                lo = mid + 1;
        	}
        }

        printf("%d\n",res);

    }

    for(int i = 0;i <= n;i++) g[i].clear() , lvl[i] = 0;

}


int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/

    int t;
    sci(t);
    int ca = 1;
    while(t--){
    	CASE(ca++);
    	solve();
    }













return 0;}
