#include<iostream>

int main(int argc,char* argv[])
{
	std::cout << "this is subApp message" << std::endl;

	if (argc>= 2)
	{
		std::cout << "work... pass,the return code will be 0" << std::endl;
		getchar();
		return 0;
	}
	else
	{
		std::cout << "work... failed,the return code will be 1" << std::endl;
		getchar();
		return 1;
	}

}