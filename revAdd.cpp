#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define MAX_ITER 1000
#define MAX_PALIN 4294967295

int reverseNum(int &fwd);
void rev_and_add(int &test);

int main() {

    int cases;
    std::cout << "Enter the number of test cases, press enter, then enter cases line by line:\n";
    std::cin >> cases;

    std::vector<int> testers;

    int n;
    for(size_t i = 0; i < cases; i++) {
        std::cin >> n;
        testers.push_back(n);
    }
    

    
}