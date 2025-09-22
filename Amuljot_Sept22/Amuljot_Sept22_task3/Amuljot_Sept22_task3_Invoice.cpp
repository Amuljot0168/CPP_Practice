#include <iostream>
#include <string>
#include "Amuljot_Sept22_task3_Invoice.h"

Invoice::Invoice(std::string number,
                 std::string description,
                 int p_quantity,
                 int p_price) : part_number(number), part_description(description)
{
    // Using setter function to initialize value and validate also
    setQuantity(p_quantity);
    setPrice(p_price);
}

// Getters
std::string Invoice::getPartNumber() const
{
    return part_number; // return part number of hardware
}

std::string Invoice::getPartDescription() const
{
    return part_description; // return part description
}

int Invoice::getQuantity() const
{
    return quantity; // return  quantity of part
}

int Invoice::getPrice() const
{
    return price; // return price per item
}

// Setters Function
void Invoice::setPartNumber(const std::string &number)
{
    part_number = number; // set part_number
}

void Invoice::setPartDescription(const std::string &description)
{
    part_description = description; // set description of part
}

void Invoice::setQuantity(int qty)
{
    // Validating quantity
    if (qty < 0)
    {
        std::cout << "Warning: Quantity cannot be negative. Setting default value 0." << std::endl;

        quantity = 0; // set quantity as 0 when given qty is negative
    }
    else
    {
        quantity = qty; // set quantity when qty is positive
    }
}

void Invoice::setPrice(int pricePerItem)
{
    if (pricePerItem < 0)
    {
        std::cout << "Warning: price cannot be negative. Setting default value 0." << std::endl;

        price = 0; // set price equal to 0 when priceperitem is negative
    }
    else
    {
        price = pricePerItem; // set price when priceperitem is psoitive
    }
}

// Memeber function

// Invoice calculation
int Invoice::getInvoiceAmount() const
{
    return quantity * price; // return Invoice amount by calculating quantity and price per item
}
