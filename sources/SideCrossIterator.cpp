#include "MagicalContainer.hpp"
using namespace ariel ;

///-----Public Ctor by a reference to a container -----
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
        : elementsList(&container.elementsList),
          startIter((&container.elementsList)->begin()),
          endIter(--(&container.elementsList)->end()),
          isForward(true)
          ,location(0){}


///-----Private Ctor by an attributes of a container -----
MagicalContainer::SideCrossIterator::SideCrossIterator(list<int>* elementsList, list<int>::iterator startIter, list<int>::iterator endIter, int location)
        : elementsList(elementsList),
          startIter(startIter),
          endIter(endIter),
          isForward(true),
          location(location)    {}

///-----Copy Ctor -----
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) {
    this->elementsList = other.elementsList;
    this->startIter = other.startIter ;
    this->endIter = other.endIter ;
    this->location = other.location ;
    this->isForward = other.isForward ;
}

///-----Default Dtor-----
MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

///-----Returns a new iterator instance pointing to the lowest element in the container-----
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
    list<int>::iterator lastElement = --elementsList->end();
    return SideCrossIterator(elementsList, elementsList->begin(), lastElement, 0);
}

///-----Returns a new iterator instance pointing to the end iterator of the inner list----
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
    return SideCrossIterator(elementsList, elementsList->end(), elementsList->end(), numeric_limits<int>::max()) ;
}

///-----Assigment operator overloading, in case that different containers holds the assigned iterators, exception -----
///-----will be thrown.                                                                                           -----
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

///-----Equality operator overloading - using the inequality operator overloading to evaluate the bool return value-----
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
    if(*this != other){
        return false ;
    }
    return true ;
}

///-----Inequality operator overloading - tests if the both iterators holds the same attributes and pointing to the-----
///-----same element.                                                                                              -----
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
    if(elementsList != other.elementsList || startIter != other.startIter || endIter != other.endIter){
        return true ;
    }
    return false ;
}

///-----LT operator overloading - using the GT operator to evaluate which of the iterators is "bigger" -----
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return location < other.location ;
}

///-----GT operator overloading - determine by the iterators "location" which iterator is more advanced -----
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return other.location < location ;
}

///-----Pre-increment operator overloading - set the iterator to point to the next value in side cross order by -----
///isForward variable. if  the iterator points to end(), runtime exception will be thrown.                      -----
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

///-----Returns the element that the iterator points to -----
int MagicalContainer::SideCrossIterator::operator*(){return (isForward) ? *startIter : *endIter ;}