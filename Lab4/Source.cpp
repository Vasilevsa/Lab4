#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");

	Complex x1;
	cout << "Создание объекта x1 => " << x1 << endl;

	Complex x2(3, 6);
	cout << "Демонстация объекта x2 => " << x2 << endl;

	Complex x3(6);
	cout << "Демонстация объекта x3 => " << x3 << endl;

	cout << endl;

	cout << "Сложение (x3 + x2) => " << x3 + x2 << endl;
	cout << "Разность (x3 - x2) => " << x3 - x2 << endl;
	cout << "Умножение (x3 * x2) => " << x3 * x2 << endl;
	cout << "Деление (x3 / x2) => " << x3 / x2 << endl;

	cout << endl;

	cout << "Введите r, а затем phi для объекта x1 " << endl;
	cin >> x1;

	cout << "Данные объекта x1 => " 
		<< "Re = " << x1.Re()
		<< " Im = " << x1.Im()	
		<< " R = " << x1.R()
		<< " Phi = " << x1.Phi()
		<< endl;

	cout << endl;

	cout << "y(x2) => " << y(x2) << endl;
	cout << "sin(x2) => " << sin(x2) << endl;
	cout << "tg(x2) => " << tg(x2) << endl;
	cout << "th(x2) => " << th(x2) << endl;
	cout << "sh(x2) => " << sh(x2) << endl;
	cout << "pow(x3, x2) => " << pow(x3, x2) << endl;
	
	return 0;
}