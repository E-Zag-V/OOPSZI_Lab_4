#include <iostream>

class Complex
{
	private:
		double re, im, r, phi;
		
		void Init();
	public:
		Complex(double, double);
		Complex(double);
		Complex();

		double Re() const; 
		double Im() const;
		double R() const;
		double Phi() const;

		Complex pow(const Complex &z1, double z2);
		Complex th(const Complex &z);
		Complex exp(const Complex &z);

		friend std::ostream& operator<<(std::ostream &out, const Complex &ex);
		friend std::istream& operator>>(std::istream &in, Complex &ex);
		Complex operator+(Complex &expr);
		Complex operator+=(Complex &expr);
		Complex operator-(Complex &expr);
		Complex operator-=(Complex &expr);
		Complex operator*(Complex &expr);
		Complex operator*=(Complex &expr);
		Complex operator/(Complex &expr);
		Complex operator/=(Complex &expr);
};
