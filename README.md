# cub3d

![screenshot](sample.gif)

### SUMMARY
Simple 3D maze, using raycasting. Project of the 42 cursus. \
Uses a basic graphics library called MiniLibX, provided by 42 school. You can find more info on the subject file.

### COMPILING (with CMake)
- go to the lib folder that corresponds to your OS \(mms and opengl are the mac options\)
- compile the MiniLibX with 'make'
- go back to the root folder and type: ``cmake -B build && cd build && make``

### COMPILING (with Makefile, only adapted for Mac)
- type ``make``. This will use the Makefile to compile the program along with the .dylib/.a of MiniLibX

### RUNNING
- run ``./bin/cub3D res/maps/<valid map.cub file>``
- you can quit by pressing the red cross window button or by pressing the ESC key

### NOTES
If using CLion or other editor that uses CMake:
- you still have to first compile the MiniLibX lib with the Makefile
- on the Run/Debug configurations, set your working directory as ``$ProjectFileDir$``
- on the Run/Debug configurations, add ``DYLD_LIBRARY_PATH=\<working directory\>`` as an environment variable (not sure if this one is still needed)

