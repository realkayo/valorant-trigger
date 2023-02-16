#pragma once
#include <iostream>
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <tchar.h>
#include <string>
#include <TlHelp32.h>
#include <locale.h>  
#include <conio.h>
#include "color.h"

#pragma comment(lib, "gdiplus.lib")
class screenn
{
public:
      void DrawFilledRect(int x, int y, int w, int h) {
          HBRUSH EnemyBrush = CreateSolidBrush(0x000000FF);
          HDC screenDC = GetDC(HWND_DESKTOP);
          RECT rect = { x, y, x + w, y + h };
          FillRect(screenDC, &rect, EnemyBrush);
      }

      void DrawBorderBox(int x, int y, int w, int h, int thickness) {
          HBRUSH EnemyBrush = CreateSolidBrush(0x000000FF);
          HDC screenDC = GetDC(HWND_DESKTOP);
          DrawFilledRect(x, y, w, thickness);
          DrawFilledRect(x, y, thickness, h);
          DrawFilledRect(x + w - thickness, y, thickness, h);
          DrawFilledRect(x, y + h - thickness, w, thickness);
      }
};

