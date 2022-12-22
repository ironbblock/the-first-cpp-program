#include <graphics.h>

int main()
{
	initgraph(640, 480);

	//设置线条颜色, GREEN是颜色常数 详细可以查ege.h对这个宏的定义的值
	setcolor(GREEN);

	//画一条直线, 从(100, 100)到(400, 150)
	//特别注意的是端点, (100,100)这个点会被画上颜色, 但(400,150)不会画上颜色
	//以下所有的矩形(或者说两点)描述方式, 总是前一个点取得到, 但后一个点取不到

	line(100, 100, 400, 150);

	//设置线条颜色为蓝色
	setcolor(EGERGB(0x23, 0x80, 0xF2));

	//画一条直线, 从(600,50)到(80,400)
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