#include "tools.h"
#include <windows.h>
#include <stdio.h>

void SetWindowSize(int cols, int lines) {  //设置窗口大小 函数
  system("title greedysnake");  //设置窗口标题
  char cmd[30];
  sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//  一个图形■占两个字符，故宽度乘以2
  system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}
void SetColor(int colorID) { //设置文本颜色
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor() {  //设置文本背景色
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
						  FOREGROUND_BLUE |
							  BACKGROUND_BLUE |
							  BACKGROUND_GREEN |
							  BACKGROUND_RED);
}
void SetCursorPosition(const int x, const int y) { // 设置光标位置
  COORD position;  // 屏幕缓冲区字符坐标
  position.X = x * 2;
  position.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);  //
}
