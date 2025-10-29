#include "Hash.h"

using namespace std;

// implemented for you - don't change this one
unsigned int djb2(string key) {
    unsigned int hash = 5381;
    for (size_t i = 0; i < key.length(); i++) {
    char c = key[i];
    hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// implemented for you - don't change this one
unsigned int mod_bucket_func(unsigned int hashcode, unsigned int cap) {
    unsigned int b = hashcode % cap;
    return b;
}

// init hash table
hash_table* init_hash_table(unsigned int cap) {
    // TODO
    hash_table* ret(new hash_table);

    ret->capacity = cap;
    ret->size = 0;
    ret->occupied = 0;
    ret->table = new htable(cap);
    ret->hash_func = djb2;
    ret->bucket_func = mod_bucket_func;
    
    return ret;
}

// init hash node
hash_node* init_hash_node(string key, unsigned int hashcode, string val) {
    // TODO
    hash_node* ret(new hash_node);
    
    ret->deleted = false;
    ret->key = key;
    ret->hashcode = hashcode;
    ret->value = val;
    
    return ret;
}

bool set_kvp(hash_table* tbl, string key, string value) {
    // TODO

    // get the key's hash code
    int hash_code = djb2(key);

    // first search for the key in the table. If found, update the bucket's value
    bool found_empty_since_start = false;
    for (unsigned int i = 0; found_empty_since_start == false && i < tbl->capacity; i++) {
        int bucket_index = (hash_code + i) % tbl->capacity;
        hash_node* current_node = (*tbl->table)[bucket_index];

        // An empty-since-start bucket implies the key is not in the table
        if (current_node == nullptr) {
            found_empty_since_start = true;
        } else if (current_node->key == key) {
            current_node->value = value;
            return true;
        }
        
    }

    // the key is not in the table so insert into 1st empty bucket
    for (unsigned int i = 0; i < tbl->capacity; i++) {
        int bucket_index = (hash_code + i) % tbl->capacity;
        hash_node* current_node = (*tbl->table)[bucket_index];

        if (current_node == nullptr || current_node->deleted == true) {
            hash_node* new_node(new hash_node);
            new_node->key = key;
            new_node->value = value;
            (*tbl->table)[bucket_index] = new_node;
            
            tbl->occupied = tbl->occupied + 1;
            tbl->size = tbl->size + 1;
            
            return true;
        }
    }
    
    return false;
}

// return how full the table is using occupied / capacity
float hash_table_load(hash_table* tbl) {
    // TODO
    return (float)tbl->size / tbl->capacity;
}

string get_value(hash_table* tbl, string key) {
    // TODO
    
    // hashes the key applies mudolo with table's length / capacity to get key 
    int array_index = djb2(key) % tbl->capacity;
    // looks up node in table
    hash_node* node = (*tbl->table)[array_index];
    if (node == nullptr) {
        return "";
    } else if (node->deleted == true) {
        return "";
    } else if (node->key == key && node->deleted == false) {
        return node->value;
    } else {
        return "";
    }
}

bool contains(hash_table* tbl, string key) {
    // TODO
    
    // get the key's hash code
    int hash_code = djb2(key);
    
    // looks for not deleted and key match to return true
    for (unsigned int i = 0; i < tbl->capacity; i++) {
        int bucket_index = (hash_code + i) % tbl->capacity;
        hash_node* current_node = (*tbl->table)[bucket_index];

        // nullptr condition handles empty since start 
        if (current_node == nullptr) {
            continue;
        } else if (current_node->deleted == false && current_node->key == key) {
            return true;
        }
    }
    return false;
}

bool remove(hash_table* tbl, string key) {
    // TODO
    
    // get the key's hash code
    int hash_code = djb2(key);
    
    // 
    for (unsigned int i = 0; i < tbl->capacity; i++) {
        int bucket_index = (hash_code + i) % tbl->capacity;
        hash_node* current_node = (*tbl->table)[bucket_index];

        // nullptr condition handles empty since start 
        if (current_node == nullptr) {
            continue;
        } else if (current_node->key == key) {
            current_node->deleted = true;
            tbl->size = tbl->size -1 ;
            
            return true;
        }
    }
    return false;
}

void resize(hash_table* tbl, unsigned int new_capacity) {
    // TODO
    // creates new htable with new cap and temp table of the original
    htable* new_htable = new htable(new_capacity);

        // print_hash_table(tbl);
    
    htable* temp_htable = tbl->table;
    unsigned int old_capacity = tbl->capacity + 1;

    // updates underlying table
    tbl->capacity = new_capacity; 
    tbl->table = new_htable;

    // loops through old array and assigns new nodes based on new calculated index
    for (unsigned int i = 0; i < old_capacity; i++) {
        hash_node* current_node = (*temp_htable)[i];
        if (current_node == nullptr) {
            continue;
        } else if (current_node->deleted == false) {
            int hash_code = djb2(current_node->key);
            int bucket_index = (hash_code + i) % new_capacity;

            hash_node* new_node(new hash_node);
            new_node->key = current_node->key;
            new_node->value = current_node->value;
            new_node->hashcode = hash_code;
            (*tbl->table)[bucket_index] = new_node;
      
        }
    }
        // print_hash_table(tbl);

}

// implemented for you - feel free to change this one if you like
void print_hash_table(hash_table* tbl) {
  cout << "Hashtable:" << endl;
  cout << "  capacity: " << tbl->capacity << endl;
  cout << "  size:     " << tbl->size << endl;
  cout << "  occupied: " << tbl->occupied << endl;
  cout << "  load:     " << hash_table_load(tbl) << endl;
  if (tbl->capacity < 130) {
    for (unsigned int i = 0; i < tbl->capacity; i++) {
      cout << "[" << i << "]    ";
      if (!tbl->table->at(i)) {
        cout << "<empty>" << endl;
      } else if (tbl->table->at(i)->deleted) {
        cout << "<deleted>" << endl;
      } else {
        cout << "\"" << tbl->table->at(i)->key << "\" = \""
             << tbl->table->at(i)->value << "\"" << endl;
      }
    }
  } else {
    cout << "    <hashtable too big to print out>" << endl;
  }
}
