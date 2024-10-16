#include "stack.h"

Node::Node(int32_t value, Node* previous) : value(value), previous(previous) {
}

int32_t Stack::Size() const {
    return size_;
}

Stack::Stack() : size_(0) {
}

int32_t Stack::Top() const {
    return head_->value;
}

bool Stack::Empty() const {
    return size_ == 0;
}

void Stack::Pop() {
    if (!Empty()) {
        --size_;
        Node* temp = head_;
        head_ = temp->previous;
        delete temp;
    }
}

void Stack::Clear() {
    while (!Empty()) {
        Pop();
    }
}

Stack::~Stack() {
    Clear();
}

void Stack::Push(int32_t value) {
    head_ = new Node(value, head_);
    ++size_;
}
