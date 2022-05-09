#include "matrix.h"

using namespace std;

void input(int m, int* p);
void martixinput(int m, int* p1, int* p2);
void add(int* ju);
void reduce(int* ju);
void multi(int* ju);
void trans(int* ju);
void temp(double aa[], double bb[], int n);
double fun(double** f, int n);
void tridet(int* ju);
void oppo(int* ju);
void back(int* ju);
float MatDet(float* p, int n);
float Creat_M(float* p, int m, int n, int k);
void print(float* p, int n);
int trace();
void trace(int* ju);
void solve(int* ju);
void example();


void example(){
	cout << "针对矩阵输入格式,请仿照示例进行输入:" << endl;
	cout << "        3 2 3 " << endl;
	cout << "3*3矩阵 2 2 3 的输入格式是:3 2 3 2 2 3 0 3 2" << endl;
	cout << "        0 3 2 " << endl;
}


// int main() 
// {
// 	express();
// 	return 0;
// }

void input(int m, int* p) {
	int cnt = 0, i = 0;
	do {
	outloop1:
		cin >> *(p + i); //输入一个数
		cnt++; //个数累加1
		i++;
	} while (cin.get() != '\n');
	if (cnt < m) {
		cout << "您未输入完所有数字,本次输入作废,请重新输入(将本矩阵重新输入)" << endl << endl;
		cnt = 0;
		goto outloop1;
	}
	else if (cnt > m) {
		cout << "您的输入超限,超出规格的输入不会被计入处理" << endl;
	}
	else {
		cout << "您的输入成功" << endl;
	}
	return;
}

void martixinput(int m, int* p1, int* p2) {
	cout << "请开始输入第一个矩阵:";
	input(m, p1);
	cout << endl << "请开始输入第二个矩阵:";
	input(m, p2);
}

//矩阵相加
void add(int* ju) {
	write_history mat("matrix");
	int m, n;
	cout << "你将会输入两个矩阵,";
	cout << "请输入这两个矩阵的行数与列数" << endl;
	cout << "行数:"; cin >> m;
	cout << "列数:"; cin >> n;
	int* p1 = new int[m * n];
	int* p2 = new int[m * n];
	int* p = new int[m * n];
	martixinput(m * n, p1, p2);
	mat.write_his(p1,m,n);
	mat.write_his("+\n");
	mat.write_his(p2,m,n);
	mat.write_his("=\n");
	for (int i = 0; i < m * n; i++) {
		p[i] = p1[i] + p2[i];
	}
	cout << endl << "相加结果是:" << endl;

	for (int i = 0; i < m; i++) {
		cout << "   ";
		for (int j = i * (n); j < (i + 1) * (n); j++) {
			cout << setw(4) << p[j];
		}
		cout << endl;
	}
	mat.write_his(p,m,n);
	solve(ju);
}

//矩阵相减
void reduce(int* ju) {
	write_history mat("matrix");
	int m, n;
	cout << "你将会输入两个矩阵,";
	cout << "请输入这两个矩阵的行数与列数" << endl;
	cout << "行数:"; cin >> m;
	cout << "列数:"; cin >> n;

	int* p1 = new int[m * n];
	int* p2 = new int[m * n];
	int* p = new int[m * n];
	martixinput(m * n, p1, p2);
	mat.write_his(p1,m,n);
	mat.write_his("-\n");
	mat.write_his(p2,m,n);
	mat.write_his("=\n");
	for (int i = 0; i < m * n; i++) {
		p[i] = p1[i] - p2[i];
	}
	cout << endl << "相减结果是:" << endl;
	mat.write_his(p,m,n);
	for (int i = 0; i < m; i++) {
		cout << "   ";
		for (int j = i * (n); j < (i + 1) * (n); j++) {
			cout << setw(4) << p[j];
		}
		cout << endl;
	}

	solve(ju);
}

