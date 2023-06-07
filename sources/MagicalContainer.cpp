//
// Created by vboxuser on 6/7/23.
//
#include "MagicalContainer.hpp"
using namespace ariel;

bool ariel :: isPrime(int n){
    if (n <= 1){
        return false;
    }
    for (int i = 2; i <= n/2 ; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

MagicalContainer :: MagicalContainer(MagicalContainer& other){
    contsize = other.contsize;
    iteratia = other.iteratia;
    prim = other.prim;
}

void MagicalContainer :: addElement(int abb){
    for (unsigned int i=0; i<contsize; i++){                    //checking if the curr val exist in the container
        if (iteratia[i]->getVal() == abb)
            return;
    }
    if ((isPrime(abb)) == true){
        MysticalPrimeElement* mist = new MysticalPrimeElement(abb);            //creating a new magical stone with desired value
        insertPrime(mist);
        return;
    }
    MysticalElement* mist = new MysticalElement(abb);                      //creating mystical element with value
    insert(mist);
}

void MagicalContainer :: insertPrime(MysticalPrimeElement* thing){
    MysticalElement * ptr1;
    ptr1 = thing;
    insert(ptr1);
    if (prim == nullptr){
        prim = thing;
        return;
    }
    MysticalPrimeElement* mpe = prim;
    if (prim->getVal() > thing->getVal()){
        prim = thing;
        thing->SetNextPrime(mpe);
        return;
    }
    while (mpe->getNextPrime() != nullptr){
        if (mpe->getVal() < thing->getVal() && mpe->getNextPrime()->getVal()> thing->getVal()){
            MysticalPrimeElement* thi = mpe->getNextPrime();
            mpe->SetNextPrime(thing);
            thing->SetNextPrime(thi);
            return;
        }
        mpe = mpe->getNextPrime();
    }
    mpe->SetNextPrime(thing);
}


//later change to private
void MagicalContainer :: insert(MysticalElement* thing){
    if (contsize==0)
        iteratia.insert(iteratia.begin(),thing);
    else {
        for (unsigned int i=0; i<=contsize; i++){
            if (i==0){
                if (iteratia[0]->getVal()> thing->getVal()){
                    iteratia.insert(iteratia.begin(),thing);
                    break;
                }
            }
            else if(i<contsize){
                if (iteratia[i]->getVal() > thing->getVal()){
                    iteratia.insert(iteratia.begin()+i,thing);
                    break;
                }
            }
            else {
                iteratia.insert(iteratia.begin()+contsize,thing);
                break;
            }
        }
    }
    contsize++;                                         //finish inserting values

    if (contsize==1){                                          //thing is the only element in the container
        thing->setCross(nullptr);
    }

    else if (contsize == 2){
        iteratia[0]->setCross((iteratia[1]));
        iteratia[1]->setCross(nullptr);
    }

    else {
        int counter = 1;
        unsigned int i =0;
        unsigned int j= (unsigned int) contsize - 1;
        MysticalElement * tmp = nullptr;

        while(i<j){
            if (tmp!=nullptr)
                tmp->setCross(iteratia[i]);
            MysticalElement* tmp1 = iteratia[i];
            MysticalElement* tmp2 = iteratia[j];
            tmp1->setCross(tmp2);
            tmp = tmp2;
            i++;
            j--;
        }
        if (i==j){
            tmp->setCross(iteratia[i]);
            iteratia[i]->setCross(nullptr);
            end = iteratia[i];
        }
        else {
            tmp->setCross(nullptr);
            end = tmp;
        }
    }
}

MagicalContainer :: AscendingIterator :: AscendingIterator(MagicalContainer& cont): conti(cont){
    if (conti.size()==0){
        current = -1;
    }
    else current = 0;
}

bool MagicalContainer :: AscendingIterator :: operator ==(const AscendingIterator& other) const{
    return (current == other.current);
}

MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end(){
    AscendingIterator itr = *this;
    itr.current = (unsigned int)itr.conti.size();
    return itr;
}

const int :: MagicalContainer :: AscendingIterator :: operator*() const{
    return conti.iteratia[current]->getVal();
}

bool :: MagicalContainer :: AscendingIterator :: operator != (const AscendingIterator& other) const{
    return !(*this == other);
}

bool :: MagicalContainer :: AscendingIterator :: operator >(const AscendingIterator& other) const{
    return (current > other.current);
}

bool :: MagicalContainer :: AscendingIterator :: operator <(const AscendingIterator& other) const{
    return !(*this>other);
}

MagicalContainer :: SideCrossIterator :: SideCrossIterator(MagicalContainer& cont): conti(cont){
    if (conti.contsize == 0){
        next = nullptr;
        idx = -1;
    }
    else {
        next = conti.iteratia[0];
        idx = 0;
    }
}

bool MagicalContainer :: SideCrossIterator :: operator ==(const SideCrossIterator& other){
    return (idx==other.idx);
}

bool MagicalContainer :: SideCrossIterator :: operator != (const SideCrossIterator& other){
    return (idx!=other.idx);
}

bool MagicalContainer :: SideCrossIterator :: operator> (const SideCrossIterator& other){
    return (idx>other.idx);
}

bool MagicalContainer :: SideCrossIterator :: operator<(const SideCrossIterator& other) {
    return !(idx<other.idx);
}

const int MagicalContainer :: SideCrossIterator :: operator*() const {
    if (next!= nullptr)
        return next->getVal();
}

MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator++(){
    if (next != nullptr) {
        next = next->getCross();
        idx++;
    }
    return *this;
}

MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end() {
    MagicalContainer :: SideCrossIterator tmp(conti);
    tmp.next = nullptr;
    tmp.idx = conti.size();
    return tmp;
}

