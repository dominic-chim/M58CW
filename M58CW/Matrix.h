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
		if(!checkbounds(x,y)||(x>row-1)||(y>col-1) )
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
		return true;
	}

	void print()
	{
		printf("\n");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
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

	Matrix();
	Matrix(int row,int col);
	Matrix(Matrix *tMatrix);
	Matrix<T> operator+(Matrix<T> &tMatrix);
	Matrix<T> operator+=(Matrix<T> &tMatrix);
	Matrix<T> operator-(Matrix<T> &tMatrix);
	Matrix<T> operator-=(Matrix<T> &tMatrix);
	Matrix<T> operator*(const T val);
	Matrix<T> operator*(Matrix<T> &tMatrix);
	Matrix<T> operator*=(Matrix<T> &tMatrix);
	bool operator==(Matrix<T> &tMatrix);
	bool operator!=(Matrix<T> &tMatrix);
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
	
	
template <typename T> Matrix<T>::Matrix<T>(Matrix<T> *nMatrix)
	{
		for (int i = 0; i < nMatrix->row; i++)
		{
			for (int j = 0; j < nMatrix->col; j++)
			{
				data[i][j]=nMatrix->data[i][j];
			}
		}
	}


template<typename T>Matrix<T> Matrix<T>::operator+(Matrix<T> &tMatrix)
{
	if(!checkarry(tMatrix.row,tMatrix.col))
		return NULL;

	Matrix<T> resultMatrix(row,col);
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				resultMatrix.data[x][y] = this->data[x][y]+tMatrix.data[x][y];
			}
		}
	return resultMatrix;
}

template<typename T>Matrix<T> Matrix<T>::operator+=(Matrix<T> &tMatrix)
{
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				data[x][y] +=tMatrix.data[x][y];
			}
		}
	return this;
}

template<typename T>Matrix<T> Matrix<T>::operator-(Matrix<T> &tMatrix)
{
	Matrix<T> resultMatrix(row,col);
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				resultMatrix.data[x][y] = this->data[x][y]-tMatrix.data[x][y];
			}
		}
	return resultMatrix;
}

template<typename T>Matrix<T> Matrix<T>::operator-=(Matrix<T> &tMatrix)
{
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				data[x][y] -=tMatrix.data[x][y];
			}
		}
	return this;
}

template<typename T>Matrix<T> Matrix<T>::operator*(const T val)
{
	Matrix<T> resultMatrix(row,col);
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				resultMatrix.data[x][y] = this->data[x][y]* val;
			}
		}
	return resultMatrix;
}

template<typename T>Matrix<T> Matrix<T>::operator*(Matrix<T> &tMatrix)
{
	Matrix<T> resultMatrix(row,col);
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				resultMatrix.data[x][y] = this->data[x][y]*tMatrix.data[x][y];
			}
		}
	return resultMatrix;
}

template<typename T>Matrix<T> Matrix<T>::operator*=(Matrix<T> &tMatrix)
{
	for(int x=0;x<row;x++)
		{
			for (int y = 0; y < col; y++)
			{
				data[x][y] *=tMatrix.data[x][y];
			}
		}
	return this;
}

template<typename T>bool Matrix<T>::operator==(Matrix<T> &tMatrix)
{
	if (tMatrix==this)
	{
		return true;
	}
	return false;
}

template<typename T>bool Matrix<T>::operator!=(Matrix<T> &tMatrix)
{
	if (tMatrix!=this)
	{
		return true;
	}
	return false;
}
