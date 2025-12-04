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
    Inventory inventory;
    inventory.createSoftlist();
    inventory.createHardlist();
    inventory.createDigitallist();
    Softcover softcover;
    Hardcover hardcover;
    Digital digital;
    
    std::string nameb;
    int num_pages = 0;
    int id_libro = 0;
    int option = 0;
    int optionn = 0;
    int optionnn = 0;
    std::string tof;

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
                std::cout << "Name of the book (Use '_' for spaces): " << std::endl;
                std::cin >> nameb;
                std::cout << "Number of pages: " << std::endl;
                std::cin >> num_pages;
                inventory.addBook(optionn, nameb, num_pages);
            }
            break;
        case 5:
            optionnn = 0;
            while (optionnn != 4){
                std::cout << "1. List of Softcover books for price" << std::endl;
                std::cout << "2. List of Hardcover books for price" << std::endl;
                std::cout << "3. List of Digital books for price" << std::endl;
                std::cout << "4. Back to main menu" << std::endl;
                std::cin >> optionnn;
                if(optionnn == 1){
                    inventory.showSoft();
                    std::cout << "Type the ID number of the book: " << std::endl;
                    std::cin >> id_libro;
                    std::cout << "Would you like your book to be special edition? (Yes or No): " << std::endl;
                    std::cin >> tof;
                    if (tof == "Yes"){
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
                else if(optionnn == 4){
                    break;
                }
            }
            break;
        }
    }
    return 0;
}