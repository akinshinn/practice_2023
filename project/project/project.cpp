#include "Header.h"

int main()
{
    vector<Point> points = read("in.txt");
    int n = points.size();
    vector<Point> above_points, below_points;
    get_above_below_points(above_points, below_points, points);
    out(above_points);
    cout << endl;
    out(below_points);
    cout << endl;
    std::vector<Point> res = get_polygon(above_points,points);
    vector<Point> res2 = get_polygon(below_points, points);
    out(res);
    cout << endl;
    out(res2);
    cout << endl;
    write("out.txt", res, res2);
}