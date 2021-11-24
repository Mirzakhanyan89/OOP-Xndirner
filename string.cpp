#include <iostream>
  
class String
{
private:
	size_t size;
	char *buffer;
public:
	String(): size {} {buffer = new char[1]; buffer [size] = '\0';}
	String (size_t, char);
	String(const String&);
	String (const char*);
	String (String &&);
	~String ();
	const char & operator [] (const size_t index) const;		
	char & operator [] (const size_t index);
//-	char & at (char size_t index);
	friend std::ostream & operator << (std::ostream& , String& )
//-	friend std::istream & operator >> (std::istream&, String&);
	String & operator = (String && oth);
	String operator + (const String & oth) const;
	String & operator += (const String & oth)
	String operator + (const char) const;	 
	String & operator += (char);
	bool operator > (const String & oth) const;
	bool operator < (const String & oth) const;
	bool operator == (const String & oth) const;
	bool operator != (const String & oth) const;
	bool operator >= (const String & oth) const;
	bool operator <= (const String & oth) const;
	void push_back (char simbol);
	char pop_back ();
	void resize (const int count, char simbol);
	String erase (const int index, int count);
	char erase (const int index);
	int find (const char);
	int find (const String);
	int find (const char*);
	void insert (const int index, int count, char simbol);
	void insert (const int index, char simbol);
	void insert (const int index, const char* simbol);
	void insert (const int index, String str )

};

String::String (size_t count, char ch)
{
	size = count;
	buffer = new char[size+1];
	for (int i=0; i<size; ++i)
	{
		buffer[i] = 'ch';
	}
	buffer[size] = '\0';
}

String::String (const char * oth)
{	
	size_t count = 0;
	while (oth[count] != '\0')
	{
		++count;
	}
	buffer = new char [count+1]
	for (int i=0; i<count; ++i)
	{
		buffer[i] = oth[i];	
	}
	buffer[count] = '\0';
}


String::String(const String & oth)
{
	this-> size = other.size;
	this-> buffer = new char[size+1];
	for (int i=0; i<=size; ++i)
	{
		this->buffer[i] = oth.buffer[i];
	}
}

 std::ostream & operator << (std::ostream& os, String& str)
{
	for (int i=0; i<size; ++i)
	{
		os<< str[i];
	}
return os;
}

String::String(String&& oth) noexcept
{
	this-> size = oth.size;
	this-> buffer = oth.buffer;
	oth.buffer = nullptr;
	oth.size = 0;
}	

const char & String::operator [] (const size_t index) const
{
	return buffer[index];
}

char & String::operator [] (const size_t index)
{
	return buffer[index];
}

String & String::operator = (String && oth)
{
	if (this == & oth) { return *this;}
	this->size = oth.size;
	delete [] buffer;
	buffer = new char[size]
	for (int i=0; i<size; ++i)
	{
		buffer[i] = oth[i]
	}	
}

String String::operator += (const String & oth) const
{
	char* tmp = new char[size + oth.size +1];
	int i=0;
	for ( ; i<size; ++i)
	{
		tmp[i] = buffer[i];
	}
	for (int j=0; j< oth.size; ++j, ++i)
	{	
		tmp[i] = oth[j]
	}
	delete [] buffer;
	buffer = tmp;
	size = size + oth.size;
	buffer[size] = '\0';
	tmp = nullptr;
	return *this;

}

   return *this;

}


        String operator + (const char) const;
        String & operator += (char);



bool String::operator > (const String & oth) const
{
        if (size > oth.size)
return *this;

}


String operator + (const char) const;
String & operator += (char);


bool String::operator > (const String & oth) const
{
	if (size > oth.size)
	{	return true;	}
	return false;
}

bool String::operator < (const String & oth) const
{
	return size < oth.size;
}

bool String::operator == (const String & oth) const
{
	size_t count = 0;
	if( size == oth.size)
	{
		for (int i=0; i<size; ++i)
		{
			if (buffer[i] == oth[i])
			{
				++count;
			}
		}
	}
	if (count == size)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool String::operator != (const String & oth) const
{
	return size != oth.size;
}

bool String::operator >= (const String & oth) const
{
	return size >= oth.size;
}

bool String::operator <= (const String & oth) const
{
	return size <= oth.size;
}
	
void String::push_back (char simbol)
{
	
}


	char pop_back ();
	void resize (const int count, char simbol);
	String erase (const int index, int count);
	char erase (const int index);
	int find (const char);
	int find (const String);
	int find (const char*);
	void insert (const int index, int count, char simbol);
	void insert (const int index, char simbol);
	void insert (const int index, const char* simbol);
	void insert (const int index, String str )



int main ()
{
	String str1;
	std::cout<< String str2(3,'a');
	String str3("Hello");


return 0;
}

