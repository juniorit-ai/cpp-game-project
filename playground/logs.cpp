#include <iostream>
#include <fstream>

int main() {
    std::cout << "This will print to standard output." << std::endl;
    std::cerr << "This will print to standard error." << std::endl;
    std::clog << "This is a log message." << std::endl;

    std::ofstream log("log.txt");
    log << "This will be written to a log file." << std::endl;
    log.close();

    return 0;
}