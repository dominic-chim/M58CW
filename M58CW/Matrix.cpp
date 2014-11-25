#include <stdlib.h>

#include "Matrix.h"
#include <assert.h>


int main()
{
printf("Hello World\n");
Matrix<int> test(5,3);
Matrix<int> test2(5,3);
Matrix<int> test3(5,4);
Matrix<int> result,result2,result3;

	//= new Matrix<int>(5,3);

//assert(test2.getNumCols()==3);
//assert(test.getNumRows() ==5);

	test.randInit();
	test2.randInit();
	test3.randInit();
	cout<<"test array"<<endl;
	test.print();
	cout<<"test 2 array"<<endl;
	test2.print();
	/*cout<<"test 3 array"<<endl;
	test3.print();*/
	
	
	/*cout<<"result test+test2"<<endl;
	result = test+test2;
	result.print();*/
	/*cout<<"result test+=test2"<<endl;
	test+=test2;
	test.print();*/
	/*cout<<"result test-test2"<<endl;
	result = test-test2;
	result.print();*/
	//result.arrayReset();
	/*cout<<"result test-=test2"<<endl;
	test-=test2;
	test.print();*/
	/*cout<<"result test*5"<<endl;
	result = test * 5;
	result.print();
	cout<<"result test*test2"<<endl;
	result = test * test2;
	result.print();*/
	/*if(test==test2)
	{
		cout<<"result test==test2"<<endl;
	}

	if(test!=test2)
	{
		cout<<"result test!=test2"<<endl;
	}*/

	cout<<"result test  transpose test2"<<endl;
	result = test.transpose();
	

	getchar();
	return 0;
}