#include "MagicalContainer.hpp"
using namespace ariel ;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        :primesList(&container.primesList),
        iter((&container.primesList)->begin()),
        location(0)   {}

MagicalContainer::PrimeIterator::PrimeIterator(list<int*>* primesList, list<int*>::iterator iter, int location = 0)
        :primesList(primesList),
        iter(iter),
        location(location)  {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) {
    this->primesList = other.primesList ;
    this->location = other.location ;
    this->iter = other.iter ;
}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator(primesList, primesList->begin(), 0) ;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
    return PrimeIterator(primesList, primesList->end(), numeric_limits<int>::max()) ;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if(primesList != other.primesList){
        throw runtime_error("Cannot use = operator on iterators from different containers.") ;
    }
    this->primesList = other.primesList ;
    this->location = other.location ;
    this->iter = other.iter ;
    return *this ;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
    if(*this != other){
        return false ;
    }
    return true ;
}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
    if(primesList != other.primesList || iter != other.iter){
        return true ;
    }
    return false ;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return location < other.location ;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return other.location < location ;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if(*this == end()){
        throw runtime_error("Cannot increase iterator beyond end.") ;
    }
    iter++ ;
    location++ ;
    return *this;
}
int MagicalContainer::PrimeIterator::operator*(){return **iter ;}