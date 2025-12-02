#include <iostream>


//print books available
//make list of preset books in inventory

const int MAX = 100;

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
    void addSoft(std::string title, int num_pag);
    void addHard(std::string title, int num_pag);
    void addDigital(std::string title, int num_pag);
    
};

Inventory::Inventory(){
    ibookS = 0;
    ibookH = 0;
    ibookD = 0;
}

void Inventory::createSoftlist(){

};
