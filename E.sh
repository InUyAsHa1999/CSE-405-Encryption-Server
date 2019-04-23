#!/bin/bash 
IFS=','
HomDir="$(pwd)"
mkdir encrypt
mkdir Lock
cd Lock
Dim="$(pwd)"
cd $HomDir
cd Engine
mv $HomDir/Lock/* $HomDir/Engine/Working_With.txt
mv $HomDir/Lock/* $HomDir/Engine/Working_With.txt

g++ -std=c++11 Settings.cpp -o Sh
./Sh

g++ -std=c++11 Encrypt.cpp -o Ec
./Ec
mv $HomDir/Engine/ECR.vvn $HomDir/encrypt
rm Sh
rm Ec
rm Working_With.txt
rm XxPre_SetxX.cfg
cd $HomDir
./b.sh
