	//as1q2.cpp : Write a program in C++ to implement
	//Matrix Factorization method to solve linear simultaneous
	//equations
	#include<iostream>
	using namespace std;
	class Mat_Fact
	{
	float a[10][10], b[10], x[10];
	float l[10][10],u[10][10];
	int n;
	public:
	Mat_Fact(float x[10][10],float b1[10],int m);
	void mat_fact();
	void display(); // to display all roots
	void display1(); // to display lower triangular, upper triangular
                         // Matrix
	};

Mat_Fact :: Mat_Fact(float x[10][10], float b1[10], int m)
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

	void Mat_Fact :: mat_fact()
	{
	float s;
	int i,j,k;
	float y[10];
	
	//To initialize lower triangular matrix and upper triangular matrix
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
			u[i][j]=0;
				if(i==j)
				l[i][j]=1;
				else
				l[i][j]=0;
			}
	
	//To generate the elements of lower triangular matrix and upper 
	//triangular matrix
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i<=j)
				{
				s=0;
					for(k=0;k<i;k++)
					s=s+l[i][k]*u[k][j];
				u[i][j]=a[i][j]-s;
				}
				else if(i>j)
				{
				s=0;
					for(k=0;k<j;k++)
					s=s+l[i][k]*u[k][j];
				l[i][j]=(a[i][j]-s)/u[j][j];
				}
	display1(); //To display elements in l[] and u[]

	//To calculate y[] using forward substitution method
	y[0]=b[0];
		for(i=1;i<n;i++)
		{
		s=0;
			for(j=0;j<i;j++)
			s=s+l[i][j]*y[j];
		y[i]=b[i]-s;
		}
	//To display values of y[]

		for(i=0;i<n;i++)
		cout<<"y["<<(i+1)<<"="<<y[i]<<endl;
	
	//To calculate roots from u[][] equations using back substitution
	//method
	x[n-1]=y[n-1]/u[n-1][n-1];
		for(i=(n-2);i>=0;i--)
		{
		s=0;
			for(j=(i+1);j<n;j++)
			s=s+u[i][j]*x[j];
		x[i]=(y[i]-s)/u[i][i];
		}
	
	display(); // To display all roots
	}
	
	void Mat_Fact :: display()
	{
	int i;
	cout<<"\nSolutions of Linear Simultaneous Equations :\n";
		for(i=0;i<n;i++)
		cout<<"x["<<(i+1)<<"]="<<x[i]<<endl;
	}

	void Mat_Fact :: display1()
	{
	int i,j;
	cout<<"\nElements in Lower Triangular Matrix--->\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<l[i][j]<<"\t";
		cout<<endl;
		}

	 cout<<"\nElements in Upper Triangular Matrix--->\n";
                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        cout<<u[i][j]<<"\t";
                cout<<endl;
                }
	int ch;
	cout<<"\nType any number and then press enter key to continue-->";
	cin>>ch;
	}

	int main()
	{
	float a[10][10],b[10];
	int i,j,n;
	system("clear");
	cout<<"\nEnter number of simultaneous equations(1-10)=";
	cin>>n;
	cout<<"\nEnter co-efficients of all equations --->\n";
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
	Mat_Fact MF(a,b,n);
	MF.mat_fact();
	return 0;
	}