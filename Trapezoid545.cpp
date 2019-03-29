//Trapezoidal Rule
#include<iostream>
using namespace std;
class Trapezoid
{
	public :
		double function1(double x);
		double trapezoid(double a,double b,long int n);
};
double Trapezoid :: function1(double x)
{
	double y;
	y=4/(1+x*x);
	return y;
}
double Trapezoid :: trapezoid(double a,double b,long int n)
{
	long int i;
	double s1,s2,h,it;
	h=(b-a)/n;
	s1=function1(a)+function1(b);
	s2=0;
	for(i=1;i<=n;i++)
	s2=s2+function1(a+i*h);
	it=.5*h*(s1+2*s2);
	cout<<"Number of Intervals="<<n<<"Value of Integral using Trapezoidal Rule= "<<it<<endl;
	return it;
}
int main()
{
	double a,b,it;
	long int n;
	system("cls");
	cout<<"\nEnter lower limit= ";
	cin>>a;
	cout<<"\nEnter upper limit= ";
	cin>>b;
	cout<<"Enter total no of intervals= ";
	cin>>n;
	Trapezoid T;
	it=T.trapezoid(a,b,n);
	return 0;
}
