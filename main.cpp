// se incluye libro.h e inventario.h para poder utilizar las clases y metodos definidos en esos archivos
#include <iostream>
#include "libro.h"
#include "inventario.h"


// se crea el menu principal, con las opciones disponibles
void menu(){
        std::cout << "Menu" << std::endl;
        std::cout << "1. List of Softcover books" << std::endl;
        std::cout << "2. List of Hardcover books" << std::endl;
        std::cout << "3. List of Digital books" << std::endl;
        std::cout << "4. Add a book" << std::endl;
        std::cout << "5. Check book price" << std::endl;
        std::cout << "6. Exit" << std::endl;
    };

// el main se crea para ejecutar el programa
int main(){
    // se inicializan las listas de libros
    Inventory inventory;
    inventory.createSoftlist();
    inventory.createHardlist();
    inventory.createDigitallist();
    // se crean los objetos necesarios para manejar los libros
    Softcover softcover;
    Hardcover hardcover;
    Digital digital;
    
    // se crean las variables necesarias para el menu, 3 opciones,
    // el nombre del libro, numero de paginas, 
    // id del libro, y tof que es verdadero o falso
    std::string nameb;
    int num_pages = 0;
    int id_libro = 0;
    int option = 0;
    int optionn = 0;
    int optionnn = 0;
    std::string tof;

    // se utiliza un while para que el menu se repita hasta que el
    // usuario decida salir pulsando la opcion 6
    while(option != 6){
        menu();
        std::cin >> option;
        // se utiliza un switch para manejar las diferentes opciones del menu
        switch(option){
        case 1:
            // se imprimen las listas de los diferentes tipos de libros
            inventory.showSoft();
            break;
        case 2:
            inventory.showHard();
            break;
        case 3:
            inventory.showDigital();
            break;
        case 4:
            // se utiliza otro while y una variable de opcion para agregar un
            // libro al inventario
            optionn = 0;
            while (optionn != 4){
                std::cout << "1. Add Softcover book" << std::endl;
                std::cout << "2. Add Hardcover book" << std::endl;
                std::cout << "3. Add Digital book" << std::endl;
                std::cout << "4. Back to main menu" << std::endl;
                std::cin >> optionn;
                if(optionn == 4){
                    break;
                }
                // se piden los datos del libro a agregar
                std::cout << "Name of the book (Use '_' for spaces): " << std::endl;
                std::cin >> nameb;
                std::cout << "Number of pages: " << std::endl;
                std::cin >> num_pages;
                // manda llamar al metodo addBook de la clase Inventory para
                // agregar el libro al inventario
                inventory.addBook(optionn, nameb, num_pages);
            }
            break;
        case 5:
            // se utiliza otro while y una variable de opcion
            // para calcular el precio del libro
            optionnn = 0;
            while (optionnn != 4){
                std::cout << "1. List of Softcover books for price" << std::endl;
                std::cout << "2. List of Hardcover books for price" << std::endl;
                std::cout << "3. List of Digital books for price" << std::endl;
                std::cout << "4. Back to main menu" << std::endl;
                std::cin >> optionnn;
                // imprime la lista de los libros y pregunta el id del
                // libro que quieren calcular el precio
                // dependiendo del tipo de libro, pregunta si se quiere
                // edicion especial o audiolibro
                // y calcula el precio correspondiente
                if(optionnn == 1){
                    inventory.showSoft();
                    std::cout << "Type the ID number of the book: " << std::endl;
                    std::cin >> id_libro;
                    std::cout << "Would you like your book to be special edition? (Yes or No): " << std::endl;
                    std::cin >> tof;
                    if (tof == "Yes"){
                        // accede al arreglo de libros del inventario y calcula el precio
                        // dependiendo si es edicion especial o no
                        softcover.calc_price(0, inventory.bookS[id_libro - 1].get_num_pag(), true);
                        std::cout << "Special edition price: " << softcover.get_price() << std::endl;
                    }
                    else{
                        softcover.calc_price(0, inventory.bookS[id_libro - 1].get_num_pag(), false);
                        std::cout << "Price: " << softcover.get_price() << std::endl;
                    }
                }
                else if(optionnn == 2){
                    inventory.showHard();
                    std::cout << "Type the ID number of the book: " << std::endl;
                    std::cin >> id_libro;
                    std::cout << "Would you like your book to be special edition? (Yes or No): " << std::endl;
                    std::cin >> tof;
                    if (tof == "Yes"){
                        hardcover.calc_price(0, inventory.bookH[id_libro - 1].get_num_pag(), true);
                        std::cout << "Special edition price: " << hardcover.get_price() << std::endl;
                    }
                    else{   
                        hardcover.calc_price(0, inventory.bookH[id_libro - 1].get_num_pag(), false);
                        std::cout << "Price: " << hardcover.get_price() << std::endl;
                    }
                }
                else if(optionnn == 3){
                    inventory.showDigital();
                    std::cout << "Type the ID number of the book: " << std::endl;
                    std::cin >> id_libro;
                    std::cout << "Would you like your book to be an audiobook? (Yes or No): " << std::endl;
                    std::cin >> tof;
                    if(tof == "Yes"){
                        digital.calc_price(0, inventory.bookD[id_libro - 1].get_num_pag(), true);
                        std::cout << "Audiobook price: " << digital.get_price() << std::endl;
                    }
                    else{
                        digital.calc_price(0, inventory.bookD[id_libro - 1].get_num_pag(), false);
                        std::cout << "Price: " << digital.get_price() << std::endl;
                    }
                }
                // opcion para regresar al menu principal
                else if(optionnn == 4){
                    break;
                }
            }
            // opcion para salir del programa
            break;
        }
    }
    // termina el programa
    return 0;
}