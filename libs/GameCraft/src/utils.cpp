#include <string>
#include <cassert>
#include "juniorit/GameCraft/utils.h"

std::string getResourceFilePath(const std::string& inFile) {
    std::string resourcePath = "res/" + inFile;
    // Optionally, you can add assert or exception handling if needed.
    // assert(!resourcePath.empty());
    return resourcePath;
}
