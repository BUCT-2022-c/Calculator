#include"else.h"
void buct::welcome() {
    cout << "******************" << endl;
    cout << "1.分数约简" << endl;
    cout << "2.最大公因数和最小公倍数" << endl;
    cout << "3.质因数分解" << endl;
    cout << "4.进制转换" << endl;
    cout << "5.判断素数" << endl;
    // cout << "6.数据统计" << endl;
    get_time();
    cout << "******************" << endl;
    cout << "输入\"c\"清理屏幕\t输入\"q\"退出\n";
    cout << "请输入您的选择:";
    char num = 0;
    bool ttt = 0;
    while(cin >> num)
    
    {
        switch (num) 
        {
            case '1': 
            {
                Fraction_simplification();
                break;
            }
            case '2': 
            {
                Greatest_common_factorand_least_common_multiple();
                break;
            }
            case '3': 
            {
                Prime_factorization();
                break;
            }
            case '4': 
            {
                base_conversion();
                break;
            }
            case '5': 
            {
                determine_prime();
                break;
            }
            // case 6: {
            //     Statistics();
            //     break;
            // }
            case 'q':
            {
                ttt = 1;
                break;
            }
                
            case 'c':
            {
                std::system(CLEAR_SCREEN);
                cout << "******************" << endl;
                cout << "1.分数约简" << endl;
                cout << "2.最大公因数和最小公倍数" << endl;
                cout << "3.质因数分解" << endl;
                cout << "4.进制转换" << endl;
                cout << "5.判断素数" << endl;
                // cout << "6.数据统计" << endl;
                get_time();
                cout << "******************" << endl;
                cout << "输入\"c\"清理屏幕\t输入\"q\"退出\n";
                cout << "请输入您的选择:";
                break;
            }
            default:
            {
                cout << "input error!";
                break;
            }
            
        }
        if(ttt==1)
            break;
    }
    std::system(CLEAR_SCREEN);
    out0();
}
void buct:: Fraction_simplification() {
    //分子:molecular 分母:denominator 分数线:fractionbar
    int molecular;
    char  fractionbar;
    int denominator;
    cout << "请输入一个分数,如:1/2" << endl;
    cin >> molecular >> fractionbar >> denominator;
    for (int i = 1; i > 0; ++i) {
        if (molecular * denominator == 0) {
            cout << "请输入正确的分数:" << endl;
            cin >> molecular >> fractionbar >> denominator;
        }
        else {
            break;
        }
    }
    if (molecular < denominator || molecular * denominator != 0) {
        for (int i = 2; i <= molecular; ++i) {
            if (molecular % i == 0 && denominator % i == 0) {
                molecular /= i;
                denominator /= i;
            }
            else {
                continue;
            }
        }
        for (int i = molecular; i >= 2; --i) {
            if (molecular % i == 0 && denominator % i == 0) {
                molecular /= i;
                denominator /= i;
            }
            else {
                continue;
            }
        }
    }
    else if (molecular > denominator || molecular * denominator != 0) {
        for (int i = 2; i <= denominator; ++i) {
            if (molecular % i == 0 && denominator % i == 0) {
                molecular /= i;
                denominator /= i;
                break;
            }
            else {
                break;
            }
        }
        for (int i = denominator; i >= 2; --i) {
            if (molecular % i == 0 && denominator % i == 0) {
                molecular /= i;
                denominator /= i;
            }
            else {
                continue;
            }
        }
    }
    if (molecular == denominator) {
        cout << "化简后的结果是:" << molecular << endl;
    }
    else if (denominator == 1) {
        cout << "化简后的结果是:" << molecular << endl;
    }
    else {
        cout << "化简后的结果是:" << molecular << "/" << denominator << endl;
    }
}
void buct::Greatest_common_factorand_least_common_multiple() {
    int x, y;    // x存放整组数的最大公约数，y存放整组数的最小公倍数
    int p;    // p存放用户键入整数的个数，作为循环的判断条件
    int a[1000];    //定义数组a

    printf("请输入您即将输入整数的个数:\n");
    cin >> p;

    printf("请输入所要求解的整数:\n");
    for (int i = 0; i < p; i++)     // 通过for循环为数组赋值
        cin >> a[i];

    x = max_common_divisor(a, p);
    y = min_common_multiple(a, p);
    printf("该组数的最大公约数为:%d\n", x);
    printf("该组数的最小公倍数为:%d\n", y);
}
/* max_common_divisor()函数实现对一组数最大公约数的求解 */
int buct::max_common_divisor(int a[], int p)
{
    int i = a[0];
    int j = a[1];
    int k = gcd(i, j);    // k存放一组数的最大公约数，通过调用gcd()函数求k
    int r = 0;

    /* 通过for循环依次从数组中取出每个数，求其与k的最大公约数 */
    for (r = 2; r < p; r++)
    {
        k = gcd(k, a[r]);    // 更新k的值
    }

    return(k);
}
/* min_coommon_multipe()函数实现对一组数最小公倍数的求解 */
int buct::min_common_multiple(int a[], int p)
{
    int i = a[0];
    int j = a[1];
    int k = lcm(i, j);    // k存放一组数的最小公倍数，通过调用lcm()函数求k
    int r = 0;

    for (r = 2; r < p; r++)
    {
        k = lcm(k, a[r]);
    }

    return(k);
}
/* lcm()函数实现对两数最小公倍数的求解 */
int buct::lcm(int m, int n) {
    int temp;
    temp = gcd(m, n);
    return(m * n / temp);
}
/* gcd()函数实现对两数最大公约数的求解 */
int buct::gcd(int m, int n)
{
    int temp;
    if (m < n)
    {
        temp = m;
        m = n;
        n = temp;
    }
    while (n != 0)
    {
        temp = m % n;
        m = n;
        n = temp;
    }
    return(m);

}
void buct::Prime_factorization() {
    int k;
    cout << "请输入您想找出质因数的整数k:";
    cin >> k;
    if (k < 2)
        cout << "不能够进行质因数分解" << endl;
    else if (k == 2)
        cout << "分解质因数的等式为:" << "2*1" << endl;
    else
    {
        cout << "分解质因数的等式为:";
        for (int i = 2; i < sqrt(k); i++)
        {
            while (k != i)//这里用while循环是考虑到质因子中有可能有重复个i的情况
            {
                if (k % i == 0)
                {
                    cout << i << "*";
                    k = k / i;
                }
                else
                    break;
            }
        }
        cout << k << " * 1" << endl;
    }
}
void buct::base_conversion() {
    int B, b;
    char a[20];
    printf("请输入待转换数的进制(2-16):");
    do {
        scanf("%d", &B);
    }
    while (B < 2 && B > 16);
    printf("请输入待转换数:");
    cin>>a;                      //将输入的n进制数存放在数组a中
    int m = TenNum(a, B);             //将输入的数字转换成十进制数
    printf("请输入需要转成几进制数(2-16):");
    do {
        scanf("%d", &b);
    } while (B < 2 && B > 16);
    printf("%d进制数%s转换为%d进制数的结果为:", B, a, b);
    Numchange(m, b);                 //将十进制数转换为所需进制数
    printf("\n");
}
//将输入的数字转换成10进制数
int buct::TenNum(char a[], int B) {
    int len, i, num;
    int sum = 0;
    len = strlen(a);                    //求得字符串长度
    for (i = 0; i < len; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
            num = a[i] - '0';
        else if (a[i] >= 'A' && a[i] <= 'F')
            num = a[i] - 'A' + 10;
        sum = sum * B + num;
    }
    return sum;
}
//将转换好了的10进制数转换为所需进制数
void buct::Numchange(int m, int B) {
    int n;
    if (m)
    {
        Numchange(m / B, B);
        n = m % B;
        if (n < 10)
            cout << n;           //小于10直接输出
        else
            cout << n + 55;      //大于10转换成字符输出
    }
}
void buct::determine_prime() {
    int pnnum;
    cout << "请输入一个数" << endl;
    cin >> pnnum;
    int temp = sqrt(pnnum) + 1;
    for (int i = 2; i <= temp; i++) {
        if (pnnum % i == 0) {
            cout << pnnum << " 不是素数" << endl;
            break;
        }
        if (i == temp) {
            cout << pnnum << " 是素数" << endl;
        }
    }
    
}
void buct::Statistics() {
    int a[100], n;
    cout << "请输入这组数据的数据个数:";
    cin >> n;
    cout << "请输入每一个数；" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    double max(double a[], int);//最大值 
    double ave(double a[], int);//平均   
    double min(double a[], int);//中值  
    double variance(double a[], int);//方差；
}
//这是求最大值 
double buct::max(double a[], int n)
{

    double h = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > h)
            h = a[i];
    }

    return h;
}
//方差要用的是平均值，不是中值；
double buct::ave(double a[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    cout << "这组数据的平均值为" << sum / n << endl;
    return sum / n;
}
//这个是求中值  
double buct::mid(double a[], int n)
{
    int mid;
    if (n % 2 == 0)
        mid = (a[n / 2 - 1] + a[n / 2]) / 2;
    else
        mid = a[(n - 1) / 2];
    cout << "这组数据的中位数为" << mid << endl;
    return mid;
}
//这个是求方差的，最后要除以n
double buct::variance(double a[], int n)
{
    double sum = 0;
    double average = ave(a, n);
    for (int i = 0; i < n; i++)
        sum = (a[i] - average) * (a[i] - average);
    cout << "这组数据的方差为" << sum / n << endl;
    return sum / n;
}


