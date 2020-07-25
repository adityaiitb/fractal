/*
  Copyright 2020 Aditya Agrawal
  
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
  
      http://www.apache.org/licenses/LICENSE-2.0
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include<stdio.h>
#include<complex.h>

#define CONVERGENCE 1e-10
#define ITERATIONS 32
#define TOTAL_POINTS 1000

std::complex<double> new_guess(std::complex<double> old_guess) {
//double complex new_guess(double complex old_guess) {
	//Function = (x-1)x(x+1)
	std::complex<double> temp = std::pow(old_guess,2);
	std::complex<double> function = temp * old_guess - old_guess;
	std::complex<double> derivative_function = 3.0 * temp - 1.0;
	std::complex<double> new_guess = old_guess - (function)/(derivative_function);
	return new_guess;
}

int main() {

	int i,j,k;
	int iterations;
	std::complex<double> initial_guess, guess, guess1, difference;

	for (i = 0; i < TOTAL_POINTS; i++) {
		for (k = 0; k < TOTAL_POINTS; k++) {
			double real = -1 + 2*((double)k)/((double) TOTAL_POINTS);
			double imag = -1 + 2*((double)i)/((double) TOTAL_POINTS);
			initial_guess = std::complex<double>(real, imag);
			
			guess = initial_guess;
		
			for (j = 0; j < ITERATIONS; j++) {
				guess1 = new_guess(guess);
				difference = guess1 - guess;
				guess = guess1;
				if (std::abs(difference) < CONVERGENCE) {
					iterations = j;
					break;
				}
				if (j == ITERATIONS) {
					printf("Error: Cannot converge\n");
					exit(0);
				}
			}
			printf("%f ", std::real(guess)+((float)iterations/ITERATIONS));
		}
		printf("\n");
	}

	return 0;
}
