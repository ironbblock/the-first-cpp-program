#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//����������ɫ, GREEN����ɫ���� ��ϸ���Բ�ege.h�������Ķ����ֵ
	setcolor(GREEN);

	//��һ��ֱ��, ��(100, 100)��(400, 150)
	//�ر�ע����Ƕ˵�, (100,100)�����ᱻ������ɫ, ��(400,150)���ử����ɫ
	//�������еľ���(����˵����)������ʽ, ����ǰһ����ȡ�õ�, ����һ����ȡ����

	line(100, 100, 400, 150);

	//����������ɫΪ��ɫ
	setcolor(EGERGB(0x23, 0x80, 0xF2));

	//��һ��ֱ��, ��(600,50)��(80,400)
	line(600, 50, 80, 400);

	getch();

	closegraph();

	return 0;
}
//#include<iostream>
//#include<graphics.h>
//int main()
//{
//	
//}
//using namespace std;
//int main()
//{
//	double a, b, c, x1, x2, dlt;
//	cout << "press a b c:\n";
//	cin >> a >> b >> c;
//	dlt = b * b - 4 * a * c;
//	if (a == 0)
//		cout << "GUN";
//	else if (dlt < 0)
//		cout << "GUN";
//	else
//	{
//		if (dlt == 0)
//		{
//			x1 = x2 = -b / 2 / a;
//			cout << "x1=x2=" << x1;
//		}
//		else
//		{
//			x1 = -b + dlt / 2 / a;
//			x2 = -b - dlt / 2 / a;
//			cout << "x1=" << x1 << "  x2=" << x2;
//		}
//	}
//	system("pause");
//	return 0;
//}