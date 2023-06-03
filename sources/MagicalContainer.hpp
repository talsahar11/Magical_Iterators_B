//
// Created by ts on 5/28/23.
//
#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H
#include <list>
#include <limits>
#include <stdexcept>
#include <iostream>

using namespace std ;
namespace ariel {
    class MagicalContainer {
    private:

        list<int> elementsList ;

        list<int*> primesList ;

    public:
        MagicalContainer() ;

        void addElement(int element);

        void removeElement(int element);

        int size();

        list<int> getList(){
            return elementsList ;
        }

        list<int*> getPrimesList(){
            return primesList ;
        }

        class AscendingIterator {
        private:
            list<int>* elementsList;
            list<int>::iterator iter ;
            int location ;

            AscendingIterator(list<int>* elementsList, list<int>::iterator iter, int location) ;

        public:
            AscendingIterator(MagicalContainer& container) ;

            AscendingIterator(const AscendingIterator& other) ;

            AscendingIterator(AscendingIterator&& other) noexcept = default;

            AscendingIterator& operator=(AscendingIterator&& other) noexcept = default;

            ~AscendingIterator() ;

            AscendingIterator begin() const ;

            AscendingIterator end() const ;

            AscendingIterator& operator=(const AscendingIterator& other) ;

            bool operator==(const AscendingIterator& iter) const ;

            bool operator!=(const AscendingIterator& iter) const ;

            bool operator<(const AscendingIterator& iter) const ;

            bool operator>(const AscendingIterator& iter) const ;

            AscendingIterator& operator++() ;

            int operator*() ;
        };

        class PrimeIterator {
        private:
            list<int*> *primesList;
            list<int*>::iterator iter;
            int location ;

            PrimeIterator(list<int*>* primesList, list<int*>::iterator iter, int location);

        public:
            PrimeIterator(MagicalContainer& container);

            PrimeIterator(const PrimeIterator& other) ;

            PrimeIterator(PrimeIterator&& other) noexcept = default;

            PrimeIterator& operator=(PrimeIterator&& other) noexcept = default;

            ~PrimeIterator() ;

            PrimeIterator begin() const;

            PrimeIterator end() const;

            PrimeIterator& operator=(const PrimeIterator& other) ;

            bool operator==(const PrimeIterator& iter) const;

            bool operator!=(const PrimeIterator& iter) const;

            bool operator<(const PrimeIterator& iter) const ;

            bool operator>(const PrimeIterator& iter) const ;

            PrimeIterator &operator++();

            int operator*();
        };

        class SideCrossIterator {
            list<int> *elementsList;
            list<int>::iterator startIter, endIter;
            bool isForward ;
            int location ;

            SideCrossIterator(list<int>* elementsList, list<int>::iterator startIter, list<int>::iterator endIter, int location);

        public:
            SideCrossIterator(MagicalContainer& container);

            SideCrossIterator(const SideCrossIterator& other) ;

            SideCrossIterator(SideCrossIterator&& other) noexcept = default;

            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept = default;

            ~SideCrossIterator() ;

            SideCrossIterator begin() const;

            SideCrossIterator end() const;

            SideCrossIterator& operator=(const SideCrossIterator& other) ;

            bool operator==(const SideCrossIterator& iter) const;

            bool operator!=(const SideCrossIterator& iter) const;

            bool operator<(const SideCrossIterator& iter) const ;

            bool operator>(const SideCrossIterator& iter) const ;

            SideCrossIterator &operator++();

            int operator*();
        };
    };
}
#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
