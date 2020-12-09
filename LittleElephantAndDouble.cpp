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

ll func(ll n){
	for(ll i = 1;;i*=2){
		if(i == n) return i;
		if(i > n) break;
	}
	return -1;
}

class LittleElephantAndDouble {
  public:
  string getAnswer(vector <int> A) {
       vector<ll> a;
       for(int i = 0;i < A.size();i++){
       	  a.push_back((ll)A[i]);
       }
       sort(a.begin() , a.end());
       bool flag = true;
       for(int i = 1;i < a.size();i++){
       	  if(a[i] % a[i - 1] == 0){
       	  	  if(func(a[i] / a[i - 1]) != -1){
       	  	  	  a[i] = a[i - 1] * func(a[i] / a[i - 1]);
       	  	  }else flag = false;
       	  }else flag = false;
       }  
       if(flag) return "YES";
       else return "NO";
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
			int A[]                   = {1, 2};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {1, 2, 3};
			string expected__         = "NO";

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {4, 8, 2, 1, 16};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {94, 752, 94, 376, 1504};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {148, 298, 1184};
			string expected__         = "NO";

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {7, 7, 7, 7};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LittleElephantAndDouble().getAnswer(vector <int>(A, A + (sizeof A / sizeof A[0])));
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
