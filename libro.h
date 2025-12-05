#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>


//se crea la clase Book para ser la clase base de los diferentes tipos de 
// libros y se definen sus atributos y metodos 
class Book {
    private:
    // los atributos de la clase Book serian el
    // id, titulo, numero de paginas y precio
    int id;
    std::string title;
    int num_pag;
    float price;
    
    public:
    // los constructores de la clase Book serian los getters y los
    // setters de cada atributo 
    // y el constructor por defecto y el constructor con parametros
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


// utilizando un precio base en 0, y dependiendo del tipo de libro calcula el
// precio con el numero de paginas 
// y si es edicion especial o audiolibro, el precio cambia si es libro de tapa
// blanda, tapa dura o digital

// se crea la clase subclase Softcover que hereda de la clase Book y se definen
// sus atributos y metodos
// los atributos de la clase Softcover seria un booleano para saber si es edicion
// especial o no
class Softcover: public Book{
    private:
    bool special_eds = false;

    // los metodos de la clase Softcover seria el constructor por defecto,
    // el constructor con parametros
    // y el metodo para calcular el precio
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

// se crea la clase Hardcover que hereda de la clase Book
// y se definen sus atributos y metodos
// los atributos de la clase Hardcover seria un booleano
// para saber si es edicion especial o no
class Hardcover: public Book{
    private:
    bool special_edh;

    // los metodos de la clase Hardcover seria
    // el constructor por defecto, el constructor con parametros
    // y el metodo para calcular el precio
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

// se crea la clase Digital que hereda de la clase Book y
// se definen sus atributos y metodos

// los atributos de la clase Digital seria un booleano
// para saber si es audiolibro o no
class Digital: public Book{
    private:
    bool audio;

    // los metodos de la clase Digital seria el constructor por defecto,
    // el constructor con parametros y el metodo para calcular el precio 
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