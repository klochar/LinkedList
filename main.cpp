#include <iostream>
#include <fstream>
#include <list>
#include "Animal.hpp"

using namespace std;
#define s endl;

int main() {
    
    Animal* a1 = new Animal(4,"chien",2);
    Animal* a2 = new Animal(4,"chat",2);
    Animal* a3 = new Animal(4,"lion",2);
    Animal* a4 = new Animal(4,"giraffe",2);
    Animal* a5 = new Animal(4,"tigre",2);

    list<Animal*> listAnimal;
    listAnimal.push_back(a1);
    listAnimal.push_back(a2);
    listAnimal.push_back(a3);
    listAnimal.push_back(a4);
    listAnimal.push_back(a5);
    
    //afficher element avec un ietrateur
    for (auto it = listAnimal.begin();it!=listAnimal.end();++it){
        cout<<(*it)->getNom()<<endl;
    }

    cout<<endl;
    cout<<endl;

    
    //pour effacer un element de la liste a la position x = n-1, dans notre cas on veut la premiere position donc l index 0
    auto element = next(listAnimal.begin(),0);
    //on efface le pointeur pour liberer l espace et ensuite on efface de la liste
    delete *element;//-->dereference nous amenera au pointeur de l animal 
    listAnimal.erase(element);
    

    //afficher element avec un ietrateur
    for (auto it = listAnimal.begin();it!=listAnimal.end();++it){
        cout<<(*it)->getNom()<<endl;
    }



    //on libere l espace
    for(auto AnimalPtr : listAnimal){
        delete AnimalPtr;
    }

    return 0;
}