#include <iostream>
#include <windows.h>
#include "point.h"
#include "map.h"
#include "tools.h"
#include "controller.h"
#include "startinterface.h"   /// 游戏初始画面头文件
#include <conio.h>
#include <unistd.h>
#include "snake.h"
#include <ctime>

int main() {
  Controller c;
  c.Game();
  return 1;
}
