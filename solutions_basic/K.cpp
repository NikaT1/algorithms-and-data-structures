#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct my_region {
    bool is_free;
    int start_ind;
    int end_ind;
    int length;
    struct my_region* left;
    struct my_region* right;
    int calc_length(){
        this->length = end_ind - start_ind + 1;
    }
    
    my_region(int start, int end) {
        start_ind = start;
        end_ind = end;
        length = end_ind - start_ind + 1;
        is_free = 1;
        left = 0;
        right = 0;
    }
};

auto compare = [](const struct my_region* a, const struct my_region* b) { return a->length > b->length; };
multiset<struct my_region*, decltype(compare)> my_set(compare);

int parse_operation(string operation) {
    return stoi(operation);
}

struct my_region* connect_region_with_next(struct my_region* region, struct my_region* next){
    region->right = next->right;
    if (next->right) next->right->left = region;
    region->end_ind = next->end_ind;
    region->calc_length();
    return region;
}

struct my_region* connect_region_with_prev(struct my_region* prev, struct my_region* region){
    region->left = prev->left;
    if (prev->left) prev->left->right = region;
    region->start_ind = prev->start_ind;
    region->calc_length();
    return region;
}

int main() {
  int n, m;
  cin >> n >> m;
  string operation_order[m];
  struct my_region* not_free_blocks[m];
  
  for (int i = 0; i < m; i++) {
    cin >> operation_order[i];
  }
  
  struct my_region* root = new my_region(0, n - 1);
  my_set.insert(root);
  
  for (int i = 0; i < m; i++) {
    int operation = parse_operation(operation_order[i]);
    if (operation > 0) {
        //выделение памяти
        struct my_region* free_region = *my_set.begin();
        while (free_region) {
            if (free_region->is_free) break;
            my_set.erase(my_set.begin());
            free_region = *my_set.begin();
        }
        if (!free_region || !free_region->is_free || free_region->length < operation) {
            cout << "-1" << endl; 
            not_free_blocks[i] = 0;
        } else {
            my_set.erase(my_set.begin());
            cout << free_region->start_ind + 1 << endl;
            int new_addr = free_region->start_ind + operation - 1;
            if (operation != free_region->length) {
                struct my_region* new_region = new my_region(new_addr + 1, free_region->end_ind);
                new_region->right = free_region->right;
                new_region->left = free_region;
                my_set.insert(new_region);
                free_region->right = new_region;
            }
            free_region->is_free = 0;
            free_region->end_ind = new_addr;
            free_region->calc_length();
            not_free_blocks[i] = free_region;
        }
    } else {
        //освобождение памяти
        operation = -operation - 1;
        struct my_region* old_region = not_free_blocks[operation];
        if (old_region) {
            old_region->is_free = 1;
            if (old_region->left && old_region->left->is_free) {
                old_region->left->is_free = 0;
                old_region = connect_region_with_prev(old_region->left, old_region);
                
            }
            if (old_region->right && old_region->right->is_free) {
                old_region->right->is_free = 0;
                old_region = connect_region_with_next(old_region, old_region->right);
            }
            my_set.insert(old_region);
        }
    }
  }
  return 0; 
}
