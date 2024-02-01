// ��� ����������� ������ � ���� ����������� ��������� ���� ���, 
// ������� ����������������, �������� � ������������ �����, � ���� ���������� 
// ����������� ������ �� ��������, ������� ����� ������ �����������, �������� ������� � ��������������� 
// ������, ������� �� �������� ���������

#pragma once

#ifndef MATH_OPERATOR_HPP
#define MATH_OPERATOR_HPP

#include<iostream>

template<typename Type>
class MathOperator {
public:
	// ����������� �� ���������
	MathOperator() :operand1_(Type()), operand2_(Type()) {} // ������ 0 ������ Type() ��� ������������� � �����	��������� �����
	// ����������� � ����������
	MathOperator(Type left, Type right) :operand1_(left), operand2_(right) {}
	// ������� ��� ������ ���������� ���������� ���� ������ ��� ����������� ��������� ���-� � ����
	void SetLeft(Type num) {
		operand1_ = num;
	}
	void SetRight(Type num) {
		operand2_ = num;
	}
	// ������� ��� ����������� �������� �����
	Type GetLeft()const { // const, ����� �������� �� �������� ���� �������
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

// ��������� �������� ���������� ������ 

// ������� 1: ��������� ���������� �������������
void PrintSumm(const MathOperator<int>& obj);

// ������� 2: ��������� ����������� ����
template<typename T>
void PrintMultiply(const MathOperator<T>& obj) {
	std::cout << obj.GetLeft() << '*' << obj.GetRight() << '=' << obj.Multiply() << "\n";
}

// ������� �������� ��������� � ������������� �������
template<>
void PrintMultiply<bool>(const MathOperator<bool>& obj) {
	// ������� 1 ���������: ������ �����������
	// throw -1; // ���� ��� �� ������, �� �������� � ������������ ���������� ��������� ����� ������� � ������� � ��������������� ������ �������

	// ������� 2 ���������: �������� � ������ ������������ ������� ������
	std::cout << obj.GetLeft() << '*' << obj.GetRight() << '=' << "not allowed operator!\n";
}

#endif // !MATH_OPERATOR_HPP