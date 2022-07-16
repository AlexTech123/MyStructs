#include <iostream>
#include <vector>
using namespace std;
class MyStack {
public:
    MyStack() :
            top_(nullptr),
            size_(0) {

    }

    MyStack(const MyStack& right) :
            MyStack() {
        Node* temp = right.top_;
        MyStack x;
        while (temp != nullptr) {
            x.push(temp->value_);
            temp = temp->back_;
        }
        temp = x.top_;
        while (temp != nullptr) {
            push(temp->value_);
            temp = temp->back_;
        }
        size_ = right.size_;
    }

    MyStack(MyStack&& right) {
        if (this != &right) {
            this->~MyStack();
            *this = std::move(right);
        }
    }

    ~MyStack() {
        while (size_ > 0) {
            pop();
        }
    }

    MyStack& operator=(MyStack&& right) noexcept {
        if (this != &right) {
            this->~MyStack();
            top_ = exchange(right.top_, nullptr);
            size_ = exchange(right.size_, 0);
        }
        return *this;
    }

    void push(int newValue) {
        if (top_ == nullptr) {
            top_ = new Node(newValue);
        } else {
            Node* oldTop = top_;
            top_ = new Node(newValue);
            top_->back_ = oldTop;
        }
        size_++;
    }

    int top() {
        if (size_ == 0) {
            throw out_of_range("Stack is empty");
        }
        return top_->value_;
    }

    void pop() {
        if (size_ == 0) {
            throw out_of_range("Stack is empty");
        }
        Node* oldTop = top_;
        top_ = top_->back_;
        delete oldTop;
        size_--;
        if (size_ == 0) {
            top_ = nullptr;
        }
    }

    bool empty() noexcept {
        return size_ == 0;
    }

    int size() noexcept {
        return size_;
    }

private:
    struct Node {
        int value_;
        Node* back_;
        explicit Node (int value) :
                value_(value),
                back_(nullptr) {

        }
    };

    Node* top_;
    int size_;
};

int main() {

    return 0;
}
