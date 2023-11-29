#define _USE_MATH_DEFINES
#include <iostream>
#include "Header.h"
using namespace std;


int main()
{

	//vector<Point> points = read("in.txt");
	vector<Point> points = gen_data(40);
	out(points);
	cout << endl;
	write("in.txt", points);
	vector<Point> res = Jarvis_algorithm(points);
	cout << endl;
	out(res);
	write("out.txt", res);
}

