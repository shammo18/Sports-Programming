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
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define lol 10000000
#define eps 1e-9
 
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
///********************************MY CODE STARTS HERE********************************///
 
 
#define mxn 300005
int n;
string s;
int mem[mxn][2][2];


int can(int pos , int a , int b , int one , int two){
    
    if(pos == n){
    	if(one == b && one == two) return lol;
        if(one == b && one == a) return lol;
        
        return 0;
    }

    int mn = lol;

    if(mem[pos][a][b] != -1) return mem[pos][a][b];

	if(a == 0 && b == 0){
		int cost = 0;
	   if(s[pos] == 'L') cost = 1;
       mn = min(mn , can(pos + 1 , b , 1 , one , two) + cost);
	}else if(a == 1 && b == 1){
	   int cost = 0;
	   if(s[pos] == 'R') cost = 1;
       mn = min(mn , can(pos + 1 , b , 0 , one , two) + cost);
	}else{
	   int cost = 0;
	   if(s[pos] == 'R') cost = 1;
	   mn = min(mn , can(pos + 1 , b , 0 , one , two) + cost);
	   cost = 0;
	   if(s[pos] == 'L') cost = 1;
	   mn = min(mn , can(pos + 1 , b , 1 , one , two) + cost);
	}

	return mem[pos][a][b] = mn;
}

 

 
 
int main(){
       IOS;
    
    int T = 1;
    cin >> T;
    while(T--){


            cin >> n;
    cin >> s;

    for(int i = 0;i <= n + 3;i++){
    	for(int j = 0 ;j < 2;j++){
    		for(int k = 0;k < 2;k++){
    			mem[i][j][k] = -1;
    		}
    	}
    }

    // int ans = can(2 , 0 , 0 , 0 , 0);
    int cost = 0;
    if(s[0] == 'R') cost++;
    if(s[1] == 'R') cost++;
    int one = can(2 , 0 , 0 , 0 , 0) + cost;

    for(int i = 0;i <= n + 3;i++){
    	for(int j = 0 ;j < 2;j++){
    		for(int k = 0;k < 2;k++){
    			mem[i][j][k] = -1;
    		}
    	}
    }
    cost = 0;
    if(s[0] == 'L') cost++;
    if(s[1] == 'R') cost++;

    int three = can(2 , 1 , 0 , 1 ,0  ) + cost;

    for(int i = 0;i <= n + 3;i++){
    	for(int j = 0 ;j < 2;j++){
    		for(int k = 0;k < 2;k++){
    			mem[i][j][k] = -1;
    		}
    	}
    }
    cost = 0;
    if(s[0] == 'L') cost++;
    if(s[1] == 'L') cost++;
    int four = can(2 , 1 , 1 , 1 , 1) + cost;

        for(int i = 0;i <= n + 3;i++){
    	for(int j = 0 ;j < 2;j++){
    		for(int k = 0;k < 2;k++){
    			mem[i][j][k] = -1;
    		}
    	}
    }
    cost = 0;
    if(s[0] == 'R') cost++;
    if(s[1] == 'L') cost++;
    int two = can(2 , 0 , 1 , 0 , 1) + cost;

    int ans = min({one , two , three , four});
    cout << ans << endl;
    }
 
return 0;
}