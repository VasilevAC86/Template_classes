# include <iostream>
# include"MathOperator.hpp"

int main() {
	const MathOperator<float> f(1., 2.);
	std::cout << f.Summ() << '\n';
	// f.SetLeft(6) вызвать метод невозможно из-за const

	MathOperator<float> f2(1.5, 2.9);
	std::cout << f2.Summ() << '\n';

	f2.SetRight(f2.GetRight() + 1);
	std::cout << f2.GetLeft() << '+' << f2.GetRight() << '=' << f2.Summ() << "\n"; // Созданные объекты
	// При работе с шаблонными классами нет запретов на использование анонимных объектов
	std::cout << 4 << '*' << 9 << '=' << MathOperator<int>(4,9).Multiply() << "\n"; // Анонимный объект шаблонного класса типа int 
	
	PrintSumm(MathOperator<int>(4, 9));

	const MathOperator<int> int_m(1, 54);
	PrintSumm(int_m);
	// PrintSumm(f2); невозможно, т.к. в функции упомянута конкретная реализация

	PrintMultiply(f);
	PrintMultiply(int_m);
	PrintMultiply(MathOperator<bool>(false, true));

	return 0;
}