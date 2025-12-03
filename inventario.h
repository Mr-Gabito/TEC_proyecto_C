
#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "libro.h"
#include <iostream>
#define MAX 100

class Inventory{
    private: 
    Softcover bookS[MAX];
    Hardcover bookH[MAX];
    Digital bookD[MAX];
    int ibookS, ibookH, ibookD;
    public:
    Inventory();

    void createSoftlist();
    void createHardlist();
    void createDigitallist();
    void showSoft();
    void showHard();
    void showDigital();
    void addBook(int option, std::string title, int num_pag);
};

Inventory::Inventory(){
    ibookS = 0;
    ibookH = 0;
    ibookD = 0;
}

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
    bookH[0] = Hardcover(ibookH, "The Hobbit", 366);
    ibookH += 1;
    bookH[1] = Hardcover(ibookH, "The Golden Compass", 399);
    ibookH += 1;
    bookH[2] = Hardcover(ibookH, "Frankenstein", 260);
    ibookH += 1;
    bookH[3] = Hardcover(ibookH, "The Picture of Dorian Gray", 253);
    ibookH += 1;
    bookH[4] = Hardcover(ibookH, "The King in Yellow", 224);
    ibookH += 1;
    bookH[5] = Hardcover(ibookH, "The Girl with the Dragon Tattoo", 480);
    ibookH += 1;
};

void Inventory::createDigitallist(){
    bookD[0] = Digital(ibookD, "The Martian", 384);
    ibookD += 1;
    bookD[1] = Digital(ibookD, "Project Hail Mary", 476);
    ibookD += 1;
    bookD[2] = Digital(ibookD, "The Girl Who Drank the Moon", 388);
    ibookD += 1;
    bookD[3] = Digital(ibookD, "1984", 368);
    ibookD += 1;
    bookD[4] = Digital(ibookD, "The Book Thief", 592);
    ibookD += 1;
    bookD[5] = Digital(ibookD, "Little Women", 449);
    ibookD += 1;
};

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

void Inventory::addBook(int option, std::string title, int num_pag){
    if(option == 1){
        ibookS += 1;
        Softcover aux(ibookS + 1, title, num_pag);
        bookS[ibookS] = aux;
    }
    else if(option == 2){
        ibookH += 1;
        Hardcover aux(ibookH, title, num_pag);
        bookH[ibookH] = aux;
    }
    else{
        ibookD += 1;
        Digital aux(ibookD, title, num_pag);
        bookD[ibookD] = aux;
    }
}
#endif
