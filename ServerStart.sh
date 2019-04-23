#!/bin/bash 
mkdir Holding
mkdir Keys
mkdir Main
mkdir Response
chmod 700 B.sh
Dim="$(pwd)"
File_Dir=$Dim/Holding
File_Type_Encrypt="Request.exp"
File_Type_Decrypt="Request.dxp"
File_Test=""
File_Key=""




while :
do
printf "\033c"
printf "Encription Server Running!\n"
pwd
#if [ "$(ls -A Q )" ]; #While Something Is In The Q Folder

if [ "$(ls -A Holding )" ]; #While Something Is In The Holding Folder!
then
if [ -f "$File_Dir/$File_Type_Decrypt" ];
then 
printf "Lets start to Decrypt!\n"
cd "$Dim/Holding"
File_Test=$(cat $File_Type_Decrypt | sed -n '1p')
File_Pars=${File_Test::-4}
cd "$Dim/Keys"
if [ -f "$Dim/Keys/$File_Pars" ];
then
printf "Can Decrypt!\n"
Saving_The_Key=$(head -1 $File_Pars)
cd "$Dim/Engine"
cd "$Dim"
mv "$Dim/Holding/$File_Test" "$Dim/Engine/"
cd "$Dim/Engine/"
mv $File_Test ECR.vvn
sed -i "1s/^/$Saving_The_Key\n/" ECR.vvn

g++ -std=c++11 Decrypt.cpp -o Dc
./Dc
sleep 3
cd "$Dim/Keys"
File_Pars=${File_Test::-4}
rm $File_Pars
cd "$Dim/Holding"
rm $File_Type_Decrypt
cd "$Dim/Engine"
rm Dc
rm ECR.vvn
mv Translated.txt "$Dim/Response" 
rm Translated.txt
#ls
else
printf "Can't Decrypt!\n"
fi
pwd
fi
if [ -f "$File_Dir/$File_Type_Encrypt" ];
then
printf "Lets start to Encrypt!\n"
cd "$Dim/Holding"
File_Test=$(cat $File_Type_Encrypt | sed -n '1p')
File_Pars=${File_Test::-4}
mv $File_Test "$Dim/Lock"
cd "$Dim/Keys"
touch $File_Test
cd "$Dim"
./E.sh
cd "$Dim/encrypt"
File_Key=$(cat ECR.vvn | sed -n '1p')
echo File_Key
sed -i '1d' ECR.vvn
mv ECR.vvn $File_Test.vvn
mv $File_Test.vvn "$Dim/Response"
cd "$Dim/Holding"
rm $File_Type_Encrypt
rm $File_Pars
cd "$Dim"


cd "$Dim/Keys"

echo $File_Key > $File_Test
fi
#exit 1
fi
File_Test=""
File_Key=""
cd "$Dim"
done
rm $File_Test
sleep 3
rmdir Holding
rmdir Keys
rmdir Main
rmdir Response
