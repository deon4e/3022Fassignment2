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
        std::vector<unsigned char *> mainImage;
        public:
            FrameSequence();
    };
};

#endif