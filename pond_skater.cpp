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
template <typename T> T Dis(T x1,T lol,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(lol-y2) );}
template <typename T> T Angle(T x1,T lol,T x2, T y2){ return atan( double(lol-y2) / double(x1-x2));}
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


#define mxn 100005


vector<string> grid;
int n , m , k;
int x1 , x2  , lol , y2;


bool valid(int x , int y){

	   if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != '.') return false;
	   return true;
}

ll bfs(int sx , int sy){
	  ll dp[n + 5][m + 5];

      mem(dp , -1);
	  queue<pii> q;
	  q.push({sx, sy});
	  dp[sx][sy] = 0;

	  while(!q.empty()){
	  	pii u = q.front();
	  	q.pop();
        
        for(int i = 1;i <= k;i++){
        	if(!valid(u.xx , u.yy + i))break;
            if(dp[u.xx][u.yy + i] != -1)break;
            dp[u.xx][u.yy + i] = dp[u.xx][u.yy] + 1;
            if(u.xx == x2 && u.yy + i == y2) return dp[x2][y2];
            q.push({u.xx , u.yy + i});
        }

        for(int i = -1;i >= -k;i--){
        	if(!valid(u.xx , u.yy + i)) break;
        	if(dp[u.xx][u.yy + i] != -1) break;
            dp[u.xx][u.yy + i] = dp[u.xx][u.yy] + 1;
            if(u.xx == x2 && u.yy + i == y2) return dp[x2][y2];
            q.push({u.xx , u.yy + i});
        }


        for(int i = 1;i <= k;i++){
        	if(!valid(u.xx + i , u.yy)) break;
        	if(dp[u.xx + i][u.yy] != -1) break;
            dp[u.xx + i][u.yy] = dp[u.xx][u.yy] + 1;
            if(u.xx + i == x2 && u.yy == y2) return dp[x2][y2];
            q.push({u.xx + i , u.yy});
        }

        for(int i = -1;i >= -k;i--){
        	if(!valid(u.xx + i , u.yy)) break;
        	if(dp[u.xx + i][u.yy] != -1) break;
            dp[u.xx + i][u.yy] = dp[u.xx][u.yy] + 1;
            if(u.xx + i == x2 && u.yy == y2) return dp[x2][y2];
            q.push({u.xx + i , u.yy});
        }


	  }
	  return dp[x2][y2];
}

ll bfs2(int sx , int sy){
	  ll dp[n + 5][m + 5];

      mem(dp , -1);
	  queue<pii> q;
	  q.push({sx, sy});
	  dp[sx][sy] = 0;

	  while(!q.empty()){
	  	pii u = q.front();
	  	q.pop();
        
        for(int i = 1;i <= k;i++){
        	if(!valid(u.xx , u.yy + i))break;
            if(dp[u.xx][u.yy + i] != -1)break;
            dp[u.xx][u.yy + i] = dp[u.xx][u.yy] + 1;
            if(u.xx == x1 && u.yy + i == lol) return dp[x1][lol];
            q.push({u.xx , u.yy + i});
        }

        for(int i = -1;i >= -k;i--){
        	if(!valid(u.xx , u.yy + i)) break;
        	if(dp[u.xx][u.yy + i] != -1) break;
            dp[u.xx][u.yy + i] = dp[u.xx][u.yy] + 1;
            if(u.xx == x1 && u.yy + i == lol) return dp[x1][lol];
            q.push({u.xx , u.yy + i});
        }


        for(int i = 1;i <= k;i++){
        	if(!valid(u.xx + i , u.yy)) break;
        	if(dp[u.xx + i][u.yy] != -1) break;
            dp[u.xx + i][u.yy] = dp[u.xx][u.yy] + 1;
            if(u.xx + i == x1 && u.yy == lol) return dp[x1][lol];
            q.push({u.xx + i , u.yy});
        }

        for(int i = -1;i >= -k;i--){
        	if(!valid(u.xx + i , u.yy)) break;
        	if(dp[u.xx + i][u.yy] != -1) break;
            dp[u.xx + i][u.yy] = dp[u.xx][u.yy] + 1;
            if(u.xx + i == x1 && u.yy == lol) return dp[x1][lol];
            q.push({u.xx + i , u.yy});
        }


	  }
	  return dp[x1][lol];
}

const ll INF = 1e17;

ll bfs3(int sx , int sy){
	  ll dp[n + 5][m + 5];

      mem(dp , -1);
	  queue<pii> q;
	  q.push({sx, sy});
	  dp[sx][sy] = 0;

	  int ptr = 0;

	  while(!q.empty()){
	  	pii u = q.front();
	  	q.pop();
	  	ptr++;
	  	if(ptr > 20000000) return INF;
        
        for(int i = 1;i <= k;i++){
        	ptr++;
        		if(ptr > 20000000) return INF;
        	if(!valid(u.xx , u.yy + i))break;
            if(dp[u.xx][u.yy + i] != -1)continue;
            dp[u.xx][u.yy + i] = dp[u.xx][u.yy] + 1;
            if(u.xx == x2 && u.yy + i == y2) return dp[x2][y2];
            q.push({u.xx , u.yy + i});
        }

        for(int i = -1;i >= -k;i--){
        	ptr++;
        		if(ptr > 20000000) return INF;
        	if(!valid(u.xx , u.yy + i)) break;
        	if(dp[u.xx][u.yy + i] != -1) continue;
            dp[u.xx][u.yy + i] = dp[u.xx][u.yy] + 1;
            if(u.xx == x2 && u.yy + i == y2) return dp[x2][y2];
            q.push({u.xx , u.yy + i});
        }


        for(int i = 1;i <= k;i++){
        	ptr++;
        		if(ptr > 20000000) return INF;
        	if(!valid(u.xx + i , u.yy)) break;
        	if(dp[u.xx + i][u.yy] != -1) continue;
            dp[u.xx + i][u.yy] = dp[u.xx][u.yy] + 1;
            if(u.xx + i == x2 && u.yy == y2) return dp[x2][y2];
            q.push({u.xx + i , u.yy});
        }

        for(int i = -1;i >= -k;i--){
        	ptr++;
        		if(ptr > 20000000) return INF;
        	if(!valid(u.xx + i , u.yy)) break;
        	if(dp[u.xx + i][u.yy] != -1) continue;
            dp[u.xx + i][u.yy] = dp[u.xx][u.yy] + 1;
            if(u.xx + i == x2 && u.yy == y2) return dp[x2][y2];
            q.push({u.xx + i , u.yy});
        }


	  }
	  return dp[x2][y2];
}




int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/
   

  sciii(n , m , k);
  scii(x1 , lol);
  scii(x2 , y2);
  char buffer[m + 5];
  x1--; x2--; lol--; y2--;

  string s;

  for(int i = 0;i < n;i++){
      scanf("%s" , buffer);
      s = buffer;
      grid.pb(s);
  }
   
  ll ans = bfs(x1 , lol);
  ans = min(bfs2(x2,y2) , ans);
  ans = min(ans , bfs3(x1 , lol));
  printf("%lld\n", ans );

















return 0;}
