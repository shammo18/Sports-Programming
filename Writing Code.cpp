//Bismillahir Rahmanir Rahim

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
		
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
#define inf INT_MAX
#define eps 1e-9

using namespace __gnu_pbds;
using namespace std;


///********************************MY CODE STARTS HERE********************************///


#define mxn 502
int mod;
int n , m , b;
int cost[mxn];

int dp[2][mxn][mxn];

int main(){
       //IOS;
/*       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif 
*/

    
    cin >> n >> m >> b >> mod;

    for(int i = 1;i <= n;i++){
    	cin >> cost[i];
    }
     

    dp[0][0][0] = 1;
    
    int row = 1;

    for(int i = 0;i <= m;i++){
        row ^= 1;

        for(int j = 0;j <= n;j++){
    		for(int k = 0;k <= b;k++){
    		    dp[row][j][k] = 0;
             
    		}
    	}

    	if(i == 0) dp[0][0][0] = 1;   
    


       for(int j = 1;j <= n;j++){
    		for(int k = 0;k <= b;k++){
    		   
    		   if(i > 0 &&  k - cost[j] >= 0)dp[row][j][k] = (dp[row][j][k] % mod +  dp[row^1][j][k - cost[j]] % mod ) % mod;

    		   if(j > 0)dp[row][j][k] =(dp[row][j][k] % mod +  dp[row][j - 1][k] % mod) % mod;	
             
    		}
    	}

    }


    int ans = 0;
    for(int i = 0;i <= b;i++){
        
    	ans += dp[row][n][i];
    	ans %= mod;
    }
    //cout << dp[row][n][b] << endl;

    cout << ans  << endl;















return 0;}
