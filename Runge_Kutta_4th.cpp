//4th order runge kutta method
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Runge_Kutta_4{
	public:
		double fun1(double x,double y);
		double runge4(double x0,double y0,double h);
};

double Runge_Kutta_4::fun1(double x,double y){
	double yy;
	yy=y+0*x;
	return yy;
}

double Runge_Kutta_4 :: runge4(double x0,double y0,double h){
	double k1,k2,k3,k4,y1;
	k1 = h*fun1(x0,y0);
	k2 = h*fun1(x0+.5*h,y0+.5*k1);
	k3 = h*fun1(x0+0.5*h,y0+.5*k2);
	k4 = h*fun1(x0+h,y0+k3);
	y1 = y0 +1.0/6.0*(k1+2*k2+2*k3+k4);
	return y1;
}

int main(){
	double x0,y0,y1,h;
	int i,n;
	system("clear");
	cout<<"\nEnter x0 = ";
	cin>>x0;
	cout<<"\nEnter y0 = ";
	cin>>y0;
	cout<<"\nEnter h = ";
	cin>>h;
	cout<<"\nEnter total no. of intervals : ";
	cin>>n;
	cout<<"x = "<<x0<<" y = "<<y0<<endl;
	Runge_Kutta_4 R;
    for(i=1;i<=n;i++){
					  y1=R.runge4(x0,y0,h);
					  x0=x0+h;
					  y0=y1;
					  cout<<"x = "<<x0<<" y = "<<y1<<endl;
	}
	return 0;
}
