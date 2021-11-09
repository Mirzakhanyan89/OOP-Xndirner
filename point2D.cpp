#include <iostream> // 
#include <string>

class Point2D
{
public:
	Point2D (){}
	Point2D (int x, int y) : m_x {x}, m_y {y} {}
	Point2D (const Point2D & other) : m_x{other.m_x}, m_y{other.m_y} {}
	Point2D(const Point2D&& ot):m_x{std::move(ot.m_x)},m_y{std::move(ot.m_y)}{}
public:
	void set_x (int x) { m_x = x;}
       	void set_y (int y) { m_y = y;}
	int get_x () { return m_x;}
	int get_y () { return m_y;}
public:
//	Point2D & operator = (Point2D ob); 
	Point2D & operator = (const Point2D & ob);
	Point2D  operator + (const Point2D & ob);
	Point2D operator - (const Point2D & ob);
	Point2D operator / (const Point2D & ob);
	Point2D operator * (const Point2D & ob);
	bool operator > (const Point2D & ob);
	bool operator < (const Point2D & ob);
	bool operator == (const Point2D & ob);
	bool operator != (const Point2D & ob);
	bool operator >= (const Point2D & ob);
	bool operator <= (const Point2D & ob);
private:
	int m_x;
	int m_y;
};

int main ()
{
	Point2D obj1(11,55);
	Point2D obj2(4,7);

//	obj1 = obj2;
	if(obj1 >  obj2) 
		std::cout << "true\n";
	else std::cout << "false\n";


/*	Point2D it = obj1*obj2;
	std::cout<< it.get_x()<< "  " << it.get_y() << '\n';
	std::cout<< obj1 * obj2;
	if (obj2 > obj1)
	{
		std::cout<< "true";
	}
	std::cout<< "false";
*/
return 0;
}

Point2D & Point2D::operator = (const Point2D & ob)
{
 	if(this == & ob) return *this;
	this->m_x = ob.m_x;
	this->m_y = ob.m_y;
	return *this;	
}

Point2D  Point2D::operator + (const Point2D & ob)
{
	return { this->m_x + ob.m_x, this->m_y + ob.m_y};
}

Point2D  Point2D::operator - (const Point2D & ob)
{
	return { this->m_x - ob.m_x, this->m_y - ob.m_y};
}

Point2D  Point2D::operator / (const Point2D & ob)
{
	return { this->m_x / ob.m_x, this->m_y / ob.m_y};
}

Point2D  Point2D::operator * (const Point2D & ob)
{
	return {this->m_x * ob.m_x,  this->m_y * ob.m_y};
}

bool Point2D::operator > (const Point2D & ob)
{
	return this->m_x > ob.m_x and this->m_y > ob.m_y ;
}

bool Point2D::operator < (const Point2D & ob)
{
	return this->m_x < ob.m_x and this->m_y < ob.m_y;
}

bool  Point2D::operator == (const Point2D & ob)
{
	return this->m_x == ob.m_x and this->m_y == ob.m_y;
}

bool Point2D::operator != (const Point2D & ob)
{
	return this->m_x != ob.m_x or this->m_y != ob.m_y;
}

bool Point2D::operator >= (const Point2D & ob)
{
	return this->m_x >= ob.m_x and this->m_y >= ob.m_y;
}

bool Point2D::operator <= (const Point2D & ob)
{
	return this->m_x <= ob.m_x and this->m_y <= ob.m_y;
}

