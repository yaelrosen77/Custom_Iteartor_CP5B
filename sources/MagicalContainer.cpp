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
    

}


//     for (int i=0; i<contsize; i++){
//         if (i == 0 && iteratia[i]>abb){        //begin case 
//             iteratia.insert(iteratia.begin(),abb);
//             break;
//         }
//         if (iteratia[i] == abb)
//             return;                                 //allready exist in the container
//         if (iteratia[i] < abb){
//             if (i+1==contsize){
//                 iteratia.insert(iteratia.end(),abb);
//                 break;
//             }
//             if (iteratia[i+1] > abb){
//                 iteratia.insert(iteratia.begin()+i+1,abb);
//                 break;
//         }
//     }
//     if (contsize ==0)
//         iteratia.insert(iteratia.begin(),abb);
//     contsize++;
// }