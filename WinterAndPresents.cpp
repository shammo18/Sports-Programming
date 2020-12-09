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



class WinterAndPresents {
  public:
  long long getNumber(vector <int> apple, vector <int> orange) {
      int lim = 1e9;
  	  for(int i = 0;i < apple.size();i++){
  	  	 lim = min(lim , apple[i] + orange[i]);
  	  }
      sort(apple.begin() , apple.end());
      sort(orange.begin() , orange.end());

      ll n = apple.size();
      ll ptr_a = 0;
      ll ptr_o = 0;
      ll small_a = 0;
      ll small_o = 0;
      ll ans = 0;
      for(ll x = 1; x <= lim;x++){
         while(ptr_a < n && apple[ptr_a] < x){
            small_a += apple[ptr_a];
         	ptr_a++;
         }

         while(ptr_o < n && orange[ptr_o] < x){
            small_o += orange[ptr_o];
         	ptr_o++;
         }

         ll A = small_a + (n - ptr_a) * x;
         ll O = small_o + (n - ptr_o) * x;
         

         if(O > A) swap(O , A);
         O = min(x * n , O);
         A = min(x * n, A);
         //cout << x  << " " << A << " " << O<< endl;
         
         ans += O + 1 - (x * n - A);
         //cout << ans << endl;

      }
     // cout << "-------" << endl;
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
			int apple[]               = {1};
			int orange[]              = {1};
			long long expected__      = 3;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int apple[]               = {1, 2, 0, 3};
			int orange[]              = {4, 5, 0, 6};
			long long expected__      = 0;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int apple[]               = {2, 2, 2};
			int orange[]              = {2, 2, 2};
			long long expected__      = 16;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int apple[]               = {7, 4, 5};
			int orange[]              = {1, 10, 2};
			long long expected__      = 46;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int apple[]               = {1000000};
			int orange[]              = {1000000};
			long long expected__      = 1000002000000LL;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int apple[]               = ;
			int orange[]              = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = WinterAndPresents().getNumber(vector <int>(apple, apple + (sizeof apple / sizeof apple[0])), vector <int>(orange, orange + (sizeof orange / sizeof orange[0])));
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
