#!/bin/bash 
IFS=','
HomDir="$(pwd)"
cd $HomDir
chmod 755 IP_LIST.txt
mkdir File_Storage
mkdir IP_Storage
chmod 755 IP_Storage
sudo mv $HomDir/IP_Storage/IP_LIST.txt /$HomDir
g++ -std=c++11 ClientPortal.cpp -o Portal
./Portal
sudo mv IP_LIST.txt IP_Storage
rm Portal
