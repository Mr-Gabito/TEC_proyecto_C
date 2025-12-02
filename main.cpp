#include <iostream>
#include "libro.h"
#include "inventario.h"

void menu(){
        std::cout << "Menu" << std::endl;
        std::cout << "1. List of Softcover books" << std::endl;
        std::cout << "2. List of Hardcover books" << std::endl;
        std::cout << "3. List of Digital books" << std::endl;
        std::cout << "4. Add a book" << std::endl;
        std::cout << "5. Check book price" << std::endl;
        std::cout << "6. Exit" << std::endl;
    };

int main(){
    //try to make the menu appear like an animation (maybe typewriter)
    //https://www.youtube.com/watch?v=dZ48fEXUEnk
    Inventory inventory;
    inventory.createSoftlist();
    inventory.createHardlist();
    inventory.createDigitallist();
    
    std::string nameb;
    int num_pages = 0;
    int option = 0;
    int optionn = 0;

    while(option != 6){
        menu();
        std::cin >> option;
        switch(option){
            case 1:
            inventory.showSoft();
            break;
            case 2:
            inventory.showHard();
            break;
            case 3:
            inventory.showDigital();
            break;
            case 4:
            while (optionn != 4){
                std::cout << "1. Softcover book:" << std::endl;
                std::cout << "2. Hardcover book:" << std::endl;
                std::cout << "3. Digital book:" << std::endl;
                std::cout << "4. Back" << std::endl;
                std::cin >> optionn;
                if(optionn == 4){
                    break;
                }
                std::cout << "Name of the book: " << std::endl;
                std::cin >> nameb;
                std::cout << "Number of pages: " << std::endl;
                std::cin >> num_pages;
                inventory.addBook(optionn, nameb, num_pages);
            }
            //case 5:
            //take price off the lists that show and try to see if you can calculate the price correctly and as you intended
            break;
        }
    }
};