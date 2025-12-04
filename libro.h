#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>

class Book {
    private:
    int id;
    std::string title;
    int num_pag;
    float price;
    
    public:
    //constructors
    Book(){
        id = 0;
        title = "undefined";
        num_pag = 0;
    };
    Book (int n, std::string titlee, int num_pagg){
        id = n;
        title = titlee;
        num_pag = num_pagg;
    };
    //getters and setters
    int getID(){
        return id;
    };

    std::string get_title(){
        return title;
    };
    void set_title(std::string titlee){
        title = titlee;
    };
    
    int get_num_pag(){
        return num_pag;
    };
    void set_num_pag(int num_pagg){
        num_pag = num_pagg;
    };

    float get_price(){
        return price;
    }
    void set_price(float p){
        price = p;
    }
};




class Softcover: public Book{
    private:
    bool special_eds = false;

    public:
    Softcover(): Book(){};
    Softcover(int id, std::string title, int num_pag): Book(id, title, num_pag){};

    float calc_price(float price, int num_pag, bool get_specials){
        if (!get_specials){
            price = price + num_pag + 50;
        }
        else{
            price = (price + num_pag + 50)*1.3;
        }
        set_price(price);
        return price;
    };
};

class Hardcover: public Book{
    private:
    bool special_edh;

    public:
    Hardcover(): Book(){};
    Hardcover(int id, std::string title, int num_pag): Book(id, title, num_pag){};

    float calc_price(float price, int num_pag, bool get_specialh){
        if (!get_specialh){
            price = price + num_pag + 50;
        }
        else{
            price = (price + num_pag + 50)*1.5;
        }
        set_price(price);
        return price;
    };
};

class Digital: public Book{
    private:
    bool audio;

    public:
    Digital(): Book(){};
    Digital(int id, std::string title, int num_pag): Book(id, title, num_pag){};

    float calc_price(float price, int num_pag, bool get_audio){
        if (!get_audio){
            price = (price + num_pag + 50)*0.9;
        }
        else{
            price = (price + num_pag + 50)*1.035;
        }
        set_price(price);
        return price;
    };
};
#endif