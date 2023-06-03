#include "MagicalContainer.hpp"
using namespace ariel ;
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : elementsList(&container.elementsList),
          startIter((&container.elementsList)->begin()),
          endIter(--(&container.elementsList)->end()),
          isForward(true)
          ,location(0){}

MagicalContainer::SideCrossIterator::SideCrossIterator(list<int>* elementsList, list<int>::iterator startIter, list<int>::iterator endIter, int location)
        : elementsList(elementsList),
          startIter(startIter),
          endIter(endIter),
          isForward(true),
          location(location)    {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) {
    this->elementsList = other.elementsList;
    this->startIter = other.startIter ;
    this->endIter = other.endIter ;
    this->location = other.location ;
    this->isForward = other.isForward ;
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
    list<int>::iterator lastElement = --elementsList->end();
    return SideCrossIterator(elementsList, elementsList->begin(), lastElement, 0);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator(elementsList, elementsList->end(), elementsList->end(), numeric_limits<int>::max()) ;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if(elementsList != other.elementsList){
        throw runtime_error("Cannot use = operator on iterators from different containers.") ;
    }
    this->elementsList = other.elementsList ;
    this->location = other.location ;
    this->startIter = other.startIter ;
    this->endIter = other.endIter ;
    this->isForward = other.isForward ;
    return *this ;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
    if(*this != other){
        return false ;
    }
    return true ;
}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
    if(elementsList != other.elementsList || startIter != other.startIter || endIter != other.endIter){
        return true ;
    }
    return false ;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return location < other.location ;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return other.location < location ;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if(*this == end()){
        throw runtime_error("Cannot increase iterator beyond end.") ;
    }
    if(startIter == endIter){
        startIter = elementsList->end() ;
        endIter = elementsList->end() ;
    }else {
        (isForward) ? startIter++ : endIter--;
        isForward = !isForward;
    }
    location++ ;
    return *this;
}
int MagicalContainer::SideCrossIterator::operator*(){return (isForward) ? *startIter : *endIter ;}