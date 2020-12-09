//Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define ll long long 

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

const double eps = 1e-10;

class DivisibleSetDiv1 {
  public:
  string isPossible(vector <int> b) {
      sort(b.begin() , b.end());
      int n = b.size();
      double ck = 0;
      for(int i = 0;i < n;i++){
         ck += 1.0 / (b[i] + 1.0);

      }

      //cout << ck << endl;

      bool flag = true;
      if(ck > 1 + eps) flag = false;
      else if(abs(ck - 1.0)  < eps){
      	for(int i = 1;i < n;i++){
      		if(b[i] == b[i - 1]) flag = false;
      	}
      }

      if(flag) return "Possible";
      else return "Impossible";
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int b[]                   = {2,1};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int b[]                   = {1,1};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int b[]                   = {7, 7, 7};
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int b[]                   = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int b[]                   = {3 , 3 , 1};
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int b[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = DivisibleSetDiv1().isPossible(vector <int>(b, b + (sizeof b / sizeof b[0])));
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
