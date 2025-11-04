#include "Huffman.h"

freq_info* huff_create_leaf(char symbol, int count) {
    // TODO
    freq_info* ret(new freq_info);
    ret->symbol = symbol;
    ret->count = count;
    ret->left = nullptr;
    ret->right = nullptr;
    ret->is_leaf = true;
    
    return ret;
}

freq_info* huff_combine_nodes(freq_info* left, freq_info* right) {
    // TODO
    freq_info* ret(new freq_info);
    ret->count = left->count + right->count;
    ret->left = left;
    ret->right = right;
    ret->is_leaf = false;
    
    return ret;
}

void huff_incr_lookup(map<char, int>& lookup, char symbol) {
    // TODO
    if (lookup[symbol]) {
        lookup[symbol] = lookup[symbol] + 1;
    } else {
        lookup[symbol] = 1;
    }
}

void huff_load_queue(const map<char, int>& lookup, tree_queue& q) {
    // TODO
    for (const auto& pair : lookup) {
        freq_info* node = huff_create_leaf(pair.first, pair.second);
        q.push(node);
    }
}

freq_info* huff_build_tree(tree_queue& q) {
    // TODO
    freq_info* root_node;
    
    while (q.size() > 1) {
        
        freq_info* first_node = q.top();
        q.pop();
        freq_info* second_node = q.top();
        q.pop();
        freq_info* combined_node = huff_combine_nodes(first_node, second_node);
        q.push(combined_node);
        
        root_node = combined_node; // updates root on each iteration
    }
    
    return root_node;
}

// huff_build_enc_table creates a lookup table for the encoding
// process. it maps each symbol in the Huffman codec tree to a string
// composed of LEFT_STR and RIGHT_STR.
//
// root is the root node of a Huffman codec tree.
map<char, string> huff_build_enc_table(freq_info* root) {
    // TODO
    map<char, string> table;
    
    tree_traversal(table, root, "");
        
    return table;
}

void tree_traversal(map<char, string>& table, freq_info* node, string value) {
    
    if (node->is_leaf == true) {
        table[node->symbol] = value;
        return;
    }

    if (node->left) {
        tree_traversal(table, node->left, value + LEFT_STR);
    }

    if (node->right) {
        tree_traversal(table, node->right, value + RIGHT_STR);
    }
}

string huff_encode(map<char, string> enc_table, string input) {
    // TODO
    string return_value = "";
    
    for (char c : input) {
        for (auto it = enc_table.cbegin(); it != enc_table.cend(); ++it) {
            char k = (*it).first;
            if (c == k) {
                return_value = return_value + (*it).second;
            }
        }
    }
    
    return return_value;
}

string huff_decode(freq_info* root, string input) {
    // TODO
    string return_value = "";
    freq_info* current_node = root;

    for (char c : input) {
        if (c == '.') {
            current_node = current_node->left;
        } else if (c == '^') {
            current_node = current_node->right;
        } 
        
        if (current_node->is_leaf == true) {
            return_value = return_value + current_node->symbol;
            current_node = root;
        }
    }
    
    return return_value;
}