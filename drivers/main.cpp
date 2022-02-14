#include <PipeNetwork.hpp>
#include <filesystem>

int
main() {

    std::string p = std::filesystem::current_path().parent_path().string();
    // Get the current path and store it in p
    // Uncomment this line to show the current
    // std::cout << p << std::endl;

    // Create a new pipe network, by passing in the current path + the input file name
    cie::pipenetwork::PipeNetwork pipeNetwork( p + "/input2.txt" );

    // Logs out the data that has been read from the input file
    pipeNetwork.inputLog();

    // Logs out the results of the calculations
    pipeNetwork.resultLog();

    // Store the result data into a file, by passing in the current path
    pipeNetwork.resultToFile( p );
    return 0;
}
