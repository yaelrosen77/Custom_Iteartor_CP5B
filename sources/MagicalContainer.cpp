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

MagicalContainer :: MagicalContainer(MagicalContainer& other){          //to change it later
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
        numofprimes++;
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
    setCross();
}

void MagicalContainer :: removeElement(int bbb) {
    int index = -1;
    for (unsigned int i = 0; i < contsize; i++) {
        if (iteratia[i]->getVal() == bbb) {
            index = (int) i;
            break;
        }
    }
    if (index == -1)
        throw runtime_error("Element does not exist");
    if (isPrime(bbb))
        updatePrime(index);

    MysticalElement *del = iteratia[(unsigned int)index];
    iteratia.erase(iteratia.begin() + index);
    contsize--;
    setCross();
    delete del;
}

void MagicalContainer ::updatePrime(int index) {
    MysticalPrimeElement *tmp2 = prim;
    MysticalPrimeElement *tmp1 = prim;
    for (int i = 0; i < numofprimes; i++) {
        if (tmp1->getVal() == iteratia[(unsigned int)index]->getVal()) {
            if (i == 0) {
                prim = tmp1->getNextPrime();
                numofprimes--;
                break;
            }
            if (i < numofprimes - 1) {
                tmp2->SetNextPrime(tmp1->getNextPrime());
                numofprimes--;
                break;
            }
            if (i == numofprimes - 1) {
                tmp2->SetNextPrime(nullptr);
                numofprimes--;
                break;
            }
        }
        tmp1 = tmp1->getNextPrime();
        if (i > 0) {
            tmp2 = tmp2->getNextPrime();
        }
    }
}

void MagicalContainer :: setCross(){
    if (contsize==1){                                          //thing is the only element in the container
        iteratia[0]->setCross(nullptr);
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
        }
        else {
            tmp->setCross(nullptr);
        }
    }
}

bool MagicalContainer :: AscendingIterator :: operator ==(const AscendingIterator& other) const{
    return (current == other.current);
}

MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end(){
    AscendingIterator itr(conti);
    itr.current = (unsigned int)conti.size();
    return itr;
}

int& :: MagicalContainer :: AscendingIterator :: operator*() const{
    return conti.iteratia[current]->getVal();
}

bool :: MagicalContainer :: AscendingIterator :: operator != (const AscendingIterator& other) const{
    return !(*this == other);
}

bool :: MagicalContainer :: AscendingIterator :: operator >(const AscendingIterator& other) const{
    return (current > other.current);
}

bool :: MagicalContainer :: AscendingIterator :: operator <(const AscendingIterator& other) const{
    return ( current < other.current);
}

MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator=(const AscendingIterator& other){
    if (&conti != &(other.conti))
        throw runtime_error("Ilegall assignment");
    current = other.current;
    return *this;
}

MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator++(){
    if (current == conti.size())
        throw runtime_error("Cannot increment beyond range");
    current++; 
    return *this;
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

bool MagicalContainer :: SideCrossIterator :: operator ==(const SideCrossIterator& other) const{
    if (idx == -1 && other.idx == conti.size())
        return true;
    if (idx == conti.size() && other.idx == -1)
        return true;
    return (idx==other.idx);
}

bool MagicalContainer :: SideCrossIterator :: operator != (const SideCrossIterator& other) const{
    return (idx!=other.idx);
}

bool MagicalContainer :: SideCrossIterator :: operator> (const SideCrossIterator& other) const {
    return (idx>other.idx);
}

bool MagicalContainer :: SideCrossIterator :: operator<(const SideCrossIterator& other) const {
    return (idx<other.idx);
}

int& MagicalContainer :: SideCrossIterator :: operator*() const{
    return next->getVal();
}

MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator=(const SideCrossIterator& other){
    if (&conti != &(other.conti))
        throw runtime_error("Ilegall assignment");
    idx = other.idx;
    next = other.next;
    return *this;
}


MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator++(){
    if (idx == conti.size())
        throw runtime_error("Cannot increment beyond range");
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

MagicalContainer :: PrimeIterator :: PrimeIterator(MagicalContainer& cont) : conti(cont){
    if (conti.numofprimes==0) {
        current = nullptr;
        idx = -1;
    }
    else {
        current = conti.getprim();
        idx = 0;
    }
}

bool MagicalContainer :: PrimeIterator :: operator ==(const PrimeIterator& other) const{
    if (idx==-1 && other.idx == conti.numofprimes)
        return true;
    if (idx == conti.numofprimes && other.idx == -1)
        return true;
    return (idx==other.idx);
}

bool MagicalContainer :: PrimeIterator :: operator != (const PrimeIterator& other) const{
    return (idx!=other.idx);
}
bool MagicalContainer :: PrimeIterator :: operator >(const PrimeIterator& other)const {
    return (idx>other.idx);
}

bool MagicalContainer :: PrimeIterator :: operator <(const PrimeIterator& other) const {
    return (idx<other.idx);
}

int& MagicalContainer :: PrimeIterator :: operator*() const{
    return current->getVal();
}

MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator++(){
    if (idx == conti.numofprimes || idx == -1)
        throw runtime_error("Cannot increment beyond range");
    if (current!= nullptr){
        current = current->getNextPrime();
        idx++;
    }
    return *this;
}

MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end() {
    PrimeIterator tmp(conti);
    tmp.current = nullptr;
    tmp.idx = conti.numofprimes;
    return tmp;
}

MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator=(const PrimeIterator& other){
    if (&conti != &other.conti)
        throw runtime_error("Ilegall assignment");
    idx = other.idx;
    current = other.current;
    return *this;
}
