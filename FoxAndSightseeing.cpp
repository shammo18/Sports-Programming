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


class FoxAndSightseeing {
  public:
  int getMin(vector <int> position) {
      int n = position.size();
      int tot = 0 , mn = 1e9;
      for(int i = 1;i <= n - 1;i++){
      	tot += abs(position[i] - position[i - 1]);
      }

      for(int i = 1;i < n - 1;i++){
      	mn = min(mn , tot + abs(position[i + 1] - position[i - 1]) - abs(position[i] - position[i - 1]) - abs(position[i + 1] - position[i]));
      }




      return mn;
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
			int position[]            = {1, 4, -1, 3};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int position[]            = {-2, 4, 3};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int position[]            = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int expected__            = 9;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int position[]            = {100, -100, 99, -99};
			int expected__            = 199;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int position[]            = {74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38};
			int expected__            = 836;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int position[]            = {2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71};
			int expected__            = 535;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int position[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int position[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int position[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
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
