#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>

using namespace std;

// 定义颜色代码
// 0 = 黑色      8 = 灰色
// 1 = 蓝色      9 = 淡蓝色
// 2 = 绿色      A = 淡绿色
// 3 = 浅绿色    B = 淡浅绿色
// 4 = 红色      C = 淡红色
// 5 = 紫色      D = 淡紫色
// 6 = 黄色      E = 淡黄色
// 7 = 白色      F = 亮白色

//***
//* 生成圣诞树函数
//* 在控制台输出多彩圣诞树图案
//***
void PrintTree()
{
    int i, j;
    // 设置树顶的颜色为绿色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    // 打印树顶的星星
    for (j = 0; j < 30; j++) // 控制前面的空格，使星星居中
        cout << " ";
    cout << "*\n"; // 打印星星

    // 打印树顶的部分
    for (i = 1; i <= 3; i++) { // 控制树顶的行数
        for (j = 0; j < 29 - i; j++) // 控制前面的空格
            cout << " ";
        for (j = 0; j < (i * 2) + 1; j++) // 控制树顶的宽度
            cout << "@"; // 打印树顶的字符
        cout << "\n";
    }

    // 打印树身的三个部分
    for (int part = 0; part < 3; part++) { // 树身分为三个部分
        for (i = 1; i <= 4; i++) { // 每个部分有4行
            for (j = 0; j < 25 - part * 3 - i; j++) // 控制前面的空格
                cout << " ";
            for (j = 0; j < (i * 2) + (part * 6) + 3; j++) // 控制树身的宽度
                cout << "@"; // 打印树身的字符
            cout << "\n";
        }
    }

    // 打印树干（长方形形状）
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN); // 设置树干颜色为棕色
    for (i = 0; i < 5; i++) { // 树干高度为5行
        for (j = 0; j < 20; j++) // 控制前面的空格，使树干居中
            cout << " ";
        for (j = 0; j < 5; j++) // 树干宽度为5个字符
            cout << "@"; // 打印树干的字符
        cout << "\n";
    }
}

// 生成雪花函数
// 直接在控制台输出无规律的雪花
void PrintXueHua()
{
    srand((unsigned)time(0)); // 初始化随机数种子
    while (true) { // 使雪花不断生成
        HANDLE hd;
        COORD pos;
        hd = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出句柄

        // 随机生成雪花的位置
        pos.X = rand() % 80; // 设置雪花的横坐标范围为0-80
        pos.Y = rand() % 25; // 设置雪花的纵坐标范围为0-25

        SetConsoleCursorPosition(hd, pos); // 将光标移动到指定位置
        SetConsoleTextAttribute(hd, 7);    // 设置雪花颜色为白色
        cout << "*";                       // 输出雪花

        Sleep(500); // 稍作停顿，以便观察雪花的生成
    }
}

int main()
{
    system("color 0A"); // 设置控制台背景为黑色，前景为绿色
    // 调用生成圣诞树函数
    PrintTree();

    // 调用生成雪花函数
    PrintXueHua();

    return 0;
}