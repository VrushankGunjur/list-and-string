#include "list.h"

list::list()
{
	capacity = max;
	wsize = 0;
}

list::~list()
{
	//call erase here once implemented
	wsize = 0;
	capacity = max;	
}

bool list::is_empty()
{
	bool isEmpty = false;
	if(wsize == 0)
	{
		isEmpty = true;
	}
	return isEmpty;
}

bool list::is_full()
{
	bool isFull = false;
	if(wsize == capacity)
	{
		isFull = true;
	}
	return isFull;
}

string & list::operator[] (int pos)
{
	return data[pos];
}

const string & list::operator[] (int pos) const
{
	return data[pos];
}

string & list::at(int pos)
{
	return data[pos];
}

size_t list::length()
{
	return (size_t) wsize;
}

string * list::find(const string & query)
{
	for(int idx = 0; idx < wsize; idx++)
	{
		if(data[idx] == query)
		{
			return &data[idx];
		}
	}
	return nullptr;
}

bool list::remove(int pos)
{
	bool success = false;
	if(pos >= wsize || pos < 0) return success;

	for(int idx = pos; idx < wsize-1; idx++)
	{
		data[idx] = data[idx+1];
	}
	wsize--;
	success = true;
	return success;
}

bool list::remove(const string & toDel)
{
	int pos;
	int numDeleted = 0;
	while(find(toDel) != nullptr)
	{
		for(int idx = 0; idx < wsize; idx++)
		{
			if(data[idx] == toDel) pos = idx;
			break;
		}
		//remove string at point pos
		for(int ptr = pos; ptr < wsize - 1; ptr++)
		{
			data[ptr] = data[ptr + 1];
		}
		wsize--;
		numDeleted++;
	}	
	if(numDeleted == 0) return false;
	else return true;
}

bool list::insert (const string & toInsert, size_t pos)
{
	bool success = false;
	//might not need the *this part, to test
	if(pos >= wsize || pos < 0 || wsize >= capacity) return success;
	
	for(int idx = wsize; idx > pos; idx--)
	{
		data[idx] = data[idx-1];
	} 
	data[pos] = toInsert; 
	wsize++;
	success = true;
	return success;
}

bool list::insert (const string & toInsert)
{
	if(wsize >= capacity) return false;
	int pos = 0;
	for(pos = 0; pos < wsize; pos++)
	{
		if(data[pos] >= toInsert) break;
	}	

	for(int idx = wsize+1; idx > pos; idx--)
	{
		data[idx] = data[idx-1];
	}

	data[pos] = toInsert;
	wsize++;
	return true;
}

bool list::erase()
{
	string nullStr = "\0";
	for(int idx = 0; idx < wsize; idx++) 
	{
		data[idx] = nullStr;
	}
	wsize = 0;
	return true;
}

std::ostream & operator << (std::ostream & out, const list & right)
{
	for(int idx = 0; idx < right.wsize; idx++)
	{
		out << right[idx] << " ";
	}
	return out;
}

std::istream & operator >> (std::istream & in, list & right)
{
	string input;
	while(in.peek() != EOF && in.peek() != '\n' && in.good() == true)
	{
		in >> input;
		if(in.good() == true) right.insert(input);
	}
	return in;
}	












