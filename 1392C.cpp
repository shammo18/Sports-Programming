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

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define inf INT_MAX
#define eps 1e-9
 
using namespace __gnu_pbds;
using namespace std;


 
#define mxn 200005
 

 
 
int main(){
       IOS;
    
    int T = 1;
    cin >> T;
    while(T--){
             int n;
     cin >> n;
     vector<ll> v(n + 10);

     for(int i = 1;i <= n;i++){
     	cin >> v[i];
     }

     ll ans = 0;

     for(int i = n - 1;i >= 0;i--){
     	if(v[i] > v[i + 1]){
     		ans += v[i] - v[i + 1];
     	}

     }
     cout << ans << endl;
    }
 
return 0;
}