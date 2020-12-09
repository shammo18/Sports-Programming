#include<iostream>
#include<cctype>
#include<cstdio>


using namespace std;

int main()
{

    char c;

    bool pro=true;

    while((c=getchar()) != EOF){
        if(pro){

            cout<<c;
            pro=false;
        }
        else if(c=='.'||c=='?'||c=='!'){

            cout<<c;
            pro = true;
        }
        else{

            c=tolower(c);
            cout<<c;
        }
    }



    return 0;
}