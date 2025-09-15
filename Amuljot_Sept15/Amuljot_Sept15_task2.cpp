#include <iostream>
#include <string>

enum Genre
{
    FICTION = 1,
    NONFICTION,
    SCIENCE,
    HISTORY,
    TECHNOLOGY
};

class Book
{
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;
    bool isReferenceOnly;
    std::string title;
    Genre genre;

public:
    // Default constructor overloaded
    Book() : bookID(0), rating(0.0), price(0.0), availabilityStatus('A'), isReferenceOnly(false), title("Untitled"), genre(FICTION) {}

    // Parameterized constructor
    Book(int bookID,
         float rating,
         double price,
         char availabilityStatus,
         bool isReferenceOnly, std::string title,
         Genre genre) : bookID(bookID), rating(rating), price(price), availabilityStatus(availabilityStatus), isReferenceOnly(isReferenceOnly), title(title), genre(genre) {}

    // Getters
    int getBookID() const { return bookID; }
    float getRating() const { return rating; }
    double getPrice() const { return price; }
    char getAvailablityStatus() const { return availabilityStatus; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }
    std::string getTitle() const { return title; }
    Genre getGenre() const { return genre; }

    // Setters
    void setBookID(int bookID) { this->bookID = bookID; }
    void setRating(float rating) { this->rating = rating; }
    void setPrice(double price) { this->price = price; }
    void setAvailablityStatus(char availabilityStatus) { this->availabilityStatus = availabilityStatus; }
    void setIsReferenceOnly(bool isReferenceOnly) { this->isReferenceOnly = isReferenceOnly; }
    void setTitle(std::string title) { this->title = title; }
    void setGenre(Genre genre) { this->genre = genre; }

    // Member function
    void updateAvailability(bool isBorrowed)
    {
        if (isBorrowed)
            availabilityStatus = 'B'; // Borrowed
        else
            availabilityStatus = 'A'; // Available
    }

    // Function to display the details of object
    void displayDetails() const
    {
        std::cout << "Book ID: " << bookID << std::endl;
        std::cout << "Rating: " << rating << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Availability Status: " << availabilityStatus << std::endl;
        std::cout << "Reference Only: " << (isReferenceOnly ? "Yes" : "No") << std::endl;
        std::cout << "Title: " << title << std::endl;

        // Used switch case to print genre in string
        switch (genre)
        {
        case FICTION:
            std::cout << "Genre: FICTION" << std::endl;
            break;
        case NONFICTION:
            std::cout << "Genre: NONFICTION" << std::endl;
            break;
        case SCIENCE:
            std::cout << "Genre: SCIENCE" << std::endl;
            break;
        case HISTORY:
            std::cout << "Genre: HISTORY" << std::endl;
            break;
        case TECHNOLOGY:
            std::cout << "Genre: TECHNOLOGY" << std::endl;
            break;
        }
    }

    // Destructor
    ~Book()
    {
        std::cout << "Book object with ID " << bookID << " destroyed" << std::endl;
    }
};

// Global Functions

// Function to mark book as reference
void markAsReference(Book &book)
{
    // used setIsReferenceOnly function to set the value to true
    book.setIsReferenceOnly(true);

    if (book.getIsReferenceOnly())
        std::cout << "Book " << book.getBookID() << " is marked as reference only!" << std::endl; // If Book is marked then print this
    else
        std::cout << "Book not marked as reference only!" << std::endl; // If not marked then print this
}

// Function to check if Book is affordable or not
bool isAffordable(const Book &book, const double budget)
{
    return book.getPrice() <= budget;
}

// Print the whole book list in formatted form
void printFormattedBookList(const Book books[], const int size)
{
    std::cout << "ID | Title | Price | Rating | Status | Reference | \n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << books[i].getBookID() << " | "
                  << books[i].getTitle() << " | "
                  << books[i].getPrice() << " | "
                  << books[i].getRating() << " | "
                  << books[i].getAvailablityStatus() << " | "
                  << (books[i].getIsReferenceOnly() ? "Yes" : "No") << "\n";
    }
}

int main()
{
    // Dynamically allocates the memory
    Book *books = new Book[3];

    books[0] = Book(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY);
    books[1] = Book(102, 4.8, 499.99, 'A', false, "Clean Code", TECHNOLOGY);
    // books[2] uses default constructor

    int choice = 0;
    int index;

    // Menu Box
    while (choice != 7)
    {
        std::cout << "\nLibrary Menu:\n";
        std::cout << "1. Add Book Details\n";
        std::cout << "2. Mark Book as Reference Only\n";
        std::cout << "3. Check if Book is Affordable\n";
        std::cout << "4. Update Availability\n";
        std::cout << "5. Display Book Details\n";
        std::cout << "6. Display All Books\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter Book index [0-2] : ";
            std::cin >> index;

            // Check the index is valid
            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index!\n";
                break;
            }

            int bookID;
            float rating;
            double price;
            char status;
            bool isReferenceOnly;
            std::string title;
            int genreInput;

            std::cout << "Enter Book ID: ";
            std::cin >> bookID;
            std::cout << "Enter Title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "Enter Rating (0.0 to 5.0): ";
            std::cin >> rating;
            std::cout << "Enter Price: ";
            std::cin >> price;
            std::cout << "Enter Availability Status (A/B): ";
            std::cin >> status;

            if (status != 'A' && status != 'B')
            {
                std::cout << "Invalid status! Choose between A or B.\n";
                break;
            }

            std::cout << "Is Reference Only (1 for Yes, 0 for No): ";
            std::cin >> isReferenceOnly;

            std::cout << "Enter Genre (1-Fiction, 2-Nonfiction, 3-Science, 4-History, 5-Technology): ";
            std::cin >> genreInput;

            if ((rating >= 0.0 && rating <= 5.0) &&
                (price >= 0) &&
                (!title.empty()) &&
                (genreInput >= 1 && genreInput <= 5))
            {
                books[index] = Book(bookID, rating, price, status, isReferenceOnly, title, static_cast<Genre>(genreInput));
                std::cout << "Book Added Successfully!\n";
            }
            break;
        }
        case 2:
        {
            std::cout << "Enter Book index [0-2] : ";
            std::cin >> index;

            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index!\n";
                break;
            }
            // used markAs Reference function
            markAsReference(books[index]);
            break;
        }
        case 3:
        {
            std::cout << "Enter Book index [0-2] : ";
            std::cin >> index;

            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index!\n";
                break;
            }

            double budget;
            std::cout << "Enter the budget: ";
            std::cin >> budget; // Enter the budget

            // Check if affordable or not
            if (isAffordable(books[index], budget))
                std::cout << "Yes, book is affordable!\n";
            else
                std::cout << "Sorry, book is not affordable.\n";

            break;
        }
        case 4:
        {
            std::cout << "Enter Book index [0-2] : ";
            std::cin >> index;

            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index!\n";
                break;
            }

            // Update Avialability according to the user
            bool borrowed;
            std::cout << "Enter 1 if book is Borrowed | Enter 0 if not: ";
            std::cin >> borrowed;

            books[index].updateAvailability(borrowed);
            break;
        }
        case 5:
        {
            std::cout << "Enter Book index [0-2] : ";
            std::cin >> index;

            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index!\n";
                break;
            }

            books[index].displayDetails();
            break;
        }
        case 6:
        {
            // print all book list in formatted form
            printFormattedBookList(books, 3);
            break;
        }
        case 7:
        {
            std::cout << "Exiting the program.....Done!\n";
            break;
        }
        default:
            std::cout << "Invalid Input!\n";
        }
    }

    delete[] books; // free memory
    return 0;
}
