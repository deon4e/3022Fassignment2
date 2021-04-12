/**
 * FrameSequence header file\
 * By Deon Fourie
 * 
**/

#ifndef FRAMESEQUENCE
#define FRAMESEQUENCE
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>

namespace FRXDEO001
{
    class FrameSequence {
        private:
        std::vector<unsigned char **> imageSequence;
        int x, y, width, height;
    
        public:
            FrameSequence();
            void read(std::string file);
            void process(int start_x, int start_y, int end_x, int end_y, int width, int height);
            void write(std::string fileName, std::string option);
            ~FrameSequence();

    };
};

#endif