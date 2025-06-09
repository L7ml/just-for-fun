#include<windows.h>
#include<stdio.h>
#include<time.h>

void color(const unsigned short textColor);
void goto_xy(int x, int y);
void tree(int height, int colorOfLeaves);
void snow(int n);

/*根据参数改变字体颜色*/
void color(const unsigned short textColor)
{
    if (textColor >= 0 && textColor <= 15) {
        //参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
    }
    else {
        //默认的字体颜色是白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}
/*定位光标位置到指定坐标*/
void goto_xy(int x, int y) {
    HANDLE hout;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x,y };
    SetConsoleCursorPosition(hout, pos);
}
/*画圣诞树*/
void tree(int height, int colorOfLeaves) {
    //画五角星
    if (colorOfLeaves == 10) {
        color(3);
    }
    else {
        color(11);
    }
    goto_xy(24, 3);
    printf("%c%c\n", 161, 239);//GBK中五角星对应的编码为A1EF，换成十进制就是161 239
    //画叶子
    color(colorOfLeaves);
    for (int i = 1; i < height; i++) {
        if (colorOfLeaves == 14) {
            Sleep(60);
        }
        goto_xy(25 - i - 1, i + 3);
        for (int j = 2 * i + 2; j > 0; j--) {
            printf("*");
        }
        printf("\n");
    }
    //画树干
    goto_xy(25 - 1, height + 3);
    color(4);
    printf("||");
    printf("\n");
}
/*绘制雪景*/
void snow(int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int x = rand() % 50;
        int y = rand() % 15;
        goto_xy(x, y);
        color(7);
        if (i < n - 5) {
            printf("·");
        }
        else {
            printf("*");
        }

    }
}
int main() {
    system("title 圣诞快乐!");
    system("mode con cols=50 lines=15");//设置窗口大小

    while (1) {
        snow(30);
        tree(10, 10);
        Sleep(1000);//延迟1000毫秒
        tree(10, 14);   
        Sleep(1000);//延迟1000毫秒
        system("cls");//清屏
    }
    return 0;
}