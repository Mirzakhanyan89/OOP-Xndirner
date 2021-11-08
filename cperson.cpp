#include <iostream> // cperson
#include <string>

struct Person
{
	std::string m_name;
	short m_age;
	std::string m_mail;
};
void Person_dctor (Person *p) {}
void Person_default (Person* p)
{
	p-> m_name = "asus";
	p-> m_age = 10;
	p-> m_mail = "www.asus.com";
}

void Person_copy (Person *p, Person *other)
{
	p-> m_name = other-> m_name;
	p-> m_age = other-> m_age;
	p-> m_mail = other-> m_mail;
}

Person* copyAssaimentOperator (Person *p, Person *other)
{
	if (p == other) 
	{
		return p;
	}
	p-> m_name = other-> m_name;
	p-> m_age = other-> m_age;
	p-> m_mail = other-> m_mail;
	return p;
}

void set_name (Person *p, std::string name)
{
	p-> m_name = name;
}
void set_age (Person *p, short age)
{
	p-> m_age = age;
}
void set_mail (Person *p, std::string mail)
{
	p-> m_mail = mail;
}
std::string get_name (const Person *p) {return p-> m_name;}
short get_age (const Person *p) {return p-> m_age;}
std::string get_mail (const Person *p) {return p-> m_mail;}

int main ()
{
	Person obj;
return 0;
}
