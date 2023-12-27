#include "MyString.h"

MyString::MyString() {
    size = 0;
    capacity = 10;
    array = new char[capacity];
    array[0] = '\0';
}

MyString::MyString(const char* other) {
    size = strlen(other);
    if (size > capacity) {
        capacity *= 2;
    }
    array = new char[size + 1];
    for (size_t i = 0; i < size; ++i) {
        array[i] = other[i];
    }
    array[size] = '\0';
}

MyString::MyString(int count, char ch) {
    size = count;
    if (size > capacity) {
        capacity *= 2;
    }
    array = new char[count + 1];
    for (size_t i = 0; i < count; ++i) {
        array[i] = ch;
    }
    array[count] = '\0';
}


MyString::MyString(const MyString& other) {
    size = other.size;
    if (size > capacity) {
        capacity *= 2;
    }
    array = new char[size + 1];
    for (size_t i = 0; i < other.size; ++i) {
        array[i] = other.array[i];
    }
    array[size] = '\0';
}

MyString MyString::operator=(const MyString& other) {
    if (array != other.array) {
        if (array != nullptr) {
            delete[] array;
        }
        size = other.size;
        capacity = other.capacity;
        array = new char[other.size + 1];
        for (size_t i = 0; i < other.size; ++i) {
            array[i] = other.array[i];
        }
        array[size] = '\0';
    }
    return *this;
}

MyString::MyString(MyString&& other) noexcept {
    size = other.size;
    capacity = other.capacity;
    array = other.array;
    other.array = nullptr;
    other.size = 0;
}

MyString MyString::operator=(MyString&& other) noexcept {
    if (array != other.array) {
        delete[] array;
        size = other.size;
        capacity = other.capacity;
        array = other.array;
        other.array = nullptr;
        other.size = 0;
    }
    return *this;
}

MyString::~MyString() {
    if (array != nullptr) {
        delete[] array;
    }
}

int MyString::length() const{
    return size;
}

bool MyString::empty() const{
    return (!size) ? true : false;
}

const char* MyString::c_str() {
    return array;
}

char& MyString::operator[](int index) {
    if (index >= size || index < 0) {
        std::cout << "Index is out of bounds, exiting...";
        exit(0);
    }
    return array[index];
}

const char& MyString::operator[](int index) const {
    if (index >= size || index < 0) {
        std::cout << "Index is out of bounds, exiting...";
        exit(0);
    }
    return array[index];
}

char& MyString::front() {
    if (array == nullptr || size == 0) {
        throw std::logic_error("No elements in string.");
        exit(0);
    }
    return array[0];
}

char& MyString::back() {
    if (array == nullptr || size == 0) {
        throw std::logic_error("No elements in string.");
        exit(0);
    }
    return array[size - 1];
}


const char& MyString::front() const {
    if (array == nullptr) {
        throw std::logic_error("No elements in string.");
    }
    return array[0];
}

const char& MyString::back() const {
    if (array == nullptr) {
        throw std::logic_error("No elements in string.");
    }
    return array[size];
}

void MyString::reserve(int capacity) {
    if (capacity > size) {
        char* buffer = new char[capacity];
        if (array != nullptr) {
            for (size_t i = 0; i < size; ++i) {
                buffer[i] = array[i];
            }
            delete[] array;
        }
        array = buffer;
        size = capacity;
    }
}

void MyString::push_back(char ch) {
    if (size + 1 <= capacity) {
        array[size] = ch;
        array[size + 1] = '\0';
    }
    else {
        capacity = capacity * 2;
        char* str2 = new char[capacity];
        for (size_t i = 0; i < size; ++i) {
            str2[i] = array[i];
        }
        delete[] array;
        array = str2;
        array[size - 1] = ch;
        array[size] = '\0';
    }
    ++size;
}


void MyString::pop_back() {
    if (size > 0) {
        --size;
        array[size] = '\0';
    }
    else {
        std::cout << "The string is empty. Cannot pop_back().\n";
    }
}

void MyString::clear() {
    if (array != nullptr) {
        delete[] array;
        array = nullptr;
    }
    size = 0;
    capacity = 0;
}

bool MyString::insert(int index, const MyString& array) {
    if (index < 0 || index > size) {
        return false;
    }

    int newSize = size + array.size;

    if (newSize > capacity) {
        capacity *= 2;
    }

    char* buffer = new char[newSize + 1];

    for (size_t i = 0; i < index; ++i) {
        buffer[i] = this->array[i];
    }

    for (size_t i = 0; i < array.size; ++i, ++index) {
        buffer[index] = array[i];
    }
    for (size_t i = index - array.size; i < size; ++i) {
        buffer[index] = this->array[i];
        ++index;
    }

    buffer[newSize] = '\0';
    delete[] this->array;
    this->array = buffer;
    size = newSize;

    return true;
}

