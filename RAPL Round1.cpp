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

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

//ll ncr(ll n,ll r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask | (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
//int bitno(int mask) {return (int)__builtin_popcount(mask);}

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template <typename T> T ABS(T a) {if(a<0)return -a;else return a;}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

///********************************MY CODE STARTS HERE********************************///


#define mxn 505

vector<string> grid(505);


int par[mxn * mxn] , rnk[mxn * mxn];


int find_par(int v){

      if(v == par[v]) return v;
      return par[v] = find_par(par[v]);

}


void union_sets(int a, int b){

     a = find_par(a);
     b = find_par(b);

     if(a != b){
        if(rnk[a] < rnk[b]) swap(a,b);
        par[b] = a;


        if(rnk[a] == rnk[b])
        rnk[a]++;
     }

}

vector<pii> adj[mxn * mxn];

struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

vector<edge> e;

int par2[mxn * mxn] , rnk2[mxn * mxn];


int find_par2(int v){

      if(v == par2[v]) return v;
      return par2[v] = find_par2(par2[v]);

}



void union_sets2(int a, int b){

     a = find_par2(a);
     b = find_par2(b);

     if(a != b){
        if(rnk2[a] < rnk2[b]) swap(a,b);
        par2[b] = a;


        if(rnk2[a] == rnk2[b])
        rnk2[a]++;
     }

}
ll tot = 0;

void mst(){

     sort(all(e));
     for(int i = 0;i <= 500 * 500;i++){
        par2[i] = i;
        rnk2[i] = 0;
     }
     int s = 0;
     for(int i = 0;i < e.size();i++){
        if(find_par2(e[i].u) != find_par2(e[i].v)){
            s += e[i].w;
            //cout << e[i].u <<" " << e[i].v << endl;
            adj[e[i].u].pb({e[i].v , e[i].w});
            adj[e[i].v].pb({e[i].u , e[i].w});
            tot += e[i].w;
            union_sets2(e[i].u , e[i].v);
        }

     }
     
}

bool vis[mxn * mxn];

void dfs(int u , int p){
     vis[u] = true;
	for(auto v : adj[u]){
		if(v.xx == p) continue;
		dfs(v.xx , u);

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


    int n , m;
    cin >> n >> m;

    
    for(int i = 0;i < n;i++){
    	cin >> grid[i];
    }
    
    int pos = -1;
    for(int i = 0;i < n;i++){
    	for(int j =0;j < m;j++){
    	   par[i * m + j] = i * m + j;
    	   if(grid[i][j] == '1') pos = i * m + j;
    	}
    }

    if(pos == -1) return cout << 0 << endl ,0;

    for(int i = 0;i < n;i++){
        int pre = -1;
        int r , c;
        int cnt = 0;
    	for(int j = 0;j < m;j++){
    		if(grid[i][j] == '0') continue;
           if(pre != -1){
           	//cout << grid[i][j] << endl;
           	  if(pre + 1 == j){
                 union_sets(i * m + pre,i * m + j);
           	  }else{
                 int uu = find_par(i * m + pre);
                 int vv = find_par(i * m + j);
                 if(uu != vv){
                 	edge get;
                 	get.u = uu;
                 	get.v = vv;
                 	get.w = j - pre - 1;
                 	e.pb(get);
                    // adj[u].pb({v , j - pre - 1});
                    // adj[v].pb({u , j - pre - 1});
                 }

           	  }
           }
           if(grid[i][j] == '1'){cnt++;pre = j; r = i; c = j;}
    	}


    	pre = -1;

        for(int j = m - 1;j >= 0 ;j--){
    		if(grid[i][j] == '0') continue;
           if(pre != -1){
           	  if(pre == j + 1){
                 union_sets(i * m + pre,i * m + j);
           	  }else{
                 int uu = find_par(i * m + pre);
                 int vv = find_par(i * m + j);
                 if(uu != vv){
                 	edge get;
                 	get.u = uu;
                 	get.v = vv;
                 	get.w = -j + pre - 1;
                 	e.pb(get);
                    // adj[u].pb({v ,  pre - j- 1});
                    // adj[v].pb({u ,  pre - j - 1});
                 }

           	  }
           }
           if(grid[i][j] == '1')pre = j;
    	}
    }

    for(int i = 0;i < m;i++){
        int pre = -1;
        int r , c ,cnt = 0;
    	for(int j = 0;j < n;j++){
    		if(grid[j][i] == '0') continue;
           if(pre != -1){
           	  if(pre + 1 == j){
                 union_sets(pre * m + i,j * m + i);
           	  }else{
                 int uu = find_par(pre * m + i);
                 int vv = find_par(j * m + i);
                 if(uu != vv){
                 	edge get;
                 	get.u = uu;
                 	get.v = vv;
                 	get.w = j - pre - 1;
                 	e.pb(get);

                 }

           	  }
           }
           if(grid[j][i] == '1'){cnt++;pre = j;r = j; c = i;}
    	}


    	pre = -1;

        for(int j = n - 1;j >= 0 ;j--){
    		if(grid[j][i] == '0') continue;
           if(pre != -1){
           	  if(pre == j + 1){
                 union_sets(pre * m + i,j * m + i);
           	  }else{
                 int uu = find_par(pre * m + i);
                 int vv = find_par(j * m + i);
                 if(uu != vv){
                 	edge get;
                 	get.u = uu;
                 	get.v = vv;
                 	get.w = -j + pre - 1;
                 	e.pb(get);
                    // adj[u].pb({v ,  pre - j- 1});
                    // adj[v].pb({u ,  pre - j - 1});
                 }

           	  }
           }
           if(grid[j][i] == '1')pre = j;
    	}
    }
     

    for(int i = 0;i < e.size();i++){
    	//cout << e[i].u << " " << e[i].v <<" " << e[i].w << endl;
    	e[i].u = find_par(e[i].u);
    	e[i].v = find_par(e[i].v);

    }


     mst();
   dfs(find_par(pos) , -1);
   for(int i = 0;i < n;i++){
    	for(int j =0;j < m;j++){
    	   if(grid[i][j] == '1'){
                if(vis[find_par(i * m + j)] == false) return cout << -1 << endl  , 0;
    	   }    
    	}
    }



  

    cout << tot << endl;












return 0;}
