#include "MyString.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>
#define DEBUG
MyString::MyString() :
        size_(0),
        arr_(nullptr) {
}

/*MyString::MyString(size_t size) :
        size_(size),
        arr_(new char[size_]) {
    for (size_t i = 0; i != size_; i++) {
        arr_[i] = '0';
    }
}*/

MyString::MyString(const char* s) :
        size_(strlen(s)),
        arr_(new char[size_]) {
    for (size_t i = 0; i != size_; i++) {
        arr_[i] = s[i];
    }
}

MyString::MyString(char s) :
        size_(1),
        arr_(new char[size_]) {
    arr_[0] = s;
}

MyString::MyString(const MyString& s) :
        size_(s.size_),
        arr_(new char[size_]) {
    for (size_t i = 0; i != size_; i++) {
        arr_[i] = s.arr_[i];
    }
    //cout << "COPIED ";
}

MyString::MyString(MyString&& s) noexcept :
        size_(s.size_),
        arr_(s.arr_) {
    s.size_ = 0;
    s.arr_ = nullptr;
}

MyString& MyString::operator=(const MyString& s) {
    if (this != &s) {
        char* newArr_ = new char[s.size_];
        delete [] arr_;
        arr_ = newArr_;
        for (size_t i = 0; i != s.size_; i++) {
            arr_[i] = s.arr_[i];
        }
        size_ = s.size_;
    }
    return *this;
}

MyString& MyString::operator=(MyString&& s) noexcept {
    if (this != &s) {
        size_ = 0;
        delete [] arr_;
        size_ = s.size_;
        arr_ = s.arr_;
        s.size_ = 0;
        s.arr_ = nullptr;
    }
}

char& MyString::operator[](size_t index) {
#ifdef DEBUG
    if (index >= size_) {
        throw std::out_of_range("Out of range");
    }
#endif
    return arr_[index];
}

const char& MyString::operator[](size_t index) const {
#ifdef DEBUG
    if (index >= size_) {
        throw std::out_of_range("Out of range");
    }
#endif
    return arr_[index];
}

MyString& MyString::operator+=(const MyString& right) {
    size_t newSize = size_ + right.size_;
    char* newArr = new char[newSize];
    for (size_t i = 0; i != size_; i++) {
        newArr[i] = arr_[i];
    }
    delete [] arr_;
    arr_ = newArr;
    newArr += size_;
    for (size_t i = 0; i != right.size_; i++) {
        newArr[i] = right.arr_[i];
    }
    size_ = newSize;
    return *this;
}

MyString MyString::operator+(const MyString& right) const {
    MyString temp(*this);
    temp += right;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const MyString& right) {
    for (size_t i = 0; i != right.size_; i++) {
        out << right.arr_[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, MyString& right) {
    while (in.peek() == ' ' || in.peek() == '\t' || in.peek() == '\n') {
        in.ignore();
    }
    while (!in.eof() && in.peek() != ' ' && in.peek() != '\t' && in.peek() != '\n') {
        char s;
        in >> s;
        right += s;
    }
    return in;
}

void MyString::reserve() {

}

size_t MyString::size () const noexcept {
    return size_;
}

MyString::~MyString() {
    delete [] arr_;
}

