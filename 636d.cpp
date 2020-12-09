#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483646;
 
#define ll long long
 
int sign(ll x)
{
  if (x > 0)
    return 1;
  else
    return -1;
}
 
int main()
{
  int t;
  cin >> t;
 
  while (t--)
  {
    int n;
    cin >> n;
    ll x;
    ll sum = 0;
    int l = 1;
    ll mx_p = 0;
    ll mx_n = -INF;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      if (i == 0)
      {
        l = sign(x);
        // cout << "****" << l << "\n";
        if (l == 1)
          mx_p = x;
        else
          mx_n = x;
 
        if (n == 1)
          sum = x;
        continue;
      }
      // cout << "***" << i;
      if (i == n - 1)
      {
        if (sign(x) != l)
        {
          if (l == 1)
            sum += mx_p;
          else
            sum += mx_n;
          sum += x;
          break;
        }
        else
        {
          if (l == 1)
            sum += max(mx_p, x);
          else
            sum += max(mx_n, x);
 
          break;
        }
      }
      if (l == 1)
      {
        if (sign(x) == 1)
        {
          mx_p = max(mx_p, x);
        }
        else
        {
          l = -1;
          sum += mx_p;
          mx_p = 0;
          mx_n = x;
        }
      }
      else if (l == -1)
      {
        if (sign(x) == -1)
        {
          mx_n = max(mx_n, x);
        }
        else
        {
          l = 1;
          sum += mx_n;
          mx_n = -INF;
          mx_p = x;
        }
      }
    }
    cout << sum << "\n";
  }
 
  return 0;
}