//矩阵相乘
void multi(int* ju) {
	write_history mat("matrix");
	int m, n, z;
	cout << "你将会输入两个矩阵." << endl;
	cout << "请输入  A矩阵的行数, A矩阵的列数/B矩阵的行数 ,B矩阵的列数" << endl;

	cin >> m >> n >> z;
	int* p1 = new int[m * n];
	cout << "请开始输入第一个矩阵:";
	input(m * n, p1);
	int* p2 = new int[n * z];
	cout << endl << "请开始输入第二个矩阵:";
	input(n * z, p2);
	cout << endl;
	mat.write_his(p1,m,n);
	mat.write_his("*\n");
	mat.write_his(p2,n,z);
	mat.write_his("=\n");
	int* p = new int[m * z];
	for (int i = 0; i < m * z; i++) {
		p[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < z; j++) {
			for (int a = 0; a < n; a++) {
				p[i * z + j] += p1[i * n + a] * p2[a * z + j];
			}
		}
	}
	cout << "矩阵相乘结果是:" << endl;
	for (int i = 0; i < m; i++) {
		cout << "   ";
		for (int j = i * (z); j < (i + 1) * (z); j++) {
			cout << setw(4) << p[j];
		}
		cout << endl;
	}
	mat.write_his(p,m,z);
	solve(ju);
}

//矩阵转置
void trans(int* ju) {
	write_history mat("matrix");
	int m, n;
	cout << "你需要输入一个矩阵的行数与列数." << endl;
	cout << "行数:"; cin >> m;
	cout << "列数:"; cin >> n;
	int* p = new int[m * n];
	cout << "请开始输入矩阵:";
	input(m * n, p);
	mat.write_his(p,m,n);
	mat.write_his("转置为:\n");
	cout << "矩阵转置结果是:" << endl;
	int* pnew = new int[m * n];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < m; j++) {
			pnew[i * m + j] = p[i + cnt];
			cnt = cnt + n;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << "   ";
		for (int j = i * (m); j < (i + 1) * (m); j++) {
			cout << setw(5) << pnew[j];
		}
		cout << endl;
	}
	mat.write_his(pnew,n,m);
	solve(ju);
}

//矩阵求上三角和行列式
void tridet(int* ju) {
	write_history mat("matrix");
	int n;
	double det;
	int i, j, kk = 0;
	cout << "请输入一个方阵的行/列数:" << endl;
	cin >> n;
	double** f = new double* [n];
	for (int i = 0; i < n; i++) {
		f[i] = new double[n];
	}
	cout << "请开始输入矩阵:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> f[i][j];
		}
	}
	int *p = new int [n*n];
	int z=0;
	for (int i=0;i<n;i++)
	{
		for(int l=0;l<n;l++)
		{
			p[z]=f[i][l];
			z++;
		}
	}
	mat.write_his(p,n,n);
	det = fun(f, n);       //获取行列式的值  
	
	mat.write_his("行列式的值为:\n");
	cout << "矩阵的行列式的值为:" << det << endl;
	mat.write_his(to_string(det));
	cout << "转换的上三角矩阵为:" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			cout << setw(7) << f[i][j];
			kk = kk + 1;
			if (kk % n == 0)
				cout << endl;
		}
	cout << endl;
	z=0;
	for (int i=0;i<n;i++)
	{
		for(int l=0;l<n;l++)
		{
			p[z]=f[i][l];
			z++;
		}
	}
	mat.write_his("\n上三角矩阵为:\n");
	mat.write_his(p,n,n);
	solve(ju);
}

void temp(double aa[], double bb[], int n)
{
	int i;
	double temp1;
	for (i = 0; i < n; i++)
	{
		temp1 = aa[i];
		aa[i] = bb[i];
		bb[i] = temp1;
	}
}

double fun(double** f, int n)
{
	int ii, jj, k, u;
	int iter = 0;  //记录行变换的次数(交换)
	double det1 = 1, yin;

	for (ii = 0; ii < n; ii++) {
		if (f[ii][ii] == 0)
			for (jj = ii; jj < n; jj++) {
				if (f[jj][ii] != 0) {
					temp(f[ii], f[jj], n);//交换两行  
					iter++;
				}
			}

		for (k = ii + 1; k < n; k++)
		{
			yin = -1 * f[k][ii] / f[ii][ii];

			for (u = 0; u < n; u++)
			{
				f[k][u] = f[k][u] + f[ii][u] * yin;
			}
		}
	}
	for (ii = 0; ii < n; ii++)  //求对角线的积 即 行列式的值
		det1 = det1 * f[ii][ii];
	//行变换偶数次符号不变
	if (iter % 2 == 1)
		det1 = -det1;
	return (det1);
}

