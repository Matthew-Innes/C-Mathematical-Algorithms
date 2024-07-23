#include <iostream>
#include <cmath>

// Define the function for which we want to find the root
double f(double x) {
    return x * x - 2; // Example: f(x) = x^2 - 2 (Root at sqrt(2))
}

// Define the derivative of the function
double f_prime(double x) {
    return 2 * x; // Derivative of f(x) = x^2 - 2 is f'(x) = 2x
}

// Newton-Raphson method implementation
double newtonRaphson(double initial_guess, double tolerance, int max_iterations) {
    double x = initial_guess;
    for (int i = 0; i < max_iterations; ++i) {
        double fx = f(x);
        double fpx = f_prime(x);
        
        if (std::abs(fpx) < tolerance) {
            std::cerr << "Derivative too small, stopping iteration." << std::endl;
            break;
        }

        double x_new = x - fx / fpx;
        
        if (std::abs(x_new - x) < tolerance) {
            std::cout << "Root found at x = " << x_new << " after " << i + 1 << " iterations." << std::endl;
            return x_new;
        }

        x = x_new;
    }
    std::cerr << "Max iterations reached, no root found." << std::endl;
    return x;
}

int main() {
    double initial_guess = 1.0; // Starting point for Newton-Raphson
    double tolerance = 1e-7;    // Tolerance for convergence
    int max_iterations = 100;   // Maximum number of iterations
    
    double root = newtonRaphson(initial_guess, tolerance, max_iterations);
    
    std::cout << "Approximate root: " << root << std::endl;
    
    return 0;
}