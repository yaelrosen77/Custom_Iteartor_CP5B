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
        void insertPrime(MysticalPrimeElement* thing);
        void insert(MysticalElement* thing);
        int contsize;

    public:
        MagicalContainer() : contsize(0), prim(nullptr){}
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
//         class SideCrossIterator{
//             MagicalContainer& conti;
//             int ndx;
//             public:
//             SideCrossIterator(MagicalContainer& cont): conti(cont),ndx(0){}
//             SideCrossIterator(const SideCrossIterator &other): conti(other.conti),ndx(0){}
//             SideCrossIterator(SideCrossIterator&& other) = default;
//             SideCrossIterator& operator=(SideCrossIterator&& other) = delete;
//             SideCrossIterator& operator=(const SideCrossIterator& other) = delete;
//             ~SideCrossIterator() = default;
//             bool operator ==(const SideCrossIterator& other){return false;}
//             bool operator != (const SideCrossIterator& other){return false;}
//             bool operator >(const SideCrossIterator& other){return false;}
//             bool operator <(const SideCrossIterator& other){return false;}
//             int& operator*() const {return conti.contsize;}
//             SideCrossIterator& operator++(){return *this;}
//             SideCrossIterator begin(){return *this;}
//             SideCrossIterator end(){return *this;}
//         };

//         class PrimeIterator{
//             MagicalContainer& conti;

//             public:
//                 PrimeIterator(MagicalContainer& cont): conti(cont){}
//                 PrimeIterator(const PrimeIterator &other) :conti(other.conti){}
//                 PrimeIterator(PrimeIterator&& other) = default;
//                 PrimeIterator& operator=(PrimeIterator&& other) = delete;
//                 PrimeIterator& operator=(const PrimeIterator& other) = delete;
//                 ~PrimeIterator() = default;
//                 bool operator ==(const PrimeIterator& other){return false;}
//                 bool operator != (const PrimeIterator& other){return false;}
//                 bool operator >(const PrimeIterator& other){return false;}
//                 bool operator <(const PrimeIterator& other){return false;}
//                 int& operator*() const {return conti.contsize;}
//                 PrimeIterator& operator++(){return *this;}
//                 PrimeIterator begin(){return *this;}
//                 PrimeIterator end(){return *this;}
//         };

// };

    };

    bool isPrime(int n);
}