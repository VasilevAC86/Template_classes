// При организации класса в виде бибилиотеки требуется весь код, 
// который являетсягаблоном, оставить в заголовочном файле, в файл реализации 
// переносятся только те элементы, которые имеют полное определение, например функции и вспомогательные 
// классы, которые не являются шаблонами

#pragma once

#ifndef MATH_OPERATOR_HPP
#define MATH_OPERATOR_HPP

#include<iostream>

template<typename Type>
class MathOperator {
public:
	// Конструктор по умолчанию
	MathOperator() :operand1_(Type()), operand2_(Type()) {} // Вместо 0 ставим Type() для совместимости с любым	возможным типом
	// Конструктор с параметром
	MathOperator(Type left, Type right) :operand1_(left), operand2_(right) {}
	// сэттэры для приёмки аргументов шаблонного типа данных для корректного занесения инф-и в поля
	void SetLeft(Type num) {
		operand1_ = num;
	}
	void SetRight(Type num) {
		operand2_ = num;
	}
	// гэттэры для возвращения значений полей
	Type GetLeft()const { // const, чтобы случайно не изменить поля объекта
		return operand1_;
	}
	Type GetRight()const {
		return operand2_;
	}
	Type Summ()const {
		return operand1_ + operand2_;
	}
	Type Multiply()const {
		return operand1_ * operand2_;
	}
private:
	int operand1_;
	int operand2_;
};

// Обработка объектов шаблонного класса 

// Вариант 1: обработка конкретной специализации
void PrintSumm(const MathOperator<int>& obj);

// Вариант 2: обработка обобщённого вида
template<typename T>
void PrintMultiply(const MathOperator<T>& obj) {
	std::cout << obj.GetLeft() << '*' << obj.GetRight() << '=' << obj.Multiply() << "\n";
}

// решение проблемы обработки в специализации шаблона
template<>
void PrintMultiply<bool>(const MathOperator<bool>& obj) {
	// вариант 1 обработки: кидаем исколючение
	// throw -1; // если так не делать, то проблема с некорректным поведением программы может вылезти в будущем в непредсказуемый момент времени

	// вариант 2 обработки: работаем с учётом особенностей входных данных
	std::cout << obj.GetLeft() << '*' << obj.GetRight() << '=' << "not allowed operator!\n";
}

#endif // !MATH_OPERATOR_HPP