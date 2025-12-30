#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "Missing file argument" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if(!file.is_open()){
        std::cout << "There was an error while opening the file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)){
        std::cout << line << std::endl;
    }
    file.close();

    std::ofstream editFile(argv[1]);

    std::cout << "Edit file (type END when done):" << std::endl;

    while (true)
    {
        std::string addLine;
        std::getline(std::cin, addLine);
        if(addLine == "END"){
            editFile.close();
            return 0;
        }
        else{
            editFile << addLine << std::endl;
        }
    }
    
    return 0;
}