/**
 * Driver file for assignment 2
 * By: Deon Fourie
 *
 **/

#include "FrameSequence.h"

int main(int argc, char const *argv[])
{
    FRXDEO001::FrameSequence seq;
    //input check for validity of params
    if (argc < 13)
    {
        std::cout << "The input you have entered is incorrect, please try again" << std::endl;
        return 0;
    }
    int start_x = std::stoi(argv[3]);
    int start_y = std::stoi(argv[4]);
    int end_x = std::stoi(argv[5]);
    int end_y = std::stoi(argv[6]);
    int width = std::stoi(argv[8]);
    int height = std::stoi(argv[9]);
    int optionLength = (argc - 10);
    int optionCount = int(optionLength / 3);
    
    seq.read(argv[1]); //read the sequence
    seq.process(start_x, start_y, end_x, end_y, width, height); //process the sequence

    
    for (int i = 0; i < optionCount; i++)
    {
        std::string options = argv[11 + i * 3];
        std::string base = argv[12 + i * 3];
        seq.write(options, base);
    }
    //still to do 

    ///sort out p tags if you have time
    return 0;
}
