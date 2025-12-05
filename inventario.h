// se incluye libro.h para utilizar las clases de los libros
#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "libro.h"
#include <iostream>
#define MAX 100


// en la clase Inventory se crean los arreglos para cada tipo de libro
// y se definen sus metodos
// los atributos de la clase Inventory serian los arreglos de Softcover,
// Hardcover y Digital y los contadores de cada arreglo
class Inventory{
    public:
    Softcover bookS[MAX];
    Hardcover bookH[MAX];
    Digital bookD[MAX];
    int ibookS, ibookH, ibookD;
    Inventory();

    // los metodos de la clase Inventory serian crear
    // la lista de los diferentes libros, 
    // mostrar la lista de los diferentes libros y agregar un libro
    // se puede agregar un libro dependiendo del
    // tipo de libro que se quiera agregar
    void createSoftlist();
    void createHardlist();
    void createDigitallist();
    void showSoft();
    void showHard();
    void showDigital();
    void addBook(int option, std::string title, int num_pag);
};

// se definen los metodos de la clase Inventory
// el constructor por defecto inicializa
// los contadores de cada arreglo en 0
Inventory::Inventory(){
    ibookS = 0;
    ibookH = 0;
    ibookD = 0;
}

// se crean las listas de los diferentes tipos de libros
// con algunos libros predefinidos
void Inventory::createSoftlist(){
    bookS[0] = Softcover(ibookS + 1, "The Little Prince", 96);
    ibookS += 1;
    bookS[1] = Softcover(ibookS + 1, "Eragon", 503);
    ibookS += 1;
    bookS[2] = Softcover(ibookS + 1, "The Lord of the Flies", 304);
    ibookS += 1;
    bookS[3] = Softcover(ibookS + 1, "The Underneath", 320);
    ibookS += 1;
    bookS[4] = Softcover(ibookS + 1, "Miss Peregrine's Home for Peculiar Children", 352);
    ibookS += 1;
    bookS[5] = Softcover(ibookS + 1, "The Giver", 208);
    ibookS += 1;
};

void Inventory::createHardlist(){
    bookH[0] = Hardcover(ibookH + 1, "The Hobbit", 366);
    ibookH += 1;
    bookH[1] = Hardcover(ibookH + 1, "The Golden Compass", 399);
    ibookH += 1;
    bookH[2] = Hardcover(ibookH + 1, "Frankenstein", 260);
    ibookH += 1;
    bookH[3] = Hardcover(ibookH + 1, "The Picture of Dorian Gray", 253);
    ibookH += 1;
    bookH[4] = Hardcover(ibookH + 1, "The King in Yellow", 224);
    ibookH += 1;
    bookH[5] = Hardcover(ibookH + 1, "The Girl with the Dragon Tattoo", 480);
    ibookH += 1;
};

void Inventory::createDigitallist(){
    bookD[0] = Digital(ibookD + 1, "The Martian", 384);
    ibookD += 1;
    bookD[1] = Digital(ibookD + 1, "Project Hail Mary", 476);
    ibookD += 1;
    bookD[2] = Digital(ibookD + 1, "The Girl Who Drank the Moon", 388);
    ibookD += 1;
    bookD[3] = Digital(ibookD + 1, "1984", 368);
    ibookD += 1;
    bookD[4] = Digital(ibookD + 1, "The Book Thief", 592);
    ibookD += 1;
    bookD[5] = Digital(ibookD + 1, "Little Women", 449);
    ibookD += 1;
};

// se muestran las listas de los diferentes tipos de libros
void Inventory::showSoft(){
    for(int i = 0; i < ibookS; i++){
        std::cout << "ID: " << bookS[i].getID() << std::endl;
        std::cout << "Title: " << bookS[i].get_title() << std::endl;
        std::cout << "Number of pages: " << bookS[i].get_num_pag() << std::endl << std::endl;
    }
}

void Inventory::showHard(){
    for(int i = 0; i < ibookH; i++){
        std::cout << "ID: " << bookH[i].getID() << std::endl;
        std::cout << "Title: " << bookH[i].get_title() << std::endl;
        std::cout << "Number of pages: " << bookH[i].get_num_pag() << std::endl << std::endl;
    }
}

void Inventory::showDigital(){
    for(int i = 0; i < ibookD; i++){
        std::cout << "ID: " << bookD[i].getID() << std::endl;
        std::cout << "Title: " << bookD[i].get_title() << std::endl;
        std::cout << "Number of pages: " << bookD[i].get_num_pag() << std::endl << std::endl;
    }
}

// se agrega un libro a cualquier arreglo dependiendo
// del tipo de libro que se quiera agregar
void Inventory::addBook(int option, std::string title, int num_pag){
    if(option == 1){
        Softcover aux(ibookS + 1, title, num_pag);
        bookS[ibookS] = aux;
        ibookS++;
    }
    else if(option == 2){
        Hardcover aux(ibookH + 1, title, num_pag);
        bookH[ibookH] = aux;
        ibookH++;
    }
    else{
        Digital aux(ibookD + 1, title, num_pag);
        bookD[ibookD] = aux;
        ibookD++;
    }
}
#endif
