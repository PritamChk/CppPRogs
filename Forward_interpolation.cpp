#include<iostream>
using namespace std;
class Forward
{
	public:
		double forward(double x[20],double y[20],double xx,int n);
};
double Forward :: forward(double x[20],double y[20],double xx,int n)
{
	double diff_table[20][20],yy;
	int i,j,k;
	float p,p1,p2,h,fact;
	//to calculate forward interpolation difference table
	for(i=0;i<n;i++)
		diff_table[i][0]=y[i];//copying y[] to diff_matrix
	for(i=1;i<n;i++)
	{
		k=n-i;	
		for(j=0;j<k;j++)
		diff_table[j][i]=diff_table[j+1][i-1]-diff_table[j][i-1];
	}
	//to display elements in Forward Difference Table
	cout<<endl<<"Elements in Forward Difference Table\n";
	for(i=0;i<n;i++)
	{
		k=n-i;
		for(j=0;j<k;j++)
		cout<<diff_table[i][j]<<"\t";
		cout<<endl;
	}
	//to calculate yy at x=xx
	h=x[1]-x[0];
	p=(xx-x[0])/h;
	yy=y[0];
	for(i=1;i<n;i++)
	{
		p1=1;
		fact=1;
		p2=p;
		for(j=i;j<=i;j++)
		{
			p1=p1*p2;
			p2=p2-1;
			fact=fact*j;
		}
		yy=yy+p1*diff_table[0][i]/fact;
	}
	cout<<"x="<<xx<<" y="<<yy<<endl;
	return yy;
}
int main()
{
	double x[20],y[20],yy,xx;
	int i,n;
	cout<<"\nEnter no. of points = ";
	cin>>n;
	cout<<"\nEnter "<<n<<" x points and y points one by one :\n";
	for(i=0;i<n;i++)
	{
		cout<<"x["<<i<<"]=";
		cin>>x[i];
		cout<<"y["<<i<<"]=";
		cin>>y[i];
	}
	cout<<"Enter your new x-point = ";
	cin>>xx;
	Forward F;
	yy=F.forward(x,y,xx,n);
	return 0;
}
