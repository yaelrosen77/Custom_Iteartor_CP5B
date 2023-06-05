#include "MagicalContainer.hpp"
using namespace ariel;

bool ariel :: isPrime(int n){
    if (n <= 1)
        return false;

    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

MagicalContainer :: MagicalContainer(MagicalContainer& other){
    contsize = other.contsize;
    iteratia = other.iteratia;
    prim = other.prim;
}

void MagicalContainer :: addElement(int abb){
    for (int i=0; i<contsize; i++){                    //checking if the curr val exist in the container
        if (iteratia[i].getVal() == abb)
            return;
    }
    if (isPrime(abb)){
        MysticalPrimeElement mist(abb);            //creating a new magical stone with desired value
        insertPrime(mist);
        return;
    }
    MysticalElement mist(abb);                      //creating mystical element with value 
    insert(mist);
}


void MagicalContainer :: insertPrime(MysticalPrimeElement& thing){
    
}


//later change to private 
void MagicalContainer :: insert(MysticalElement& thing){
    if (contsize==0)
        iteratia.insert(iteratia.begin(),thing);
    else {
        for (int i=0; i<=contsize; i++){
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
        int counter = 1;
        int i =0;
        int j= contsize -1;
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

