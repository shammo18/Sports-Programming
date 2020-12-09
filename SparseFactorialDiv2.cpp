//Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>

using namespace std;

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

//ll ncr(long long  n,long long  r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask | (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
//int bitno(int mask) {return (int)__builtin_popcount(mask);}



///********************************MY CODE STARTS HERE********************************///

#define ll long long 

map<ll , bool> mp;

ll func(ll n , ll p){
	ll ret = 0;
	for(ll i = n , j = 0;;i = n -  j * j){
        if(mp[(j * j) % p] == false)ret += i / p , mp[(j*j) % p] = true;
		j++;
		if(i < 0 || i / p == 0) break;
	}
	return ret;
}

class SparseFactorialDiv2 {
  public:
  long long getCount(long long lo, long long hi, long long divisor) {
       mp.clear();
       ll a  =  func(hi , divisor);
       mp.clear();
       ll b = func(lo - 1 , divisor);
       return a - b;

  }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			long long lo              = 4;
			long long hi              = 8;
			long long divisor         = 3;
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long lo              = 9;
			long long hi              = 11;
			long long divisor         = 7;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long lo              = 1;
			long long hi              = 1000000000000LL;
			long long divisor         = 2;
			long long expected__      = 999999999999LL;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long lo              = 16;
			long long hi              = 26;
			long long divisor         = 11;
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long lo              = 10000;
			long long hi              = 20000;
			long long divisor         = 997;
			long long expected__      = 1211;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long lo              = 123456789;
			long long hi              = 987654321;
			long long divisor         = 71;
			long long expected__      = 438184668;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			long long lo              = ;
			long long hi              = ;
			long long divisor         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long lo              = ;
			long long hi              = ;
			long long divisor         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long lo              = ;
			long long hi              = ;
			long long divisor         = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = SparseFactorialDiv2().getCount(lo, hi, divisor);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