//矩阵求特征值
void oppo(int* ju) {
	double det;
	
	double** f = new double* [2];
	for (int i = 0; i < 2; i++) {
		f[i] = new double[2];
	}
	cout << "请开始输入一个2*2矩阵:" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> f[i][j];
		}
	}
	det = fun(f, 2);       //获取行列式,行列式是特征值之积
	int tra = f[0][0];
	for (int i = 1; i < 2; i++) {//0,4,8
		tra = tra + f[i][i];
	}		//获取迹,迹是特征值之和
	int root1=0, root2=0;
	if (det > 0) {//证明两根同号,那么取其int i=1开始,算到小于abs(trace)
		for (int i = 1; i < abs(tra); i++) {//root1
			for (int j = 1; j < abs(tra); j++) {
				if (i + j == abs(tra) && (i * j) == det) {//找到,为避免重复,设定root1小于等于root2
					if (i <= j) {
						if (tra>0) {//判断两根正负情况
							root1 = i; root2 = j;
						}
						else {
							root1 =(-1)* i; root2 = (-1) * j;
						}
					}
				}
			}
		}
	}
	else if (det == 0) {
		root1 = 0; root2 = tra;
	}
	else {//两根异号
		int m = 2 * abs(tra);
		int max = (abs(det) > abs(tra)) ? abs(det) :m;//最大不过他俩中的一个
		for (int i = 1; i < max; i++) {
			for (int j = -1; j >(-1)* max; j--) {
				if (i + j == tra && (i * j) == det) {
					root1 = i; root2 = j;
				}
			}
		}
	}
	if (root1 == 0 && root2 == 0) {
		cout << "未找到特征值的整数解,但可能存在非整数解；" << endl;
	}
	else {
		cout << "解一是:" << setw(5) << root1 << endl;
		cout << "解二是:" << setw(5) << root1 << endl << endl;
	}
	solve(ju);
	return;
}

//矩阵求逆
void back(int* ju) {
	write_history mat("matrix");
	float* buffer, * p;            //定义数组首地址指针变量
	int row, num;                //定义矩阵的行数和矩阵元素个数
	int i, j;
	float determ;                //定义矩阵的行列式
	cout << endl;
	cout << "请输入矩阵的行数: ";
	cin >> row;
	num = 2 * row * row;
	buffer = (float*)calloc(num, sizeof(float));        //分配内存单元
	p = buffer;
	cout << "请输入矩阵:" << endl;
	if (NULL != p)
	{
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < row; j++)
			{
				cin >> *p++;
			}
		}
	}
	else
	{
		cout << "输入无法得到结果\n";
	}


	determ = MatDet(buffer, row);    //求整个矩阵的行列式
	p = buffer + row * row;
	if (determ != 0)
	{
		for (i = 0; i < row; i++)    //求逆矩阵
		{
			for (j = 0; j < row; j++)
			{
				*(p + j * row + i) = Creat_M(buffer, i, j, row) / determ;
			}
		}
		cout << "逆矩阵结果是: " << endl;
		print(p, row);                //打印该矩阵
	}
	else
	{
		cout << "行列式为0,所以无法得到逆矩阵\n";
	}
	free(buffer);        //释放内存空间
	solve(ju);
	return;
}

void print(float* p, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << setw(4);
		for (j = 0; j < n; j++)
		{
			cout << setiosflags(ios::right) << *p++ << setw(10);
		}
		cout << endl;
	}
}

