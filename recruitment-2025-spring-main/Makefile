CFLAG = -O3 -g -Wall -fopenmp -mavx -mavx2 -mfma

all:
	g++ driver.cc winograd.cc -std=c++11 ${CFLAG} -o winograd

clean:
	rm -f winograd
