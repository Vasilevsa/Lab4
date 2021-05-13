#pragma once
#include <iostream>

class Complex
{
private:
	double r; // ������
	double phi; // ��������

public:
	Complex();

	Complex(const double r, const double phi);

	Complex(const double digit);

	Complex operator+ (const Complex& rhs);

	Complex operator- (const Complex& rhs);

	Complex operator* (const Complex& rhs);

	Complex operator/ (const Complex& rhs);

	double Re() const;

	double Im() const;

	double R() const;

	double Phi() const;

	friend std::istream& operator>> (std::istream& is, Complex& obj);
	friend std::ostream& operator<< (std::ostream& os, const Complex& obj);
};

double Arg(const double x, const double y); // ��������������� ������� ��� �������� ������������ ����� �� ��������� x � y

Complex y(const Complex& z);

Complex sin(const Complex& z);

Complex tg(const Complex& z);

Complex th(const Complex& z);

Complex sh(const Complex& z);

Complex pow(const Complex& z1, const Complex& z2);