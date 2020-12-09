#include<bits/stdc++.h>
#define ll long long
#define N 10000007
using namespace std;

vector<bool> mark(N);
vector<int> prime;

void sieve(){
    mark[1] = 1;
    for(int i = 3; i*i < N; i+=2){
        if(!mark[i]){
           for(int j = i*i ;j<N;j += i){
              mark[j] = 1;
           }
        }
    }
    prime.push_back(2);
    for(int i = 3;i<N;i+=2)if(!mark[i])prime.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    sieve();
    cout << prime.size() << endl;
    int t;
    cin>>t;
    for(int ca =1;ca<=t;ca++){
        int n;
        cin>>n;
        int ans = 0;
        for(int i = 0;prime[i]<=n/2;i++){
            if(!mark[n - prime[i]] && ((n - prime[i])%2==1 || (n - prime[i]) == 2))ans++;
        }
        cout<<"Case "<<ca<<": ";
        cout<<ans<<endl;
    }
    return 0;
}