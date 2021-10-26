#ifndef GREEDYSNAKE_DEMO_POINT_H_
#define GREEDYSNAKE_DEMO_POINT_H_

class Point {
 public:
  Point() = default;
  Point(const int x, const int y) : x(x), y(y) {}
  void Print() const;
  void PrintCircular() const;
  void Clear() const;
  void ChangePosition(int a, int b);
  bool operator==(const Point &point) const  {return (point.x == this->x) && (point.y == this->y);}
  int GetX() const {return this->x;}
  int GetY() const {return this->y;}
 private:
  int x, y;


};

#endif //GREEDYSNAKE_DEMO_POINT_H_
