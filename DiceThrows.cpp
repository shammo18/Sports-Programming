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

vector<int> v[2] ;
vector<double> a(20005) , b(20005);
double dp[205][20005];

double go(int steps , int id , int sum){
    
    if(steps == 0){
    	if(sum == 0) return 1;
    	else return 0;
    }
    if(dp[steps][sum] != -1.0) return dp[steps][sum];
    double ret = 0;
	for(int i = 0;i < 6;i++){
       if(sum - v[id][i] >= 0)ret += go(steps - 1 , id , sum - v[id][i]);
	}
	return dp[steps][sum] = ret / 6.0;
}

class DiceThrows {
  public:
  double winProbability(int numDiceA, vector <int> sidesA, int numDiceB, vector <int> sidesB) {
      v[0] = sidesA;
      v[1] = sidesB;
      for(int i = 0;i <= 200;i++)
      	for(int j = 0;j <= 20000;j++)
      		dp[i][j] = -1.0;

      for(int i = 1;i <= 20000;i++){
      	 a[i] = go(numDiceA , 0 , i);
      }

      for(int i = 0;i <= 200;i++)
      	for(int j = 0;j <= 20000;j++)
      		dp[i][j] = -1.0;
      	
      double ans = 0;
      for(int i = 1;i <= 20000;i++){
      	 b[i] = go(numDiceB , 1 , i);
      	 b[i] += b[i - 1];
      	 ans += a[i] * (b[i - 1]);
      }

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
			int numDiceA              = 1;
			int sidesA[]              = {1,2,3,4,5,6};
			int numDiceB              = 1;
			int sidesB[]              = {1,2,3,4,5,6};
			double expected__         = 0.41666666666666663;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numDiceA              = 200;
			int sidesA[]              = {1,3,8,18,45,100};
			int numDiceB              = 200;
			int sidesB[]              = {1,4,10,21,53,100};
			double expected__         = 0.25240407058279035;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numDiceA              = 2;
			int sidesA[]              = {1,1,1,2,2,2};
			int numDiceB              = 3;
			int sidesB[]              = {1,1,1,1,1,1};
			double expected__         = 0.25;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numDiceA              = 200;
			int sidesA[]              = {6,5,4,3,2,1};
			int numDiceB              = 200;
			int sidesB[]              = {3,4,6,5,1,2};
			double expected__         = 0.49416239842107595;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numDiceA              = 100;
			int sidesA[]              = {1,1,1,1,1,2};
			int numDiceB              = 199;
			int sidesB[]              = {1,1,1,1,1,1};
			double expected__         = 1.5306467074865068E-78;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int numDiceA              = ;
			int sidesA[]              = ;
			int numDiceB              = ;
			int sidesB[]              = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numDiceA              = ;
			int sidesA[]              = ;
			int numDiceB              = ;
			int sidesB[]              = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int numDiceA              = ;
			int sidesA[]              = ;
			int numDiceB              = ;
			int sidesB[]              = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = DiceThrows().winProbability(numDiceA, vector <int>(sidesA, sidesA + (sizeof sidesA / sizeof sidesA[0])), numDiceB, vector <int>(sidesB, sidesB + (sizeof sidesB / sizeof sidesB[0])));
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
