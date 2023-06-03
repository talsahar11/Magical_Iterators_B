#include "MagicalContainer.hpp"
using namespace ariel ;

///-----Public Ctor by a reference to a container -----
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        :elementsList(&container.elementsList),
        iter((&container.elementsList)->begin()),
        location(0) {
}

///-----Private Ctor by an attributes of a container -----
MagicalContainer::AscendingIterator::AscendingIterator(list<int>* elementsList, list<int>::iterator iter, int location)
        :elementsList(elementsList),
        iter(iter),
        location(location){}

///-----Copy Ctor -----
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) {
    this->elementsList = other.elementsList ;
    this->location = other.location ;
    this->iter = other.iter ;
}

///-----Default Dtor-----
MagicalContainer::AscendingIterator::~AscendingIterator() {}

///-----Returns a new iterator instance pointing to the lowest element in the container-----
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
    return AscendingIterator(elementsList, elementsList->begin(), 0) ;
}

///-----Returns a new iterator instance pointing to the end iterator of the inner list-----
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
    return AscendingIterator(elementsList, elementsList->end(), numeric_limits<int>::max()) ;
}

///-----Assigment operator overloading, in case that different containers holds the assigned iterators, exception -----
///-----will be thrown.                                                                                           -----
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if(elementsList != other.elementsList){
        throw runtime_error("Cannot use = operator on iterators from different containers.") ;
    }
    this->elementsList = other.elementsList ;
    this->location = other.location ;
    this->iter = other.iter ;
    return *this ;
}

///-----Equality operator overloading - using the inequality operator overloading to evaluate the bool return value-----
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
    if(*this != other){
        return false ;
    }
    return true ;
}

///-----Inequality operator overloading - tests if the both iterators holds the same attributes and pointing to the-----
///-----same element.                                                                                              -----
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
    if(elementsList != other.elementsList || iter != other.iter){
        return true ;
    }
    return false ;
}

///-----LT operator overloading - using the GT operator to evaluate which of the iterators is "bigger" -----
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return location < other.location ;
}

///-----GT operator overloading - determine by the iterators "location" which iterator is more advanced -----
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return other.location < location ;
}

///-----Pre-increment operator overloading - set the iterator to point to the next value in ascending order. if -----
///-----the iterator points to end(), runtime exception will be thrown.                                         -----
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if(*this == end()){
        throw runtime_error("Cannot increase iterator beyond end.") ;
    }
    iter++ ;
    location++ ;
    return *this;
}

///-----Returns the element that the iterator points to -----
int MagicalContainer::AscendingIterator::operator*(){return *iter ;}