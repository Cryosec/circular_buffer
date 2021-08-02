#include <iostream>
#include "cbuffer.h"
#include "person.h"


/**
 * @file main.cpp
 * @brief Dichiarazione di vari test e della funzione principale "main"
 * 
 * File main del programma, contenente la definizione di vari test
 * che verranno eseguiti all'avvio.
**/

/**
 * @brief Test di alcuni metodi implementati
 * 
 * Funzione senza parametri che istanza cbuffer diversi
 * per eseguire dei test sui metodi.
**/
void test_metodi() {
    
//buffer tipo int
    cbuffer<int> cbuff_int(5);

    cbuff_int.insert(1);
    cbuff_int.insert(5);
    cbuff_int.insert(-8);
    cbuff_int.insert(987);
    cbuff_int.insert(-13);
    cbuff_int.insert(16092);
    cbuff_int.remove();

    std::cout << cbuff_int << std::endl;

    cbuffer<int> cbuff_newint(cbuff_int);
    cbuffer<int> cbuff = cbuff_newint;

    std::cout << "cbuff con operatore <<: ";
    std::cout << cbuff << std::endl;

    //buffer tipo unsigned int
    cbuffer<int>::iterator iter, iter_end;

    iter = cbuff.begin();
    iter_end = cbuff.end();
    
    std::cout << "cbuff_unsint con operatore <<: ";
    cbuffer<unsigned int> cbuff_unsint(iter, iter_end, cbuff.capacity());
    std::cout << cbuff_unsint << std::endl;


    //buffer tipo custom
    cbuffer<person> cbuff_custom(5);

    person p("Marco", "Polo");
    std::cout << "persona p: " << p << std::endl;

    cbuff_custom.insert(p);
    cbuff_custom.insert({"Steve", "Jobs"});
    cbuff_custom.insert({"Lando", "Carlissian"});

    std::cout << "cbuff_custom con operatore <<: ";
    std::cout << cbuff_custom << std::endl;

    cbuffer<person>::iterator i, ie;

    std::cout << "cbuff_custom con iteratori: ";
    for(i = cbuff_custom.begin(), ie = cbuff_custom.end(); i != ie; i++)
        std::cout << *i << " ";

    std::cout << std::endl << "Accesso a cbuff_custom[2] = " << cbuff_custom[2] << std::endl;
    
    
}

/**
 * @brief Predicato per testare un intero positivo
 * 
 * Ritorna true se l'intero passato come parametro è >= 0, false altrimenti
 * @param value Il valore da verificare
 * @return Valore booleano risultante
**/
struct positive_int{
    inline bool operator()(const int& value) {return (value >= 0);}
};

/**
 * @brief Predicato per testare un intero negativo
 * 
 * Ritorna true se l'intero passato come parametro è < 0, false altrimenti
 * @param value Il valore da verificare
 * @return Valore booleano risultante
**/
struct negative_int {
    inline bool operator()(const int &value) {return (value < 0);}
};

/**
 * @brief Predicato per testare se cognome = "Polo"
 * 
 * Ritorna true se il cognome della persona è "Polo", false altrimenti
 * @param p La persona a cui verificare il cognome
 * @return Valore booleano risultante
**/
struct surname_polo {
    inline bool operator()(const person &p) {return (p.surname == "Polo");} 
};

/**
 * @brief Valuta gli elementi del buffer
 * 
 * Verifica se gli elementi di un buffer soddisfino un predicato unario
 * che riceve in input l'elemento del buffer da verificare
 * 
 * @param cbuff buffer circolare di elementi generici
 * @param pred funtore unario 
**/
template <typename T, typename P>
void check_if(cbuffer<T> cbuff, P pred) {

    typename cbuffer<T>::size_t i;
    typename cbuffer<T>::size_t size = cbuff.size();

    for(i = 0; i < size; i++) {

        // formatting dell'output
        std::cout << "[" << i << "]: ";

        if(pred(cbuff[i]))
            std::cout << "true" << std::endl;
        else
            std::cout << "false" << std::endl;
    }
}


int main() {

    // Esecuzione dei vari test definiti
    test_metodi();

    std::cout << "===========================\n";

    cbuffer<int> cbuff(5);
    cbuff.insert(1);
    cbuff.insert(2);
    cbuff.insert(-4);
    cbuff.insert(0);
    cbuff.insert(-1);

    cbuffer<person> cbuff_person(5);
    cbuff_person.insert({"Marco", "Polo"});
    cbuff_person.insert({"Steve", "Jobs"});
    cbuff_person.insert({"Lando", "Carlissian"});

    positive_int p;
    negative_int q;
    surname_polo r;
    
    std::cout << "Test check_if con cbuffer di interi e funtore positive_int:" << std::endl;
    check_if(cbuff, p);
    std::cout << "Test check_if con cbuffer di interi e funtore negative_int:" << std::endl;
    check_if(cbuff, q);
    std::cout << "Test check_if con cbuffer di person e funtore surname_polo" << std::endl;
    check_if(cbuff_person, r);
}