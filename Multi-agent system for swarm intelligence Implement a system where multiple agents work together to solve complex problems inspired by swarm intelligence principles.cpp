#include <iostream>
#include <vector>
#include <random>

// Agent class
class Agent {
public:
    Agent(double x, double y) : positionX(x), positionY(y) {}

    void update(const std::vector<Agent>& agents) {
        // Update the agent's position and behavior based on the positions of other agents
        // Modify this function to fit your specific swarm intelligence algorithm

        // Example: Random movement
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-1.0, 1.0);

        double randomX = dis(gen);
        double randomY = dis(gen);

        positionX += randomX;
        positionY += randomY;
    }

    double getPositionX() const {
        return positionX;
    }

    double getPositionY() const {
        return positionY;
    }

private:
    double positionX;
    double positionY;
};

// Multi-Agent System class
class MultiAgentSystem {
public:
    MultiAgentSystem(int numAgents) : numAgents(numAgents) {
        // Initialize the agents
        for (int i = 0; i < numAgents; i++) {
            double x = getRandomPosition();
            double y = getRandomPosition();
            agents.push_back(Agent(x, y));
        }
    }

    void update() {
        // Update the multi-agent system
        for (auto& agent : agents) {
            agent.update(agents);
        }
    }

    void printAgentPositions() const {
        // Print the positions of all agents
        for (const auto& agent : agents) {
            std::cout << "Agent position: (" << agent.getPositionX() << ", " << agent.getPositionY() << ")" << std::endl;
        }
    }

private:
    double getRandomPosition() {
        // Generate a random position within a certain range
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-10.0, 10.0);
        return dis(gen);
    }

    int numAgents;
    std::vector<Agent> agents;
};

int main() {
    // Create a multi-agent system with 5 agents
    MultiAgentSystem system(5);

    // Update the multi-agent system for 10 iterations
    for (int i = 0; i < 10; i++) {
        std::cout << "Iteration " << i + 1 << ":" << std::endl;
        system.update();
        system.printAgentPositions();
        std::cout << std::endl;
    }

    return 0;
}
