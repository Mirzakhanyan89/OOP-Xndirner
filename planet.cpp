#include <iostream>
const double G = 6.67e-11;

class Planet
{
private:
	std::string m_name;
	double m_distance;
	double m_radius;
	double m_massa;
	double m_g ( );
			/*std::string name, double distance, double radius, double massa*/
public:
	void set_name(const std::string & name);
	std::string get_name() { return m_name; }
	void set_dist (double distance) { m_distance = distance;}
	double get_dist () { return m_distance;};
	void set_rad (double radius) { m_radius = radius; }
	double get_rad () { return m_radius;}
	void set_mas (double massa) { m_massa = massa; }
	double get_mas () { return m_massa;}
	double get_g () { return m_g(); }
};

double Planet::m_g ()
{
	return ((G * m_massa )/ (m_radius * m_radius));
}

void Planet::set_name (const std::string & name)
{
	m_name = name;
}


int main ()
{
	Planet planet;
	planet.set_name("Eart");
	planet.set_mas(5.972e+24);
	planet.set_rad(6381);
	std::cout<< planet.get_g();
return 0;
}
