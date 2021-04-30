#include <iostream>
#include <matrix.h>
using namespace std;

main()
{
	Matrix1 M;
	cout<<"Enter matrix M:"<<endl;
	cin>>M;
	cout<<M;
	/*	
	M.generateNullMatrix();
	cout<<"Generating null matrix of the given dimensions...."<<endl;
	cout<<M;
	*/
	
	Matrix2 m;
	cout<<"Enter matrix m:"<<endl;
	cin>>m;
	cout<<m;
	/*
	m.generateIdentityMatrix();
	cout<<"Generating identity matrix of the given dimensions..."<<endl;
	cout<<m;
	
	*/
	
	cout<<"Checking for square matrix:"<<endl;
	if(m.isSquareMatrix())
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	
	
	cout<<"Transpose of the matrix M:"<<endl;
	Matrix ans=M.transpose();	
	cout<<ans<<endl;
	
	if(M.isSymmetricMatrix()==1)
		cout<<"M is symmetric"<<endl;
	else if(M.isSymmetricMatrix()==-1)
		cout<<"M is skew-symmetric"<<endl;
	else
		cout<<"M is neither symmetric nor skew-symmetric"<<endl;
		
	//scalar matrix
	cout<<"Multiplying first matrix M by 3:"<<endl;
	Matrix res=M*3;
	cout<<res<<endl;
	
	
	cout<<"Adding first and second matrices..."<<endl;
	Matrix sumOfMatrices=M+m;
	if((sumOfMatrices.operator==(M))==0)
		cout<<sumOfMatrices<<endl;	
	
	cout<<"First matrix-second matrix:"<<endl;
	Matrix diffOfMatrices=M-m;
	if((diffOfMatrices.operator==(M))==0)
		cout<<diffOfMatrices<<endl;	
	
	cout<<"First matrix*second matrix"<<endl;
	Matrix prodOfMatrices=M*m;
	if((prodOfMatrices.operator==(M))==0)
		cout<<prodOfMatrices<<endl;		
}
