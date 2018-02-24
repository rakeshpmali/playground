
GCC=g++

cd ./src

echo "Building wordCountApp ..."
$GCC -Wall wordCountApp.cpp -o ../bin/wordCountApp -lpthread

echo "Building serverApp ..."
$GCC -Wall serverApp.cpp -o ../bin/serverApp -lpthread

echo "Finished"
