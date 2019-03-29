//Matrix Inversion
#include<iostream>
using namespace std;
class Mat_Inv
{
	float a[10][10],b[10],x[10],aug[20][20];
	int n;
	public:
		Mat_Inv(float x[10][10],float b1[10],int m);
		void mat_inv();
		void display();
		void display1();
};
Mat_Inv :: Mat_Inv(float x[10][10],float b1[10],int m)
{
	int i,j;
	n=m;
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			a[i][j]=x[i][j];
	b[i]=b1[i];
	}
}
void Mat_Inv :: mat_inv()
{
	float am,s;
	float inv[10][10];
	int i,j,k,n1;
	n1=2*n;
	//To form augmnted mat
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			aug[i][j]=a[i][j];
			if(i==j)
			aug[i][j+n]=1;
			else
			aug[i][j+n]=0;
		}
		cout<<"\nElements in initial aug Matrix--->\n";
		display1();
		//To modify augmnted mat and to get inv mat
		for(i=0;i<n;i++)
		{
			am=aug[i][i];
			for(j=0;j<n1;j++)
			aug[i][j]=aug[i][j]/am;
			for(j=0;j<n;j++)
			if(i!=j)
			{
				am=aug[j][i];
				for(k=0;k<n1;k++)
				aug[j][k]=aug[j][k]-aug[i][k]*am;
			}
		cout<<"\nElements in modified aug Matrix\n";
		display1();
		}
	//to extract inv mat
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		inv[i][j]=aug[i][j+n];
		//to display elements in inv mat
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<inv[i][j]<<"\t";
			cout<<endl;
		}
		//to get soln
		for(i=0;i<n;i++)
		{
			s=0;
			for(j=0;j<n;j++)
			s=s+inv[i][j]*b[j];
			x[i]=s;
		}
		display();//to display solns
}		
void Mat_Inv :: display()
{
	int i;
	cout<<"\nSolutions of Linear Simultaneous Eqns :\n";
	for(i=0;i<n;i++)
	cout<<"x["<<(i+1)<<"]="<<x[i]<<endl;
}
void Mat_Inv :: display1()
{
	int i,j,ch;
	cout<<"\nElements in augmented matrix---->\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<aug[i][j]<<"\t";
	cout<<endl;
	}
	cout<<"\nType any no and press enter-->";
	cin>>ch;
	system("cls");
}
int main()
{
	float a[10][10],b[10];
	int i,j,n;
	system("cls");
	cout<<"\nEnter no of eqns(1-10)=";
	cin>>n;
	cout<<"\nEnter coefficients of all eqns--->\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
		}
		cout<<"b["<<i<<"]=";
		cin>>b[i];
	}
	Mat_Inv MI(a,b,n);
	MI.mat_inv();
	return 0;
}
