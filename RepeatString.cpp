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

int dp[66][66];

int EditDistance(const string &a , const string &b){
	mem(dp , 0x3f3f3f3f);
	int n = a.size();
	int m = b.size();



    for(int i = 0;i <= n;i++){
    	dp[i][0] = i;
    }

    for(int j = 0;j <= m;j++){
    	dp[0][j] = j;
    }

    for(int i = 1;i <= n;i++){
    	for(int j = 1;j <= m;j++){
    		int cost = 0;
    		if(a[i - 1] != b[j - 1]) cost = 1;
    		dp[i][j] = min({dp[i - 1][j] + 1 , dp[i][j - 1] + 1 , dp[i - 1][j - 1] + cost});
    	}
    }
    return dp[n][m];
}

class RepeatString {
  public:
  int minimalModify(string s) {
  	string a = s;
  	int ans=0,i,j,k,lcs[60][60];
        string s1,s2;
        for(k=0;k+1<s.size();k++)
        {
            s1="$"+a.substr(0,k+1);
            s2="#"+a.substr(k+1);
            for(i=0;i<60;i++) lcs[0][i]=lcs[i][0]=0;
            for(i=1;i<s1.size();i++)
            {
                for(j=1;j<s2.size();j++)
                {
                    if(s1[i]==s2[j]) lcs[i][j]=lcs[i-1][j-1]+1;
                    else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
            ans=max(ans,2*lcs[s1.size()-1][s2.size()-1]);
        }
        return ans;
      // int n = s.size();
      // int mn = n;
      // for(int i = 1;i <= n - 1;i++){
      //    mn = min(mn , EditDistance(s.substr(0 , i) , s.substr(i)));
      // }
      // return mn;
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
			string s                  = "aba";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "adam";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "x";
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "aaabbbaaaccc";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "repeatstring";
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string s                  = "aaaaaaaaaaaaaaaaaaaa";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = RepeatString().minimalModify(s);
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
