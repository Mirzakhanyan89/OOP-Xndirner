#include <iostream> // utility
#include <string>
#include <regex>

class Utility
{
public:
	std::string str;
	static	bool is_integer (const std::string & str);
	static	bool is_float (const std::string & str);
	static	bool is_number (const std::string & str);
	static	bool is_boolean (const std::string & str);
	static	bool is_emile (const std::string & str);
	static	bool is_url(const std::string & str);
};

int main ()
{
	Utility obj;
	std::string str {};
	std::cout<< "Enter eiter number or string.\n";
	std::cin>> str;
//	bool i = Utility::is_integer(str);
//	std::cout<< i;	

//	bool f = Utility::is_float (str);
//	std::cout<< f;

	bool num = Utility::is_number(str);
	std::cout<< num;

//	bool b = Utility::is_boolean (str);
//	std::cout<< b;
	return 0;
}

bool Utility::is_integer (const std::string & str)
{
	int count = 0;
		if ((str[0] == '-' or str[0] >= '0') and ( str[0] <= '9'))
			
		{
			++count;	
		}
		for (int i=1; i<str.size(); ++i)
	{
		if (str[i] >= '0' and str[i] <= '9')
		{
			++count;
		}
	}	
	if (count != str.size())
	{
		return false;
	}
	return true;
}


bool Utility::is_float (const std::string & str)
{
	int count_po = 0;
	if ((str[0] == '-') or (str[0] == '+'))
	{
		if ((str[1] >= '0' and str[1] <= '9') and (str[str.size()-1] >= '0' and str[str.size()-1] <= '9'))
		{	
			for (int i=2; i<str.size()-1; ++i)
			{
				if((str[i] == '.') or (str[i] >= '0' and str[i] <= '9')) 
				{
					if (str[i] == '.')
					{	
						++count_po;
					}
				} else {
					return false;
			         	}
			}
			if(count_po == 1) return true;
		}
		return false;
	}
	else if ((str[0] >= '0' and str[0] <= '9')  and (str[str.size()-1] >= '0' and str[str.size()-1] <= '9'))
	{
		for (int i=1; i<str.size()-1; ++i)
		{	
			if((str[i] == '.') or (str[i] >= '0' and str[i] <= '9'))
			{
				if (str[i] == '.')
				{	
					++count_po;
				}
			}
			else
			{
				return false;
			}
		}
	}
	if (count_po == 1)
		return true;
	else
	{
		return false;
	}
}

bool Utility::is_number (const std::string & str)
{
	if (Utility::is_integer(str))
	{
		return true;
	}
	else if (Utility::is_float (str))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Utility::is_boolean (const std::string & str)
{
 if (str.size() == 1 and  str[0] == '0')
{
 	return false;
}
else
return true;
}

bool is_email (const std::string & str)
{
	std::regex re ("(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$)");
	return regex_search (str, re);
}

bool is_url (const std::string & str)
{
	std::regex re ("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
	return regex_search(str, re);
}