float MatDet(float* p, int n)
{
	int r, c, m;
	int lop = 0;
	float result = 0;
	float mid = 1;
	if (n != 1)
	{
		lop = (n == 2) ? 1 : n;            //控制求和循环次数,若为2阶,则循环1次,否则为n次
		for (m = 0; m < lop; m++)
		{
			mid = 1;            //顺序求和, 主对角线元素相乘之和
			for (r = 0, c = m; r < n; r++, c++)
			{
				mid = mid * (*(p + r * n + c % n));
			}
			result += mid;
		}
		for (m = 0; m < lop; m++)
		{
			mid = 1;            //逆序相减, 减去次对角线元素乘积
			for (r = 0, c = n - 1 - m + n; r < n; r++, c--)
			{
				mid = mid * (*(p + r * n + c % n));
			}
			result -= mid;
		}
	}
	else
		result = *p;
	return result;
}

float Creat_M(float* p, int m, int n, int k)
{
	int len;
	int i, j;
	float mid_result = 0;
	int sign = 1;
	float* p_creat, * p_mid;
	len = (k - 1) * (k - 1);
	p_creat = (float*)calloc(len, sizeof(float)); //分配内存单元
	p_mid = p_creat;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (i != m && j != n) //将除第i行和第j列外的所有元素存储到以p_mid为首地址的内存单元
			{
				*p_mid++ = *(p + i * k + j);
			}
		}
	}
	sign = (m + n) % 2 == 0 ? 1 : -1;    //代数余之式前面的正、负号
	mid_result = (float)sign * MatDet(p_creat, k - 1);
	free(p_creat);
	return mid_result;
}


//矩阵求迹
int trace() {
	int row;
	cin >> row;
	int* p = new int[row*row];
	cout << "请开始输入矩阵:";
	input(row * row, p);
	int x = row+1;
	int num = p[0];
	for (int i = 1; i < row; i++) {//0,4,8
		num =num+ p[x];
	}
	return num;
}

void trace(int* ju) {
	cout << "请输入矩阵/方阵的行数/列数:";
	cout << "所求方阵的迹的结果是:" << trace() << endl << endl;
	solve(ju);
	return;
}

void express() {
	int z = 1;
	int* ju = &z;
	int* node = &z;
	
	while (*ju) {
	outloop:
        cout << "***********矩阵**********"<<std::endl; 
		
		cout << "请选择以下你想要做的矩阵运算:" << endl;
		cout << "输入1——矩阵相加" << endl;
		cout << "输入2——矩阵相减" << endl;
		cout << "输入3——矩阵相乘" << endl;
		cout << "输入4——矩阵转置" << endl;
		cout << "输入5——矩阵求上三角和行列式" << endl;
		cout << "输入6——矩阵求特征值" << endl;
		cout << "输入7——矩阵求逆" << endl;
		cout << "输入8——矩阵求迹" << endl << endl;
        get_time();
        
		
		cout << "*************************"<<std::endl;
		example();
		cout << endl;
		string character;
		cin >> *node;
		switch (*node) {
		case 1:add(ju); break;
		case 2:reduce(ju); break;
		case 3:multi(ju); break;
		case 4:trans(ju); break;
		case 5:tridet(ju); break;
		case 6:oppo(ju); break;
		case 7:back(ju); break;
		case 8:trace(ju); break;
		default: {
			cout << "你输入的格式错误,请选择:1.输入c清屏并回到本级最初矩阵运算选择界面;" << endl;
			cout << "                         2.输入q返回上一级" << endl;
			cout << "                         3.输入其他任意键本级操作重新输入" << endl;
			cin >> character;
			if (character == "c") {
				system(CLEAR_SCREEN);
				goto outloop;
			}
			else if (character == "q") {
				*ju = 0;
			}
			else {
				goto outloop0;
			}
			break;
		}
		}
	}
outloop0:
	return;
}

void solve(int* ju) {
	string character;
	cout << endl << "请做出下一步操作,请选择:1.输入\"c\"清屏并回到本级最初矩阵运算选择界面;" << endl;
	cout << "                         2.输入\"q\"返回上一级" << endl;
	cout << "                         3.输入其他任意回到本级最初矩阵运算选择界面(不做清屏处理)" << endl;
	cin >> character;
	if (character == "c") {
		system(CLEAR_SCREEN);
		cout << endl;
	}
	else if (character == "q") {
		*ju = 0;
	}
}