//Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define ll long long 

using namespace std;

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

//ll ncr(long long  n,long long  r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

bool checkbit(int mask,int bit){return mask & (1<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int bitno(int mask) {return (int)__builtin_popcount(mask);}



///********************************MY CODE STARTS HERE********************************///


class OthersXor {
  public:
  long long minSum(vector <int> x) {
      
      
      int n = x.size();
      ll sum = 0;
      for(int i = 0;i < 30;i++){
      	 bool minusone = false;
      	 ll one = 0 , zero = 0 , cnt = 1e17;
      	 for(int j = 0;j < n;j++){
      	 	if(x[j] == -1) {minusone = true ; continue;}
      	 	if(checkbit(x[j] , i)) one++;
      	 	else zero++;
      	 }

      	 if(one % 2 == 0) cnt = min(cnt , one);
      	 if(zero % 2 == 1) cnt = min(cnt , zero);
      	 if(minusone && one % 2 == 1) cnt = min(cnt , one + 1);
      	 if(minusone && zero % 2 == 0) cnt = min(cnt , zero + 1);

      	 if(cnt == 1e17) return -1;
      	 sum += (1<<i) * cnt;
      }

      return sum;


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
			int x[]                   = {1,-1,3};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,0,1};
			long long expected__      = -1;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {70,100};
			long long expected__      = 170;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {-1,0,-1,100,36};
			long long expected__      = 164;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912, 0,536870912,0,536870912,0,536870912,0,536870912,0,536870912, 1073741823,1073741823,1073741823,123456789,987654321,804289383};
			long long expected__      = 11992352010LL;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703};
			long long expected__      = -1;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x[]                   = {-1,-1};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int x[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = OthersXor().minSum(vector <int>(x, x + (sizeof x / sizeof x[0])));
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
