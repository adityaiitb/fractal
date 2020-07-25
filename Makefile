all: newton

newton: newton.cc
	g++ $^ -o $@ -lm

clean:
	\rm newton
