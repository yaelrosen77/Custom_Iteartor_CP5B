#pragma once
#include <iostream>

namespace ariel{
    class MysticalElement{
        int value;                    //The value of a mystical stone is forever fixed
        MysticalElement *nextCross;  
                   
        public:
            MysticalElement(int val): value{val}, nextCross{nullptr}{}
            MysticalElement(const MysticalElement&) = default;
            MysticalElement& operator=(const MysticalElement&) = default;
            MysticalElement(MysticalElement&&) = default;
            MysticalElement& operator=(MysticalElement&&) = default;
            ~MysticalElement() = default;
            int& getVal() {return value;}
            MysticalElement* getCross(){return nextCross;}
            void setCross(MysticalElement* thing){nextCross = thing;}
    };

    class MysticalPrimeElement : public MysticalElement{
        MysticalPrimeElement(const MysticalPrimeElement& other): MysticalElement(other), nextPrime(nullptr){}
        MysticalPrimeElement& operator=(const MysticalPrimeElement& other); 
        MysticalPrimeElement(MysticalPrimeElement&& other) noexcept 
        : MysticalElement(std::move(other)), nextPrime(other.getNextPrime()) {}
        MysticalPrimeElement& operator=(MysticalPrimeElement&&) noexcept;
        MysticalPrimeElement *nextPrime;
        public: 
            MysticalPrimeElement(int val): MysticalElement(val), nextPrime{nullptr}{}
            ~MysticalPrimeElement() = default;
            MysticalPrimeElement* getNextPrime(){return nextPrime;}
            void SetNextPrime(MysticalPrimeElement* pr1){nextPrime = pr1;}
    };
}
