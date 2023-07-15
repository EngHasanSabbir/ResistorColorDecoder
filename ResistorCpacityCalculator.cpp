#include <bits/stdc++.h>
#include <map>
#include <string>

// Function to calculate the capacity of a resistor based on color code
std::pair<double, double> calculateCapacity(const std::string& color1, const std::string& color2, const std::string& color3, const std::string& color4)
{
    // Define the color code map
    std::map<std::string, int> colorCode = {
        {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4},
        {"green", 5}, {"blue", 6}, {"violet", 7}, {"gray", 8}, {"white", 9},
        {"golden", -5}, {"silver", -10}
    };

    // Get the values for each color band
    int digit1 = colorCode[color1];
    int digit2 = colorCode[color2];
    int multiplier = colorCode[color3];
    double tolerance = colorCode[color4];

    // Calculate the capacity
    double capacity = (digit1 * 10 + digit2) * pow(10, multiplier);

    // Calculate lower and upper limits
    double lowerLimit = capacity - (capacity * tolerance / 100);
    double upperLimit = capacity + (capacity * tolerance / 100);

    return std::make_pair(lowerLimit, upperLimit);
}

int main()
{
    std::string color1, color2, color3, color4;

    // Input the colors of the resistor bands
    std::cout << "Enter the color of the first band: ";
    std::cin >> color1;

    std::cout << "Enter the color of the second band: ";
    std::cin >> color2;

    std::cout << "Enter the color of the third band: ";
    std::cin >> color3;

    std::cout << "Enter the color of the fourth band (tolerance): ";
    std::cin >> color4;

    // Calculate and display the capacity range
    std::pair<double, double> capacityRange = calculateCapacity(color1, color2, color3, color4);
    std::cout << "The capacity range of the resistor is: " << capacityRange.first << " ohms to " << capacityRange.second << " ohms." << std::endl;

    return 0;
}
