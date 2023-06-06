#pragma once
#include <iostream>

namespace ariel{
    class MysticalElement{
        int value;                    //The value of a mystical stone is forever fixed
        int crossidx;                 //The serial value in the cross traversal 
        MysticalElement *nextCross;                     
        public:
            MysticalElement(int val): value{val}, nextCross{nullptr}{}
            int getVal() const {return value;}
            int getidx() const {return crossidx;}
            void setidx(int tmp){crossidx = tmp; }
            MysticalElement* getCross(){return nextCross;}
            void setCross(MysticalElement* thing){nextCross = thing;}
    };

    class MysticalPrimeElement : public MysticalElement{
        MysticalPrimeElement *nextPrime;
        public: 
            MysticalPrimeElement(int val): MysticalElement(val), nextPrime{nullptr}{}
            MysticalPrimeElement* getNextPrime(){return nextPrime;}
            void SetNextPrime(MysticalPrimeElement* pr1){nextPrime = pr1;}
    };
}
