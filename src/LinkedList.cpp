#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}
LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) { Node* n = p->next; delete p; p = n; }
}
void LinkedList::push_front(int v) { head_ = new Node(v, head_); }
void LinkedList::remove_evens() {
    while(head_->value%2==0) {
        Node* n = head_->next;
        delete head_; head_ = n;
    }
Node* v = head_;
    while (v->next) {
        if (v->next->value % 2== 0) {
            Node* n = v->next->next;
            delete v->next;
            v->next = n;
        } else {v = v->next;}
        }  
}
std::string LinkedList::to_string() const {
    std::ostringstream oss;
    oss << "[";
    Node* p = head_;
    bool first = true;
    while (p) {
        if (!first) oss << ", ";
        first = false;
        oss << p->value;
        p = p->next;
    }
    oss << "]";
    return oss.str();
}
