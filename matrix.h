#include <iostream>
using namespace std;

class Matrix
{
	public:
		double arr[25][25];
		int rows,cols;
		
		
		friend istream& operator>>(istream &input,Matrix &M2);	//input a matrix
		friend ostream& operator<<(ostream &output,Matrix &M2);	//output a matrix
		friend Matrix operator*(Matrix M,int x);	//multiply a scalar by a matrix
		
		Matrix operator+(Matrix &M2);	//add 2 matrices
		Matrix operator-(Matrix &M2);	//subtract 2 matrices
		Matrix operator*(Matrix &M2);	//multiply two matrices
		int operator==(Matrix &M2);	//are two matrices exactly equal		
		Matrix transpose();	//transpose of a matrix		
		int isSquareMatrix();	//returns 1 if given matrix is a square matrix else returns 0
		int isSymmetricMatrix();	//returns 1 if given matrix is symmetric,-1 if it is skew-symmetric and 0 if it is neither of the two	
	
};




Matrix Matrix::operator+(Matrix &M2)
{
	if((this->rows==M2.rows) && (this->cols==M2.cols))
	{
		Matrix ans;
		ans.rows=this->rows;
		ans.cols=this->cols;
		
		for(int i=0;i<ans.rows;i++)
		{
			for(int j=0;j<ans.cols;j++)
			{
				ans.arr[i][j]=this->arr[i][j]+M2.arr[i][j];
			}
		}
		
		return ans;
	}
	
	else
	{
		cout<<"Matrices not compatible for addition."<<endl;
		return *this;
	}
		
	
	
}

Matrix Matrix::operator-(Matrix &M2)
{
	if((this->rows==M2.rows) && (this->cols==M2.cols))
	{
		Matrix ans;
		ans.rows=this->rows;
		ans.cols=this->cols;
		
		for(int i=0;i<ans.rows;i++)
		{
			for(int j=0;j<ans.cols;j++)
			{
				ans.arr[i][j]=this->arr[i][j]-M2.arr[i][j];
			}
		}
		
		return ans;
	}
	
	else
	{
		cout<<"Matrices not compatible for subtraction."<<endl;
		return *this;
	}
	
	
}

Matrix operator*(Matrix M,int x)
{
	Matrix res;
	res.rows=M.rows;
	res.cols=M.cols;
	
	for(int i=0;i<M.rows;i++)
	{
		for(int j=0;j<M.cols;j++)
			res.arr[i][j]=M.arr[i][j]*x;
	}
	return res;
}


Matrix Matrix::operator*(Matrix &M2)
{
	Matrix res;
	res.rows=this->rows;
	res.cols=M2.cols;
		
	if(this->cols!=M2.rows)
	{
		cout<<"Matrices incompatible for multiplication"<<endl;
		return *this;
	}
	
	for(int i=0;i<this->rows;i++)
	{
		for(int j=0;j<M2.cols;j++)
		{
			res.arr[i][j]=0;
			for(int k=0;k<this->cols;k++)
			{
				res.arr[i][j]+=this->arr[i][k]*M2.arr[k][j];
			}
		}
	}
	
	return res;	
}
int Matrix::operator==(Matrix &M2)
{
	if((rows!=M2.rows) || (cols!=M2.cols))
	{
		return 0; 
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(arr[i][j]!=M2.arr[i][j])
			{
				return 0;
			}
		}
	}
	return 1;
	
}
int Matrix::isSquareMatrix()
{
	if(rows==cols)
		return 1;
	else
		return 0;
}

Matrix Matrix::transpose()
{
	
	int i,j;
	Matrix ans;
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			ans.arr[j][i]=this->arr[i][j];
		}
	}
	
	ans.rows=this->cols;
	ans.cols=this->rows;
	
	return ans;
}

int Matrix::isSymmetricMatrix()
{
	Matrix temp=*this;
	Matrix temp1;
	Matrix comp=(*this).transpose();
	if(comp==temp)
		return 1; //symmetric matrix
	else
	{
		temp1=temp*-1;
		if(comp==temp1)
		{
			return -1;
		}
	}
		
	return 0;	//neither symmetric nor skew symmetric matrix
}

istream& operator>>(istream &input,Matrix &M2)
{
	cout<<"Enter number of rows and columns of the matrix:"<<endl;
	input>>M2.rows>>M2.cols;
	
	cout<<"Enter elements:"<<endl;
	for(int i=0;i<M2.rows;i++)
	{
		for(int j=0;j<M2.cols;j++)
		{
			cin>>M2.arr[i][j];
		}
	}
	
	return input;
}

ostream& operator<<(ostream &output,Matrix &M2)
{
	
	cout<<"Matrix contains:"<<endl;
	for(int i=0;i<M2.rows;i++)
	{
		for(int j=0;j<M2.cols;j++)
		{
			cout<<"\t"<<M2.arr[i][j];
		}
		cout<<endl;
	}
	
	return output;
}

class Matrix1:public Matrix
{
	int i,j;
	
	
	public:
		void generateNullMatrix();
		
};
void Matrix1::generateNullMatrix()
{
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			arr[i][j]=0;
		}
	}		
}


class Matrix2:public Matrix
{
	int i,j;
	
	
	public:
		void generateIdentityMatrix();
		
};
void Matrix2::generateIdentityMatrix()
{
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			arr[i][j]=1;
		}
	}		
}




