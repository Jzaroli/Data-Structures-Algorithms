/* Note: refer to the header file (BST.h) for documentation of each method. */

#include "BST.h"

BST::BST() {
  // Here is one way to implement the constructor. Keep or change it, up to you.
  root = new bst_node*;
  *root = NULL;
}

BST::~BST() {}

bst_node* BST::init_node(int data) { 
  bst_node* ret(new bst_node);
  ret->data = data;
  return ret;
}

 // insert places the new_node in a proper location in the tree while obeying
  // the invariant. On return, root points to the root of the tree.
void BST::insert(bst_node* new_node) {
  // Your code here
  bst_node* check_root = get_root();

  if (check_root == NULL) {
    *root = new_node;
    return;
  } else {
    bst_node* current_node = get_root();
    while (current_node != NULL) {
      if (new_node->data < current_node->data) {
        if (current_node->left == NULL) {
          current_node->left = new_node;
          break;       
        } else {
          current_node = current_node->left;
        }
      } else {
        if (current_node->right == NULL) {
          current_node->right = new_node;
          break;
        } else {
          current_node = current_node->right;
        }
      }
    }
  }
}

void BST::insert_data(int data) {
  // Your code here
  bst_node* new_node = init_node(data);
  insert(new_node);
}

void BST::remove(int data) {
  int local_data = data;
  // Your code here
  bst_node* parent = nullptr;
  bst_node* current_node = get_root();

  while (current_node != nullptr) {
    if (current_node->data == local_data) {
      if (current_node->left == nullptr && current_node->right == nullptr) {
        if (parent == nullptr) {
          *root = nullptr;
        } else if (parent->left == current_node){
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
        delete current_node;
        break;
      } else if (current_node->right == nullptr) {
        if (parent == nullptr) {
          *root = current_node->left;
        } else if (parent->left == current_node){
          parent->left = current_node->left;        
        } else {
          parent->right = current_node->left;
        }
        delete current_node;
        break;
      } else if (current_node->left == nullptr) {
        if (parent == nullptr) {
          *root = current_node->right;
        } else if (parent->left == current_node) {
          parent->left = current_node->right;
        } else {
          parent->left = current_node->right;
        }
        delete current_node;
        break;
      } else {
        bst_node* successor = current_node->right;
        while (successor->left != nullptr) {
          successor = successor->left;
        }

        // Copy successor's key to current_node
        current_node->data = successor->data;
        parent = current_node;

        // Reassign current_node and key so that loop continues with new key
        current_node = current_node->right;
        local_data = successor->data;
      }
    } else if (current_node->data < local_data) {
      // search right
      parent = current_node;
      current_node = current_node->right;
    } else {
      // search left
      parent = current_node;
      current_node = current_node->left;
    }
  }
}


bool BST::contains(bst_node* subt, int data) {
  // Your code here
  bool result = get_node(subt, data);

  if (result) {
    return true;
  };

  return false;
}

bst_node* BST::get_node(bst_node* subt, int data) {
  // Your code here
  if (subt == NULL) {
    return NULL;
  };

  // pre-order traversal method
  if (data == subt->data) {
    return subt;
  } else if (data < subt->data) {
    return get_node(subt->left, data);
  } else {
    return get_node(subt->right, data);
  };

  return NULL;
}

int BST::size(bst_node* subt) {
  // Your code here
  if (subt == NULL) {
    return 0;
  }
  return 1 + size(subt->left) + size(subt->right);
}

void BST::to_vector(bst_node* subt, vector<int>& vec) {
  // Your code here
  if (subt == NULL) {
    return;
  };
  
  to_vector(subt->left, vec);
  vec.push_back(subt->data);
  to_vector(subt->right, vec);
}

bst_node* BST::get_root() {
  // This function is implemented for you
  if (*root == NULL)
    return NULL;
  return *root;
}

void BST::set_root(bst_node** new_root) {
  // This function is implemented for you
  root = new_root;
}
