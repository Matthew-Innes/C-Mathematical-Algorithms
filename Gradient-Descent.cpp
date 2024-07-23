#include <iostream>
#include <cmath>

// Define the function we want to minimize
double f(double x) {
    return (x - 3) * (x - 3); // Example: f(x) = (x - 3)^2
}

// Define the gradient (derivative) of the function
double f_prime(double x) {
    return 2 * (x - 3); // Derivative: f'(x) = 2 * (x - 3)
}

// Gradient Descent algorithm implementation
double gradientDescent(double initial_guess, double learning_rate, double tolerance, int max_iterations) {
    double x = initial_guess;
    for (int i = 0; i < max_iterations; ++i) {
        double gradient = f_prime(x);
        double x_new = x - learning_rate * gradient;
        
        if (std::abs(x_new - x) < tolerance) {
            std::cout << "Minimum found at x = " << x_new << " after " << i + 1 << " iterations." << std::endl;
            return x_new;
        }
        
        x = x_new;
    }
    std::cerr << "Max iterations reached, minimum not found within tolerance." << std::endl;
    return x;
}

int main() {
    double initial_guess = 0.0;  // Starting point for Gradient Descent
    double learning_rate = 0.1;  // Learning rate
    double tolerance = 1e-7;     // Tolerance for convergence
    int max_iterations = 1000;   // Maximum number of iterations
    
    double minimum = gradientDescent(initial_guess, learning_rate, tolerance, max_iterations);
    
    std::cout << "Approximate minimum: " << minimum << std::endl;
    
    return 0;
}
