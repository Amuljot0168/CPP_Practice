// Question 5: Smart Parcel Weight Analyzer

#include <iostream>
#include <string>

class ParcelAnalyzer
{
public:
    //  function to classify weight in grams
    std::string classifyWeight(int grams)
    {
        if (grams < 500)
        {
            return "Light";
        }
        else if (grams > 500 && grams <= 2000)
        {
            return "Medium";
        }
        else
        {
            return "Heavy";
        }
    }

    // Overloaded function to classify weight in kilograms
    std::string classifyWeight(float kilograms)
    {
        if (kilograms < 0.5)
        {
            return "Light";
        }
        else if (kilograms > 0.5 && kilograms <= 2.0)
        {
            return "Medium";
        }
        else
        {
            return "Heavy";
        }
    }

    // Overloaded function to classify weight in pounds
    std::string classifyWeight(double pounds)
    {
        if (pounds < 1.1)
        {
            return "Light";
        }
        else if (pounds > 1.1 && pounds <= 4.4)
        {
            return "Medium";
        }
        else
        {
            return "Heavy";
        }
    }
};

// Global Functions
// Print classifications of weights
void printClassification(const std::string &label)
{
    std::cout << "Classification: " << label;
}

int main()
{
    ParcelAnalyzer analyzer;

    // Grams
    printClassification(analyzer.classifyWeight(450));  // Light
    printClassification(analyzer.classifyWeight(1500)); // Medium
    printClassification(analyzer.classifyWeight(2500)); // Heavy

    // Kilograms
    printClassification(analyzer.classifyWeight(0.3f)); // Light
    printClassification(analyzer.classifyWeight(1.5f)); // Medium
    printClassification(analyzer.classifyWeight(3.0f)); // Heavy

    // Pounds
    printClassification(analyzer.classifyWeight(0.9)); // Light
    printClassification(analyzer.classifyWeight(2.5)); // Medium
    printClassification(analyzer.classifyWeight(5.0)); // Heavy
    return 0;
}