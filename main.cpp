#include <iostream>
#include  "MyDate.h"
using namespace std;

// => 代表本行的输出

int main()
{
    try {
        MyDate d(2000,15,12);
    } catch (exception& ex){
        cout << "Exception!"<<endl;
    }
    MyDate d0(0);
    //测试用例0，测试1970-01-01附近的日期
    cout << d0 << endl;  // => 1970-01-01
    cout << d0+1 << endl;  // => 1970-01-02
    cout << d0+364 << endl;  // => 1970-12-31
    cout << d0+365  << endl;  // => 1971-01-01
    cout << d0-1 << endl;  // => 1969-12-31
    cout << d0-365 << endl;  // => 1969-01-01
    cout << d0-366 << endl;  // => 1968-12-31
    cout << ((d0-1==d0+(-1)) ? "equal":"not equal" ) << endl; // => equal
    cout << ((d0-(-1)==d0+1) ? "equal":"not equal" ) << endl; // => equal
    //测试用例1，2017-03-01
    MyDate d1(17226LL*60*60*24);
    cout << d1<< endl;  // => 2017-03-01
    cout << d1+7 << endl; // => 2017-03-08
    //测试用例2，2050-01-01，测试是否支持2038年之后
    MyDate d2(2100,1,1);
    cout << d2-d0 << endl;  // => 47482
    cout << d2+365 <<endl; //=>2101-01-01
    //测试用例3，1752-09-14，测试历法切换
    MyDate d3(1752,9,14);
    cout << d3-1 << endl;  // => 1752-09-02
    //测试用例4，0001-01-01，公元1年1月1日，测试公元前日期
    MyDate d4(1,1,1);
    cout << d4-1 << endl;  // => 0000-12-31
    //测试用例5，0000-12-31，公元前1年12月31日，测试公元前日期
    MyDate d5(0,12,31);
    cout << d5 << endl;  // => 0000-12-31
    cout << (d4-1==d5 ? "equal":"not equal" ) << endl; // => equal
    //测试用例6，-0001-12-31，公元前2年12月31日，测试公元前日期
    MyDate d6(-1,12,31);
    cout << d6<< endl;  // => -0001-12-31
    cout << d6-d5 << endl; // => -366

/*
    MyDate d0(0);
    //测试用例0，测试1970-01-01附近的日期
    cout << d0.toString()  << endl;  // => 1970-01-01
    cout << d0.add(1).toString()  << endl;  // => 1970-01-02
    cout << d0.add(364).toString()  << endl;  // => 1970-12-31
    cout << d0.add(365).toString()  << endl;  // => 1971-01-01
    cout << d0.subtract(1).toString()  << endl;  // => 1969-12-31
    cout << d0.subtract(365).toString()  << endl;  // => 1969-01-01
    cout << d0.subtract(366).toString()  << endl;  // => 1968-12-31
    cout << (d0.subtract(1).equals(d0.add(-1)) ? "equal":"not equal" ) << endl; // => equal
    cout << (d0.subtract(-1).equals(d0.add(1)) ? "equal":"not equal" ) << endl; // => equal
    //测试用例1，2017-03-01
    MyDate d1(17226*60*60*24LL);
    cout << d1.toString()  << endl;  // => 2017-03-01
    cout << d1.add(7).toString() << endl; // => 2017-03-08
     //测试用例2，2050-01-01，测试是否支持2038年之后
    MyDate d2(2100,1,1);
    cout << d2.subtract(d0) << endl;  // => 47482
    cout << d2.add(365).toString() <<endl; //=>2101-01-01
     //测试用例3，1752-09-14，测试历法切换
    MyDate d3(1752,9,14);
    cout << d3.subtract(1).toString()  << endl;  // => 1752-09-02
    //测试用例4，0001-01-01，公元1年1月1日，测试公元前日期
    MyDate d4(1,1,1);
    cout << d4.subtract(1).toString()  << endl;  // => 0000-12-31
    //测试用例5，0000-12-31，公元前1年12月31日，测试公元前日期
    MyDate d5(0,12,31);
    cout << d5.toString()  << endl;  // => 0000-12-31
    cout << (d4.subtract(1).equals(d5) ? "equal":"not equal" ) << endl; // => equal
    //测试用例6，-0001-12-31，公元前2年12月31日，测试公元前日期
    MyDate d6(-1,12,31);
    cout << d6.toString()  << endl;  // => -0001-12-31
    cout << d6.subtract(d5) << endl; // => -366
*/
    return 0;
}
