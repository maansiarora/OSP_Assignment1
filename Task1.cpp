#include "Methods.h"

int main(int argc, char** argv) {
    if (argc >= 3) {
        std::string argv1 = argv[1];
        std::string argv2 = argv[2];
        Task1filter(argv1,argv2);
    }
    return EXIT_SUCCESS;
}


