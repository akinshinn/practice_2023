#define _USE_MATH_DEFINES
#include "Header.h"

const double eps = 1e-7;
int get_bottom_point(const vector<Point>& points) {
	int bottom = 0;
	int n = points.size();
	for (int i = 1; i < n; i++) if (points[i].y_ < points[bottom].y_) bottom = i;
	return bottom;
}

double get_cos_angle_vectors(const Point& last_p, const Point& current_p, const Point& candidate_p) {
	MyVector a(last_p, current_p);
	MyVector b(candidate_p, current_p);
	if (a.len() < eps || b.len() < eps) return 2;
	return a.scalar(b) / (a.len() * b.len());
}

int get_min_cos_point(const vector<Point>& points, const Point& p, int id_p, int id_lastp) {
	double min = 2;
	int res = -1;
	double ccos;
	for (int i = 0; i < points.size(); i++) {
		if (i == id_p || i == id_lastp) continue;
		if (id_lastp != -1)  ccos = get_cos_angle_vectors(points[id_lastp], p, points[i]);
		else ccos = get_cos_angle_vectors(Point(p.x_ - 1,p.y_), p, points[i]);
		if (ccos < min) {
			min = ccos;
			res = i;
		}
	}

	return res;
}

vector<Point> Jarvis_algorithm(const vector<Point>& points) {
	vector<Point> res;
	vector<int> res2;
	int i = get_bottom_point(points);
	res.emplace_back(points[i]);
	res2.emplace_back(i);
	do
	{
		Point cp = res[res.size() - 1];
		if (res2.size() >= 2) i = get_min_cos_point(points, cp, res2[res2.size() - 1], res2[res2.size() - 2]);
		else i = get_min_cos_point(points, cp, res2[res2.size() - 1], -1);
		res.emplace_back(points[i]);
		res2.emplace_back(i);


	} while (res2[res2.size() - 1] != res2[0]);
	return res;
}

vector<Point> readf(std::string file) {
	std::ifstream in(file);
	int n;
	vector<Point> points;
	if (in.is_open())
	{
		in >> n;
		double x, y;
		for (int i = 0; i < n; i++) {
			in >> x >> y;
			points.emplace_back(Point(x, y));
		}
	}
	in.close();
	return points;
}

void write(string file, const vector<Point>& points) {
	ofstream out;
	out.open(file);
	if (out.is_open()) {
		out.clear();
		out << points.size() << endl;
		for (int i = 0; i < points.size(); i++) {
			out << points[i].x_ << " " << points[i].y_ << endl;
		}
	}
}

vector<Point> gen_data(int n) {
	int seed = time(0);
	srand(seed);
	vector<Point> data;
	int max_value = 20, random_value;
	for (int i = 0; i < n; i++) {
		data.emplace_back(Point(rand() % max_value, rand() % max_value));
	}
	return data;
}