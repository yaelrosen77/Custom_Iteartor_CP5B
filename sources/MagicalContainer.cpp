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
        if (iteratia[i].getVal() == abb)
            return;
    }
    if ((isPrime(abb)) == true){
        MysticalPrimeElement mist(abb);            //creating a new magical stone with desired value
        insertPrime(mist);
        return;
    }
    MysticalElement mist(abb);                      //creating mystical element with value 
    insert(mist);
    cout << "************************************" << endl;
    cout << "current size is " << contsize << "and the element in the vector are:" <<endl; 
    for(unsigned int i =0; i<contsize; i++){
        cout<< "The magic stone is: " << iteratia[i].getVal() << "and its index on cross is: " <<iteratia[i].getidx() <<endl;
    }
    cout << "the current size of the vector is : " << contsize << "and now we can add another one" <<endl;

}


void MagicalContainer :: insertPrime(MysticalPrimeElement& thing){
    MysticalElement* tmp = &thing;
    insert(*tmp);

    if (prim == nullptr){
        prim = &thing;
        return;
    }
    MysticalPrimeElement ** mpe = &prim;
    if (prim->getVal() > thing.getVal()){
        prim = &thing;
        thing.SetNextPrime(*mpe);
        return;
    }            
    while ((*mpe)->getNextPrime() != NULL){
        if ((*mpe)->getVal() < thing.getVal() && (*mpe)->getNextPrime()->getVal()> thing.getVal()){
            MysticalPrimeElement* thi = (*mpe)->getNextPrime();
            (*mpe)->SetNextPrime(&thing);
            thing.SetNextPrime(thi);
            return;
        }
        *mpe = (*mpe)->getNextPrime();
    }    
    (*mpe)->SetNextPrime(&thing);
    cout << "We just added this prime number with the value of : " << thing.getVal() << 
    "and its value on the indeces is :" << thing.getidx() << endl;
    if (thing.getNextPrime() != nullptr){
        cout<< "this is the following value of the next prime " << thing.getNextPrime()->getVal();
    }
    cout << "the current size of the vector is : " << contsize << "and now we can add another one" <<endl;
}


//later change to private 
void MagicalContainer :: insert(MysticalElement& thing){
    if (contsize==0)
        iteratia.insert(iteratia.begin(),thing);
    else {
        for (unsigned int i=0; i<=contsize; i++){
            if (i==0){
                if (iteratia[0].getVal()> thing.getVal()){
                    iteratia.insert(iteratia.begin(),thing);
                    break;
                }
            }
            else if(i<contsize){
                if (iteratia[i].getVal() > thing.getVal()){
                    iteratia.insert(iteratia.begin()+i,thing);
                    break;
                }
            }
            else {
                iteratia.insert(iteratia.end(),thing);
                break;
            }
        }
    }
    contsize++;                                         //finish inserting values
    
    if (contsize==1){                                          //thing is the only element in the container
        thing.setidx(1);
        thing.setCross(nullptr);
    }

    else if (contsize ==2){
        iteratia[0].setidx(1);
        iteratia[0].setCross(&(iteratia[1]));
        iteratia[1].setidx(2);
        iteratia[1].setCross(nullptr);
    }

    else {
        unsigned int counter = 1;
        unsigned int i =0;
        unsigned int j= (unsigned int) contsize - 1;
        MysticalElement * tmp = nullptr;

        while(i<j){
            if (tmp!=nullptr)
                tmp->setCross(&iteratia[i]);
            MysticalElement* tmp1 = &iteratia[i];
            MysticalElement* tmp2 = &iteratia[j];
            tmp1->setidx(counter++);
            tmp1->setCross(tmp2);
            tmp2->setidx(counter);
            tmp = tmp2;
            i++;
            j--;
        }
        if (i==j){
            tmp->setCross(&iteratia[i]);
            iteratia[i].setidx(i);
            iteratia[i].setCross(nullptr);
        }
        else {
            tmp->setCross(nullptr);
        }

    }

}

