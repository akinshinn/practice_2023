def coord_line(line, x):
    p1, p2 = line[0], line[1]
    x1, y1 = p1
    x2, y2 = p2
    if x2 == x1:
        return float("inf")
    return (y2-y1)/(x2-x1) * x


def get_segment(line, points):
    p1_l, p2_l = line[0], line[1]
    left, right = False, False
    for p in points:
        x, y = p[0], p[1]
        if y > coord_line(line, x):
            left = True
        if y < coord_line(line, x):
            rigth = True
        if left and right:
            return False
    if left or rigth:
        return True


n = int(input())
points = []
for _ in range(n):
    x, y = map(float, input().split())
    points += [[x, y]]
print(points)

segments = []
for i in range(n):
    for j in range(i+1, n):
        p1 = points[i]
        p2 = points[j]
        

print(segments)
