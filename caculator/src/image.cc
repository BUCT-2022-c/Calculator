

#define bei 0.02857142
//#define pi 3.1415926
#include "image.h"
using namespace std;
//绘制背景
void abstract_graph(int graphic_x, int graphic_y) {
	//int graphic_x = 700;
	//int graphic_y = 700;
	initgraph(graphic_x, graphic_y);
	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(LIGHTGRAY);//设置辅助线颜色
	for (int i = 0; i < 701; i += 35) {
		line(0, i, graphic_x, i);
		line(i, 0, i, graphic_y);
	}
	setlinecolor(BLACK);//设置坐标轴颜色
	line(0, graphic_y / 2, graphic_x, graphic_y / 2);
	line(graphic_x / 2, 0, graphic_x / 2, graphic_y);

	POINT x_pts[] = { {693, 343}, {graphic_x, graphic_y / 2}, {693, 357} };
	polyline(x_pts, 3);
	POINT y_pts[] = { {343, 7}, {graphic_x / 2, 0}, {357, 7} };
	polyline(y_pts, 3);

	settextcolor(BLACK);//设置字体颜色
	outtextxy(graphic_x - 10, graphic_y / 2 + 7, 'x');
	outtextxy(350 - 10, graphic_y / 2 + 7, '0');
	outtextxy(175 - 9, graphic_y / 2 + 7, '-');
	outtextxy(175 - 4, graphic_y / 2 + 7, '5');
	outtextxy(525 - 4, graphic_y / 2 + 7, '5');
	outtextxy(graphic_x / 2 - 15, 0, 'y');
	outtextxy(graphic_x / 2 - 20, 525 - 10 + 4, '-');
	outtextxy(graphic_x / 2 - 15, 175 - 10 + 4, '5');
	outtextxy(graphic_x / 2 - 15, 525 - 10 + 4, '5');
	setorigin(graphic_x / 2, graphic_y / 2);
}
//绘制函数
void print_graph(double a, double b, double c, double d, int parameter) {
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	int temp;
	switch (parameter) {
	case 1: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(b * 35 + i * a);
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 2: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(c * 35 + i * b + pow(i, 2) * bei * a);
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 3: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * sin(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 4: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * cos(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 5: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * tan(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 6: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * tan(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 7: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * asin(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 8: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * acos(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 9: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * atan(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 10: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * sinh(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 11: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * cosh(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 12: {
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * tanh(c * bei + i * bei * d));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	case 13: {
		if (d <= 1 or c <= 1) {
			break;
		}
		for (int i = -350; i < 350; i++) {
			temp = (int)(a * 35 + b * 35 * log(i * bei * d) / log(c));
			putpixel(i, -(int)temp, LIGHTBLUE);
			putpixel(i, -(int)(temp - 1), LIGHTBLUE);
			putpixel(i, -(int)(temp + 1), LIGHTBLUE);
		}
		break;
	}
	}
}

void graph::welcome() {
	cout << "********函数图像********" << endl;
	cout << "1.一次函数" << endl;
	cout << "2.二次函数" << endl;
	cout << "3.正弦函数" << endl;
	cout << "4.余弦函数" << endl;
	cout << "5.正切函数" << endl;
	cout << "6.余切函数" << endl;
	cout << "7.反正弦函数" << endl;
	cout << "8.反余弦函数" << endl;
	cout << "9.反正切函数" << endl;
	cout << "10.双曲正弦函数" << endl;
	cout << "11.双曲余弦函数" << endl;
	cout << "12.双曲正切函数" << endl;
	cout << "13.对数函数" << endl;
	get_time();
	cout << "***********************" << endl;
	cout << "请输入您的选择：";
	cin >> this->parameter;
	system("cls");
	switch (parameter) {
	case 1: {
		//todo
		cout << "您的选择为一次函数" << endl;
		cout << "格式： a * x + b " << endl;
		cout << "请依次输入a b" << endl;
		cin >> this->a >> this->b;
		this->c = 0;
		this->d = 0;
		break;
	}
	case 2: {
		//todo
		cout << "您的选择为二次函数" << endl;
		cout << "格式： a * x^2 + b * x + c" << endl;
		cout << "请依次输入a b c " << endl;
		cin >> this->a >> this->b >> this->c;
		this->d =0;
		break;
	}
	case 3: {
		//todo
		cout << "您的选择为正弦函数" << endl;
		cout << "格式： a + b * sin(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a>> this->b >> this->c >> this->d;
		break;
		}
	case 4: {
		//todo
		cout << "您的选择为余弦函数" << endl;
		cout << "格式： a + b * cos(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 5: {
		//todo
		cout << "您的选择为正切函数" << endl;
		cout << "格式： a + b * tan(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 6: {
		//todo
		cout << "您的选择为余切函数" << endl;
		cout << "格式： a + b * cot(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 7: {
		//todo
		cout << "您的选择为反正弦函数" << endl;
		cout << "格式： a + b * arcsin(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 8: {
		//todo
		cout << "您的选择为反余弦函数" << endl;
		cout << "格式： a + b * arccot(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 9: {
		//todo
		cout << "您的选择为反正切函数" << endl;
		cout << "格式： a + b * arccot(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 10: {
		//todo
		cout << "您的选择为双曲正弦函数" << endl;
		cout << "格式： a + b * arccot(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 11: {
		//todo
		cout << "您的选择为双曲余弦函数" << endl;
		cout << "格式： a + b * arccot(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 12: {
		//todo
		cout << "您的选择为双曲正切函数" << endl;
		cout << "格式： a + b * arccot(c + d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	case 13: {
		//todo
		cout << "您的选择为对数函数" << endl;
		cout << "格式： a + b * logc(d * x)" << endl;
		cout << "请依次输入a b c d" << endl;
		cin >> this->a >> this->b >> this->c >> this->d;
		break;
	}
	default: {
		cout << "输入错误";
		  }
	}

}
bool graph::check_input()
{
	if (a > 1000000 or b > 1000000 or c > 1000000 or d > 1000000 or a < -1000000 or b < -1000000 or c < -1000000 or d < -1000000)
	{
		cout << "[Error] input error";
		return 0;
	}
	return 1;
}
double graph::get_a() {
	return this->a;
}
double graph::get_b() {
	return this->b;
}
double graph::get_c() {
	return this->c;
}
double graph::get_d() {
	return this->d;
}
int graph::get_parameter() {
	return this->parameter;
}


//int main() {
//
//	/*graph s1;
//	if (s1.check_input()) {
//		abstract_graph(700, 700);
//		print_graph(s1.get_a(), s1.get_b(), s1.get_c(), s1.get_d(), s1.get_parameter());
//	}*/
//	
//
//
//	_getch();
//	closegraph();
//	system("pause");
//	return 0;
//}