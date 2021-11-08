#include <iostream>  //Person
class Person
{
private: 
	std::string m_name;
	short m_age;
	std::string m_mail;
public:
	Person (){}
	~Person() {}
	Person (const Person & obj): m_name {obj.m_name}, m_age {obj.m_age}, m_mail {obj.m_mail} {}
	Person & operator = (const Person & obj)
	{
		if(this == & obj){return *this;}
		this->m_name = obj.m_name;
		this->m_age = obj.m_age;
		this->m_mail = obj.m_mail;
		return *this;
	}
	void set_name (const std::string& name) {m_name = name; }
	void set_age (short age) {m_age = age; }
	void set_mail (const std::string& mail) {m_mail = mail; }
	std::string get_name ()const {return m_name;}
	short get_age()const {return m_age; }
	std::string get_mail ()const {return m_mail; }
};

int main()
{
	Person obj;
	
return 0;
}

