#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>

using namespace std;

// ������ɫ����
// 0 = ��ɫ      8 = ��ɫ
// 1 = ��ɫ      9 = ����ɫ
// 2 = ��ɫ      A = ����ɫ
// 3 = ǳ��ɫ    B = ��ǳ��ɫ
// 4 = ��ɫ      C = ����ɫ
// 5 = ��ɫ      D = ����ɫ
// 6 = ��ɫ      E = ����ɫ
// 7 = ��ɫ      F = ����ɫ

//***
//* ����ʥ��������
//* �ڿ���̨������ʥ����ͼ��
//***
void PrintTree()
{
    int i, j;
    // ������������ɫΪ��ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    // ��ӡ����������
    for (j = 0; j < 30; j++) // ����ǰ��Ŀո�ʹ���Ǿ���
        cout << " ";
    cout << "*\n"; // ��ӡ����

    // ��ӡ�����Ĳ���
    for (i = 1; i <= 3; i++) { // ��������������
        for (j = 0; j < 29 - i; j++) // ����ǰ��Ŀո�
            cout << " ";
        for (j = 0; j < (i * 2) + 1; j++) // ���������Ŀ��
            cout << "@"; // ��ӡ�������ַ�
        cout << "\n";
    }

    // ��ӡ�������������
    for (int part = 0; part < 3; part++) { // �����Ϊ��������
        for (i = 1; i <= 4; i++) { // ÿ��������4��
            for (j = 0; j < 25 - part * 3 - i; j++) // ����ǰ��Ŀո�
                cout << " ";
            for (j = 0; j < (i * 2) + (part * 6) + 3; j++) // ��������Ŀ��
                cout << "@"; // ��ӡ������ַ�
            cout << "\n";
        }
    }

    // ��ӡ���ɣ���������״��
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN); // ����������ɫΪ��ɫ
    for (i = 0; i < 5; i++) { // ���ɸ߶�Ϊ5��
        for (j = 0; j < 20; j++) // ����ǰ��Ŀո�ʹ���ɾ���
            cout << " ";
        for (j = 0; j < 5; j++) // ���ɿ��Ϊ5���ַ�
            cout << "@"; // ��ӡ���ɵ��ַ�
        cout << "\n";
    }
}

// ����ѩ������
// ֱ���ڿ���̨����޹��ɵ�ѩ��
void PrintXueHua()
{
    srand((unsigned)time(0)); // ��ʼ�����������
    while (true) { // ʹѩ����������
        HANDLE hd;
        COORD pos;
        hd = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼������

        // �������ѩ����λ��
        pos.X = rand() % 80; // ����ѩ���ĺ����귶ΧΪ0-80
        pos.Y = rand() % 25; // ����ѩ���������귶ΧΪ0-25

        SetConsoleCursorPosition(hd, pos); // ������ƶ���ָ��λ��
        SetConsoleTextAttribute(hd, 7);    // ����ѩ����ɫΪ��ɫ
        cout << "*";                       // ���ѩ��

        Sleep(500); // ����ͣ�٣��Ա�۲�ѩ��������
    }
}

int main()
{
    system("color 0A"); // ���ÿ���̨����Ϊ��ɫ��ǰ��Ϊ��ɫ
    // ��������ʥ��������
    PrintTree();

    // ��������ѩ������
    PrintXueHua();

    return 0;
}