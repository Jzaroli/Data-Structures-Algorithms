#include "Node.h"

Node::Node(string s) {
  // DONE FOR YOU
  data = s;
}

Node::~Node() {
    // "DONE" FOR YOU
    //
    // This is equivalent to the default destructor the compiler will
    // generate for you. As a rule of thumb, you only need to `delete`
    // member variables that were created with `new` inside this
    // class. So, you don't need to do anything here. It could have been
    // left out of the header/impl file entirely.
}

string Node::getData() {
    // DONE FOR YOU
    return data;
}

void Node::setRank(int r) {
    // DONE FOR YOU
    rank = r;
}

void Node::clear() {
    // TODO
    color = 1;
    discovery_time = -1;
    completion_time = -1;
    rank = -1;
    predecessor = NULL;
}

void Node::setColor(int search_color, int time) {
    // TODO
    if (search_color == 1) {
        color = search_color;
        discovery_time = -1;
        completion_time = -1;
    }

    if (search_color == 2) {
        color = search_color;
        discovery_time = time;
    }

    if (search_color == 3) {
        color = search_color;
        completion_time = time;
    }
}

void Node::getDiscoveryInformation(int& thecolor, int& disco_time,
                                   int& finish_time, int& bfs_rank) {
    // TODO
    thecolor = color;
    disco_time = discovery_time;
    finish_time = completion_time;
    bfs_rank = rank;
}

bool Node::isAncestor(Node* other) {
    // TODO
    Node* current_node = this;
    while (current_node->predecessor != NULL) {
        if (current_node->predecessor == other) {
            return true;
        }
        current_node = current_node->predecessor;
    }
    return false;
}

void Node::setPredecessor(Node* other) {
    // TODO
    this->predecessor = other;
}

// overloading operator << lets you put a Node object into an output
// stream.
ostream& operator<<(std::ostream& out, Node node) {
  // DONE FOR YOU
  out << node.data;
  return out;
}
