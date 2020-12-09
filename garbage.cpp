// A C++ program to demonstrate working of Chinise remainder 
// Theorem 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h> 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std; 


template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

int findMinX(int num[], int rem[], int k) 
{ 
    int x = 1; // Initialize result 
  
    // As per the Chinese remainder theorem, 
    // this loop will always break. 
    while (true) 
    { 
        // Check if remainder of x % num[j] is  
        // rem[j] or not (for all j from 0 to k-1) 
        int j; 
        for (j=0; j<k; j++ ) 
            if (x%num[j] != rem[j]) 
               break; 
  
        // If all remainders matched, we found x 
        if (j == k) 
            return x; 
  
        // Else try next numner 
        x++; 
    } 
  
    return x; 
} 


// Driver method 
int main(void) 
{ 
  // int num[] = {2, 3, 5}; 
  // int rem[] = {1, 2, 4}; 
  IOS;
  int num[100005], rem[100005];
  int n;
  cin >> n;
  int l = 1;
  for(int i = 0;i < n;i++) cin >> rem[i];
  for(int i = 0;i < n;i++) {cin >> num[i]; l = lcm(l , num[i]);}

  int k = n;
  
  cout << findMinX(num, rem, k) % l << endl; 
  return 0; 
} 
