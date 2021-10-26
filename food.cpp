#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>

void Food::DrawFood(Snake &csnake) {  /// 食物生成

  while (true) {
	int tmp_x = rand() % 30;
	int tmp_y = rand() % 30;
	/// 刷新位置随机
	if (tmp_x < 2) tmp_x += 2;  // 防止刷新在边界处
	if (tmp_y < 2) tmp_y += 2;
	bool flag = false;
	for (auto &point : csnake.snake) {
	  if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == big_x && tmp_y == big_y)) {
	    /// 条件为真时表示， snake头部 = food的位置(tmp_x, tmp_y)
		flag = true;
		break;
	  }
	}
	if (flag) continue;
	x = tmp_x;
	y = tmp_y;
	SetCursorPosition(x, y);
	SetColor(13);
	std::cout << "f";
	++cnt;  // 刷新次数
	cnt %= 5;  // 每5次刷新一个大食物
	if (cnt == 0) {
	  DrawBigFood(csnake);
	}
	break;
  }
}
void Food::DrawBigFood(Snake &csnake) {
  SetCursorPosition(5, 0);
  SetColor(11);
  std::cout << "-----------------------------------------";
  progress_bar = 42;
  while (true) {
	int tmp_x = rand() % 30;
	int tmp_y = rand() % 30;
	if (tmp_x < 2) tmp_x += 2;
	if (tmp_y < 2) tmp_y += 2;
	bool flag = false;
	for (auto &point : csnake.snake) {
	  if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y)) {
		flag = true;
		break;
	  }
	}
	if (flag) continue;
	big_x = tmp_x;
	big_y = tmp_y;
	SetCursorPosition(big_x, big_y);
	SetColor(18);
	std::cout << "f";
	big_flag = true;
	flash_flag = true;
	break;
  }
}

int Food::GetCnt() {
  return cnt;
}

void Food::FlashBigFood() {
  SetCursorPosition(big_x, big_y);
  SetColor(18);
  if (flash_flag) {
	std::cout << " ";
	flash_flag = false;
  } else {
	std::cout << "f";
	flash_flag = true;
  }
  SetCursorPosition(26, 0);
  SetColor(11);
  for (int i = 42; i >= progress_bar; --i) {
    std::cout << "\b \b";
  }
  --progress_bar;
  if (progress_bar == 0) {
	SetCursorPosition(big_x, big_y);
	std::cout << " ";
	big_flag = false;
	big_x = 0;
	big_y = 0;
  }
}

bool Food::GetBigFlag() {  /// 返回游戏中有闪烁的大食物存在时
  return big_flag;
}

int Food::GetProgressBar() {
  return progress_bar;
}



