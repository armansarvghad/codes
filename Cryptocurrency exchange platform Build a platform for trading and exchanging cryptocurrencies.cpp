#include <iostream>
#include <unordered_map>
#include <vector>

// Structure to represent a cryptocurrency order
struct Order {
    std::string traderId;
    std::string symbol;
    double price;
    double quantity;
};

// Function to match buy and sell orders
void matchOrders(const std::vector<Order>& buyOrders, const std::vector<Order>& sellOrders) {
    std::unordered_map<std::string, double> symbolPrices;

    // Match buy and sell orders for each symbol
    for (const Order& buyOrder : buyOrders) {
        for (const Order& sellOrder : sellOrders) {
            if (buyOrder.symbol == sellOrder.symbol && buyOrder.price >= sellOrder.price) {
                // Execute the trade
                double tradePrice = sellOrder.price;
                double tradeQuantity = std::min(buyOrder.quantity, sellOrder.quantity);

                // Update the symbol price
                symbolPrices[buyOrder.symbol] = tradePrice;

                // Print the trade details
                std::cout << "Trade: "
                          << "Symbol: " << buyOrder.symbol << ", "
                          << "Buyer: " << buyOrder.traderId << ", "
                          << "Seller: " << sellOrder.traderId << ", "
                          << "Price: " << tradePrice << ", "
                          << "Quantity: " << tradeQuantity << std::endl;

                // Update the remaining quantities
                buyOrder.quantity -= tradeQuantity;
                sellOrder.quantity -= tradeQuantity;

                // Remove fully filled orders
                if (buyOrder.quantity == 0) {
                    break;
                }
            }
        }
    }

    // Print the current symbol prices
    std::cout << "Symbol Prices:" << std::endl;
    for (const auto& symbolPrice : symbolPrices) {
        std::cout << symbolPrice.first << ": " << symbolPrice.second << std::endl;
    }
}

int main() {
    // Sample buy and sell orders
    std::vector<Order> buyOrders = {
        {"buyer1", "BTC", 50000.0, 2.0},
        {"buyer2", "BTC", 48000.0, 1.5},
        {"buyer3", "ETH", 3000.0, 5.0},
        {"buyer4", "ETH", 3200.0, 3.0}
    };

    std::vector<Order> sellOrders = {
        {"seller1", "BTC", 49000.0, 1.0},
        {"seller2", "BTC", 51000.0, 2.5},
        {"seller3", "ETH", 3300.0, 2.0},
        {"seller4", "ETH", 2800.0, 4.0}
    };

    // Match the orders
    matchOrders(buyOrders, sellOrders);

    return 0;
}