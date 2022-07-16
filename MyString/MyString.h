#ifndef MYSTRING1_MYSTRING_H
#define MYSTRING1_MYSTRING_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cstring>
#include <exception>

class MyString {
public:
    //empty constructor
    MyString();

    //MyString(size_t size);
    //constructor
    MyString(const char* s);

    MyString(char s);

    MyString(const MyString& s);

    MyString(MyString&& s) noexcept;

    ~MyString();

    MyString& operator=(const MyString& s);

    MyString& operator=(MyString&& s) noexcept;

    char& operator[](size_t a);

    const char& operator[](size_t a) const;

    MyString& operator+=(const MyString& right);

    MyString operator+(const MyString& right) const;

    friend std::ostream& operator<<(std::ostream& out, const MyString& right);

    friend std::istream& operator>>(std::istream& in, MyString& right);

    size_t size () const noexcept;


private:
    void reserve();
    size_t reserve_size;
    size_t size_;
    char* arr_;
};

#endif //MYSTRING1_MYSTRING_H
