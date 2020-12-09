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

int n;
vector<int> w;
int dp[55][2222];

int solve(int pos , int cur){

	if(pos == n){
		return 0;
	}
	if(dp[pos][cur] != -1) return dp[pos][cur];
    int ret = solve(pos + 1 , cur - min(cur , w[pos]));
	if(cur + w[pos] >= 2200){
		if(pos == n - 1){
                ret = max(ret , solve(pos + 1, 2222) + 1);

		}else{
			if(cur + w[pos] - min(w[pos + 1] , cur + w[pos]) < 2200){
				ret = max(ret , solve(pos + 2 , cur + w[pos] - min(w[pos + 1] , cur + w[pos])) + 2);
			}
		}
	}else{
		ret = max(ret, solve(pos + 1, cur + w[pos]));
	}

    return dp[pos][cur] = ret;
}

class TypoCoderDiv1 {
  public:
  int getmax(vector <int> D, int X) {
      n = D.size();
      w = D;

      memset(dp , -1 , sizeof dp);
      int ans = solve(0 , X);
      cout << ans << endl;
      return ans;


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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int D[]                   = {100,200,100,1,1};
			int X                     = 2000;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int D[]                   = {0,0,0,0,0};
			int X                     = 2199;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int D[]                   = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
			int X                     = 0;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int D[]                   = {1000000000,1000000000,10000,100000,2202,1};
			int X                     = 1000;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int D[]                   = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
			int X                     = 2199;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int D[]                   = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
			int X                     = 1223;
			int expected__            = 29;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int D[]                   = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
			int X                     = 1328;
			int expected__            = 20;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int D[]                   = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int D[]                   = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int D[]                   = ;
			int X                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TypoCoderDiv1().getmax(vector <int>(D, D + (sizeof D / sizeof D[0])), X);
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
