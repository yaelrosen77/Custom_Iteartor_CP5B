#pragma once
#include <iostream>
#include <vector>                    //best for keeping track only of the next element
#include <cmath>
using namespace std;
#include "MysticalElements.hpp"
using namespace ariel;

namespace ariel{

    class MagicalContainer{
        vector<MysticalElement*> iteratia;
        MysticalPrimeElement* prim;
        int numofprimes;
        void insertPrime(MysticalPrimeElement* thing);
        void insert(MysticalElement* thing);
        int contsize;

    public:
        MagicalContainer() : contsize(0), prim(nullptr), numofprimes(0){}
        ~MagicalContainer(){}
        MagicalContainer(MagicalContainer&& other) = default;
        MagicalContainer(MagicalContainer& other);
        void addElement(int abb);
        void removeElement(int bbb){}
        int size() const{return contsize;}
        MagicalContainer& operator=(MagicalContainer&& other) noexcept;
        MagicalContainer& operator=(const MagicalContainer &other){return *this;}
        vector<MysticalElement*> getIteratia(){return iteratia;} //remove this
        MysticalPrimeElement* getprim(){return prim;}


        class AscendingIterator{
            MagicalContainer& conti;
            unsigned int current;

        public:
            AscendingIterator(MagicalContainer& cont);
            AscendingIterator(const AscendingIterator &other):
                    conti(other.conti),current(other.current){}
            AscendingIterator(AscendingIterator&& other) = default;
            AscendingIterator& operator=(AscendingIterator&& other) = delete;
            ~AscendingIterator() = default;
            AscendingIterator& operator=(const AscendingIterator& other) = delete;
            bool operator ==(const AscendingIterator& other) const;
            bool operator != (const AscendingIterator& other) const;
            bool operator >(const AscendingIterator& other) const;
            bool operator <(const AscendingIterator& other) const;
            const int operator*() const;
            AscendingIterator& operator++(){current++; return *this;}
            AscendingIterator begin(){return AscendingIterator(conti);}
            AscendingIterator end();
        };
         class SideCrossIterator{
             MagicalContainer& conti;
             MysticalElement* next;
             int idx;

             public:
             SideCrossIterator(MagicalContainer& cont);
             SideCrossIterator(const SideCrossIterator &other): conti(other.conti), next(other.next), idx(other.idx){}
             SideCrossIterator(SideCrossIterator&& other) = default;
             SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
             SideCrossIterator& operator=(const SideCrossIterator& other) = delete;
             ~SideCrossIterator() = default;
             bool operator ==(const SideCrossIterator& other);
             bool operator != (const SideCrossIterator& other);
             bool operator >(const SideCrossIterator& other);
             bool operator <(const SideCrossIterator& other);
             const int operator*() const;
             SideCrossIterator& operator++();
             SideCrossIterator begin(){SideCrossIterator cro(conti); return cro;}
             SideCrossIterator end();
         };

         class PrimeIterator{
             MagicalContainer& conti;
             MysticalPrimeElement* current;
             int idx;

             public:
                 PrimeIterator(MagicalContainer& cont);
                 PrimeIterator(const PrimeIterator &other) :conti(other.conti), idx(other.idx){}
                 PrimeIterator(PrimeIterator&& other) = default;
                 PrimeIterator& operator=(PrimeIterator&& other) = delete;
                 PrimeIterator& operator=(const PrimeIterator& other) = delete;
                 ~PrimeIterator() = default;
                 bool operator ==(const PrimeIterator& other);
                 bool operator != (const PrimeIterator& other);
                 bool operator >(const PrimeIterator& other);
                 bool operator <(const PrimeIterator& other);
                 const int operator*() const;
                 PrimeIterator& operator++();
                 PrimeIterator begin(){PrimeIterator tmp(conti); return tmp;}
                 PrimeIterator end();
         };

 };

    bool isPrime(int n);
}