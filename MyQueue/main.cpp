#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
public:
    MyQueue() :
            head_(nullptr),
            tail_(nullptr),
            size_(0) {

    }

    MyQueue(const MyQueue& right) :
            MyQueue() {
        Node* temp = right.head_;
        while (temp != nullptr) {
            push(temp->value_);
            temp = temp->next_;
        }
        size_ = right.size_;
    }

    MyQueue(MyQueue&& right) {
        if (this != &right) {
            this->~MyQueue();
            *this = std::move(right);
        }
    }

    ~MyQueue() {
        while (size_ > 0) {
            pop();
        }
    }

    MyQueue& operator=(MyQueue&& right) noexcept {
        if (this != &right) {
            this->~MyQueue();
            head_ = exchange(right.head_, nullptr);
            tail_ = exchange(right.tail_, nullptr);
            size_ = exchange(right.size_, 0);
        }
        return *this;
    }

    void push(int newValue) {
        if (head_ == nullptr) {
            head_ = new Node(newValue);
            tail_ = head_;
        } else {
            tail_->next_ = new Node(newValue);
            tail_ = tail_->next_;
        }
        size_++;
    }

    int front() const {
        if (size_ == 0) {
            throw std::out_of_range("Queue is empty");
        } else {
            return head_->value_;
        }
    }

    void pop() {
        if (size_ == 0) {
            throw std::out_of_range("Queue is empty");
        }
        Node* oldHead = head_;
        head_ = head_->next_;
        delete oldHead;
        size_--;
        if (size_ == 0) {
            head_ = nullptr;
            tail_ = nullptr;
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
        Node* next_;

        explicit Node(int value) :
                value_(value),
                next_(nullptr) {

        }
    };

    Node* head_;
    Node* tail_;
    int size_;
};


int main() {
    MyQueue a;
    a.push(1);
    a.push(2);
    MyQueue x = std::move(a);
    cout << x.front();
    return 0;
}
