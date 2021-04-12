/**
 * FrameSequence header file\
 * By Deon Fourie
 * 
**/

#ifndef FRAMESEQUENCE
#define FRAMESEQUENCE
#include <iostream>
#include <string>
#include <vector>

namespace FRXDEO001
{
    class FrameSequence {
        private:
        std::vector<unsigned char **> imageSequence;
    
        public:
            FrameSequence();
            void read(std::string file);
            void process(int start_x, int start_y, int end_x, int end_y, int width, int height);
            void write();
            ~FrameSequence();

    };
};

#endif