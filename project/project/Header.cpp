#include "Header.h"


using namespace std;

// Получаем точки над и под прямой, проходящей через граничные точки(т.е. с мин. и макс. координатами по x)
void get_above_below_points(vector<Point>& above_points, vector<Point>& below_points, vector<Point> points) {
	int n = points.size();
	double xmin = points[0].x_, ymin = points[0].y_;
	double xmax = points[0].x_, ymax = points[0].y_;
	for (int i = 1; i < n; i++) {
		if (points[i].x_ < xmin) {
			xmin = points[i].x_; ymin = points[i].y_;
		}
		if (points[i].x_ > xmax) {
			xmax = points[i].x_; ymax = points[i].y_;
		}
	}
	for (int i = 0; i < n; i++) {
		if (points[i].y_ >= get_y_coordinate(Point(xmin, ymin), Point(xmax, ymax), points[i].x_)) 
			above_points.emplace_back(points[i]);
		else below_points.emplace_back(points[i]);
	}

	quicksort(above_points, 0, above_points.size()-1);
	below_points.emplace_back(above_points[0]);
	below_points.emplace_back(above_points[above_points.size() - 1]);
	quicksort(below_points, 0, below_points.size()-1, false);

}

int partition(vector<Point>& a, int start, int end, bool increase)
{
	double pivot = a[end].x_;

	int pIndex = start;

	if (increase) {
		for (int i = start; i < end; i++)
		{
			if (a[i].x_ <= pivot)
			{
				swap(a[i], a[pIndex]);
				pIndex++;
			}
		}
	}
	else {
		for (int i = start; i < end; i++)
		{
			if (a[i].x_ >= pivot)
			{
				swap(a[i], a[pIndex]);
				pIndex++;
			}
		}
	}


	swap(a[pIndex], a[end]);

	return pIndex;
}

void quicksort(vector<Point>& a, int start, int end, bool increase)
{
	if (start >= end) {
		return;
	};

	int pivot = partition(a, start, end, increase);

	quicksort(a, start, pivot - 1, increase);

	quicksort(a, pivot + 1, end, increase);
}

vector<Point> get_polygon(const vector<Point>& local_points, const vector<Point>& all_points) {
	std::vector<Point> res;
	if (local_points.size() == 0) return res;
	int n = local_points.size();
	Point p1, p2;
	res.emplace_back(local_points[0]);
	for (int i = 0; i < n; i++) {
		p1 = Point(local_points[i].x_ , local_points[i].y_);
		for (int j = i+1; j < n; j++) {
			p2 = Point(local_points[j].x_, local_points[j].y_);
			if (check_segment(p1, p2, all_points)) {
				res.emplace_back(p2);
				break;
			};
		}
	}
	return res;
}

bool check_segment(const Point& p1, const Point& p2, const vector<Point>& points) {
	bool ArePreviousBeenUpper = 1; // все предыдущие были: 1 - выше, 0 - ниже
	bool isUpperThanLine = 1;
	double x, y_true, liney;
	for (int i = 0; i < points.size(); i++) {
		x = points[i].x_;
		if (p1.x_ == p2.x_ && x == p1.x_) continue;
		if (p1.x_ == p2.x_ && x > p1.x_) {
			if (isUpperThanLine != ArePreviousBeenUpper) return 0;
		}
		else {
			y_true = points[i].y_;
			liney = get_y_coordinate(p1, p2, x);
			if (y_true == liney) continue;
			isUpperThanLine = (y_true > liney);
			if (i == 0 && !isUpperThanLine) {
				ArePreviousBeenUpper = 0;
				continue;
			}

			if (isUpperThanLine != ArePreviousBeenUpper) return 0;
		}
		
	}
	return 1;
}

double get_y_coordinate(const Point& p1, const Point& p2, double x) {
	return (p2.y_ - p1.y_) / (p2.x_ - p1.x_) * (x - p1.x_) + p1.y_;
};

vector<Point> read(const string& file) {

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

void write(const string& file, const vector<Point>& above_points, const vector<Point>& below_points) {
	ofstream out;
	out.open(file);
	if (out.is_open()) {
		out.clear();
		out << above_points.size() + below_points.size() - 1 << endl;
		for (int i = 0; i < above_points.size(); i++) {
			out << above_points[i].x_ << " " << above_points[i].y_ << endl;
		}
		for (int i = 0; i < below_points.size(); i++) {
			out << below_points[i].x_ << " " << below_points[i].y_ << endl;
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