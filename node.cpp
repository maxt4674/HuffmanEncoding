#include "node.h"

node::node(float prob) : probability(prob) {}

node::node(float prob, char charIncoming) : probability(prob), charIn(charIncoming) {}

void node::assignChildren(std::shared_ptr<node> newLeft, std::shared_ptr<node> newRight) {
    left = newLeft;
    right = newRight;
    if (newLeft) newLeft->parent = shared_from_this();
    if (newRight) newRight->parent = shared_from_this();
}

void node::assignParent(std::shared_ptr<node> newParent) {
    parent = newParent;
}

bool node::operator<(const node& other) const {
    return probability < other.probability;
}