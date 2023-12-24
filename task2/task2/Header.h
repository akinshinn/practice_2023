#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


struct Point {
	double x_, y_;
	Point() { x_ = 0; y_ = 0; }
	Point(double x, double y) { x_ = x; y_ = y; };
	Point(const Point& obj) { x_ = obj.x_; y_ = obj.y_; }
	void print() {
		cout << x_ << " " << y_ << endl;
	}
	bool operator==(const Point& p) {
		return (p.x_ == x_ && p.y_ == y_);
	}
};
struct MyVector {
	double x, y;
	MyVector() {
		x = 0; y = 0;
	}
	MyVector(const Point& p1,  const Point& p2) {
		x = p1.x_ - p2.x_;
		y = p1.y_ - p2.y_;
	}
	double scalar(const MyVector& obj) {
		return obj.x * x + obj.y * y;
	}
	double len() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}
};

int get_bottom_point(vector<Point>& points);

vector<Point> Jarvis_algorithm(const vector<Point>& points);

void write(string file, const vector<Point>& points);

vector<Point> readf(std::string file);

double get_cos_angle_vectors(const Point& last_p, const Point& current_p, const Point& candidate_p);

int get_min_cos_point(vector<Point>& points, const Point& p, int id_p, int id_lastp);

vector<Point> gen_data(int n);

template <typename T>
void out(vector<T>& points) {
	if (points.size() > 0) for (int i = 0; i < points.size(); i++) points[i].print();
}

