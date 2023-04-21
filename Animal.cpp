#include "Animal.hpp"

using namespace std;

Animal::Animal(int nbPatte,string nom,int nbYeux):nbPatte(nbPatte),nom(nom),nbYeux(nbYeux) {}
int Animal::getNbPatte()const{
    return this->nbPatte;
}
string Animal::getNom()const{
    return this->nom;
}
int Animal::getNbYeux()const{
    return this->nbYeux;
}