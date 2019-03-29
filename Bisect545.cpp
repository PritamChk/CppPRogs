//Bisection Method
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Bisection
{
	double x[10];
	int n;
	public:
		double function1(double x1);
		double bisection();
};
double Bisection :: function1(double x1)
{
	double y;
	//y=x1*x1 -3;
	y=x1*x1-2;
	//y=(x1-1.01)*(x1-1.02)*(x1-1.03);
	return y;
}
double Bisection :: bisection()
{
	double a,b,c,f1,f2,f3,ff;
	double i;
	int j;
	a=-10;
	n=0;
	f1=function1(a);
		for(i=-9.99;i<=10;i=i+.01)
		{
			b=i;
			f2=function1(b);
				if(f1*f2<0)
				{
					do
					{
						c=(a+b)/2;
						f3=function1(c);
							if(f1*f3<0)
							{
								b=c;
								f2=function1(b);
							}
							else if(f2*f3<0)
							{
								a=c;
								f1=function1(a);
							}
							if(f3<0)
							ff=-f3;
							if(ff<1e-10)
							{
								x[n++]=c;
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
	Bisection B;
	B.bisection();
}	
