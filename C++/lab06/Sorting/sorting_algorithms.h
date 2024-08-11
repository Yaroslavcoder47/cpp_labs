#include <vector>

#ifndef SORTING_ALGORITHMS_H_
#define SORTING_ALGORITHMS_H_

template<typename T> 
void bubbleSort(std::vector<T>& a)
{
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = a.size() - 1; j > i; --j) {
            if (a[j - 1] > a[j]) {
                std::swap(a[j - 1], a[j]);
            }
        }
    }
}

template<typename T>
void insertionSort(std::vector<T>& a)
{
    for (size_t i = 1; i < a.size(); ++i) {
        for (size_t j = i; j > 0 && a[j - 1] > a[j]; --j) {
            std::swap(a[j - 1], a[j]);
        }
    }
}

template<typename T>
void shellSort(std::vector<T>& a)
{
    for (size_t i = a.size() / 2; i > 0; i /= 2) {
        for (size_t j = i; j < a.size(); j += 1) {
            T tmp = a[j];
            size_t k;
            for (k = j; k >= i && a[k - i] > tmp; k -= i) {
                a[k] = a[k - i];
            }
            a[k] = tmp;
        }
    }
}

template<typename T>
void oddEvenSort(std::vector<T>& a)
{
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = (i % 2) ? 0 : 1; j + 1 < a.size(); j += 2) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

template<typename T>
void cocktailSort(std::vector<T>& a)
{
    size_t left = 0;
    size_t right = a.size()-1;
    bool check = true;
    while ((left < right) && check) {
        check = false;
        for (size_t i = left; i < right; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                check = true;
            }
        }
        right--;
        for (size_t i = right; i > left; --i) {
            if (a[i] < a[i - 1]) {
                std::swap(a[i], a[i - 1]);
                check = true;
            }
        }
        left++;
    }
}

template<typename T>
void combSort(std::vector<T>& a)
{
    size_t n = a.size();
    size_t step = n;
    bool check = true;

    while (step > 1 || check) {
        
        step = (step * 10) / 13;
        if (step < 1) {
            step = 1;
        }

        check = false;
        for (size_t i = 0; i < n - step; ++i) {
            if (a[i] > a[i + step]) {
                std::swap(a[i], a[i + step]);
                check = true;
            }
        }
    }
}

template<typename T> 
void selectionSort(std::vector<T>& a)
{
    T max;
    size_t iMax;
    for (size_t i = a.size() - 1; i > 0; --i) {
        max = a[0];
        iMax = 0;
        for (size_t j = 0; j <= i; ++j) {
            if (max < a[j]) {
                max = a[j];
                iMax = j;
            }
        }
        std::swap(a[iMax], a[i]);
    }
}

template<typename T>
void doubleSelectionSort(std::vector<T>& a)
{
    size_t left = 0;
    size_t right = a.size() - 1;

    while (left < right) {
        size_t minIndex = left;
        size_t maxIndex = left;

        for (size_t i = left; i <= right; i++) {
            if (a[i] < a[minIndex]) {
                minIndex = i;
            }
            else if (a[i] > a[maxIndex]) {
                maxIndex = i;
            }
        }
        std::swap(a[left], a[minIndex]);
        if (maxIndex == left) {
            maxIndex = minIndex;
        }
        std::swap(a[right], a[maxIndex]);
        left++;
        right--;
    }
}

// help function for quickSort()
template <typename T>
int partition(std::vector<T>& a, int low, int high)
{
    T pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j) {
        if (a[j] < pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return (i + 1);
}
template <typename T>
void quickSort(std::vector<T>& a, int low, int high)
{
    if (low < high) {
        int pivotIndex = partition(a, low, high);

        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}
template <typename T>
void quickSort(std::vector<T>& a)
{
    int low = 0;
    int high = a.size() - 1;
    quickSort(a, low, high);
}


// functions for mergeSort()
template <typename T>
void merge(std::vector<T>& a, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = a[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
template <typename T>
void mergeSort(std::vector<T>& a, int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);
        merge(a, left, middle, right);
    }
}
template <typename T>
void mergeSort(std::vector<T>& a)
{
    size_t n = a.size();
    mergeSort(a, 0, n - 1);
}

#endif // SORTING_ALGORITHMS_H_