#include "MagicalContainer.hpp"
#include <cmath>

using namespace ariel;
using namespace std;

///-----Check whether a given number is prime or not-----
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

///-----Empty ctor-----
MagicalContainer::MagicalContainer(){}

///-----Add element into the container by adding the element to the elements list in ascending order, in case the -----
///-----element is prime, we also add a pointer to the element into the primes list                               -----
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

///-----Remove an element from the container by removing it from the elements list. In case the element is prime,  -----
///-----remove it`s pointer also from the primes list. In case the element does not exists, throw runtime exception-----
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

///-----Return the amount of element in the container -----
int MagicalContainer::size() {
    return elementsList.size() ;
}
