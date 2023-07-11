#include <iostream>
#include <vector>
#include <algorithm>

struct Record {
    int id;
    std::string name;
    int age;
};

std::vector<Record> database;

// Function to insert a record into the database
void insertRecord(int id, const std::string& name, int age) {
    database.push_back({id, name, age});
}

// Function to select records from the database based on a condition
std::vector<Record> selectRecords(const std::string& condition) {
    std::vector<Record> result;

    if (condition.empty()) {
        return database;
    }

    // Sample condition: age > 30
    for (const auto& record : database) {
        if (record.age > 30) {
            result.push_back(record);
        }
    }

    return result;
}

int main() {
    insertRecord(1, "John", 25);
    insertRecord(2, "Alice", 35);
    insertRecord(3, "Bob", 45);

    std::vector<Record> selectedRecords = selectRecords("age > 30");

    for (const auto& record : selectedRecords) {
        std::cout << "ID: " << record.id << ", Name: " << record.name << ", Age: " << record.age << std::endl;
    }

    return 0;
}
