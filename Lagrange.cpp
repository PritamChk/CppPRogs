//LAGRANGE
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Lagrange{
	public:
		double lagrange(double x[20],double y[20],double xx,int n);
};
double Lagrange::lagrange(double x[20],double y[20],double xx,int n){
	double diff_table[20][20],s,num1,den1,yy;
	int i,j;
	//to calculate Lagrange Diff table 
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          if(i==j)
             diff_table[i][j]=xx-x[i];
          else
          	  diff_table[i][j]=x[i]-x[j];
    //TO DISPLAY ELEMENTS IN LAGRANGE DIFFERENCE TABLE
    cout<<endl<<"ELEMENTS IN LAGRANGE DIFFERENCE TABLE:\n";
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++)
    	cout<<diff_table[i][j]<<"\t";
      cout<<endl;
	}
	//To calculate Value of y at x=xx;
	s=0;
	for(i=0;i<n;i++){
		num1=1;
		den1=1;
		 for(j=0;j<n;j++)
		  if(i!=j){
		  	 num1=num1*diff_table[j][j];
		  	 den1=den1*diff_table[i][j];
		  }
		  s=s+num1/den1*y[i];
	}
	yy=s;
	cout<<"x="<<xx<<" y="<<yy<<endl;
	return yy;
}

int main(){
	double x[20],y[20],yy,xx;
	int i,n;
	system("cls");
	cout<<"\nEnter no. of points : ";
	cin>>n;
	cout<<"\nEnter "<<n<<" x point and y points one by one -->\n";
	for(i=0;i<n;i++){
		cout<<"x["<<(i+1)<<"]= ";
		cin>>x[i];
		cout<<"y["<<(i+1)<<"]= ";
		cin>>y[i];
	}
	cout<<"\nEnter Your new x value=";
	cin>>xx;
	Lagrange L;
	yy=L.lagrange(x,y,xx,n);
	return 0;
}
