//wap in c++ to implement Gauss_Seidel method.
//date:17/01/19
//qus 1d
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Gauss_Seidel{
	float a[10][10],b[10],x[10];
	int n;
	public:
		Gauss_Seidel(float x[10][10],float b1[10],int m);
		void seidel_itr();
		void display();
};

Gauss_Seidel :: Gauss_Seidel(float x[10][10],float b1[10],int m){
	int i,j;
	n=m;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				a[i][j]=x[i][j];
				b[i]=b1[i];
		}
}

void Gauss_Seidel :: seidel_itr(){
	float s;
	float xg[10],e[10],eps;
	int i,j,k,itr,flag;
	flag=0;
	itr=0; //itr=no. of iterations
	eps=1e-6;//eps=lowest value of difference of 2 consecutive roots
	//to initialize gauss values
	for(i=0;i<n;i++){
		 x[i]=0; //change
		 xg[i]=0;
	}
	//Jacobi Iteration starts
	while(flag==0){
		flag=1;
		itr=itr+1;
		for(i=0;i<n;i++){
			s=0;
			for(j=0;j<n;j++)
			  if(i!=j)
			  s=s+a[i][j]*x[j]; //change xg->x
			  x[i]=(b[i]-s)/a[i][i];
			  e[i]=x[i]-xg[i];
			  if(e[i]<0)
  		     	e[i]=-e[i];
			}
			//to check value of e[]
			for(i=0;i<n;i++)
			if(e[i]>eps){
				flag=0;
				break;
			}
			//
			for(i=0;i<n;i++)
			xg[i]=x[i];
	}
	    cout<<"\nTotal Number of Iteration: "<<itr;
		display();// to display all roots;
}

void Gauss_Seidel :: display(){
	int i;
	cout<<"\nSolutions of linear Simultanious Equations :\n";
	for(i=0;i<n;i++)
	cout<<"x["<<(i+1)<<"]="<<x[i]<<endl;
}

int main(){
	float a[10][10],b[10];
	int i,j,n;
	system("cls");
	cout<<"\nEnter no. of simultaneous eqn(1-10)= ";
	cin>>n;
	cout<<"\nEnter coeff. of all eqn--->"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<"a["<<(i+1)<<"]["<<(j+1)<<"]=";
			cin>>a[i][j];
		}
		cout<<"b["<<(i+1)<<"]=";
		cin>>b[i];
	}
	Gauss_Seidel J(a,b,n);
	J.seidel_itr();
	
	return 0;
}
