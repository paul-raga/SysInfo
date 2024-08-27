# SysInfo
The program explores /proc and /sys directories to retrieve informations about hardware devices. 

It only uses fuctions from the C standard library and fetches data from common kernel-defined directories, making it portable on a wide range of systems running Linux.

SysInfo is at an early stage of development: avoid running it on low end or embedded devices as it could cause a crash or generate kernel panic. 
