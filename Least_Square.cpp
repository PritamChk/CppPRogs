#include<iostream>
using namespace std;
class Least_square
{
	double a[10][10],b[10],x1[10];
	double x[20],y[20];
	int n,m;
	public:
		Least_square(double xx[20],double yy[20],int m1,int n1);
		void g_elm();
		void least_square();
};
Least_square :: Least_square(double xx[20],double yy[20],int m1,int n1)
{
	int i;
	n=n1;
	m=m1;
	for(i=0;i<m;i++)
	{
		x[i]=xx[i];
		y[i]=yy[i];
	}
}
void Least_square :: g_elm()
{
	double am,s;
	int i,j,k;
	//to obtain triangular equations
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				am=a[j][i]/a[i][i];
				for(k=0;k<n;k++)
				a[j][k]=a[j][k]-a[i][k]*am;
				b[j]=b[j]-b[i]*am;
			}
		}
	}
	x1[n-1]=b[n-1]/a[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
		s=0;
		for(j=i+1;j<n;j++)
		s=s+a[i][j]*x[j];
		x1[i]=(b[i]-s)/a[i][i];
	}
}
void Least_square :: least_square()
{
	int i,j,k,k1,ij;
	double s,p;
	//to calculate a[][] matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ij=i+j; //ij=power of x[]
			s=0;
			for(k1=0;k1<m;k1++)
			{
				p=1;
				for(k=1;k<=ij;k++)
				p=p*x[k1];
				s=s+p;
			}
			a[i][j]=s;
		}
	}
	for(i=0;i<n;i++)
	{
		ij=i;
		s=0;
		for(k1=0;k1<m;k1++)
		{
			p=1;
			for(k=1;k<=i;k++)
			p=p*x[k1];
			s=s+y[k1]*p;
		}
		b[i]=s;
	}
	//to display elements of a[][] matrix
	cout<<"\nElements of a[][] matrix :\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<a[i][j]<<"\t";
		cout<<endl;
	}
	//to display elements of b[]
	cout<<"\nElements of b[] :\n";
	for(i=0;i<n;i++)
	cout<<b[i]<<endl;
	g_elm();
	cout<<"Roots are :\n";
	for(i=0;i<n;i++)
	cout<<"a-"<<i<<" -"<<x1[i]<<endl;
}
int main()
{
	double x[20],y[20];
	int i,m,n;
	cout<<"\nEnter order of the polynomial(1-10) = ";
	cin>>n;
	n++;
	cout<<"Enter number of experimental points(1-20) = ";
	cin>>m;
	cout<<"\nEnter x-points and y-points one by one :\n";
	for(i=0;i<m;i++)
	{
		cout<<"x["<<i<<"]=";
		cin>>x[i];
		cout<<"y["<<i<<"]=";
		cin>>y[i];
	}
	Least_square L(x,y,m,n);
	L.least_square();
	return 0;
}
