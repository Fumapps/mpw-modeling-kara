# Kara the ladybug - MPW Simulator

This is the modeled kara MPW simulator example based on the MPW framework (https://github.com/Fumapps/mpw-modeling-framework).

![modeling approach](documentation/graphics/mdsd-approach-concrete-simulator.svg)

It defines the modeling of the kara-simulator under `/bundles/de.unistuttgart.iste.sqa.mpw.modeling.karasimulator`.
After code-generation with Maven `package`, in `/simulators` the both simulators for Java and C++ can be found.

## Java Simulator

The Java simulator is similar to the PSE-Simulator (https://git.rss.iste.uni-stuttgart.de/open-to-public/pse the PSE-Simulator).

##  C++ Simulator

The C++ simulator is based on CMake and SDL2.
Import the CMake project with an IDE like Visual Studio or CLion.
How to setup the dependencies for SDL2 is explained in the `README.md` under `/simulators/de.unistuttgart.iste.sqa.mpw.karasimulator.cpp/ui`.