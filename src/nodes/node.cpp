#include "node.hpp"

namespace rre  {
    

void Node::_ready()
{

}

void Node::_process(float delta) {

}

void Node::_input() {

}

void Node::_unhandled_input(InputEvent event) {

}

void Node::_draw() {
    
}

void Node::add_child(Node *node)
{
    if (node->parent != nullptr) {
        std::string  errorMessage = "\033[1;31m Node: " + node->name + " already has parent: " + node->parent->name;
        std::cerr << errorMessage + "\n\n\033[0m";

        throw std::runtime_error("already has parent!");
    }
    node->parent = this;
    children.push_back(node);
}

Node::Node() {
    this->name = "Node";
    parent = nullptr;
    children = std::vector<Node*>();
    // std::cout << "Created node: " + name + "\n";
    
}

Node::Node(const std::string& name) {
    this->name = name;
    parent = nullptr;
    children = std::vector<Node*>();
}

Node::~Node() {

}

uint32_t Node::get_child_count() {
    return children.size();
}

Node* Node::get_child(int p_index) {
    if (get_child_count() < 1) return nullptr;
    if ((size_t)p_index >= children.size()) return nullptr;
    return children[p_index];
}

Node* Node::get_tree() {
    return nullptr;
}

std::vector<Node*> Node::get_children() {
    return children;
}

Node* Node::get_parent() {
    if (parent == nullptr) return nullptr;
    return parent;
}

void Node::set_name(std::string name) {
   this->name = name;
}

 std::string Node::get_name() const {
    return name;
}


}