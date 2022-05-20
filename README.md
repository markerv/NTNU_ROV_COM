# NTNU_ROV_COM
This is a collection of code used in a NTNU bachelors-thesis where the goal was to achievie automatic transmission of data between multiple ROS based ROV's using acoustic modems.

The solution uses the JANUS protocol as a universal language allowing for integration of modems from differing manufacturers. The original implementation was done with Evologics 18-34 USBL modems.

## Requirements
The solution requires some libraries to function propperly:

### Make
```bash
make -version #Check if make is installed
sudo apt install make
sudo apt install build-essential
```
### cmake
```bash
sudo snap install cmake --classic
```
### FFTW3
```bash
wget http://fftw.org/fftw-3.3.10.tar.gz
tar -xzf fftw-3.3.10.tar.gz
cd fftw-3.3.10
./configure
make
sudo make install
make check
```

### libreadline
```bash
sudo apt-get install libreadline-dev
```
## Compilation
### Compile SDMSH
in "lib/sdmsh/":
```bash
make
```
### Compile JANUS
The supplied version of JANUS comes patched with the Evologics Patchset.

in "lib/janus-c-3.0.5/":
```bash
cmake -S . -B bin/
cd bin
make .
```

### Compile execution files
The main code sould be checked to make sure that the modem IP is corret before compilation.

The executables were built induvidually using the compiler in visual studio. Parameters for the compilation process can be found in ".vscode/task.json"

## Setup

Firstly the modems should be in "PHY"-mode. This can be done by acessing them over tcp and issuing a command:
```bash
nc MODEM_IP MODEM_SOCKET #Default socket is 9200
+++ATP
```

Then modemSetup can be run to configure source level and the JANUS preamble.

The modems are now ready to transceive!