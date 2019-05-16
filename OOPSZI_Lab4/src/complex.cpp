#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

Complex::Complex(double _r, double _phi)
{
	r = _r;
	phi = _phi;

	Init();
}

Complex::Complex(double _r)
{
	r = r;
	phi = 0;

	Init();
}

Complex::Complex()
{
	r = 0;
	phi = 0;

	Init();
}

void Complex::Init()
{
	re = Re();
	im = Im();
}

double Complex::Re() const
{
	return r * cos(phi);
}

double Complex::Im() const
{
	return r * sin(phi);
}

double Complex::R() const
{
	return r;
}

double Complex::Phi() const
{
	return phi;
}

Complex Complex::pow(const Complex &z1, double z2)
{
	return Complex( _CMATH_::pow(z1.R() * cos(z2 * phi), sin(z2 * phi)) );
}

Complex Complex::exp(const Complex &z)
{
	return Complex(_CMATH_::exp(z.Re()), 0) * Complex(cos(z.Im()), sin(z.Im()));
}

Complex Complex::th(const Complex &z)
{
	return ( exp(z) - exp(z) * Complex(-1, 0) ) / (exp(z) + exp(z) * Complex(-1, 0));
}

ostream& operator<<(ostream &out, const Complex &ex)
{
	out << "(" << ex.re << ", " << ex.im << "i)";
	return out;
}

istream& operator>>(istream &in, Complex &ex)
{
	in >> ex.re >> ex.im;
	return in;
}

Complex Complex::operator+(Complex &ex)
{
	return Complex(re + ex.Re(), im + ex.Im());
}

Complex Complex::operator+=(Complex &ex)
{
	re += ex.Re();
	im += ex.Im();

	return *this;
}

Complex Complex::operator-(Complex &ex)
{
	return Complex(re - ex.Re(), im - ex.Im());
}

Complex Complex::operator-=(Complex &ex)
{
	re -= ex.Re();
	im -= ex.Im();

	return *this;
}

Complex Complex::operator*(Complex &ex)
{
	return Complex( re * ex.Re() - im * ex.Im(), re * ex.Im() + im * ex.Re() );
}

Complex Complex::operator*=(Complex &ex)
{
	double _re = re;

	re = re * ex.Re() - im * ex.Im();
	im = _re * ex.Im() + im * ex.Re();

	return *this;
}

Complex Complex::operator/(Complex &ex)
{
    	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

    	return Complex( ( re * ex.Re() + im * ex.Im() ) / r, ( im * ex.Re() - re * ex.Im() ) / r );
}

Complex Complex::operator/=(Complex &ex)
{
	double _re = re;
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

	re = ( re * ex.Re() + im * ex.Im() ) / r;
	im = ( im * ex.Re() - _re * ex.Im() ) / r;

	return *this;
}
