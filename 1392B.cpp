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

/********************************MY CODE STARTS HERE********************************///
 
 
#define mxn 200005
 

 
 
int main(){
       IOS;
    
    int T = 1;
    cin >> T;
    while(T--){
        ll n , k;
     cin >> n >> k;

     vector<ll> v(n);
     ll mmmx = -1e15;
     
     int x , y  , z;
     bool flag = false;

     for(int i= 0;i < n;i++){
     	cin >> v[i];
     	if(v[i] < 0) flag = true;
     	mmmx = max(mmmx , v[i]);
     }

     if(flag){
        k--;
        for(int i = 0;i < n;i++) v[i] = mmmx - v[i];
     }


     if(k == 0){
     	for(int i = 0;i < n;i++) cout << v[i] <<" ";
     	cout << endl;
        continue;


     }
     mmmx = -1e15;

     for(int i = 0;i < n;i++){
     	mmmx = max(mmmx , v[i]);
     }
     
     for(int i = 0;i < n;i++){
     	v[i] = mmmx - v[i];
     }
     k--;
     mmmx = -1e17;

     for(int i = 0;i < n;i++){
     	mmmx = max(mmmx , v[i]);
     }


     if(k & 1){
     	          for(int i = 0;i < n;i++){
           v[i] = mmmx - v[i];
     }
     }

          for(int i = 0;i < n;i++){
           cout << v[i] <<" ";
     }
     cout << endl;

    }
 
return 0;
}