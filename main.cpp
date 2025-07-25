#include "main.h"
#include "fileinout.h"
#include "encode.h"
#include "decode.h"
#include <string>

int main(){
    bool isRunning = true;

    printStartMenu();

    while (isRunning)
    {
        std::string usrInput;
        std::cin >> usrInput;

        int input;

        if(usrInput.length() == 1){
            if(std::isdigit(usrInput.at(0))){
                input = std::stoi(usrInput);

                if(input == 1){
                    printEncodeFileMenu();
                    std::string filename;
                    std::cin >> filename;

                    if(isFileValid(filename)){
                        printFileFound();

                        if(encodeFile(filename)){
                            std::cout << "Success!";
                        } else {
                            std::cout << "Failure!";
                        }
                    } else {
                        printFileNotFound();
                    }

                    printMainMenu();
                } else if(input == 2){
                    printDecodeFileMenu();
                    std::string filename;
                    std::cin >> filename;

                    if(isFileValid(filename)){
                        printFileFound();
                        decodeFile(filename);
                    } else {
                        printFileNotFound();
                    }

                    printMainMenu();
                } else if(input == 3){
                    isRunning = false;
                    printExiting();
                } else {
                    printMenuError();
                    printMainMenu();
                }
            } else {
                printMenuError();
                printMainMenu();
            }
        } else {
            printMenuError();
            printMainMenu();
        }
    }
}