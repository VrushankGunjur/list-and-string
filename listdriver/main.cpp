#include "main.h"

int main(int argc, char **argv, char **envp)
{
	list vars;
	string input;
	int idx = 0;
	//count number of envp variables
	int numenvp = 0;
	for(numenvp = 0; envp[numenvp] != nullptr; numenvp++);
	
	std::cout << numenvp << std::endl;
	for(idx = 0; idx < argc; idx++)
	{
		input = argv[idx];
		if(vars.find(input) == nullptr)
		{
			vars.insert(input);
		}
	}
	
	for(idx = 0; idx < numenvp; idx++)
	{
		if(underCapacity(envp[idx]) == true)
		{
			input = envp[idx];
			if(vars.find(input) == nullptr)
			{
				vars.insert(input);
			}
		}
	}	 
	
	std::cout << vars << std::endl;
	return 0;
}

bool underCapacity(char * input)
{
	int len;
	for(len = 0; input[len] != '\0'; len++);
	if(len > max) return false;
	else return true;
}
