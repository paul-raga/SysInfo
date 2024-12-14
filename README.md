# SysInfo 
A simple command-line tool to print informations of your machine. 


## Description

SysInfo is a shell utility that fetches informations from various files spread across a tipical Unix file system. It is fully written in C and does not depend on any libreries, so it comes native and ready to run on any machine runnin a Linux kernel.  


## Dependencies

* Any Linux distribution on whatever architecture
* GCC (version here)
* CMake (version here)
* Make (version here)

## Installing

Download and compile the source code:
```
git clone https://github.com/paul-raga/SysInfo.git
cd SysInfo
mkdir build
cd build
cmake ..
make
```

## Executing program

Currently installation does not add sysinfo to PATH, so from the project folder: 
```
./sysinfo <arguments>
```

### Help

To get help on how to use the tool: 
```
./sysinfo -h
```

### Authors

* Paul Ragazzini  
paul.raga2001@gmail.com 

### Version History

* 0.1.0-alpha 
    * full, base and custom system report support. Full report needs to be fixed due to memory allocation overflow on some devices     

### License

This project is licensed under the GPL-3.0 License - see the LICENSE.md file for details
