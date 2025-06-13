#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

// Class Template Package<T>
template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        std::cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Full Specialization for std::string
template<>
class Package<std::string> {
private:
    std::string item;
public:
    Package(std::string i) : item(i) {}
    void label() {
        std::cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial Specialization for Pointer Types
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        std::cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

// Class Template Box<T, int Size>
template<typename T, int Size>
class Box {
private:
    std::array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            std::cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
        std::cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            std::cout << " - " << items[i] << "\n";
        }
    }
};

// Function Template shipItem<T>
template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

// Specialization for double (temperature-controlled items)
template<>
void shipItem(const double& item) {
    std::cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

// Main function demonstrating the system
int main() {
    // Demonstrating Package class with different types
    Package<int> intPackage(42);
    intPackage.label();

    Package<std::string> stringPackage("C++ Primer");
    stringPackage.label();

    double temperature = 22.5;
    Package<double*> pointerPackage(&temperature);
    pointerPackage.label();

    // Demonstrating Box class
    Box<std::string, 3> bookBox;
    bookBox.addItem("The Pragmatic Programmer");
    bookBox.addItem("Clean Code");
    bookBox.printItems();

    // Demonstrating shipItem function template
    shipItem(10);
    shipItem(std::string("Smart Package"));
    shipItem(22.5);

    return 0;
}
