#include <string>
#include <iostream>
#include <vector> 
#include <list>
#include <ctype.h>

using namespace std;

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
