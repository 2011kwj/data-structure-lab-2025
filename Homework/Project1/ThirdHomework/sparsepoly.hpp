#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <stdio.h>
#include <vector>
#include <iostream>

#define MAX_DEGREE 101 // ���׽��� ó�� ������ �ִ� ���� + 1

class SparsePoly {
    int numTerms;                        // ���׽� ���� ����
    std::vector<int> exponents;         // �� ���� ���� ���� ����
    std::vector<float> coefficients;    // �� ���� ��� ���� ����

public:
    // ������
    SparsePoly() : numTerms(0) {}

    // ���׽� �Է� �Լ�
    void read() {
        std::cout << "���� ������ �Է��ϼ���: ";
        std::cin >> numTerms;

        exponents.resize(numTerms);
        coefficients.resize(numTerms);

        for (int i = 0; i < numTerms; ++i) {
            std::cout << i + 1 << "��° ���� ����� ������ �Է��ϼ��� (��: ��� ����): ";
            std::cin >> coefficients[i] >> exponents[i];
        }
    }

    // ���׽� ��� �Լ�
    void display(const char* str) {
        std::cout << str;
        for (int i = 0; i < numTerms; ++i) {
            std::cout << coefficients[i] << "x^" << exponents[i];
            if (i != numTerms - 1)
                std::cout << " + ";
        }
        std::cout << std::endl;
    }

    // ���׽� ���� �Լ�: A + B �� this
    void add(SparsePoly a, SparsePoly b) {
        int i = 0, j = 0;
        exponents.clear();
        coefficients.clear();

        while (i < a.numTerms && j < b.numTerms) {
            if (a.exponents[i] > b.exponents[j]) {
                exponents.push_back(a.exponents[i]);
                coefficients.push_back(a.coefficients[i]);
                ++i;
            }
            else if (a.exponents[i] < b.exponents[j]) {
                exponents.push_back(b.exponents[j]);
                coefficients.push_back(b.coefficients[j]);
                ++j;
            }
            else {
                float sum = a.coefficients[i] + b.coefficients[j];
                if (sum != 0) {
                    exponents.push_back(a.exponents[i]);
                    coefficients.push_back(sum);
                }
                ++i; ++j;
            }
        }

        while (i < a.numTerms) {
            exponents.push_back(a.exponents[i]);
            coefficients.push_back(a.coefficients[i]);
            ++i;
        }

        while (j < b.numTerms) {
            exponents.push_back(b.exponents[j]);
            coefficients.push_back(b.coefficients[j]);
            ++j;
        }

        numTerms = exponents.size();
    }
};

#endif
