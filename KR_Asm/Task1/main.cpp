#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
const int n = 1;
const int m = 2;

extern "C" float __fastcall calculateSqrt(int, float*);
extern "C" void __cdecl CreateVectorB(unsigned int a[n][m], int n, int m, int* b);

float CalculateSqrt(int n, float* a) {
    float variable = *a;
    __asm {
        finit
        mov esi, dword ptr[a]
        mov ecx, n
        _loop :
        fld dword ptr[esi]
            fld1
            fld1
            fadd

            fdivp st(1), st(0)
            fld dword ptr[variable]

            fld1
            fld1
            fadd
            fld dword ptr[esi]

            fmulp st(1), st(0)
            fdivp st(1), st(0)
            faddp st(1), st(0)
            fstp dword ptr[esi]
            loop _loop
    }
    return *a;
}

void task1() {
    //float result = CalculateSqrt(n, &a);
    std::cout << "Input value of number a = ";
    float a;
    std::cin >> a;
    std::cout << "Input number of iterations n = ";
    int n;
    std::cin >> n;

    float* aPtr = &a;
    float result;
    __asm {
        mov ecx, n
        mov edx, dword ptr[aPtr]
        call calculateSqrt
        fstp dword ptr[result]
    }

    std::cout << "Result of function: " << result << ' ' << "Difference: " << std::sqrt(a) - result;
}

void task2()
{
    std::vector<int> res(n, -1);
    int* b = res.data();
    unsigned int a[n][m];
    std::cout << "Input array:\n";
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }

    CreateVectorB(a, n, m, b);
    std::cout << "Rows : ";
    for (size_t i = 0; i < n; ++i) {
        if (b[i] != -1) {
            std::cout << b[i] << ' ';
        }
    }
}

int main() {
    task2();
    /*int n, m;
    std::cin >> n >> m;
    unsigned int** a = new unsigned int* [n];
    for (size_t i = 0; i < n; ++i) {
        a[i] = new unsigned int[m];
    }*/
    
    /*__asm {
        push n
        push m
        push dword 
       
        xor eax, eax
        xor ebx, ebx
        call CreateVectorB
    }*/
    return 0;
}