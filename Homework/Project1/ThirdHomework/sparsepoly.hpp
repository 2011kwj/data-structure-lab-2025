#ifndef SPARSEPOLY_HPP
#define SPARSEPOLY_HPP

#include <stdio.h>
#include <vector>
#include <iostream>

#define MAX_DEGREE 101 // 다항식의 처리 가능한 최대 차수 + 1

class SparsePoly {
    int numTerms;                        // 다항식 항의 개수
    std::vector<int> exponents;         // 각 항의 차수 저장 벡터
    std::vector<float> coefficients;    // 각 항의 계수 저장 벡터

public:
    // 생성자
    SparsePoly() : numTerms(0) {}

    // 다항식 입력 함수
    void read() {
        std::cout << "항의 개수를 입력하세요: ";
        std::cin >> numTerms;

        exponents.resize(numTerms);
        coefficients.resize(numTerms);

        for (int i = 0; i < numTerms; ++i) {
            std::cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (예: 계수 차수): ";
            std::cin >> coefficients[i] >> exponents[i];
        }
    }

    // 다항식 출력 함수
    void display(const char* str) {
        std::cout << str;
        for (int i = 0; i < numTerms; ++i) {
            std::cout << coefficients[i] << "x^" << exponents[i];
            if (i != numTerms - 1)
                std::cout << " + ";
        }
        std::cout << std::endl;
    }

    // 다항식 덧셈 함수: A + B → this
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
