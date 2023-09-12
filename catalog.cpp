#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <limits>

# define MAX_BOOKS 1000

struct bookT {
    std::string title; // Book title
    std::vector<std::string> authors; // Book author(s)
    int catalogNum; // LoC catalog number
    std::vector<std::string> subHeadings; // subject headings
    std::string publisher; // publisher 
    int pubYear; // publication year
    bool isCirc; // whether it is circulating
};
struct libraryT {
    std::vector<bookT> books;
    int libSize;
};

libraryT initBooks();
void searchBySubject(libraryT &library, std::string &searcher);

int main() {

    libraryT libdata = initBooks();

    std::cout << "Welcome to the library database. Please select an option from the following.\n";
    std::cout << "1. Add a new Book\n2. Search by subject\n3. Display all books\n";
    std::cout << "Please enter the number of your request:\n";

    int userChoice;
    std::cin >> userChoice;

    std::string usrInput;
    char yn;
    bookT newBK; // for if user wants to make a new book

    switch (userChoice)
    {
    case 1:
        std::cout << "Enter the title of the book: \n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, newBK.title);

        std::cout << "Enter the author(s) of the book. Type 7787 when finished. : \n";
        while (usrInput != "7787") {
            getline(std::cin, usrInput);
            newBK.authors.push_back(usrInput);
        }
        usrInput = "";

        std::cout << "Enter the catalog number: \n";
        std::cin >> newBK.catalogNum;

        std::cout << "Enter subject headings. Type 7787 when finished. : \n";
        while (usrInput != "7787") {
            getline(std::cin, usrInput);
            newBK.subHeadings.push_back(usrInput);
        }
        usrInput = "";

        std::cout << "Enter the publisher: \n";
        getline(std::cin, newBK.publisher);

        std::cout << "Enter the year of publication: \n";
        std::cin >> newBK.pubYear;

        std::cout << "Is this book still in ciculation, Y/N?: \n";
        std::cin >> yn;
        if (yn == 'Y' || yn == 'y') {
            newBK.isCirc = true;
        }
        else if (yn == 'N' || yn == 'n') {
            newBK.isCirc = false;
        }
        else {
            std::cout << "We'll call that a no.\n";
            newBK.isCirc = false;
        }

        libdata.books.push_back(newBK);
        std::cout << "The book '" << newBK.title << "' has been added.\n";
        std::cout << "Further details: \n";
        std::cout << ">> Author: " << newBK.authors[0] << "\n>> Catalog #: " << newBK.catalogNum << "\n>> First subject: " << newBK.subHeadings[0] << "\n";
        break;
    case 2:
        std::cout << "Enter subject string (For example:\n";
        std::cout << "'Siblings--Fiction', 'Politics and government', 'Boys--Fiction', 'Interpersonal relations--Fiction', or 'Science fiction'): \n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, usrInput);
        searchBySubject(libdata, usrInput);
        break;

    case 3:
        for (bookT book : libdata.books) {
            std::cout << "Entry: \n>> " << book.title << ", by ";
            for (std::string author : book.authors) {
                std::cout << author << " ";
            }  
            std::cout << "\n";
        }
        break;
    
    default:
        std::cout << "Unrecognized command. Exiting.";
        exit(1);
    }

    
}

libraryT initBooks() {
    libraryT newLib;

    //Default 1
    bookT bk1;
    bk1.title = "Lord of the Flies";
    bk1.authors.push_back("William Golding");
    bk1.catalogNum = 2016036300;
    bk1.subHeadings.push_back("Survival--Psychological aspects--Fiction");
    bk1.subHeadings.push_back("Regression (Psychology)--Fiction");
    bk1.subHeadings.push_back("Boys--Fiction");
    bk1.publisher = "Penguin Books";
    bk1.pubYear = 2016;
    bk1.isCirc = true;

    //Default 2
    bookT bk2;
    bk2.title = "Flipped";
    bk2.authors.push_back("Wendelin Van Draanen");
    bk2.catalogNum = 2001029238;
    bk2.subHeadings.push_back("Interpersonal relations--Fiction");
    bk2.subHeadings.push_back("Self-perception--Fiction");
    bk2.publisher = "Knopf";
    bk2.pubYear = 2001;
    bk2.isCirc = true;

    //Default 3
    bookT bk3;
    bk3.title = "Legend";
    bk3.authors.push_back("Marie Lu");
    bk3.catalogNum = 2014501950;
    bk3.subHeadings.push_back("Fugitives from justice--Fiction");
    bk3.subHeadings.push_back("Soldiers--Fiction");
    bk3.subHeadings.push_back("Plague--Fiction");
    bk3.subHeadings.push_back("Siblings--Fiction");
    bk3.subHeadings.push_back("Science fiction");
    bk3.publisher = "Speak";
    bk3.pubYear = 2013;
    bk3.isCirc = true;

    //Default 4
    bookT bk4;
    bk4.title = "The Alchemyst: The Secrets of the Immortal Nicholas Flamel";
    bk4.authors.push_back("Michael Scott");
    bk4.catalogNum = 2006024417;
    bk4.subHeadings.push_back("Alchemists--Fiction");
    bk4.subHeadings.push_back("Supernatural--Fiction");
    bk4.subHeadings.push_back("Siblings--Fiction");
    bk4.publisher = "Delacorte Press";
    bk4.pubYear = 2007;
    bk4.isCirc = true;

    //Default 5
    bookT bk5;
    bk5.title = "Long Walk to Freedom: the Autobiography of Nelson Mandela";
    bk5.authors.push_back("Nelson Mandela");
    bk5.catalogNum = 2013498441;
    bk5.subHeadings.push_back("Mandela, Nelson, 1918-2013");
    bk5.subHeadings.push_back("Presidents--South Africa--Biography");
    bk5.subHeadings.push_back("Politics and government");
    bk5.publisher = "Little Brown and Company";
    bk5.pubYear = 2013;
    bk5.isCirc = true;

    newLib.books.push_back(bk1);
    newLib.books.push_back(bk2);
    newLib.books.push_back(bk3);
    newLib.books.push_back(bk4);
    newLib.books.push_back(bk5);

    return newLib;
}

void searchBySubject(libraryT &library, std::string &searcher) {
    std::cout << "Results found: \n";
    for (bookT book : library.books) {
        for (std::string heading : book.subHeadings) {
            if (heading == searcher) {
                std::cout << ">> " << book.title << " ; " << book.authors[0] << " ; " << book.catalogNum << "\n"; 
            }
        }
    }
    std::cout << "Operation complete.\nIf you do not see results above this message, no results were found.\n";

}