/**
 * Driver file for assignment 2
 * By: Deon Fourie
 *
 **/

#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    //input check for validity of params
    if (argc < 13)
    {
        std::cout << "The input you have entered is incorrect, please try again" << std::endl;
    }
    int start_x = std::stoi(argv[3]);
    int start_y = std::stoi(argv[4]);
    int end_x = std::stoi(argv[5]);
    int end_y = std::stoi(argv[6]);
    int width = std::stoi(argv[8]);
    int height = std::stoi(argv[9]);

    std::cout << start_x << start_y << end_x << end_y << width <<height << std::endl;
    return 0;
}
