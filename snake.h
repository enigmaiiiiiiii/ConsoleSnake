#ifndef GREEDYSNAKE_SNAKE_H
#define GREEDYSNAKE_SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

class Food;
class Snake {
 public:
  enum Direction{UP,DOWN,LEFT,RIGHT};  // 不限定作用域枚举类型

  Snake() {
	snake.emplace_back(14,8);
	snake.emplace_back(15,8);
	snake.emplace_back(16,8);
	direction = Direction::DOWN;
  }
  void InitSnake();
  void Move();
  void NormalMove();
  bool OverEdge();
  bool HitItself();
  bool ChangeDirection();
  bool GetFood(const Food&);
  bool GetBigFood(Food&);
 private:
  std::deque<Point> snake;
  Direction direction;  /// snake当前运动方向
  friend class Food;
};
#endif //GREEDYSNAKE_SNAKE_H
