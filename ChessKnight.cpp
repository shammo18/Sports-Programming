//Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>

using namespace std;

int dx[] = {2,1,2,-1,-2,-2,1,-1};
int dy[] = {1,2,-1,2,1,-1,-2,-2};

//ll ncr(long long  n,long long  r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask | (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
//int bitno(int mask) {return (int)__builtin_popcount(mask);}



///********************************MY CODE STARTS HERE********************************///

double m;

bool valid (int x , int y){
	if(x >= 1 && x <= 8 && y >= 1 && y <= 8) return true;
	else return false;
}

double dp[9][9][105];

double go(int x , int y , int rem){
    
    if(rem == 0) return 1.0;
    if(dp[x][y][rem] != -1.0) return dp[x][y][rem];
    double ret = 0;

	for(int i = 0;i < 8;i++){
		int X = x + dx[i];
		int Y = y + dy[i];
        
		if(valid(X , Y)){
			ret += go(X , Y , rem - 1);
		}

	}
	ret = ret / 8.0;
	return dp[x][y][rem] = ret;
}

class ChessKnight {
  public:
  double probability(int x, int y, int n) {
       m = n;
       //cout << go(x , y , n) << endl;
       for(int i = 0;i < 9;i++){
       	for(int  j = 0;j < 9;j++){
       		for(int k = 0;k <= n;k++){
       			dp[i][j][k] = -1.0;
       		}
       	}
       }
       double ans = go(x , y , n);
       return ans;
  }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}
	
	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int x                     = 1;
			int y                     = 1;
			int n                     = 2;
			double expected__         = 0.1875;

			std::clock_t start__      = std::clock();
			double received__         = ChessKnight().probability(x, y, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 4;
			int y                     = 4;
			int n                     = 1;
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = ChessKnight().probability(x, y, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 2;
			int y                     = 3;
			int n                     = 10;
			double expected__         = 0.0522148497402668;

			std::clock_t start__      = std::clock();
			double received__         = ChessKnight().probability(x, y, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 4;
			int y                     = 3;
			int n                     = 50;
			double expected__         = 8.356427906809618E-7;

			std::clock_t start__      = std::clock();
			double received__         = ChessKnight().probability(x, y, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x                     = ;
			int y                     = ;
			int n                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = ChessKnight().probability(x, y, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x                     = ;
			int y                     = ;
			int n                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = ChessKnight().probability(x, y, n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x                     = ;
			int y                     = ;
			int n                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = ChessKnight().probability(x, y, n);
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
