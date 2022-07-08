#include <iostream>
#include <vector>
#include <chrono>
#include "functions.h"


int main() {
    const long long TIMES_TO_RUN{100};
    const long long NUM_VALS{10000};
    std::vector<double> runtimes;
    std::vector<int> dataset;

    for (int i = 0; i < TIMES_TO_RUN; ++i)
    {
        //Populate vector
        for (int i = 0; i < NUM_VALS; ++i) {
            long long randNum = rand() % 100000;
            dataset.push_back(randNum);
        }
        //std::cout << "Unsorted Vector\n";
        //printVector(dataset);
        //Time the sort
        std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
        //Bubble sort
        for (int i = 0; i < NUM_VALS; ++i) {
            for (int j = 0; j < NUM_VALS - 1; j++) {
                if (dataset.at(j) > dataset.at(j + 1)) {
                    int temp{0};
                    temp = dataset.at(j + 1);
                    dataset.at(j + 1) = dataset.at(j);
                    dataset.at(j) = temp;
                }
            }
        }

        std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
        double runtime = std::chrono::duration_cast<std::chrono::duration<double>>(
                _end - _start).count();
        runtimes.push_back(runtime);

                //std::cout << "Sorted Vector\n";
                //printVector(dataset);

        //Clear vector
        dataset.clear();
    }


    //Calculate timing results
    double avgRuntime{0};

    //Sum the vector
    for (double& n : runtimes)
        avgRuntime += n;

    std::cout << "\n\n\nTotal runtime: " << avgRuntime << " seconds\n";

    //Average the sum
    avgRuntime = avgRuntime / runtimes.size();

    std::cout << "\n\n\nAverage run time: " << avgRuntime << " seconds\n";
    return 0;
}
