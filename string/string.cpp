#include "string.h"

//CONSTRUCTORS

string::string()
{
	capacity = max;		//maximum size
	wsize = 0;			//working size

	for(int idx = 0; idx < max; idx++)
	{
		data[idx] = '\0';
	}
	
	//character array isn't a custom data type, we need to initialize the values ourselves
	//however, since it's a capacity-managed array, this doesn't really matter
}

string::string(const string & right)
{
	capacity = right.capacity;
	wsize = right.wsize;

	for(int idx = 0; idx < wsize; idx++)
	{
		data[idx] = right[idx];
	}
	for(int idx2 = wsize; idx2 < max; idx2++)
	{
		data[idx2] = '\0';
	}
}

string::string(const char * right)
{
	capacity = max;
	int ptr = 0;
	
	//null byte of cstring signifies end of cstring
	while(right[ptr] != '\0')
	{
		ptr++;
	}
	//wsize is the number of elements, so it's the index of the null byte
	wsize = ptr;

	for(int idx = 0; idx < wsize; idx++)
	{
		data[idx] = right[idx];
	}
	for(int idx2 = wsize; idx2 < max; idx2++)
	{
		data[idx2] = '\0';
	}
}

//DESTRUCTOR

string::~string()
{
	for(int idx = 0; idx < wsize; idx++)
	{
		data[idx] = '\0';
	}
	wsize = 0;
	capacity = max;
}

//MEMBER OPERATORS

string & string::operator = (const string & right)
{
	wsize = right.wsize;
	capacity = right.capacity;
	
	for(int idx = 0; idx < wsize; idx++)
	{
		data[idx] = right[idx];
	}
	data[wsize] = '\0';
	return *this;
}

const char & string::operator[] (int pos) const
{
	if(pos < 0) return data[0];
	if(pos >= wsize) return data[wsize-1];
	return data[pos];
}

char & string::operator[] (int pos)
{
	if(pos < 0) return data[0];
	if(pos >= wsize) return data[wsize-1];
	return data[pos];
}

//SIZE/LENGTH

int string::size()
{
	return wsize;
}

int string::length()
{
	return wsize;
}

//NON-MEMBER FUNCTIONS

//RELATIONAL OPERATORS

bool operator == (const string & left, const string & right)
{
	if(strcmp(left.data, right.data) == 0)
	{
		return true;
	}
	return false;
}

bool operator != (const string & left, const string & right)
{
	if(strcmp(left.data, right.data) != 0)
	{
		return false;
	}
	return true;
}

bool operator < (const string & left, const string & right)
{
	if(strcmp(left.data, right.data) < 0)
	{
		return true;
	}
	return false;
}

bool operator <= (const string & left, const string & right)
{
	if(strcmp(left.data, right.data) < 0 || strcmp(left.data, right.data) == 0)
	{
		return true;
	}
	return false;
}

bool operator > (const string & left, const string & right)
{
	if(strcmp(left.data, right.data) > 0)
	{
		return true;
	}
	return false;
}

bool operator >= (const string & left, const string & right)
{
	if(strcmp(left.data, right.data) > 0 || strcmp(left.data, right.data) == 0)
	{
		return true;
	}
	return false;
}

//STREAM OPERATORS

std::ostream & operator << (std::ostream & out, const string & right)
{
	for(int idx = 0; idx < right.wsize; idx++)
	{
		out << right[idx];
	}
	return out;
}

std::istream & operator >> (std::istream & in, string & right)
{
	char input[max];
	int ptr = 0;
	while(in.peek() != EOF && in.peek() != '\n' && in.good() == true && ptr < max)
	{
		in >> input[ptr];
		ptr++;
	}
	
	input[ptr + 1] = '\0';
	
	right = input;

	return in;
}
