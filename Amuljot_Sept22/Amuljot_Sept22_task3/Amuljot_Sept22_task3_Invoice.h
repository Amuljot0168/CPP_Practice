#ifndef INVOICE_H
#define INVOICE_H

#include <string>

// Declaring class Invoice
class Invoice
{
    // Data members
private:
    std::string part_number;      // depicts hardware part number
    std::string part_description; // Description of hardware part
    int quantity;                 // Quantity of hardware parts
    int price;                    // Price of hardware part

public:
    // Parameterised Constructor
    Invoice(std::string number, std::string description, int part_quantity, int part_price);

    //  Getter Functions to access the data members
    std::string getPartNumber() const;      // Function to get Number of hardware part
    std::string getPartDescription() const; // Function to get Description of hardware part
    int getQuantity() const;                // Function to get quantity of hardware parts
    int getPrice() const;                   // Function to get price of hardware part

    // Setter Functions to set the values of data members
    void setPartNumber(const std::string &number);           // Function to Set Part Number of item
    void setPartDescription(const std::string &description); // Function to Set description of hardware part
    void setQuantity(int number);                            // Function to Set quantity of hardware parts
    void setPrice(int newprice);                             // Function to Set price of hardware part

    // Member Functions
    int getInvoiceAmount() const; // return the amount by multiplying quantity with price of each item
};
#endif