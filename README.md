# Too-Much-Milk-Problem
Too Much Milk Problem

To run the files:

(Solution 1)

g++ Jill1.cpp -o Jill1 

g++ Jack1.cpp -o Jack1

./Jill1 & ./Jack1 &

(Solution 2)

g++ Jill2.cpp -pthread -o Jill2

g++ Jill2.cpp -pthread -o Jack2

./Jill2 & ./Jack2 &
