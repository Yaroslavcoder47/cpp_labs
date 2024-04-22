#include <iostream>
#include <utility>
#include <cmath>

extern "C" float __fastcall calculateSqrt(int, float*);

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

int main() {
    std::cout << "Input value of number a = ";
    float a;
    std::cin >> a;
    std::cout << "Input number of iterations n = ";
    int n;
    std::cin >> n;

    float result = CalculateSqrt(n, &a);

    /*float* aPtr = &a;
    float result;
    __asm {
        mov ecx, n
        mov edx, dword ptr[aPtr]
        call calculateSqrt
        fstp dword ptr[result]
    }*/

    std::cout << "Result of function: " << result << ' ' << "Difference: " << std::sqrt(a) - result;
    return 0;
}