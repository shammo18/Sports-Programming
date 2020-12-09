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


	#define mxn 300005

	vector<int> adj[4 * mxn];

	vector<pii> arr;

	void mergeSort(int node, int l, int h)
	{
		if(l == h)
		{
			adj[node].pb(arr[l].yy);
			return ;
		}
		
		int m = (l + h) >> 1;

		mergeSort(node * 2, l, m);
		mergeSort(node * 2 + 1, m + 1, h);

		for(int i = 0, j = 0, curr = l; curr <= h; curr++)
		{
			if(i >= adj[node * 2].size())
				adj [node].pb(adj [node * 2 + 1][j++]);
			else if(j >= adj[node * 2 + 1].size())
				adj [node].pb( adj [node * 2][i++]);
			else if(adj [node * 2][i] < adj [node* 2 + 1][j])
				adj [node].pb ( adj [node * 2][i++]);
			else
				adj [node].pb ( adj [node * 2 + 1][j++] );
		}
	}

	int query(int node,int b,int e,int l,int r,int x){

	        if(b > r || e < l) return 0;
	        if(b >= l && e <= r){
	           int pos = lower_bound(all(adj[node]),x) - adj[node].begin();
	           //for(int i = 0;i < adj[node].size();i++) cout << adj[node][i] <<" ";
	           //cout << adj[node].size() <<" " << pos << endl;
	           return adj[node].size() - pos;
	        }

	        int mid = b + e >> 1;
	        int xx = query(node << 1,b,mid,l,r,x);
	        int y = query(node << 1 | 1, mid + 1 , e,l,r,x);
			
	        return xx + y;

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
	    scii(n , m);

	    for(int i = 0;i < n;i++){
	    	int l , r;
	    	scii(l , r);
	    	arr.pb({l , r});
	    }

	    sort(all(arr));


	    mergeSort(1 , 0 , n - 1);



	    while(m--){
	    	int cnt;
	    	sci(cnt);
	        vector<int> v;
	        for(int i = 0;i < cnt;i++){
	           int x;
	           sci(x);
	           v.pb(x);
	        }

	        sort(all(v));
	        int prev = -1;
	        int tot = 0;
	        for(int i = 0;i < cnt;i++){
	           
	           int lo = 0 , hi = n - 1, pos = -1;

	           while(lo <= hi){
	           	  int mid = (lo + hi) / 2;

	           	  if(arr[mid].xx <= v[i]){
	           	  	 pos = mid;
	           	  	 lo = mid + 1;
	           	  }else hi = mid - 1;
	           }

	           if(pos < prev || pos >= n || prev >= n || pos == -1) continue;
	           int l = prev , r = pos;

	           int ans = query(1 , 0 , n - 1, l , r , v[i]);
	           tot += ans;
	           prev = pos + 1;
	        }


	        printf("%d\n",tot );



	        
	    }














	return 0;}
