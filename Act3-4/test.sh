rm main
g++ -std=c++11 -o main main.cpp
for i in {0..4}
do
  echo "Test $i"
  ./main "input$i.txt" "out$i.txt"
  diff "output$i.txt" "out$i.txt"
done