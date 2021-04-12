/**
 * FrameSequence sourcefile
 * By Deon Fourie
 * */

#include "FrameSequence.h"
//constructor
FRXDEO001::FrameSequence::FrameSequence(void)
{
}

void FRXDEO001::FrameSequence::read(std::string file)
{
}

void FRXDEO001::FrameSequence::process(int start_x, int start_y, int end_x, int end_y, int width, int height)
{
}

void FRXDEO001::FrameSequence::write(std::string option, std::string base)
{
    int size = FrameSequence::imageSequence.size();
    for (int i = 0; i < size; ++i)
    {
        char outputName[100];
        const char *c_fileName = base.c_str();
        sprintf(outputName, "%s%s%04d.pgm", "./output/", c_fileName, i);

        std::string file = outputName;
        int width = FrameSequence::width;
        int height = FrameSequence::height;
        

        std::ofstream ofs(file);

        ofs << "P5"<< std::endl << width << " " << height << std::endl << 255 << std::endl; //data at start of file
    
        //loop for inverting
        if (option == "invert")
        {
            for (int j = 0; j < height; ++j)
            {
                for (int k = 0; k < width; ++k)
                {
                    ofs << (unsigned char)(255 - (int)((FrameSequence::imageSequence)[i][j][k]));
                }
            }
        }
        //loop through reversing and writing to file
        else if (option == "reverse")
        {
            for (int j = 0; j < height; ++j)
            {
                ofs.write(reinterpret_cast<char *>(((FrameSequence::imageSequence)[i][size - i - 1][j])), width);
            }
        }
        //loop for reinverting image
        else if (option == "reinvert")
        {
            for (int j = 0; j < height; ++j)
            {
                for (int z = 0; z < width; ++z)
                {
                    ofs << (unsigned char)(255 - (int)(FrameSequence::imageSequence[size - i - 1][j][z]));
                }
            }
        }
        // default ie no options. will loop through and write to file as normal
        else
        {
            for (int j = 0; j <height; ++j)
            {
                ofs.write(reinterpret_cast<char *>(((FrameSequence::imageSequence)[i][j])), width);
            }
        }
    }
}