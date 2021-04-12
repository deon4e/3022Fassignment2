/**
 * FrameSequence sourcefile
 * By Deon Fourie
 * */

#include "FrameSequence.h"
//constructor
FRXDEO001::FrameSequence::FrameSequence(void) : imageSequence(std::vector<unsigned char **>())
{
}
/** Destructor loops through all frames and frees up all the memry used in the dynamic 2d array
 * */

FRXDEO001::FrameSequence::~FrameSequence()
{

    int size = FrameSequence::imageSequence.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            delete[] FrameSequence::imageSequence[i][j];
        }
        delete[] FrameSequence::imageSequence[i];
    }
}

/**
 * To calculate gradient for mastery section
 * */

void FRXDEO001::FrameSequence::gradientCalculator(int x, int y, int end_x, int end_y)
{
}
/**
 * Function to read in the file and write contents to an FrameSequence frame variable
 **/

void FRXDEO001::FrameSequence::read(std::string file)
{
    int Ncols, Nrows;
    std::string line;
    char *matrix_c;
    std::ifstream ifs(file, std::ios::binary);
    FrameSequence::y = Nrows;
    FrameSequence::x = Ncols;

    if (!ifs)
    {
        std::cout << "Failed to read input image" << std::endl;
    }

    std::getline(ifs, line); // first line
    std::getline(ifs, line); // second line

    while (line[0] == '#')
    {
        std::getline(ifs, line); //while the char is a # ie comment
    }
    Nrows = std::stoi(line.substr(line.find(" ") + 1)); // part of line indicating the size of the window showing number of rows
    Ncols = std::stoi(line.substr(0, line.find(" ")));  // part of line indicating the size of the window showing number of columns
    std::getline(ifs, line); // line with 255
    ifs >> std::ws;          //binary block
    matrix_c = new char[Ncols * Nrows];
    ifs.read(matrix_c, Ncols * Nrows);
    unsigned char *window = reinterpret_cast<unsigned char *>(matrix_c);
    FrameSequence::frame = new unsigned char *[Nrows];
    for (int i = 0; i < Nrows; ++i)
    {
        FrameSequence::frame[i] = new unsigned char[Ncols]; //adding frame sequence based on number of rows
        for (int j = 0; j < Ncols; ++j)
        {
            FrameSequence::frame[i][j] = window[i * Ncols + j];
        }
    }

    delete[] window;
}
/**
 * Function to process the framesequence given parameters
 * 
 * */

void FRXDEO001::FrameSequence::process(int start_x, int start_y, int end_x, int end_y, int width, int height)
{
    FrameSequence::width = width;
    FrameSequence::height = height;
    float gradient = ((float)(end_y - start_y) / (end_x - start_x));

    if (std::abs(gradient) > 1.0)
    {
        float x = start_x;
        gradient = (float)(1 / gradient);
        for (int y = start_y + 1; y <= end_y; ++y) //loop through y offset by 1
        {
            x += gradient;
            int roundedX = round(x);
            unsigned char **frame = new unsigned char *[height];
            for (int i = y; i < y + height; ++i)
            {
                frame[i - y] = new unsigned char[width];
                for (int j = roundedX; j < roundedX + width; ++j)
                {
                    frame[i - y][j - roundedX] = FrameSequence::frame[i][j];
                }
            }
            FrameSequence::imageSequence.push_back(frame);
        }
    }
    else
    {
        float y = start_y;
        for (int x = start_x + 1; x <= end_x; ++x)
        {
            y += gradient;
            int roundedY = ::round(y);
            unsigned char **frame = new unsigned char *[height];

            for (int i = roundedY; i < roundedY + height; ++i)
            {
                frame[i - roundedY] = new unsigned char[width];
                for (int j = x; j < x + width; ++j)
                {
                    frame[i - roundedY][j - x] = FrameSequence::frame[i][j];
                }
            }
            FrameSequence::imageSequence.push_back(frame);
        }
    }
    for (int i = 0; i < FrameSequence::y; ++i)
    {
        delete[] FrameSequence::frame[i];
    }
    delete[] FrameSequence::frame; //cleaning
}

/**
 * Function to write the FrameSequence object to a file based on the options selected on the command line
 * 
 **/

void FRXDEO001::FrameSequence::write(std::string option, std::string base)
{
    int size = FrameSequence::imageSequence.size();
    for (int i = 0; i < size; ++i)
    {
        char outputName[50];
        const char *fileNameBase = base.c_str();
        sprintf(outputName, "%s%s%04d.pgm", "./output/", fileNameBase, i); //using c to format output file names based on options

        std::string file = outputName;
        int width = FrameSequence::width;
        int height = FrameSequence::height;

        std::ofstream ofs(file);

        ofs << "P5" << std::endl
            << width << " " << height << std::endl
            << 255 << std::endl; //data at start of file

        //loop for inverting
        if (option == "invert")
        {
            //std::cout <<"Invert" << std::endl;
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
            //std::cout <<"Reverse" << std::endl;
            for (int j = 0; j < height; ++j)
            {
                ofs.write(reinterpret_cast<char *>(((FrameSequence::imageSequence)[i][size - i - 1][j])), width);
            }
        }
        //loop for reinverting window
        else if (option == "revinvert")
        {
            //std::cout <<"revinvert" << std::endl;
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
            for (int j = 0; j < height; ++j)
            {
                ofs.write(reinterpret_cast<char *>(((FrameSequence::imageSequence)[i][j])), width);
            }
        }
    }
}