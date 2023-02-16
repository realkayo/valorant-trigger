#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include "main_menu.h"
#include "SkCR.h"

class trigger
{
public:

    void main_trigger() {

        const int screenWidth = 80;
        const int screenHeight = 50;
        HBRUSH EnemyBrush = CreateSolidBrush(0x000000FF);
        HDC screenDC = GetDC(HWND_DESKTOP);

        int screenCenterX = GetSystemMetrics(SM_CXSCREEN) / 2;
        int screenCenterY = GetSystemMetrics(SM_CYSCREEN) / 2;
        int width = 8;
        int height = 10;

        int x = screenCenterX - width / 2;
        int y = screenCenterY - height / 2;

        bool hold_mode = false;
        bool tap_mode = false;
        bool ta_color = false;
        int tap_delay = 250;
        menu(width, height, tap_mode, tap_delay);
        color cor;
        screenn screenn;


        Gdiplus::GdiplusStartupInput gdiplusStartupInput;
        ULONG_PTR gdiplusToken;
        GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

        HDC memoryDC = CreateCompatibleDC(screenDC);
        HBITMAP memoryBitmap = CreateCompatibleBitmap(screenDC, width, height);

        while (true) {
            if (GetAsyncKeyState(VK_UP))
            {
                ta_color = true;
            }

            if (GetAsyncKeyState(VK_DOWN))
            {
                ta_color = false;
            }


            if (GetAsyncKeyState(VK_XBUTTON2)) {

                HGDIOBJ oldBitmap = SelectObject(memoryDC, memoryBitmap);
                BitBlt(memoryDC, 0, 0, width, height, screenDC, x, y, SRCCOPY);
                SelectObject(memoryDC, oldBitmap);

                Gdiplus::Bitmap bitmap(memoryBitmap, nullptr);
                Gdiplus::Color color;

                bool stop_loop = false;

                for (int i = 0; i < height && !stop_loop; ++i) {
                    for (int j = 0; j < width && !stop_loop; ++j) {
                        bitmap.GetPixel(i, j, &color);

                        if (cor.isPurple(color.GetR(), color.GetG(), color.GetB())) {
                            stop_loop = true;

                            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                            screenn.DrawBorderBox(screenCenterX + j - 15, screenCenterY + i - 10, 30, 30, 2);
                            Sleep(200);
                        }
                    }
                }
            }
            else
            {
                bool hold_mode = false;
            }

            if (ta_color == true) {
                HGDIOBJ oldBitmap = SelectObject(memoryDC, memoryBitmap);
                BitBlt(memoryDC, 0, 0, width, height, screenDC, x, y, SRCCOPY);
                SelectObject(memoryDC, oldBitmap);

                Gdiplus::Bitmap bitmap(memoryBitmap, nullptr);
                Gdiplus::Color color;

                bool stop_loop = false;

                for (int i = 0; i < height && !stop_loop; ++i) {
                    for (int j = 0; j < width && !stop_loop; ++j) {
                        bitmap.GetPixel(i, j, &color);

                        if (cor.isPurple(color.GetR(), color.GetG(), color.GetB())) {
                            stop_loop = true;

                            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                            screenn.DrawBorderBox(screenCenterX + j - 15, screenCenterY + i - 10, 30, 30, 2);
                            Sleep(300);
                        }
                    }
                }
            }
        }



    };


    void menu(int width, int height, bool tap_mode, int tap_delay  ) {
        SetConsoleTitleA(skCrypt("Lucid Dreams | V1 |"));
        printf(skCrypt("\n                                                                                                \033[0;36mSua assinatura:\033[0m Lifetime"));
        std::cout << "\033[36m" << skCrypt(R"(
_              _     _        _                              
| |            (_)   | |      | |                             
| | _   _  ____ _  __| |    __| | ____ _____ _____ ____   ___ 
| || | | |/ ___) |/ _  |   / _  |/ ___) ___ (____ |    \ /___) made by)");
std::cout << "\033[0m" << skCrypt(R"(
| || |_| ( (___| ( (_| |  ( (_| | |   | ____/ ___ | | | |___ |        kayo
 \_)____/ \____)_|\____|   \____|_|   |_____)_____|_|_|_(___/ 
                                                        
)");


        printf(skCrypt("\n\033[0;36mAlways ON/OFF:\033[0m Arrow Up/Arrow Down"));
        std::cout << skCrypt("          \033[0;36mFOV do trigger:\033[0m ") << width << skCrypt("\033[0m\033[0;36mx\033[0m") << height << skCrypt(" (Altura\033[0;36m e \033[0mLargura)") << std::endl;
        printf(skCrypt("\033[36mHold MODE:\033[0m XButton2"));
        std::cout << skCrypt("\n\033[36mTap MODE:\033[0m ") << tap_mode << skCrypt("                                 \033[0;36mTap Delay:\033[0m ") << tap_delay << skCrypt("ms ") << std::endl;
        printf(skCrypt("\033[36mEnemy color:\033[0m Purple\n"));


    }

};