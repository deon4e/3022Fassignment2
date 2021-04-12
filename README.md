# CSC3022F assignment 2

Provided with a very large input image (for example, 16K x 16K “image moscaic” from
an astronomy sky survey) we want to produce a video that captures the movement of a
much smaller window across this large image. 

The command line options for your program is extractor <inputPGMfile> [options],
where <inputPGMfile> is the large image you read in and [options] is a list of the
following parameters:
-t <int> <int> <int> <int> # x1 y1 x2 y2 (begin & end origin pixel coords,
for frame trajectory)
-s <int> <int> # <width> <height> (size of small frame in
pixels)
-w <string> <string> # write frames with <operation> <name>


## Data

All pgm images are read from the root directory so you can drop any pgm file in the root directory and it should work


## Usage

In the root directory run the following to create object and executable files:

```
make
```

After succesfull compilation, you can navigate to the location of the 'extractor' target executable with the following command:

```
cd build/executables
```

In the executables directory, there should be a single driver file called extractor.

To execute with arguments simply run your own arguments like the following: 
 
```
./extractor myLargeImage.pgm -t 0 10 5000 5000 -s 640 480 -w invert invseq -w none sequence2
```

Alternatively, a run command has been set up in the Makefile.

Here you can add your own filename and arguments to run the program

Simply run the following in the root directory:

```
make run
```

To clean the build directory (object files and executables) & the output images, run:

```
make clean
```

To get info about the file structure run
```
make info
```