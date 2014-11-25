#include <stdlib.h>

#include "Matrix.h"
#include <assert.h>


int main()
{
printf("Hello World\n");
Matrix<int> test(5,3);
Matrix<int> test2(5,3);
Matrix<int> result,result2,result3;

	//= new Matrix<int>(5,3);

//assert(test2.getNumCols()==3);
//assert(test.getNumRows() ==5);
	test.randInit();
	test2.randInit();
	test.print();
	test2.print();

	result = test+test2;
	test change
	result.print();
	test+=test2;
	test.print();

	getchar();
	return 0;
}