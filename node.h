#ifndef NODE
#define NODE

#include <memory>

class node : public std::enable_shared_from_this<node> {
public:
    char charIn{};
    float probability;

    std::shared_ptr<node> left = nullptr;
    std::shared_ptr<node> right = nullptr;
    std::weak_ptr<node> parent;

    node(float prob);
    node(float prob, char charIncoming);
    
    void assignChildren(std::shared_ptr<node> newLeft, std::shared_ptr<node> newRight);
    void assignParent(std::shared_ptr<node> newParent);

    bool operator<(const node& other) const;
};

#endif