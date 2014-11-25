#include <stdio.h>
#include <iostream>
using namespace std;

template<typename T> class Matrix
{
public:

	int getNumRows()
	{
		return row;
	}

	int getNumCols()
	{
	
		return col;
	}
	void setRows(int i)
	{
		row = i;
	}
	void setCols(int i )
	{
		col= i;

	}

	T getDataElem(int i,int j)
	{
		T out = data[i][j];
		return out;
	}

	bool checkbounds(int x,int y)
	{
		if(x<0 || y <0 )
		{
			return false;
		}
		return true;
	}

	bool checkarry(int x,int y)
	{
		if(x<0||y<0||(x>row)||(y>col) )
		{
			return false;
		}
		return true;
	}


	bool getElem(int rows,int cols,Matrix<T> tMatrix)
	{
		if(data[row][col]!=NULL)
		{
			return true;
		}
			return false;
	}

	bool setElem(int rows,int cols,T elem)
	{
		if(!checkarry(rows,cols))
		return false;

		data[rows][cols] = elem;
		cout<<data[rows][cols]<<endl;
		return true;
	}

	void print()
	{
		printf("\n");
		for (int i = 0; i < getNumRows(); i++)
		{
			for (int j = 0; j < getNumCols(); j++)
			{
				printf("%d	",data[i][j]);
			}
			printf("\n");
		}
	}

	void randInit()
	{	
		int ranval;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				ranval = rand() % 10;
				data[i][j]=ranval;
			}
		}
	}

	void arrayReset()
	{
		Matrix();
	}

	Matrix<T>();
	Matrix<T>(int row,int col);
	Matrix<T>(Matrix<T> *tMatrix);

	Matrix<T> operator+(Matrix<T> tMatrix);
	void operator+=(Matrix<T> tMatrix);
	Matrix<T> operator-(Matrix<T> tMatrix);
	void operator-=(Matrix<T> tMatrix);
	Matrix<T> operator*(const T val);
	Matrix<T> operator*(Matrix<T> tMatrix);
	void operator*=(Matrix<T> tMatrix);
	bool operator==(Matrix<T> tMatrix);
	bool operator!=(Matrix<T> tMatrix);
	Matrix<T> transpose();
	void inverse();
	void setToIdentity();


private:
	int row,col;
	T **data;
};













template <typename T> Matrix<T>::Matrix()
	{
		data = new T*[0];
	}

template <typename T> Matrix<T>::Matrix<T>(int rows,int cols)
{
	if(checkbounds(rows,cols)==true)
	{
		setCols(cols);
		setRows(rows);
		data = new T*[row];
		for(int i =0;i<rows;i++)
		{
			data[i] = new T[col];
		}
		for(int x=0;x<rows;x++)
		{
			for(int y=0;y<cols;y++)
			{
				data[x][y]=0;
			}
		}
	}
}
	
	
template <typename T> Matrix<T>::Matrix<T>(Matrix<T>* nMatrix)
{
		for (int i = 0; i < nMatrix->getNumRows(); i++)
		{
			for (int j = 0; j < nMatrix->getNumCols(); j++)
			{
				data[i][j]= nMatrix->getDataElem(i,j);
			}
		}
}


template<typename T>Matrix<T> Matrix<T>::operator+(Matrix<T> tMatrix)
{

	if(checkarry(tMatrix.row,tMatrix.col))
	{
		printf("in bounds");
	
		Matrix<T> resultMatrix(row,col);
		for(int x=0;x<row;x++)
			{
				for (int y = 0; y < col; y++)
				{
					resultMatrix.data[x][y] = data[x][y]+tMatrix.data[x][y];
				}
			}
		return resultMatrix;
	}
	return 0;
}

template<typename T> void Matrix<T>::operator+=(Matrix<T> tMatrix)
{
	if(checkarry(tMatrix.row,tMatrix.col))
	{
		printf("in bounds");
	

	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				data[x][y] +=tMatrix.getDataElem(x,y);
			}
		}
	}
}

template<typename T>Matrix<T> Matrix<T>::operator-(Matrix<T> tMatrix)
{
	if(checkarry(tMatrix.row,tMatrix.col))
	{
		printf("in bounds");
	

	Matrix<T> resultMatrix(row,col);
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
				{
					resultMatrix.data[x][y] = data[x][y]-tMatrix.data[x][y];
				}
		}
	return resultMatrix;
	}
	return 0;
}

template<typename T> void Matrix<T>::operator-=(Matrix<T> tMatrix)
{
	if(checkarry(tMatrix.row,tMatrix.col))
	{
		printf("in bounds");
	
	
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				data[x][y] -=tMatrix.getDataElem(x,y);
			}
		}
	}
}

template<typename T>Matrix<T> Matrix<T>::operator*(const T val)
{

	Matrix<T> resultMatrix(row,col);
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
				{
					resultMatrix.data[x][y] = data[x][y] * val;
				}
		}
	return resultMatrix;
}

template<typename T>Matrix<T> Matrix<T>::operator*(Matrix<T> tMatrix)
{
	if(checkarry(tMatrix.row,tMatrix.col))
	{
		printf("in bounds");
	

	Matrix<T> resultMatrix(row,col);
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
				{
					resultMatrix.data[x][y] = data[x][y] * tMatrix.data[x][y];
				}
		}
	return resultMatrix;
	}
	return 0;
}

template<typename T> void Matrix<T>::operator*=(Matrix<T> tMatrix)
{
	if(checkarry(tMatrix.row,tMatrix.col))
	{
		printf("in bounds");
	
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				data[x][y] *=tMatrix.getDataElem(x,y);
			}
		}
	}
}

template<typename T>bool Matrix<T>::operator==(Matrix<T> tMatrix)
{
	if(!checkarry(tMatrix.row,tMatrix.col))
	{
		return false;
	}
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if(data[i][j]!=tMatrix.data[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

template<typename T>bool Matrix<T>::operator!=(Matrix<T> tMatrix)
{
	if(!checkarry(tMatrix.row,tMatrix.col))
	{
		return false;
	}
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if(data[i][j]!=tMatrix.data[i][j])
				return true;
		}
	}

	return false;
}

template<typename T>Matrix<T> Matrix<T>::transpose()
{
	Matrix<T> resultMatrix(row,col);
	for ( int i = 0; i < row; i++ )
	 {
       for ( int j = 0; j < col; j++ )
       {
		
		   resultMatrix.data[j][i] = data[i][j];
		   //cout<< resultMatrix.data[j][i]<<"  "<<data[i][j]<<endl;
       }
	}

	for (int i = 0; i<col; i++)
	{
	   for (int j = 0; j<row; j++)
	   {
			
		  // cout<<i<<" "<<j<<" "<<data[i][j];
		  cout << resultMatrix.data[i][j] << "\t";
		
	   }
	   cout<<endl;
	}
	return resultMatrix;
}
