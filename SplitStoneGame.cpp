//Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))


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

int dp[51][51];

bool go(int one , int big){
     
     if(big == 0) return 0;
     if(one + big <= 2) return 0;
     if(dp[one][big] != -1) return dp[one][big];
     bool ret = 0;
     if(big > 2)ret |= go(one , big - 1) ^ 1;
	 if(one >= 1 && big > 1) ret |= go(one - 1 , big) ^ 1; 
	 if(one >= 2) ret |= go(one - 2 , big + 1) ^ 1;
     
     return dp[one][big] = ret;
}

class SplitStoneGame {
  public:
  string winOrLose(vector <int> number) {
      int one =  0 , big = 0;
      for(int i = 0;i < number.size();i++){
      	if(number[i] == 1) one++;
      	else big++;
      }
      //cout << number.size() << endl;
      mem(dp , -1);
      if(go(one , big)) return "WIN";
      else return "LOSE";


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
			int number[]              = {1, 1, 1};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int number[]              = {2, 2};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int number[]              = {1, 1, 2};
			string expected__         = "WIN";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int number[]              = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
			string expected__         = "WIN";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int number[]              = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

        case 5: {
			int number[]              = {1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
     case 6: {
			int number[]              = {1 , 1 ,1 , 2};
			string expected__         = "LOSE";

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int number[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SplitStoneGame().winOrLose(vector <int>(number, number + (sizeof number / sizeof number[0])));
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
