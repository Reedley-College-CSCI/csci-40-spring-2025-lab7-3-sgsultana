#include <iostream>
#include <fstream>
using namespace std;

// TODO: Step 1 - Define the struct TemperatureRecord
// It should contain two integer fields: day and temperature.
// updated struct comment for TemperatureRecord
struct TemperatureRecord {
    int day;
    int temperature;
};

// Constants
const int MAX_DAYS = 31;

// Function Prototypes
void readTemperatures(TemperatureRecord arr[], int& size); // TODO: Fix the parameters
void printTemperatures(const TemperatureRecord arr[], int size);
//TemperatureRecord findMin(const ???);
//TemperatureRecord findMax(const ???);
double findAverage(const TemperatureRecord arr[], int size);

int main() {
    // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)
    TemperatureRecord temperatures[MAX_DAYS];  // Static array of structs
    int size = 0;  // Actual number of records read


    // TODO: Step 3 - Call readTemperatures() to load data from file
    readTemperatures(temperatures, size);

    // TODO: Step 4 - Print the temperatures
    cout << "Data Read from File:\n";
    printTemperatures(temperatures, size);

    // TODO: Step 5 - Compute and display min, max, and average temperature
    double averageTemp = findAverage(temperatures, size);
    cout << "Average Temperature: " << averageTemp << "�F" << endl;
    return 0;
}

// TODO: Step 6 - Implement readTemperatures()
// Read from "temps.txt" and store data in the array
// Function to read data from file into array
void readTemperatures(TemperatureRecord arr[], int& size) {
    ifstream inputFile("temps.txt");
    if (!inputFile) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }

    // Read until EOF or maximum days reached
    while (size < MAX_DAYS && inputFile >> arr[size].day >> arr[size].temperature) {
        size++;
    }
    inputFile.close();
}

// TODO: Step 7 - Implement printTemperatures()
// Print all stored temperatures in a formatted table
// Function to print temperatures
void printTemperatures(const TemperatureRecord arr[], int size) {
    cout << "Day  Temp\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i].day << "    " << arr[i].temperature << endl;
    }
}

// TODO: Step 8 - Implement findMin()
// Return the TemperatureRecord with the lowest temperature

// TODO: Step 9 - Implement findMax()
// Return the TemperatureRecord with the highest temperature

// TODO: Step 10 - Implement findAverage()
// Compute and return the average temperature
// Function to calculate average temperature
double findAverage(const TemperatureRecord arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i].temperature;
    }
    return static_cast<double>(sum) / size;
}