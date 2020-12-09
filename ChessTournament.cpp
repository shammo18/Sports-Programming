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


class ChessTournament {
  public:
  vector <int> nextRound(vector <int> score, vector <int> rating) {
      
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int score[]               = {0,2,4,3,3,2,4,3,0,3};
			int rating[]              = {1923,1882,2103,2210,2027,1988,2320,2294,1736,1864} ;
			int expected__[]          = { 8, 5, 6, 9, 7, 1, 2, 4, 0, 3 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChessTournament().nextRound(vector <int>(score, score + (sizeof score / sizeof score[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int score[]               = {1,2,3,4,1,2,3,4,1,2,3,4,2,3};
			int rating[]              = {2000,2001,2002,2003,2004,2005,2006,2007,2008,2009,2010,2011,2012,1999};
			int expected__[]          = { 4, 9, 12, 11, 0, 8, 13, 10, 5, 1, 7, 3, 2, 6 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChessTournament().nextRound(vector <int>(score, score + (sizeof score / sizeof score[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int score[]               = {0,1000};
			int rating[]              = {1500,3000};
			int expected__[]          = { 1, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChessTournament().nextRound(vector <int>(score, score + (sizeof score / sizeof score[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int score[]               = ;
			int rating[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChessTournament().nextRound(vector <int>(score, score + (sizeof score / sizeof score[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			int score[]               = ;
			int rating[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChessTournament().nextRound(vector <int>(score, score + (sizeof score / sizeof score[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int score[]               = ;
			int rating[]              = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = ChessTournament().nextRound(vector <int>(score, score + (sizeof score / sizeof score[0])), vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
