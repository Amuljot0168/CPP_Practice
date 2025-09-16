// LaneBoundary Detection in ADAS

#include <iostream>

// Lane Boundary class
class LaneBoundary
{
    // Data members of class LaneBoundary
private:
    float curvature;
    int lane_id;

public:
    // Constructor of class LaneBoundary to initialize members
    LaneBoundary(float curvatureValue, int lane_id)
    {
        if (curvature < 0.0f || lane_id <= 0)
        {
            throw std::invalid_argument("Invalid curvature or lane identifier.");
        }
        this->curvature = curvature;
        this->lane_id = lane_id;
    }

    // const Getters function to access data members

    float getCurvature() const
    {
        return curvature; // return object curvature value
    }

    int getLaneID() const
    {
        return lane_id; // return object lane id
    }

    // Function to compare curvature of objects
    bool compareCurvature(const LaneBoundary &other) const
    {
        if (this->curvature > other.curvature)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Const function to display lane details
    void display() const
    {
        std::cout << "Lane Details-> \n";
        std::cout << "Lane Curvature : " << this->curvature << std::endl;
        std::cout << "Lane ID : " << this->lane_id << std::endl;
    }
};

// Global Functions

// function to check lane1 curvature is greater than lane2 curvature
bool isCurvatureGreater(const LaneBoundary &lane1, const LaneBoundary &lane2)
{
    if (lane1.getCurvature() > lane2.getCurvature())
    {
        return true; // returns true if lane1 curvature is greater
    }
    else
    {
        return false; // returns false if lane2 curvature is greater or equal
    }
}

// Function to do comparison between lanes and print the comparisons
void printLaneComparison(const LaneBoundary &lane1, const LaneBoundary &lane2)
{
    if (lane1.getCurvature() == lane2.getCurvature())
    {
        // print equal if curvatures of both lanes are equal
        std::cout << "Lane1 curvature is equal to Lane2 curvature. " << std::endl;
    }
    else if (lane1.getCurvature() > lane2.getCurvature())
    {
        // print Lane1 is greater
        std::cout << "Lane1 has greater curvature than Lane2" << std::endl;
    }
    else
    {
        // print Lane2 is greater
        std::cout << "Lane2 has greater curvature than Lane1" << std::endl;
    }
}
int main()
{
    // Dynamically creating objects
    LaneBoundary *Lane1 = new LaneBoundary(0.015, 1);
    LaneBoundary *Lane2 = new LaneBoundary(0.023, 2);

    // Calling member functions
    std::cout << "\nMemeber function Output: " << std::endl;
    if (Lane1->compareCurvature(*Lane2))
    {
        std::cout << "Lane1 is greater." << std::endl;
    }
    else
    {
        std::cout << "Lane 2 is greater." << std::endl;
    }

    std::cout << std::endl;
    // Calling global functions
    std::cout << "Global Function outputs " << std::endl;
    if (isCurvatureGreater(*Lane1, *Lane2))
    {
        std::cout << "Yes " << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Comparison between Lane1 and Lane2: " << std::endl;
    printLaneComparison(*Lane1, *Lane2);

    std::cout << std::endl;

    // dislpay the details of both lanes
    Lane1->display();
    Lane2->display();

    // Free Dynamic memory
    delete Lane1;
    delete Lane2;

    return 0;
}
