//Bismillahir Rahmanir Rahim		
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
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}

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


#define mxn 100005




int main(){
       //IOS;
       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif

    int t;
    cin >> t;
    int ca = 1;
    while(t--){

    	cout <<"Case #" << ca++ <<": ";


      int n;
      cin >> n;
      vector<string> start , finish;
      string ans;
      for(int i = 0;i < n;i++){
      	string s;
      	cin >> s;
        string one , two;
        int a , b;
      	for(int j = 0;j < s.size();j++){
      		if(s[j] == '*'){ a = j;break;}
            one.pb(s[j]);
      	}
      	for(int j = s.size() - 1;j >= 0;j--){
      		if(s[j] == '*'){b = j;break;}
           two.pb(s[j]);
      	}
      	for(int j = a;j <= b;j++){
      		ans.pb(s[j]);
      	}

        int x = 100 - one.size();
        while(x--){
        	one.pb('*');
        }

        x = 100 - two.size();
           while(x--){
        	two.pb('*');
        }

        start.pb(one);
        finish.pb(two);


      }
       bool flag = true;
       for(int i = 0;i < 100;i++){
       	char ch = '*';
       	 for(int j = 0;j < n;j++){
       	 	if(start[j][i] != '*' && ch == '*'){
       	 		ch = start[j][i];
       	 	}
       	 	if(start[j][i] != ch && start[j][i] != '*'){
       	 		flag = false;
       	 		break;
       	 	}
       	 }
       	 if(flag == false) break;

       	 if(ch == '*') ch = 'A';
       	 for(int j = 0; j < n;j++){
             start[j][i] = ch; 
       	 }
       }

             bool flag2 = true;
       for(int i = 0;i < 100;i++){
       	char ch = '*';
       	 for(int j = 0;j < n;j++){
       	 	if(finish[j][i] != '*' && ch == '*'){
       	 		ch = finish[j][i];
       	 	}
       	 	if(finish[j][i] != ch && finish[j][i] != '*'){
       	 		flag2 = false;
       	 		break;
       	 	}
       	 }
       	 if(flag2 == false) break;

       	 if(ch == '*') ch = 'A';
       	 for(int j = 0; j < n;j++){
             finish[j][i] = ch; 
       	 }
       }

       if(flag == false || flag2 == false){
       	cout << "*" << endl;
       }else {

           string p;
           p = start[0];
           p = p + ans;
           reverse(all(finish[0]));
           p = p + finish[0];
           for(int i = 0;i < p.size();i++){
           	if(p[i] == '*')p[i] = 'A';
           }
                  cout << p << endl;

       }




      }



    













return 0;}
