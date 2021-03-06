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
#define mod 1000000007LL
#define inf INT_MAX
#define eps 1e-9

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
template <typename T> T Dis(T x1, T y1, T x2, T y2) {return sqrt( SQR(x1 - x2) + SQR(y1 - y2) );}
template <typename T> T Angle(T x1, T y1, T x2, T y2) { return atan( double(y1 - y2) / double(x1 - x2));}
template <typename T> T gcd(T a, T b) {if (a < 0)return gcd(-a, b); if (b < 0)return gcd(a, -b); return (b == 0) ? a : gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {if (a < 0)return lcm(-a, b); if (b < 0)return lcm(a, -b); return a * (b / gcd(a, b));}
template <typename T> T euclide(T a, T b, T &x, T &y) {if (a < 0) {T d = euclide(-a, b, x, y); x = -x; return d;}   if (b < 0) {T d = euclide(a, -b, x, y); y = -y; return d;}   if (b == 0) {x = 1; y = 0; return a;} else {T d = euclide(b, a % b, x, y); T t = x; x = y; y = t - (a / b) * y; return d;}}
template <typename T> void ia (T a[], int n) {for (int i = 0; i < n; i++) cin >> a[i];}
template <typename T> void pa (T a[], int n) {for (int i = 0; i < n - 1; i++) cout << a[i] << " "; cout << a[n - 1] << endl;}
template <typename T> ll isLeft(T a, T b, T c) { return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);}

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

///********************************MY CODE STARTS HERE********************************///



const int N = 1000000 + 5;
int sp[N];
bool prime[N];

void sieve() {

	mem(prime , true);
	for (int i = 2; i * i < N; i++) {
		if (prime[i]) {
			for (int j = i + i; j < N; j += i) {
				if (!sp[j]) sp[j] = i;
				prime[j] = false;
			}
		}
	}

	for (int i = 2; i < N; i++) {
		if (prime[i]) sp[i] = i;
	}
}

unordered_map<int , int > mp;

void solve() {

	int d;
	sci(d);
	ll ans = 1;
	ll tot = 0;
	for (int i = 1; i <= d; i++) {
		int g;
	    sci(g);


       
		if (g > 0) {

			int x = abs(g);
			int prev = sp[x];
			int cnt = 0;

			while (1) {
				if (x == 1 || prev != sp[x]) {
					// cout<< prev << " " << cnt << endl;
                    ans *= ModInv(mp[prev] + 1LL , mod);
                    ans %= mod;
                    mp[prev] += cnt;
                    ans *= (mp[prev] + 1);
                    ans %= mod;
					cnt = 1;
					prev = sp[x];
				} else cnt++;
				if(x == 1) break;
				x = x / sp[x];
				// cout << x<< endl;
			}
			// cout << ans << endl;
		} else {

			int x = abs(g);
			int prev = sp[x];
			int cnt = 0;

			while (1) {
				if (x == 1 || prev != sp[x]) {
					// cout<< prev << " " << cnt << endl;
                    ans *= ModInv(mp[prev] + 1LL , mod);
                    ans %= mod;
                    mp[prev] -= cnt;
                    ans *= (mp[prev] + 1LL);
                    ans %= mod;
					cnt = 1;
					prev = sp[x];
				} else cnt++;
				if(x == 1) break;
				x = x / sp[x];
				// cout << x<< endl;
			}
			// cout << ans << endl;
		}

		//cout << ans << endl;

		tot += ans;
		tot %= mod;
	}
    
    printf("%lld\n",tot);

}


int main() {
	//IOS;

	sieve();
	 // cout << sp[6] << endl;
	int T = 1;
	cin >> T;
	int ca = 1;
	while (T--) {
		CASE(ca++);
		mp.clear();
		solve();
	}

	return 0;
}