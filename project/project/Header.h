#pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


struct Point {
	double x_, y_;
	Point() { x_ = 0; y_ = 0; }
	Point(double x, double y) { x_ = x; y_ = y; };
	void print() {
		cout << x_ << " " << y_ << endl;
	}
};

struct Segment {
	double x1_, x2_, y1_, y2_;
	Segment(double x1, double y1, double x2, double y2) {
		x1_ = x1;
		x2_ = x2;
		y1_ = y1;
		y2_ = y2;
	};
	Segment(Point& p1, Point& p2) {
		x1_ = p1.x_;
		x2_ = p2.x_;
		y1_ = p1.x_;
		y2_ = p2.y_;
	};
	void print() {
		cout << x1_ << " " << y1_ << "\t " << x2_ << " " << y2_ << endl;
	}
};

vector<Point> get_polygon(vector<Point> points, vector<Point> all_points);

bool check_segment(Point p1, Point p2, vector<Point> points);

double get_y_coordinate(Point p1, Point p2, double x);

vector<Point> read(std::string file);

template <typename T>
void out(vector<T> points) {
	if (points.size() > 0) for (int i = 0; i < points.size(); i++) points[i].print();
}

void write(string file, vector<Segment> segments);

void write(string file, vector<Point> above_points, vector<Point> below_points);

void get_above_below_points(vector<Point>& above_points, vector<Point>& below_points, vector<Point> points);

int partition(vector<Point>& a, int start, int end, bool increase = true);
void quicksort(vector<Point>& a, int start, int end, bool increase = true);