#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int pages;
    int year;

public:

    Book(std::string t, std::string a, int p, int y) : title(t), author(a), pages(p), year(y) {}


    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getPages() const { return pages; }
    int getYear() const { return year; }


    void display() const {
        std::cout << "Назва: " << title << ", Автор: " << author
                  << ", Кількість сторінок: " << pages << ", Рік видання: " << year << std::endl;
    }
};


std::vector<Book> loadCatalog(const std::string &filename) {
    std::vector<Book> catalog;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string title, author;
        int pages, year;
        while (file >> title >> author >> pages >> year) {
            catalog.push_back(Book(title, author, pages, year));
        }
        file.close();
    } else {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
    }

    return catalog;
}


void searchByAuthor(const std::vector<Book> &catalog, const std::string &author) {
    for (const auto &book : catalog) {
        if (book.getAuthor() == author) {
            book.display();
        }
    }
}


void searchByTitle(const std::vector<Book> &catalog, const std::string &title) {
    for (const auto &book : catalog) {
        if (book.getTitle() == title) {
            book.display();
        }
    }
}

int main() {
    std::vector<Book> catalog = loadCatalog("/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework15/catalog.txt");

    std::string author, title;
    std::cout << "Введіть ім'я автора для пошуку: ";
    std::cin >> author;
    searchByAuthor(catalog, author);

    std::cout << "Введіть назву книги для пошуку: ";
    std::cin >> title;
    searchByTitle(catalog, title);

    return 0;
}
