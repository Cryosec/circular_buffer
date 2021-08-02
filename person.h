#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

/**
 * @file person.h
 * @brief Dichiarazione di un tipo custom nominato "person"
 * 
 * Tipo custom che rappresenta una persona, dotata di nome e cognome.
**/
struct person {
    std::string name;
    std::string surname;

    /**
     * Costruttore di default, necessario per poter creare un array di person.
    **/
    person() {}

    /**
     * Costruttore secondario per creare una person con nome e cognome definiti dall'utente.
     * @param n nome della persona
     * @param s cognome della persona
    **/
    person(const std::string n, const std::string s) : name(n), surname(s) {}
};

/**
 * @brief Operatore di stream in output
 * 
 * Overloading dell'operatore <<, per permettere la stampa di una variabile di tipo person facilmente
**/
std::ostream &operator<<(std::ostream &os, const person &p);

#endif