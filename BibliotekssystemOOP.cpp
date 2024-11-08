#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class Item {
protected:
    string title, author;
    int year;
public:
    Item(const string& title, const string& author, int year) : title(title), author(author), year(year) {}
    virtual ~Item() = default;
    virtual void display_info() const = 0;
    string getTitle() const { return title; }
};

class Book : public Item {
    int pages;
public:
    Book(const string& title, const string& author, int year, int pages) : Item(title, author, year), pages(pages) {}
    void display_info() const override {
        cout << "Book: " << title << ", by " << author << ", Year: " << year << ", Pages: " << pages <<endl;
    }
};

class Magazine : public Item {
    int issue;
public:
    Magazine(const string& title, const string& author, int year, int issue) : Item(title, author, year), issue(issue) {}
    void display_info() const override {
        cout << "Magazine: " << title << ", by " << author << ", Year: " << year << ", Issue: " << issue <<endl;
    }
};

class LibraryUser {
    string name;
    vector<shared_ptr<Item>> borrowed_items;
public:
    LibraryUser(const string& name) : name(name) {}
    void borrow(const shared_ptr<Item>& item) {
        borrowed_items.push_back(item);
        cout << name << " borrowed " << item->getTitle() <<endl;
    }
    void return_item(const shared_ptr<Item>& item) {
        borrowed_items.erase(remove(borrowed_items.begin(), borrowed_items.end(), item), borrowed_items.end());
        cout << name << " returned " << item->getTitle() <<endl;
    }
    void list_borrowed_items() const {
        cout << name << " has borrowed the following items: "<<endl;
        for (const auto& item : borrowed_items) item->display_info();
    }
};

class Library {
    vector<shared_ptr<Item>> items;
    vector<shared_ptr<LibraryUser>> users;
public:
    void add_item(const shared_ptr<Item>& item) { items.push_back(item); }
    void register_user(const shared_ptr<LibraryUser>& user) { users.push_back(user); }
    void borrow_item(const shared_ptr<LibraryUser>& user, const shared_ptr<Item>& item) {
        if (auto it = find(items.begin(), items.end(), item); it != items.end()) {
            items.erase(it);
            user->borrow(item);
        } else {
            cout << item->getTitle() << " is not available in the library"<<endl;
        }
    }
    void return_item(const shared_ptr<LibraryUser>& user, const shared_ptr<Item>& item) {
        user->return_item(item);
        items.push_back(item);
    }
    void list_items() const {
        cout << "Library has the following items: "<<endl;
        for (const auto& item : items) item->display_info();
    }
};

int main() {
    Library library;
    auto book1 = make_shared<Book>("Zlatan: Jag är Zlatan", "David Lagercrantz", 2011, 283);
    auto book2 = make_shared<Book>("Monsters inc", "Disney", 2001, 10);
    auto magazine1 = make_shared<Magazine>("National Geographic", "NGS", 1888, 1);

    library.add_item(book1);
    library.add_item(book2);
    library.add_item(magazine1);
    cout <<endl;

    auto user1 = make_shared<LibraryUser>("Ilir");
    library.register_user(user1);
    
    library.borrow_item(user1, book1);
    library.borrow_item(user1, book2);
    library.borrow_item(user1, magazine1);
    cout <<endl;
    
    user1->list_borrowed_items();
    cout <<endl;

    library.return_item(user1, book1);
    library.return_item(user1, book2);
    cout <<endl;
    
    library.list_items();

    return 0;
}
