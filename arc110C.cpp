// C++ program to count inversions using Binary Indexed Tree
#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
ll getSum(ll BITree[], ll index)
{
    ll sum = 0; // Initialize result
 
    // Traverse ancestors of BITree[index]
    while (index > 0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 

void updateBIT(ll BITree[], ll n, ll index, ll val)
{
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       BITree[index] += val;
 
       index += index & (-index);
    }
}
 
// Returns inversion count arr[0..n-1]
ll getInvCount(ll arr[], ll n)
{
    ll invcount = 0; // Initialize result
 
    // Find maximum element in arr[]
    ll maxElement = 0;
    for (ll i=0; i<n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];

    ll BIT[maxElement+1];
    for (ll i=1; i<=maxElement; i++)
        BIT[i] = 0;

    for (ll i=n-1; i>=0; i--)
    {
        // Get count of elements smaller than arr[i]
        invcount += getSum(BIT, arr[i]-1);
 
        // Add current element to BIT
        updateBIT(BIT, maxElement, arr[i], 1);
    }
 
    return invcount;
}
 
// Driver program
int main()
{    
    ll m;
    cin >> m;
    ll arr[m];
    vector<ll> id(m + 5);

    for(ll i = 0;i < m;i++) {
        cin >> arr[i];
        id[arr[i]] = i;
     }
    ll n = sizeof(arr)/sizeof(ll);
     ll x =  getInvCount(arr,n);
     //cout << x << endl;
     if(x == n - 1){

        ll cur = m;
        int y = m - 1;

        while(1){
            for(int i = id[cur];i < cur - 1;i++){
                cout << i + 1 << endl;
                swap(id[arr[i]] , id[arr[i + 1]]);
                swap(arr[i] , arr[i + 1]);
            }
            cur--;
            if(cur == 0) return 0;
        }
          
     }else cout << -1 << endl;
        
    return 0;
}