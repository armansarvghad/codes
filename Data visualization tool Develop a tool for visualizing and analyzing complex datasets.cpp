#include <iostream>
#include <fstream>
#include <vector>

// Function to generate a data file for visualization
void generateDataFile(const std::vector<double>& x, const std::vector<double>& y, const std::string& filename) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (size_t i = 0; i < x.size(); i++) {
            file << x[i] << " " << y[i] << std::endl;
        }

        file.close();
    } else {
        std::cout << "Error: Failed to open the file." << std::endl;
    }
}

// Function to visualize data using gnuplot
void visualizeData(const std::string& dataFile) {
    std::string gnuplotCommand = "gnuplot -persist -e \"plot \'" + dataFile + "\' with lines\"";

    std::system(gnuplotCommand.c_str());
}

int main() {
    // Sample data
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {1.0, 4.0, 9.0, 16.0, 25.0};

    // Generate a data file
    generateDataFile(x, y, "data.txt");

    // Visualize the data
    visualizeData("data.txt");

    return 0;
}
