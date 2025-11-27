#include <iostream>

class Book {
    private:
    std::string title;
    std::string id;
    std::string genre;
    float price;
    int num_pag;
    
    public:
    //constructors
    Book(){
        title = "undefined";
        id = "undefined";
        genre = "undefined";
        price = 0.0;
        num_pag = 0;
    };
    Book (std::string titlee, std::string idd, std::string genree, float pricee, int num_pagg){
        title = titlee;
        id = idd;
        genre = genree;
        price = pricee;
        num_pag = num_pagg;
    };
    //getters and setters
    std::string get_title(){
        return title;
    };
    void set_title(std::string titlee){
        title = titlee;
    };
    

    std::string get_id(){
        return id;
    };
    void set_id(std::string idd){
        id = idd;
    };


    std::string get_genre(){
        return genre;
    };
    void set_genre(std::string genree){
        genre = genree;
    };


    float get_price(){
        return price;
    };
    void set_price(float pricee){
        price = pricee;
    };


    int get_num_pag(){
        return num_pag;
    };
    int set_num_pag(int num_pagg){
        num_pag = num_pagg;
    };

    

    void print_book(){
        std::cout << "Title: " << title << std::endl;
        std::cout << "ID: " << id << std::endl;
        std::cout << "Genre: " << genre << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Number of pages: " << num_pag << std::endl;

    };
};


class Softcover: public Book{
    private:
    bool special_eds;

    public:
    bool get_specials;
    bool set_specials;

    float calc_price(float price, int num_pag, bool get_specials){
        if (get_specials = false){
            price = price + num_pag + 50;
            std::cout << "No extra price on the book" << std::endl;
            std::cout << "Price: " << price << std::endl;
        }
        else{
            price = (price + num_pag + 50)*1.3;
            std::cout << "Special edition price: " << price << std::endl;
        }
    };
};

class Hardcover: public Book{
    private:
    bool special_edh;

    public:
    bool get_specialh;
    bool set_specialh;

    float calc_price(float price, int num_pag, bool get_specialh){
        if (get_specialh = false){
            price = price + num_pag + 50;
            std::cout << "No extra price on the book" << std::endl;
            std::cout << "Price: " << price << std::endl;
        }
        else{
            price = (price + num_pag + 50)*1.5;
            std::cout << "Special edition price: " << price << std::endl;
        }
    };
};

class Digital: public Book{
    private:
    bool audio;

    public:
    bool get_audio;
    bool set_audio;

    float calc_price(float price, int num_pag, bool get_audio){
        if (get_audio = false){
            price = (price + num_pag + 50)*0.9;
            std::cout << "Price: " << price << std::endl;
        }
        else{
            price = (price + num_pag + 50)*1.035;
            std::cout << "Audiobook price: " << price << std::endl;
        }
    };
};