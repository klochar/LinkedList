#include <iostream>
#include <fstream>
#include <list>
#include "Animal.hpp"
#include <string>
#include <algorithm>

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

    Animal* a7 = new Animal(4,"TEST",2);

    list<Animal*>::iterator iterDernier = listAnimal.end();//pointe vers un pointeur null 
    list<Animal*>::iterator iter = listAnimal.begin();//pointe vers le premier
    iter++;//rendu au deuxieme
    listAnimal.insert(iter,a7);//il va le mettre avant ce que iter pointe donc il va le mettre avant a2 

    //find_if, marche mieux avec les pointeurs et lambda pour les criteres
    string nom = "TEST";

    auto animalTrouveFind_If = find_if(listAnimal.begin(), listAnimal.end(),[&](Animal* animal){return animal->getNom() == nom;});
    if (animalTrouveFind_If != listAnimal.end()){//pointeur null donc il n a pas trouve
        cout<<"trouve find_if"<< " " <<(*animalTrouveFind_If)->getNom()<<endl;
    } else {
        cout<<"Animal non trouve";
    }


    cout<<endl;
    cout<<endl;
    //find, ne marche pas vrm avec les pointeur de type
    //Animal* animalATrouver = new Animal(4,"chat",2);
    auto animalTrouveFind = find(listAnimal.begin(),listAnimal.end(),a2);
    if(animalTrouveFind!= listAnimal.end()){
        cout<<"trouve find";
    } else {
        cout<<"non trouve find";
    }


    cout<<endl;
    cout<<endl;

    
    // //pour effacer un element de la liste a la position x = n-1, dans notre cas on veut la premiere position donc l index 0
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