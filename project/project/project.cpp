#include "Header.h"

int main()
{
    //vector<Point> points = read("in.txt");
    vector<Point> points = gen_data(10000);
    
    int n = points.size();
    clock_t start = clock();
    vector<Point> above_points, below_points;
    get_above_below_points(above_points, below_points, points);
    //out(above_points);
    cout << endl;
    //out(below_points);
    cout << endl;
    vector<Point> res = get_polygon(above_points,points);
    vector<Point> res2 = get_polygon(below_points, points);
    clock_t end = clock();
    //out(res);
    cout << endl;
    //out(res2);
    cout << endl;
    //write("out.txt", res, res2);
    cout << (double)(end - start) / CLOCKS_PER_SEC;
}