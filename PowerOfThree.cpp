//Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>

using namespace std;


#define pb push_back


///********************************MY CODE STARTS HERE********************************///

vector<int> base_to_three(int n){
	vector<int> v;
	while(1){
		int q = n / 3;
		int r = n % 3;
		v.pb(r);
		if(q == 0) break;
		n = q;
	}
	return v;
}

class PowerOfThree {
  public:
  string ableToGet(int x, int y) {
  	x = abs(x); y = abs(y);

      vector<int> X = base_to_three(x);
      vector<int> Y = base_to_three(y);
      int g = 30 - X.size();

      while(g--)X.pb(0);        //packed by zero
      g = 30 - Y.size();
      while(g--) Y.pb(0);

      for(int i = 0;i < 30;i++){

      	  if(X[i] == 3) X[i + 1]++ , X[i] = 0;
      	  if(Y[i] == 3) Y[i + 1]++ , Y[i] = 0;


     

      	 if(X[i] != 0 && Y[i] == 0){
      	 	if(X[i] == 2){
      	 		X[i + 1]++;
      	 	}
      	 }else if(X[i] == 0 && Y[i] != 0){
      	 	if(Y[i] == 2){
      	 		Y[i + 1]++;
      	 	}
      	 }else {
      	 	if(X[i] == 0 && Y[i] == 0){
      	  	for(int j = i;j < 30;j++) if(X[j] != 0 || Y[j] != 0) return "Impossible";
      	    }else return "Impossible";
      	 }

      }

      return "Possible";




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
			int x                     = 1;
			int y                     = 3;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 0;
			int y                     = 2;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 1;
			int y                     = 9;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = 3;
			int y                     = 0;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = 1;
			int y                     = 1;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = -6890;
			int y                     = 18252;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x                     = 1000000000;
			int y                     = -1000000000;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			int x                     = 0;
			int y                     = 0;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PowerOfThree().ableToGet(x, y);
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
