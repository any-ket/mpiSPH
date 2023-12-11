/* SPH_main.cpp
    Main cpp function to instantiate SPH class, calls SPH::RunSimulation to start the simulation and handles
    deallocation of SPH class when complete.
*/

#include "SPH.h"
#include <sys/time.h>

#include <chrono>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){

    MPI_Init(NULL, NULL);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    SPH *solver = new SPH(argc, argv);

    struct timeval time_now {};
      gettimeofday(&time_now, nullptr);
      time_t t = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
    solver->RunSimulation();
    struct timeval time_now2 {};
      gettimeofday(&time_now2, nullptr);
      time_t t2 = (time_now2.tv_sec * 1000) + (time_now2.tv_usec / 1000); 

    if(rank == 0)
        cout<<"Time taken: "<<t2-t<<" milli seconds"<<endl;

    delete solver;

    MPI_Finalize();

}