#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <algorithm>
using namespace std;


struct Point {
	double x_, y_;
	Point() { x_ = 0; y_ = 0; }
	Point(double x, double y) { x_ = x; y_ = y; };
	void print() {
		cout << x_ << " " << y_ << endl;
	}
};

vector<Point> get_polygon(const vector<Point>& local_points, const vector<Point>& all_points);

bool check_segment(const Point& p1, const Point& p2, const vector<Point>& points);

double get_y_coordinate(const Point& p1, const Point& p2, double x);

vector<Point> read(const string& file);

template <typename T>
void out(vector<T> points) {
	if (points.size() > 0) for (int i = 0; i < points.size(); i++) points[i].print();
}


void write(const string& file, const vector<Point>& above_points, const vector<Point>& below_points);

void get_above_below_points(vector<Point>& above_points, vector<Point>& below_points, vector<Point> points);

int partition(vector<Point>& a, int start, int end, bool increase = true);

void quicksort(vector<Point>& a, int start, int end, bool increase = true);

vector<Point> gen_data(int n);