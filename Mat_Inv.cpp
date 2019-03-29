/*Matrix Inversion Method*/
#include<iostream>
using namespace std;
class Matrix_inversion{
	float a[10][10],b[10],x[10],aug[10][10];
	int n;
	public:
		Matrix_inversion(float x[10][10],float b1[10],int m);
		void matrix_inv_method();
		void display();
		void display1();
};
void Matrix_inversion :: display1(){
	int i,j,ch;
	cout<<"\nElements in augmented matrix --->\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<aug[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"\nType any num and press enter--->\n";
	cin>>ch;
	system("cls");
}


void Matrix_inversion :: display(){
	int i;
	cout<<"\nSolutions of linear Simultanious Equations :\n";
	for(i=0;i<n;i++)
	cout<<"x["<<(i+1)<<"]="<<x[i]<<endl;
}


Matrix_inversion :: Matrix_inversion(float x[10][10],float b1[10],int m){
	int i,j;
	n=m;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				a[i][j]=x[i][j];
				b[i]=b1[i];
		}
}

void Matrix_inversion :: matrix_inv_method(){
	float am,s;
	float inverse[10][10];
	int i,j,k,n1;
	n1=2*n;
	//to form initial augmented matrix
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
		    aug[i][j]=a[i][j];
		    if(i==j)
		     aug[i][j+n]=1;
   		    else
	          aug[i][j+n]=0;
	   }
		cout<<"\nElements in initial augmented matrix--->\n";
		display1();
		// to modify aug mat to get inv. mat
		for(i=0;i<n;i++){
			am=aug[i][i];
			for (j=0;j<n;j++)
			aug[i][j]=aug[i][j]/am;
			for(j=0;j<n;j++)
			   if (i!=j)
			   {
			   	  am=aug[j][i];
			   	  for(k=0;k<n1;k++)
			   	  aug[j][k]=aug[j][k]-aug[i][k]*am;			   
		       }
		}
		cout<<"\nElements in modified augmented mat. :--->\n";
		display1();
		//to Extract inverse mat.
		for(i=0;i<n;i++)
		   for(j=0;j<n;j++)
		   	   inverse[i][j]=aug[i][j+n];
   //to display elements in inverse matris
   for(i=0;i<n;i++){
   	for(j=0;j<n;j++)
   	 cout<<inverse[i][j]<<"\t";
   	 cout<<endl;
   }
  // to get solution of linear simult. eqn
  	 for(i=0;i<n;i++){
  	 	s=0;
  	 	for(j=0;j<n;j++)
  	 	s=s+inverse[i][j]*b[j];
  	 	x[i]=s;
	   }
	   display();
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
	Matrix_inversion GE(a,b,n);
	GE.matrix_inv_method();
	
	return 0;
}
