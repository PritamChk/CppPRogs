//Bisection Method
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Raphson
{
	double x[10];
	int n;
	public:
		double fd(double x1);
		double function1(double x1);
		double raphson();
};
double Raphson :: function1(double x1)
{
	double y;
	y=x1*x1-3;
	//y=x1*x1-2;
	//y=(x1-1.01)*(x1-1.02)*(x1-1.03);
	return y;
}
double Raphson :: fd(double x1)
{
	double y;
	y=2*x1;
	return y;
}
double Raphson :: raphson()
{
	double a,b,c,f1,f2,f3,ff;
	double i,h,xg;
	int j;
	a=-10;
	n=0;
	f1=function1(a);
		for(i=-9.999;i<=10;i=i+.001)
		{
			b=i;
			f2=function1(b);
				if(f1*f2<0)
				{
					xg=(a+b)/2;
					do
					{
						h=-function1(xg)/fd(xg);
							if(h<0)
							ff=-h;
							else
							ff=h;
							xg=xg+h;
							if(ff<1e-10)
							{
								x[n++]=xg+h;
								break;
							}
					}while(1==1);
				}
				a=i;
				f1=function1(a);
		}
		//To display roots
		for(j=0;j<n;j++)
		cout<<"Root["<<j<<"]="<<x[j]<<endl;
}
int main()
{
	Raphson R;
	R.raphson();
}	
