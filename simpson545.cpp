//Simpson's1/3 Rule
#include<iostream>
using namespace std;
class Simpson
{
	public :
		double function1(double x);
		double simpson(double a,double b,long int n);
};
double Simpson :: function1(double x)
{
	double y;
	y=4/(1+x*x);
	return y;
}
double Simpson :: simpson(double a,double b,long int n)
{
	long int i;
	double s1,s2,s3,h,is;
	h=(b-a)/n;
	s1=function1(a)+function1(b);
	s2=0;//to get sum of even
	s3=0;//to get sum of odd
	for(i=1;i<=n;i++)
		if(i%2==0)	
		s2=s2+function1(a+i*h);
		else
		s3=s3+function1(a+i*h);
	is=1.0/3.0*h*(s1+2*s2+4*s3);
	cout<<"Number of Intervals="<<n<<" Value of Integral using Simpson's 1/3 Rule= "<<is<<endl;
	return is;
}
int main()
{
	double a,b,is;
	long int n;
	system("cls");
	cout<<"\nEnter lower limit= ";
	cin>>a;
	cout<<"\nEnter upper limit= ";
	cin>>b;
	cout<<"Enter total no of intervals= ";
	cin>>n;
	Simpson S;
	is=S.simpson(a,b,n);
	return 0;
}
