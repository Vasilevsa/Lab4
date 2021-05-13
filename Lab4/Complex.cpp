#include "Complex.h"
#include <complex>

Complex::Complex() : r(0), phi(0) { }

Complex::Complex(const double r, const double phi) : r(r), phi(phi) { }

Complex::Complex(const double digit)
{
	double x = digit, y = 0;

	r = sqrt(x*x + y*y);
	phi = Arg(x, y);
}

Complex Complex::operator+ (const Complex& rhs) {
	double x = this->Re() + rhs.Re(), 
		   y = this->Im() + rhs.Im();

	Complex result;
	result.r = sqrt(x * x + y * y);
	result.phi = Arg(x, y);

	return result;
}

Complex Complex::operator- (const Complex& rhs) {
	double x = this->Re() - rhs.Re(),
		   y = this->Im() - rhs.Im();

	Complex result;
	result.r = sqrt(x * x + y * y);
	result.phi = Arg(x, y);

	return result;
}

Complex Complex::operator* (const Complex& rhs) {
	Complex result;

	result.r = this->r * rhs.r;
	result.phi = this->phi + rhs.phi;

	return result;
}

Complex Complex::operator/ (const Complex& rhs) {
	Complex result;

	result.r = this->r / rhs.r;
	result.phi = this->phi - rhs.phi;

	return result;
	
	/*double x = ( (Re() * rhs.Re()) + (Im() * rhs.Im()) ) /
		(pow(rhs.Re(), 2) + pow(rhs.Im(), 2)),
		   y = ((Re() * rhs.Im() * (-1)) + (Im() * rhs.Re())) /
		(pow(rhs.Re(), 2) + pow(rhs.Im(), 2));

	return Complex(sqrt(x*x + y*y), Arg(x,y));*/
}

double Complex::Re() const { return r * cos(phi); }

double Complex::Im() const { return r * sin(phi); }

double Complex::R() const { return r; }

double Complex::Phi() const { return phi; }

std::istream& operator>>(std::istream& is, Complex& obj)
{
	is >> obj.r >> obj.phi;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Complex& obj)
{
	os << "r= " << obj.R() << " phi= " << obj.Phi();

	return os;
}

double Arg(const double x, const double y)
{
	double PI = 3.1415926535;

	if (x > 0 && y >= 0)
		return atan(y / x);
	else if (x < 0 && y >= 0)
		return PI - atan(abs(y / x));
	else if (x < 0 && y < 0)
		return PI + atan(abs(y / x));
	else if (x > 0 && y < 0)
		return 2 * PI - atan(abs(y / x));
	else if (x == 0 && y > 0)
		return PI / 2;
	else if (x == 0 && y < 0)
		return (3 * PI) / 2;
}

Complex y(const Complex& z) {

	Complex z1(z.R() / 2, z.Phi());

	Complex z2( pow(z.R(), 5), z.Phi()*5 );

	Complex result(1); 

	result = result - z2 - th(z1);
	return result;
}

Complex sin(const Complex& z) {
	double x = sin(z.Re()) * cosh(z.Im()),
		   y = cos(z.Re()) * sinh(z.Im());
	
	Complex result(sqrt(x*x + y*y), Arg(x, y));
	return result;
}

Complex tg(const Complex& z) {
	double x = sin(2 * z.Re()) / (cos(2 * z.Re()) + cosh(2 * z.Im())),
		   y = sinh(2 * z.Im()) / (cos(2 * z.Re()) + cosh(2 * z.Im()));

	Complex result(sqrt(x * x + y * y), Arg(x, y));
	return result;
}

Complex th(const Complex& z) {

	double x = ( cosh(z.Re()) * sinh(z.Re()) * pow( cos( z.Im()), 2 ) + cosh(z.Re()) * sinh(z.Re()) * pow(sin(z.Im()), 2) )
		/
		( pow(cosh(z.Re()) , 2) * pow(cos(z.Im()) , 2) + pow(sinh(z.Re()), 2) * pow(sin(z.Im()), 2) ),
	
		   y = ( pow(cosh(z.Re()) , 2) * cos(z.Im()) * sin(z.Im()) - pow(sinh(z.Re()) , 2) * cos(z.Im()) * sin(z.Im()) )
		/
		( pow(cosh(z.Re()), 2) * pow(cos(z.Im()), 2) + pow(sinh(z.Re()), 2) * pow(sin(z.Im()), 2) );

	Complex result(sqrt(x * x + y * y), Arg(x, y));
	return result;
}

Complex sh(const Complex& z) {
	double x = sinh(z.Re())*cos(z.Im()),
		   y = cosh(z.Re())*sin(z.Im());

	Complex result(sqrt(x * x + y * y), Arg(x, y));
	return result;
}

Complex pow(const Complex& z1, const Complex& z2) {
	std::complex <double> f(z1.Re(), z1.Im());
	std::complex <double> s(z2.Re(), z2.Im());
	std::complex <double> res = std::pow(f, s);
	
	Complex result(sqrt(res.real() * res.real() + res.imag() * res.imag()), Arg(res.real(), res.imag()));
	return result;
}