bool MyString::insert(int index, const char* array, int count) {
    if (index < 0 || index > size) {
        return false;
    }

    int newSize = size + count;

    if (newSize > capacity) {
        capacity *= 2;
    }

    char* buffer = new char[newSize + 1];

    for (size_t i = 0; i < index; ++i) {
        buffer[i] = this->array[i];
    }

    for (size_t i = 0; i < count; ++i, ++index) {
        buffer[index] = array[i];
    }

    for (size_t i = index - count; i < size; ++i) {
        buffer[index] = this->array[i];
        ++index;
    }

    buffer[newSize] = '\0';
    delete[] this->array;
    this->array = buffer;
    size = newSize;

    return true;
}

bool MyString::erase(int index, int count) {

    if (index < 0 || index >= size || count <= 0) {
        return false;
    }

    int deleteCount = std::min(count, size - index);
    int newSize = size - deleteCount;

    char* buffer = new char[newSize + 1];
    for (size_t i = 0; i < index; ++i) {
        buffer[i] = array[i];
    }
    for (size_t i = index + deleteCount, j = index; i < size; ++i, ++j) {
        buffer[j] = array[i];
    }
    buffer[newSize] = '\0';
    delete[] array;
    array = buffer;
    size = newSize;

    return true;
}

MyString MyString::operator+ (const MyString& other) {
    int newSize = size + other.size;

    if (newSize > capacity) {
        capacity *= 2;
    }

    char* newBuffer = new char[newSize + 1];

    for (size_t i = 0; i < size; ++i) {
        newBuffer[i] = array[i];
    }

    for (size_t j = 0; j < other.size; ++j) {
        newBuffer[size + j] = other.array[j];
    }

    newBuffer[newSize] = '\0';

    MyString result(newBuffer);

    delete[] newBuffer;

    return result;
}


MyString& MyString::operator+=(const MyString& other) {

    if ((other.size + size) > capacity) {
        capacity *= 2;
    }

    if (&other != this) {
        *this = *this + other;
    }
    return *this;
}


int MyString::compare(const MyString& array) const {
    for (size_t i = 0; i < size && i < array.size; ++i) {
        if (this->array[i] > array.array[i]) {
            return 1;
        }
        else if (this->array[i] < array.array[i]) {
            return -1;
        }
    }
    if (size < array.size) {
        return -1;
    }
    if (size > array.size) {
        return 1;
    }
    return 0;
}

int MyString::compare(const char* array) const {
    size_t i = 0;
    for (i; i < size && array[i] != '\0'; ++i) {
        if (this->array[i] > array[i]) {
            return 1;
        }
        else if (this->array[i] < array[i]) {
            return -1;
        }
    }

    if (i == size) {
        return 0;
    }

    if (size > i) {
        return 1;
    }

    return -1;
}


bool MyString::operator==(const char* other) const {
    return compare(other) == 0;
}

bool MyString::operator!=(const char* other) const {
    return compare(other) != 0;
}

bool MyString::operator<(const char* other) const {
    return compare(other) == -1;
}

bool MyString::operator<=(const char* other) const {
    return compare(other) != 1;
}

bool MyString::operator>(const char* other) const {
    return compare(other) == 1;
}

bool MyString::operator>=(const char* other) const {
    return compare(other) != -1;
}

bool MyString::operator==(const MyString& other) const {
    return compare(other) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return compare(other) != 0;
}

bool MyString::operator<(const MyString& other) const {
    return compare(other) == -1;
}

bool MyString::operator<=(const MyString& other) const {
    return compare(other) != 1;
}

bool MyString::operator>(const MyString& other) const {
    return compare(other) == 1;
}

bool MyString::operator>=(const MyString& other) const {
    return compare(other) != -1;
}

bool operator==(const char* array, const MyString& other) {
    return other.compare(array) == 0;
}

bool operator!=(const char* array, const MyString& other) {
    return other.compare(array) != 0;
}

bool operator<(const char* array, const MyString& other) {
    return other.compare(array) == -1;
}

bool operator<=(const char* array, const MyString& other) {
    return other.compare(array) != 1;
}

bool operator>(const char* array, const MyString& other) {
    return other.compare(array) == -1;
}

bool operator>=(const char* array, const MyString& other) {
    return other.compare(array) != 1;
}