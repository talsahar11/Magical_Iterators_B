#include "MagicalContainer.hpp"
#include <iostream>
#include <cmath>

using namespace ariel;
using namespace std;
bool isPrime(int num){
    if(num <= 1){
        return false ;
    }else if(num <= 3){
        return true ;
    }else{
        for(int i = 2 ; i <= sqrt(num) ; i++){
            if(num % i == 0) {
                return false ;
            }
        }
        return true ;
    }
}

MagicalContainer::MagicalContainer(){
}
void MagicalContainer::addElement(int element) {
    bool isNumPrime = isPrime(element) ;
    auto primesIt = primesList.begin() ;
    for(auto it = elementsList.begin() ; it != elementsList.end() ; it++){
        if(*it > element){
            elementsList.insert(it, element) ;
            if(isNumPrime){
                primesList.insert(primesIt, &(*(--it))) ;
            }
            return ;
        }
        if(primesIt != primesList.end()) {
            if (**primesIt == *it) {
                primesIt++;
            }
        }
    }
    elementsList.push_back(element) ;
    if(isNumPrime){
        primesList.push_back(&elementsList.back()) ;
    }
}

void MagicalContainer::removeElement(int element) {
    auto primesIt = primesList.begin() ;
    for(auto it = elementsList.begin() ; it != elementsList.end() ; it++){
        if(*it == element){
            if(isPrime(element)){
                primesList.erase(primesIt) ;
            }
            elementsList.erase(it) ;
            return ;
        }
        if(*primesIt != nullptr){
            if(*it == **primesIt){
                primesIt++ ;
            }
        }
    }
    throw runtime_error("Failed removing element - element do not exists.") ;
}

int MagicalContainer::size() {
    return elementsList.size() ;
}
