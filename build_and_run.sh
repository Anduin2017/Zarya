echo "Preparing to build and run..."
mkdir Bin &> /dev/null
rm ./Bin/Program.out &> /dev/null

echo "Building..."
g++ ./Program.cpp -o Bin/Program.out

echo "Running..."
./Bin/Program.out
