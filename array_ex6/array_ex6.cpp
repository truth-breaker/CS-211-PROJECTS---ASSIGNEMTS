/****************************************************************************************
Dennise Arenas
CS 211-Spring
1/27/2022
Array Exercise 6

This program will generate 10  random numbers from 1-100. As well
asking users key if it exists within the array(generated #'s).
Outputs: if key exists or not and average of the 10 random numbers.
**************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> // Added to ensure srand is working properly
using namespace std;

// Prototypes
void fillArray(int ar[], int size);
bool findFunction(const int ar[], int size, int userskey);
void display(const int ar[], int size, int userskey);
void average(const int ar[], int size);

int main() {
    int key;
    srand(time(0));  // Seed the random number generator
    
    const int SIZE = 10;
    int ar[SIZE];

    // Fill the array with random numbers
    fillArray(ar, SIZE);

    cout << "\nEnter the number you are looking for: ";
    cin >> key;

    // Call find function display "found" or "not found"
    display(ar, SIZE, key);

    // Call Avg function
    average(ar, SIZE);

    return 0;
}

// Function to generate 10 random numbers from 1-100
void fillArray(int ar[], int size) {
    for (int i = 0; i < size; i++) {
        ar[i] = rand() % 100 + 1;  // Generates a number from 1 to 100
        cout << right << setw(4) << ar[i] << " ";
    }
    cout << endl;
}

// Function to find if the user's input exists in the 10 generated numbers
bool findFunction(const int ar[], int size, int userskey) {
    for (int i = 0; i < size; i++) {
        if (ar[i] == userskey) {
            return true;  // If found, return true
        }
    }
    return false;  // If not found, return false
}

// Function to display whether the key was found or not
void display(const int ar[], int size, int userskey) {
    if (findFunction(ar, size, userskey)) {
        cout << userskey << " was found in the array.\n";
    } else {
        cout << userskey << " was not found in the array.\n";
    }
}

// Function to calculate and print the sum and average of the array
void average(const int ar[], int size) {
    double sum = 0;

    // Calculate the sum of the array elements
    for (int i = 0; i < size; i++) {
        sum += ar[i];
    }

    // Print the sum of the numbers
    cout << "Sum of the numbers: " << sum << endl;

    // Calculate the average
    double avg = sum / size;

    // Set output format for decimal precision
    cout << fixed << showpoint << setprecision(2);

    // Print the average of the numbers in the array
    cout << "The average of the numbers in the array is " << avg << endl;
}
