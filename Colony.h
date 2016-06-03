//
// Created by ivanedo on 17-05-16.
//

#ifndef VRPTW_ACO_COLONY_H
#define VRPTW_ACO_COLONY_H
#include <deque>
#include "Ant.h"

class Colony {
private:
    // const double alpha;  // in ant colony system, the alpha parameter is equal to one
    const double beta;
    const double phi;  // pheromone's evaporation rate (global update)
    const double xi; // pheromone's evaporation rate (local update)
    const double initial_pheromone;  // tau_0
    const int size;
    const int max_iterations;
    const double q0;
    std::vector<Ant*> ants;
    Graph *graph;
    Solution *best_solution;

public:
    Colony(const double beta, const double phi, const double xi, const int size, const int max_iterations, const double q0, const double initial_pheromone, Graph *graph);
    ~Colony();
    void create_ants();
    // const double get_alpha() const;
    const double get_beta() const;
    const double get_evaporation() const;
    const double get_local_evaporation() const;
    const int get_size() const;
    const int get_max_iterations() const;
    const double get_q0() const;
    void deposit_initial_pheromone();
    void run();
    void step();
    void save_best_solution();
    void global_update_pheromone_trail();
    void restart_ants();
};
#endif //VRPTW_ACO_COLONY_H
