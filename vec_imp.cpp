#include <iostream>  //vec_impl

class Vector
{
private:
	int m_capacity;
	int m_size;
	int * m_arr;
public:
	Vector() { m_capacity = 4; m_size = 0; m_arr = new int[m_capacity];}
	void push_back(int elem);
	void utility ();
	void push_front(int elem);
	int operator [] (int);
};

int main()
{
	Vector v;
	v.push_front(4);
	v.push_front(7);
	v.push_front(10);
//	v.push_front(15);
//	v.push_front(17);
//	v.push_front(20);
	std::cout<< v.operator[](1) << std::endl;


return 0;
}

void Vector::push_back (int elem)
{
	if (m_size == m_capacity)
	{
		utility();
	}
	m_arr[m_size] = elem;
	++m_size;
	for (int i=0; i<m_size; ++i)
	{
		std::cout<< m_arr[i] << std::endl;
	}
	std::cout<< "_____________________________________________________________________________\n";
}

void Vector::push_front(int elem)
{	if (m_size+1 == m_capacity)
	{	
		utility ();	
	}
	m_arr[m_size] = elem;
	++m_size;
	if (m_size > 1)
	{
		for (int i=0; i<m_size; ++i)
		{
			m_arr[m_size-i] = m_arr[m_size-i-1];
		}
		m_arr[0] = m_arr[m_size];
		m_arr[m_size] = 0;
		for (int i=0; i<m_size; ++i)
		{
			std::cout<< m_arr[i] << std::endl;
		}
	std::cout<< "_____________________________________________________________________________\n";
	}
}	

void Vector::utility ()
{
	m_capacity *= 2;
	int * tmp = new int[m_capacity];
	for (int i=0; i<m_size; ++i)
	{
		tmp[i] = m_arr[i];
	}
	delete [] m_arr;
	m_arr = tmp;
	tmp = nullptr;
}	
	
int Vector::operator [] (int index)
{
	return m_arr[index];
}
