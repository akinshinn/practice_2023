#define _USE_MATH_DEFINES
#include <iostream>
#include "Header.h"
using namespace std;


int main()
{

	vector<Point> points = readf("in.txt");
	//vector<Point> points = gen_data(100000);
	//out(points);
	cout << endl;
	//write("in.txt", points);
	clock_t start = clock();
	vector<Point> res = Jarvis_algorithm(points);
	clock_t end = clock();
	cout << endl;
	out(res);
	write("out.txt", res);
	cout << (double)(end - start) / CLOCKS_PER_SEC;
}

