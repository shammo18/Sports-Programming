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


string t;
int n;
int dp[20][20];


int solve(int pos , int prev){

     if(pos >= n){
     	if(prev == n - 1){;
     		return 0;
     	}
     	else return 2e9;
     }
     int ret = 2e9;
     ret = min(ret , solve(pos + 1,prev));
     if(t[prev] == 'R'){
        if(t[pos] == 'G') ret = min(ret , solve(pos + 1,pos) + (pos - prev) * (pos - prev));
     }else if(t[prev] == 'G'){
        if(t[pos] == 'B') ret = min(ret , solve(pos + 1,pos) + (pos - prev) * (pos - prev));
     }else{
        if(t[pos] == 'R') ret = min(ret , solve(pos + 1,pos) + (pos - prev) * (pos - prev));
     }
     return ret;
}


class ColorfulRoad {
  public:
  int getMin(string road) {
      n = road.size();
      t = road;
      // cout << t << endl;
      int ans = solve(1 , 0);
      // cout << ans << endl;
      if(ans > 1000) ans = -1;
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
			string road               = "RGGGB";
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string road               = "RGBRGBRGB";
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string road               = "RBBGGGRR";
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string road               = "RBRRBGGGBBBBR";
			int expected__            = 50;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string road               = "RG";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string road               = "RBRGBGBGGBGRGGG";
			int expected__            = 52;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string road               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string road               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string road               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ColorfulRoad().getMin(road);
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
