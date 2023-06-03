#include "MagicalContainer.hpp"
using namespace ariel ;
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        :elementsList(&container.elementsList),
        iter((&container.elementsList)->begin()),
        location(0) {
}

MagicalContainer::AscendingIterator::AscendingIterator(list<int>* elementsList, list<int>::iterator iter, int location)
        :elementsList(elementsList),
        iter(iter),
        location(location){}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) {
    this->elementsList = other.elementsList ;
    this->location = other.location ;
    this->iter = other.iter ;
}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
    return AscendingIterator(elementsList, elementsList->begin(), 0) ;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
    return AscendingIterator(elementsList, elementsList->end(), numeric_limits<int>::max()) ;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if(elementsList != other.elementsList){
        throw runtime_error("Cannot use = operator on iterators from different containers.") ;
    }
    this->elementsList = other.elementsList ;
    this->location = other.location ;
    this->iter = other.iter ;
    return *this ;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
    if(*this != other){
        return false ;
    }
    return true ;
}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    if(elementsList != other.elementsList || iter != other.iter){
        return true ;
    }
    return false ;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if(*this == end()){
        throw runtime_error("Cannot increase iterator beyond end.") ;
    }
    iter++ ;
    location++ ;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return location < other.location ;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return other.location < location ;
}
int MagicalContainer::AscendingIterator::operator*(){return *iter ;}