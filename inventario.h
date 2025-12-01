//add books to inventory
//delete books from inventory
//add amount of books in stock
//print books available
//print books available<
//make list of preset books in inventory
//try to find a way to randomize the books you have access to, to make it all seem more natural

const int MAX = 100;

class Inventory{
    //add methods here (delete book, add book, search book, price)
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
