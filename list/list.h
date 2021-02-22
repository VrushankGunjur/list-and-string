#pragma once
#include <iostream>
#include "string.h"

#define max 100

struct list
{
	string data[max];	//Data Array
	int capacity;
	int wsize;			//Working Size of List

	list();				//Default Constructor
	~list();			//Destructor

	bool is_empty();	//Checks if list is empty
	bool is_full();		//Checks if list is full
		
	string & operator[] (int);				//return specified string from list (reference)
	const string & operator[] (int) const;	//return specifid string from list (value)
	
	string & at(int);	//returns requested element

	size_t length();	//returns num elements in list
	
	string * find(const string &);		//searches list for a given string

	bool remove(int);			//positional deletion
	bool remove(const string &);	//value deletion

	bool insert(const string &, size_t);	//positional insert
	bool insert(const string &);			//ordered insertion

	bool erase();	//removes all elements from the list without deleting the list
	
	
};

//stream operators
std::ostream & operator << (std::ostream &, const list &);
std::istream & operator >> (std::istream &, list &); 
