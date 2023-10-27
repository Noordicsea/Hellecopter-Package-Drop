#include <iostream>
#include <cmath>
#include <thread> // Required for sleep functionality
#include <chrono> // Required for specifying time duration

int main() {
    char continueChoice = 'y';

    // Constants
    const double g = 9.81;

    while (continueChoice == 'y') {
        // Clear the console (works for most environments)
        system("cls");

        // Ask for variables
        double a, initialTime;
        std::cout << "------------------------------------------\n";
        std::cout << "Helicopter Mailbag Fall Time Calculator\n";
        std::cout << "------------------------------------------\n\n";
        std::cout << "Enter the coefficient for t^3 (e.g., 3.30 for h = 3.30t^3): ";
        std::cin >> a;
        std::cout << "Enter the time when mailbag is released (in seconds): ";
        std::cin >> initialTime;

        // Calculate the velocity at the given time
        double initialVelocity = 3 * a * std::pow(initialTime, 2);

        // Displaying the calculation and sleeping
        std::cout << "\nCalculating initial velocity using formula: 3 * a * time^2...";
        std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep for 2 seconds

        // Use the quadratic formula
        double a_quadratic = 0.5 * g;
        double b_quadratic = -initialVelocity;
        double c_quadratic = -a * std::pow(initialTime, 3);  // This is the initial height, but negated for our equation.

        // Showing the equation set up
        std::cout << "\nSetting up the quadratic equation to solve for time...";
        std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep for 2 seconds

        double discriminant = std::pow(b_quadratic, 2) - 4 * a_quadratic * c_quadratic;

        // Calculating the discriminant
        std::cout << "\nCalculating the discriminant...";
        std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep for 2 seconds

        // Find the positive root
        double totalTime = (-b_quadratic + std::sqrt(discriminant)) / (2 * a_quadratic);

        std::cout << "\nSolving the equation for the total time...";
        std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep for 2 seconds

        std::cout << "\nThe mailbag reaches the ground after " << totalTime << " seconds of its release.\n";

        // Ask if the user wants to solve another problem
        std::cout << "\nWould you like to solve another problem? (y/n): ";
        std::cin >> continueChoice;
    }

    return 0;
}
