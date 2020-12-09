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
#define endl '\n'
#define READ  freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout);
#define PI acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define inf (double)(1LL<<55)
#define eps 1e-3

using namespace __gnu_pbds;
using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

//ll ncr(ll n,ll r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask | (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
//int bitno(int mask) {return (int)__builtin_popcount(mask);}

template <typename T> T BigMod (T b, T p, T m) {if (p == 0) return 1; if (p % 2 == 0) {T s = BigMod(b, p / 2, m); return ((s % m) * (s % m)) % m;} return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;}
template <typename T> T ModInv (T b, T m) {return BigMod(b, m - 2, m);}
template <typename T> T POW(T B, T P) { if (P == 0) return 1; if (P & 1) return B * POW(B, P - 1);  else return SQR(POW(B, P / 2));}
template <typename T> T Dis(T x1, T y1, T x2, T y2) {return ( SQR(x1 - x2) + SQR(y1 - y2) );}
template <typename T> T Angle(T x1, T y1, T x2, T y2) { return atan( double(y1 - y2) / double(x1 - x2));}
template <typename T> T gcd(T a, T b) {if (a < 0)return gcd(-a, b); if (b < 0)return gcd(a, -b); return (b == 0) ? a : gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {if (a < 0)return lcm(-a, b); if (b < 0)return lcm(a, -b); return a * (b / gcd(a, b));}
template <typename T> T euclide(T a, T b, T &x, T &y) {if (a < 0) {T d = euclide(-a, b, x, y); x = -x; return d;}   if (b < 0) {T d = euclide(a, -b, x, y); y = -y; return d;}   if (b == 0) {x = 1; y = 0; return a;} else {T d = euclide(b, a % b, x, y); T t = x; x = y; y = t - (a / b) * y; return d;}}
template <typename T> void ia (T a[], int n) {for (int i = 0; i < n; i++) cin >> a[i];}
template <typename T> void pa (T a[], int n) {for (int i = 0; i < n - 1; i++) cout << a[i] << " "; cout << a[n - 1] << endl;}
template <typename T> ll isLeft(T a, T b, T c) { return (a.xx - b.xx) * (b.yy - c.yy) - (b.xx - c.xx) * (a.yy - b.yy);}

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

///********************************MY CODE STARTS HERE********************************///


#define mxn 100005

struct ob
{
	double xl , yl , xh , yh , xw , yw;
};

struct point 
{
	 double x, y;
};

double area(point a  , point b , point c){
       
      double u =  abs(0.5 * ((a.x * b.y) + (b.x * c.y) + (c.x * a.y) - (a.x * c.y) - (b.x * a.y) - (c.x * b.y)));
     if(u <= eps){
     	return inf;
     }else return u;
}

bool isInside(double x , double y , ob r){
    
    if(r.yw != inf){
    	//cout << "hi" << endl;
       double tot = area({r.xl , r.yl} , {r.xh , r.yh} , {r.xw , r.yw});
       double temp = 0 ;
       temp += area({x , y} , {r.xl , r.yl} , {r.xh , r.yh});
       temp += area({x , y} , {r.xh , r.yh} , {r.xw , r.yw});
       temp += area({x , y} , {r.xw , r.yw} , {r.xl , r.yl});
        if(abs(temp - tot) < eps){
        	return true;
        }else return false;
      
    }else if(r.yh != inf){
	  if(x > r.xl && x < r.xh && y > r.yl && y < r.yh) return true;
	  return false;
	}else{
      if(Dis(x , y , r.xl , r.yl) < r.xh * r.xh){
      	return true;

      }else return false;
	}
}

void solve() {

	vector<ob> v;
	while (1) {
		char ch;
		cin >> ch;
		if (ch == 'r') {
			double a , b , c , d;
			cin >> a >> b >> c >> d;

			v.pb({a , d , c , b , inf , inf});
		} else if(ch == 'c') {
			double a , b , r;
			cin >> a >> b >> r;
			v.pb({a , b , r , inf , inf , inf});
		} else if(ch == 't'){
            double a , b , c , d , e , f;
            cin >> a >> b >> c >> d >> e >> f;
            v.pb({a , b , c , d , e , f});
		}else break;
	}


	int c = 1;
	while (1) {
		double a , b;
		cin >> a >> b;
		if (a == 9999.9 && b == 9999.9) break;
		bool flag = false;
		for (int i = 0; i < v.size(); i++) {
			if (isInside(a , b , v[i])){
				printf("Point %d is contained in figure %d\n", c , i + 1);
                flag = true;
			}
			}

			if(!flag) printf("Point %d is not contained in any figure\n", c);
	        c++;
	}

}


int main() {
	//IOS;

	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}