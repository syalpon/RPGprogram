g++ -c Parameter.cpp -o Parameter.o

g++ -c Hp.cpp -o Hp.o

g++ -c Mp.cpp -o Mp.o

g++ -c Exp.cpp -o Exp.o

g++ -c Lv.cpp -o Lv.o

g++ -c Atk.cpp -o Atk.o

g++ -c Character.cpp -o Character.o

g++ -c main.cpp -o main.o

g++ -o main main.o Character.o Hp.o Mp.o  Lv.o Exp.o Atk.o  Parameter.o 

main.exe

pause >NUL