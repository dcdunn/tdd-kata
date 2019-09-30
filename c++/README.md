# Test-Driven Development C++ Boilerplate

The master branch contains an empty boiler plate C++ project that uses gmock. Gmock is not
included in this repo, so needs to be installed on your system. 


## Installing gmock
The build tools are set up to look for a copy of the googletest 
distribution in the top-level C++ directory. Either clone the repo
there
```
git clone https://github.com/google/googletest.git
```
or download and unzip one of the [latest release](https://github.com/google/googletest/releases)

## Building with CMake

Create a build directory in the top-level C++ directory, and from that
directory run the following command to configure:

```
cmake ../
```

Build with `make`, and run tests with `ctest -V`

## Building with MSVC

[Building and running on Windows](msvc/README.md)
