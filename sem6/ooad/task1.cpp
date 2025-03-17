#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct Item {
    std::string name;
    int quantity;
    double price;

    Item(const std::string& n, int q, double p)
        : name(n), quantity(q), price(p) {}
};

class ShoppingCart {
private:
    std::vector<Item> items;

public:
    void addItem(const std::string& itemName, double price) {
        items.push_back(Item(itemName, 1, price));
        std::cout << "Added 1 unit of \"" << itemName 
                  << "\" at $" << price << " each.\n";
    }

    void addItem(const std::string& itemName, int quantity, double price) {
        items.push_back(Item(itemName, quantity, price));
        std::cout << "Added " << quantity << " unit(s) of \"" << itemName 
                  << "\" at $" << price << " each.\n";
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item.quantity * item.price;
        }
        return total;
    }
};

class PaymentProcessor {
public:
    void processPayment(double amount) {
        std::cout << "[COD] Payment of $" << amount 
                  << " will be collected on delivery.\n";
    }

    void processPayment(double amount, const std::string& cardNumber) {
        std::cout << "[Credit Card] Processed payment of $" << amount
                  << " using card number \"" << cardNumber << "\".\n";
    }

    void processPayment(double amount, 
                        const std::string& bankName,
                        const std::string& accountNumber) {
        std::cout << "[Net Banking] Processed payment of $" << amount
                  << " via \"" << bankName 
                  << "\" with account number \"" << accountNumber << "\".\n";
    }
};

int main() {
    ShoppingCart cart;
    PaymentProcessor processor;

    std::cout << "Enter commands (type \"exit\" to quit). Examples:\n"
              << "  addItem Phone 800\n"
              << "  addItem 2 Phone 800\n"
              << "  calculateTotal\n"
              << "  processPayment 1200\n"
              << "  processPayment 185 9999-8888-7777-6666\n"
              << "  processPayment 300 XYZ 5555-6666-7777-8888\n\n";

    while (true) {
        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line)) {
            break;
        }

        if (line == "exit") {
            break;
        }

        if (line.empty()) {
            continue;
        }

        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "addItem") {
            std::vector<std::string> tokens;
            std::string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
            if (tokens.size() == 2) {
                std::string itemName = tokens[0];
                double price = std::stod(tokens[1]);
                cart.addItem(itemName, price);
            }
            else if (tokens.size() == 3) {
                int quantity = std::stoi(tokens[0]);
                std::string itemName = tokens[1];
                double price = std::stod(tokens[2]);
                cart.addItem(itemName, quantity, price);
            }
            else {
                std::cout << "Invalid addItem usage. "
                          << "Format:\n  addItem itemName price\n"
                          << "  addItem quantity itemName price\n";
            }
        }
        else if (command == "calculateTotal") {
            double total = cart.calculateTotal();
            std::cout << "Total cost: $" << total << "\n";
        }
        else if (command == "processPayment") {
            std::vector<std::string> tokens;
            std::string token;
            while (iss >> token) {
                tokens.push_back(token);
            }
            if (tokens.size() == 1) {
                double amount = std::stod(tokens[0]);
                processor.processPayment(amount);
            }
            else if (tokens.size() == 2) {
                double amount = std::stod(tokens[0]);
                std::string cardNumber = tokens[1];
                processor.processPayment(amount, cardNumber);
            }
            else if (tokens.size() == 3) {
                double amount = std::stod(tokens[0]);
                std::string bankName = tokens[1];
                std::string accountNumber = tokens[2];
                processor.processPayment(amount, bankName, accountNumber);
            }
            else {
                std::cout << "Invalid processPayment usage.\n"
                          << "Examples:\n"
                          << "  processPayment 1200\n"
                          << "  processPayment 185 9999-8888-7777-6666\n"
                          << "  processPayment 300 XYZ 5555-6666-7777-8888\n";
            }
        }
        else {
            std::cout << "Unknown command: " << command << "\n";
        }
    }

    std::cout << "Exiting...\n";
    return 0;
}
