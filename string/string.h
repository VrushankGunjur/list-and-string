#pragma once
#include <iostream>
#include <cstring>

#define max 100

/*
String element interface
*/

struct string
{
	char data[max];			//String data
	int capacity;
	int wsize;				//Working size	

	string();				//Default Constructor
	string(const string &);	//Copy Constructor
	string(const char *);	//c-string Constructor
	~string();				//Destructor

	string & operator = (const string &);	//resets string's data to parameter string
	const char & operator[] (int) const;	//return specified char from string (value)
	char & operator[] (int);				//returns specified char from string (reference)

	int size();		//returns size of the string
	int length();	//returns length (size) of the string
};

//Non-member functions below

//Relational Operators
bool operator == (const string &, const string &);


bool operator != (const string &, const string &);
bool operator < (const string &, const string &);
bool operator <= (const string &, const string &);
bool operator > (const string &, const string &);
bool operator >= (const string &, const string &);

//Stream Operators
std::ostream & operator << (std::ostream &, const string &);
std::istream & operator >> (std::istream &, string &);

