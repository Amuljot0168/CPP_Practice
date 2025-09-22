#include <iostream>
#include "Amuljot_Sept22_task3_Invoice.h"

int main()
{
    //  Dynamically allocating Invoice objects
    Invoice *item1 = new Invoice("A123", "MotherBoard", 5, 1000);
    Invoice *item2 = new Invoice("B456", "Wires", -3, 200); // Invalid quantity will be set to 0

    // Display initial details and invoice amounts
    std::cout << "Item 1: " << item1->getPartNumber()
              << " | " << item1->getPartDescription()
              << " | Quantity: " << item1->getQuantity()
              << " | Price per item: $" << item1->getPrice()
              << " | Total: $" << item1->getInvoiceAmount() << std::endl;

    std::cout << "Item 2: " << item2->getPartNumber()
              << " | " << item2->getPartDescription()
              << " | Quantity: " << item2->getQuantity()
              << " | Price per item: $" << item2->getPrice()
              << " | Total: $" << item2->getInvoiceAmount() << std::endl;

    //  Update item2 with valid quantity and price
    item2->setQuantity(4);
    item2->setPrice(250);

    // Update part number and description
    item2->setPartNumber("B789");
    item2->setPartDescription("Copper Wires");

    //  Display updated item2 details
    std::cout << "Updated Item 2: " << item2->getPartNumber()
              << " | " << item2->getPartDescription()
              << " | Quantity: " << item2->getQuantity()
              << " | Price per item: $" << item2->getPrice()
              << " | Total: $" << item2->getInvoiceAmount() << std::endl;

    // Free up dynamically allocated memory
    delete item1;
    delete item2;

    return 0;
}