#include "main.h"

int main(int argc, char **argv, char **envp)
{
	string mystr1 = "Abacus";
	string mystr2 = "Algebra";

	std::cout << "String 1: " << mystr1 << std::endl;
	std::cout << "String 2: " << mystr2 << std::endl;

	std::cout << (mystr1 > mystr2) << std::endl;
	return 0;
}
