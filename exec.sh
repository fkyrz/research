g++ -std=c++17 inputGenerate.cpp
./a.out > input.txt
echo "Input generated"
g++ -std=c++17 puzzle.cpp
./a.out < input.txt > output.txt
echo "Output generated"
g++ -std=c++17 toVisualizer.cpp
./a.out < output.txt > inputVis.js
echo "Visualizer input generated"