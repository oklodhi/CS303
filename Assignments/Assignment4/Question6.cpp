#include <string>
#include <iostream>
#include <vector> 
#include <list>
#include <ctype.h>

using namespace std;

// There is a difference in performance between vector and list (linked list). 
// It is faster to find an element in vector
// Faster to push elements into the vector rather than list
// But deletion is faster in list with larger data because all elements need to be shifted in a vector
//


// Can't modify the vector insertion sort code because with a list, traverse the whole list once, and as youre traversing,
// you would sort again as youre traversing.
// So essentially, list is far slower in insertion sort performance

int insertion_sort(list<int> &num){
    int i, j, key;
    
    bool insertionNeeded = false; 
    
    for (j  = 1; j < num.size(); j++){
        key = num[j]; 
        insertionNeeded = false; 
        
        for (i = j - 1; i >= 0; i--){
            if (key < num[i]){
                num[i+1] = num[i];
                insertionNeeded = true;
            } else {
                break; 
            }
        }
        if (insertionNeeded){
            num[i + 1] = key; 
        }
    }
}

int main(){
    list l = {7, 5, 16, 8};
    
    insertion_sort(l);
}
