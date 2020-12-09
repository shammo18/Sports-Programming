#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

const int N = 4000000 + 10;

int tot_node = 1;
int to[N][65];
int cnt_last[N];
int under[N];
vector<int> adj[N];


inline void add_edge(int u , int v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void addstring(string &s){

	  int cur = 1;
	  for(int i = 0;i < s.size();i++){
	  	int c;
	  	if(s[i] >= '0' && s[i] <= '9') c = s[i] - '0';
	  	else if(s[i] >= 'a' && s[i] <= 'z') c = s[i] - 'a' + 10;
	  	else c = s[i] - 'A' + 36;

        if(!to[cur][c]) {to[cur][c] = ++tot_node; add_edge(cur , tot_node);}
        
        cur = to[cur][c];
        under[cur]++;


      }
      
      cnt_last[cur]++;

}


inline ll func(ll n){
	return (n * (n - 1)) / 2;
}

ll cnt = 0;


void dfs(int u, int p){
    
    for(auto v : adj[u]){
      if(v == p) continue;
      dfs(v , u);
    }
    
    ll sum = 0;
    for(auto v : adj[u]){
      if(v == p) continue;
      sum += under[v];
    }  
    ll temp = 0;

    for(auto v : adj[u]){
      if(v == p) continue;
      temp += (sum - under[v]) * under[v];

    } 
    cnt += temp / 2;   





}

int main(){
       IOS;

   
   int n;
   int ca = 1;
   while(1){


     cin >> n;
     if(n == 0) return 0;

     mem(to , 0);
     mem(cnt_last , 0);
     mem(under , 0);


     tot_node = 1;
     cnt = 0;


   	 for(int i = 0;i < n;i++){
   	 	string s;
   	 	cin >> s;
        
        addstring(s);

   	 }


     dfs(1 , 0);

     for(int i = 2;i <= tot_node;i++){

        ll niche = under[i] - cnt_last[i];
        
        cnt += func(under[i]) * 2;
        cnt += func(cnt_last[i]) * 2;
        cnt += niche * cnt_last[i];

        adj[i].clear();

     }

     adj[1].clear();

     cout << "Case " << ca++ << ": " << cnt << endl;

   }













return 0;}
