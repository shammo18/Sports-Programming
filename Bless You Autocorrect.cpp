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

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

///********************************MY CODE STARTS HERE********************************///


const int N = 2e6+7;            ///Highest length of string

int tot_node = 1; // # GLobal nodes

int to[N][27];
int most_common[N];

vector<string> v;
string sob;
int suru[N];


const int  LG = 20;
int lvl[N] , P[N][LG];
vector<int> g[N];



void dfs(int u, int par){
    lvl[u] = 1 + lvl[par];
    P[u][0] = par;
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

void init(){
	int n = tot_node;

    for(int i = 0;i < LG;i++){
        for(int j = 0;j < n + 1;j++) P[j][i] = -1;
    }

    lvl[0] = -1;
    dfs(1,0);

    for(int  i=1; i < LG; i++){
        for(int j = 1;j < n + 1;j++)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}

}





// Finding LCA

int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);

    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }

    if (u == v)
    	return u;

    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}




//returns the distance between
//two nodes "u" and "v".
int dis(int u, int v){
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = lca(u, v);
    return lvl[u] + lvl[v] - 2*lvl[w];
}



inline void add_edge(int u , int v){
    g[u].pb(v);
    g[v].pb(u);
}

void addstring(string &s , int id){

	  int cur = 1;
	  for(int i = 0;i < s.size();i++){
	  	int c = s[i] - 'a';
        if(!to[cur][c]) {
        	 to[cur][c] = ++tot_node;
        	 most_common[tot_node] = id;
        	 add_edge(cur , tot_node);
        }
        
        cur = to[cur][c];
        // under[cur]++;


      }

      ses_hoiche[tot_node] = ;

}

void query(string &t){

       int cur = 1;
       for(int i = 0;i < t.size();i++){
          int c = t[i] - 'a';
          if(!to[cur][c]) return 0;
          
          

          cur = to[cur][c];

          string s = v[most_common[cur]];





       }



}





int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/
  
  hashPre();
  int n , m;
  cin >> n >> m;
  string buffer;

  for(int i = 0;i < n;i++){
     cin >> buffer;
     v.pb(buffer);
     addstring(buffer , i);


  }

  init();

  for(int i = 0;i < m;i++){
  	cin >> buffer;
  	query(buffer);

  }



return 0;}
