/*WAP in c++ to implement gauss elimination methode to solve
Linear simult. Eqn*/
#include<iostream>
using namespace std;
class Gauss_Elimination{
	float a[10][10],b[10],x[10];
	int n;
	public:
		Gauss_Elimination(float x[10][10],float b1[10],int m);
		void gauss_elimination();
		void display();
};

Gauss_Elimination :: Gauss_Elimination(float x[10][10],float b1[10],int m){
	int i,j;
	n=m;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				a[i][j]=x[i][j];
				b[i]=b1[i];
		}
}

void Gauss_Elimination :: gauss_elimination(){
	float am;
	int i,j,k,s=0;
	//to obtain triangular equations
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j){
				am=a[j][i]/a[i][i];
				for(k=0;k<n;k++)
				a[j][k]=a[j][k]-a[i][k]*am;
				b[j]=b[j]-b[i]*am;
			}
		//to apply back substitution method to obtain solutions
		x[n-1]=b[n-1]/a[n-1][n-1];
		for(i=(n-2);i>=0;i--){
			s=0;
			for(j=(i+1);j<n;j++)
			s=s+a[i][j]*x[j];
			x[i]=(b[i]-s)/a[i][i];
		}
		display();// to display all roots;
}

void Gauss_Elimination :: display(){
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
	Gauss_Elimination GE(a,b,n);
	GE.gauss_elimination();
	
	return 0;
}
