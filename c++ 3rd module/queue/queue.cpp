#include "queue.h"

Node::Node(int32_t value, Node* next) : value(value), next(next) {
}

Queue::Queue() : size_(0) {
}

bool Queue::Empty() const {
    return size_ == 0;
}

int32_t Queue::Size() const {
    return size_;
}

int32_t Queue::Front() const {
    return front_->value;
}

void Queue::Pop() {
    if (!Empty()) {
        --size_;
        Node* temp = front_;
        front_ = temp->next;
        delete temp;
    }
}

void Queue::Clear() {
    while (!Empty()) {
        Pop();
    }
}

void Queue::Push(int32_t value) {
    Node* temp = new Node(value, nullptr);
    if (size_ == 0) {
        front_ = temp;
    } else {
        tail_->next = temp;
    }
    tail_ = temp;
    ++size_;
}

Queue::~Queue() {
    Clear();
}