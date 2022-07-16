#ifndef MYVECT_MYVECTOR_H
#define MYVECT_MYVECTOR_H

#include <vector>
#include <stdexcept>

template <class T>
class MyVector {
public:
    MyVector();

    MyVector(const MyVector<T>& right);

    MyVector(MyVector<T>&& right) noexcept;

    ~MyVector() noexcept;

    MyVector<T>& operator=(const MyVector<T>& right);

    MyVector<T>& operator=(MyVector<T>&& right) noexcept;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    MyVector<T>& push_back(const T& elem);

    MyVector<T>& push_back(T&& elem);

private:
    T* data_;
    size_t size_;
};

template <class T>
MyVector<T>::MyVector() :
        data_(nullptr),
        size_(0) {

}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& right) :
        MyVector() {
    *this = right;
}

template<class T>
MyVector<T>::MyVector(MyVector<T>&& right) noexcept :
        MyVector() {
    *this = std::move(right);
}

template<class T>
MyVector<T>::~MyVector() noexcept {
    //delete [] data_;
    for (int i = 0 ; i != size_; i++) {
        data_[i].~T();
    }
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T> &right) {
    if (this != &right) {
        T* newData = static_cast<T*>(::operator new(right.size_ * sizeof(T)));
        for (size_t i = 0; i != right.size_; i++) {
            try {
                new(newData + i) T(right.data_[i]);
            } catch (...) {
                for (size_t j = 0; j != i; j++) {
                    newData[j].~T();
                }
                ::operator delete(newData);
                throw;
            }
        }
        //delete [] data_;
        for (int i = 0 ; i != size_; i++) {
            data_[i].~T();
        }
        data_ = newData;
        size_ = right.size_;
    }
    return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& right) noexcept {
    if (this != &right) {
        data_ = std::exchange(right.data_, nullptr);
        size_ = std::exchange(right.size_, 0);
    }
    return *this;
}

template<class T>
T& MyVector<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<class T>
const T& MyVector<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<class T>
MyVector<T>& MyVector<T>::push_back(const T& elem) {
    T* newData = static_cast<T*>(::operator new((size_ + 1) * sizeof(T)));
    try {
        new(newData + size_) T(elem);
    } catch (...) {
        ::operator delete(newData);
        throw;
    }
    for (size_t i = 0; i != size_; i++) {
        new(newData + i) T(std::move(data_[i]));
    }
    //delete [] data_;
    for (int i = 0 ; i != size_; i++) {
        data_[i].~T();
    }
    data_ = newData;
    size_++;
    return *this;
}

template<class T>
MyVector<T>& MyVector<T>::push_back(T&& elem) {
    T* newData = static_cast<T*>(::operator new((size_ + 1) * sizeof(T)));
    try {
        new(newData + size_) T(std::move(elem));
    } catch (...) {
        ::operator delete(newData);
        throw;
    }
    for (size_t i = 0; i != size_; i++) {
        new(newData + i) T(std::move(data_[i]));
    }
    //delete [] data_;
    for (int i = 0 ; i != size_; i++) {
        data_[i].~T();
    }
    data_ = newData;
    size_++;
    return *this;
}

#endif //MYVECT_MYVECTOR_H
