#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Define the problem
double fitnessFunction(const std::vector<double>& solution) {
    // Calculate the fitness value for a given solution
    // Modify this function to fit your specific problem
    double fitness = 0.0;
    for (const auto& gene : solution) {
        fitness += gene;
    }
    return fitness;
}

// Genetic Algorithm class
class GeneticAlgorithm {
public:
    GeneticAlgorithm(int populationSize, int numGenes, double mutationRate, double crossoverRate) :
        populationSize(populationSize),
        numGenes(numGenes),
        mutationRate(mutationRate),
        crossoverRate(crossoverRate) {
    }

    void initialize() {
        // Initialize the population
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < populationSize; i++) {
            std::vector<double> solution;
            for (int j = 0; j < numGenes; j++) {
                solution.push_back(dis(gen));
            }
            population.push_back(solution);
        }
    }

    std::vector<double> optimize(int numIterations) {
        // Optimization loop
        for (int i = 0; i < numIterations; i++) {
            evaluateFitness();
            selection();
            crossover();
            mutation();
        }

        // Find the best solution
        evaluateFitness();
        auto bestSolution = *std::max_element(population.begin(), population.end(), [](const auto& a, const auto& b) {
            return fitnessFunction(a) < fitnessFunction(b);
        });

        return bestSolution;
    }

private:
    void evaluateFitness() {
        for (auto& solution : population) {
            double fitness = fitnessFunction(solution);
            fitnessValues.push_back(fitness);
        }
    }

    void selection() {
        // Selection operator
        // Modify this function to implement different selection strategies
        // In this example, we use a simple tournament selection

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, populationSize - 1);

        std::vector<std::vector<double>> newPopulation;

        for (int i = 0; i < populationSize; i++) {
            int index1 = dis(gen);
            int index2 = dis(gen);

            if (fitnessValues[index1] > fitnessValues[index2]) {
                newPopulation.push_back(population[index1]);
            } else {
                newPopulation.push_back(population[index2]);
            }
        }

        population = newPopulation;
        fitnessValues.clear();
    }

    void crossover() {
        // Crossover operator
        // Modify this function to implement different crossover strategies
        // In this example, we use a simple one-point crossover

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (int i = 0; i < populationSize; i += 2) {
            if (dis(gen) < crossoverRate) {
                int crossoverPoint = dis(gen) * numGenes;
                for (int j = crossoverPoint; j < numGenes; j++) {
                    std::swap(population[i][j], population[i + 1][j]);
                }
            }
        }
    }

    void mutation() {
        // Mutation