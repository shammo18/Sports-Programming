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


#define mxn 500005

int mp2[mxn] , mp1[mxn];
int par_l[mxn];
int deleted[mxn];


int find_par_l(int v){

      if(v == par_l[v]) return v;
      return par_l[v] = find_par_l(par_l[v]);

}




void union_sets_l(int a, int b){

     a = find_par_l(a);
     b = find_par_l(b);

     if(a != b){
        //if(rnk_l[a] < rnk_l[b]) swap(a,b);
        par_l[b] = a;


       // if(rnk_l[a] == rnk_l[b])
        //rnk_l[a]++;
     }

}

int par_r[mxn];


int find_par_r(int v){

      if(v == par_r[v]) return v;
      return par_r[v] = find_par_r(par_r[v]);

}



void union_sets_r(int a, int b){

     a = find_par_r(a);
     b = find_par_r(b);

     if(a != b){
     //   if(rnk_r[a] < rnk_r[b]) swap(a,b);
        par_r[b] = a;


        // if(rnk_r[a] == rnk_r[b])
        //rnk_r[a]++;
     }

}



int main(){
       IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/

  int n , m , p;

  cin >> n >> m >> p;

  string s;
  cin >> s;
  string t;
  cin >> t;

  s = "?" + s;
  t = "?" + t;

  stack<pair<char , int>> stk;



  for(int i = 1;i <= n;i++){
  	if(stk.size() == 0) stk.push({s[i] , i});
  	else if(s[i] == ')'){
  		if(stk.top().xx == '('){
  			mp2[i] = stk.top().yy;
  			mp1[stk.top().yy] = i;
  			  			stk.pop();
  		}
  	}else {
  		stk.push({s[i] , i});
  	}

  	par_r[i] = i;
  	par_l[i] = i;
  }
   
  par_r[n + 1] = n + 1;
  par_l[n + 1] = n + 1;

  for(int i = 1;i <= m;i++){
  	 // cout << p << endl;
     if(t[i] == 'D'){
       int l , r;
       if(s[p] == '('){
         r = mp1[p];
         l = p;
       }else{
         l = mp2[p];
         r = p;
       }

        // cout << l <<" " << r << endl;
       deleted[l]++;
       deleted[r + 1]--;
       union_sets_l(l - 1 , r);
       union_sets_r(r + 1 , l);
       int u  = find_par_r(l);
       int v = find_par_l(r);

       // cout << u << " " << v << endl;

       if(u == n + 1){
             p = v;
       }else p = u;

     }else if(t[i] == 'L'){

        p = find_par_l(p - 1);

     }else {
        p = find_par_r(p + 1);
     }
  }

  for(int i = 1;i <= n;i++){
  	deleted[i] += deleted[i - 1];
  }

  for(int i = 1;i <= n;i++){
  	if(deleted[i] == 0){
  		cout << s[i];
  	}
  }
  cout << endl;













return 0;}
