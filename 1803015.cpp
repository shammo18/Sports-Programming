#include<bits/stdc++.h>

using namespace std;

double f(double x,double y)
{
    double ans= 1 + ((2.0 * x * y)/(1+x*x));
    return ans;
}


double cal_k(double xo,double yo,double h)
{

    double k1 = h*f(xo,yo);
    double k2 = h*f(xo+h/2.0,yo+k1/2.0);
    double k3 = h*f(xo+h/2,yo+k2/2.0);
    double k4 = h*f(xo+h,yo+k3);

    double k =1.0 / 6.0 * (k1+2*k2+2*k3+k4);

    return k;
}

int main(){


    double h=0.1;
    double x0=0;
    double y0=0;

    double k = cal_k(x0,y0,h);

    double y1=y0+k;

    k = cal_k(0.1,y1,h);
    double y2=y1+k;

    k = cal_k(0.2,y2,h);
    double y3=y2+k;


    cout<<y1<<" "<<y2<<" "<<y3<<endl;



}