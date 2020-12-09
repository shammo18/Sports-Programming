//Bismillahir Rahmanir Rahim

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")
		
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



bool checkbit(int mask,int bit){return mask & (1<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int bitno(int mask) {return (int)__builtin_popcount(mask);}

///********************************MY CODE STARTS HERE********************************///


#define mxn 100005
int n;
int lim;
vector<pii> v;
int dp[1<<16];


inline int same_traingle(pii A,pii B,pii C)
{
    return A.xx*(B.yy-C.yy) + B.xx*(C.yy-A.yy) + C.xx*(A.yy-B.yy) ;
}

int call(int mask){
        
        
       int &ret1 = dp[mask];
       if(ret1 != -1) return ret1;

    int cnt = 0 ;
    cnt = n - __builtin_popcount(mask);
    if(cnt==1) return ret1 = 1 ;
    if(cnt==0) return ret1 = 0 ;
    ret1 = 1e9 ;

       for(int i = 0;i < n;i++){
        if(!checkbit(mask , i)){
       	  for(int j = 0;j < n;j++){

       	 	if(i != j &&  !checkbit(mask , j)){
               int temp = mask;
               temp = setbit(mask , i);
               for(int k = 0;k < n;k++){
               	  if(i != k  && same_traingle(v[i] , v[j] , v[k]) == 0){
                     temp = setbit(temp , k);
               	  }
               }
               ret1 = min(ret1,call(temp) + 1);
               
       	 	}
       	 	
       	  }
          break;
       	}

          
       }

       return ret1;


}

void solve(){
    
    mem(dp , -1);
    v.clear();

	sci(n);


	for(int i = 0;i < n;i++){
		int x, y;
		scii(x, y);
		v.pb({x,y});
	}


   
	int ans = call(0);
	printf("%d\n", ans);


}

int main(){
       //IOS;
       
    #ifndef ONLINE_JUDGE
      READ;
      WRITE;
    #endif

    int t;
    sci(t);
    int ca = 1;
    while(t--){
    	CASE(ca++);
    	solve();
    }













return 0;}
