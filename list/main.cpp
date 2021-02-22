#include <iostream>
#include "main.h"
#include "list.h"

int main (int argc, char ** argv, char ** envp)
{
	list myList;
	
	string myStr = "Abacus";	
	myList.insert("Aardvark");
	myList.insert("Vrushank");
	myList.insert("Holden");
	myList.insert("Salinger");
	myList.insert("Vrushank");
	myList.insert("Vrushank");
	
	std::cout << myList << std::endl;
	std::cout << myList.length() << std::endl;

	myList.remove("Vrushank");
	
	std::cout << myList << std::endl;
 	//std::cout << myList.length() << std::endl;	
	return 0;
}
