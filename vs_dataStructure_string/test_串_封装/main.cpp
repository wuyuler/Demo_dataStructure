#include <iostream>
using namespace std;
#include"time.h"
#include "String.hpp"
#include "Sunday.hpp"
int main() {
    //测试线性表
//    SepList<char> list1(5);
//    list1.SepListInsert(0,'a');
//    list1.SepListInsert(0,'a');
//    list1.SepListInsert(0,'a');
//    list1.SepListInsert(0,'a');
//    list1.SepListInsert(0,'a');
//    cout<<list1[0]<<endl;
//    list1.append(2);
//    list1.resize(10);
//    cout<<list1[5];
//    cout<<endl;
//    list1.outPut();

    String testString1 = "sadofijjci";
    String testString2 = "sioxijiods";

    //测试显示构造函数
//    String string1 = String("hello world");
//    String string2 = "人生苦短";
//    char a[5] = "我是";  //一个char类型无法存储汉字
//    cout<<a[0];
//    string1.outPut();
//    cout<<string1[0];
//
//    string2.outPut();
//    cout<<endl;

//    testString1 =testString2;//测试深复制
//    testString1.outPut();




//    testString1.subString(1,5)->outPut();//测试取字串函数

//    //测试字符串连接
//    string1.concat(string2);
//    string1.outPut();

//    //测试比较函数
//    cout<<string1.compare(string2);

//    //测试切割函数
//    String testString3 = "eaeaea";
//    SepList<String> subs = SepList<String>(5);
//    int numOfSplitStr=testString3.split(subs,'e');
//    for(int i=0;i<numOfSplitStr;i++){
//        subs[i].outPut();
//        cout<<endl;
//    }


////测试删除函数
//    String string3 = String("aassddpython");
//    string3.outPut();
//    string3.remove(1,3);
//    string3.outPut();
////测试插入函数
//    String string4 = "aahhshshhs";
//    String string5 = "ssss";
//    string4.insert(1,string5);
//    string4.outPut();
//测试匹配函数
//    String string6 = "jjisilzksjf";
//    String string7 = "jji";
//    cout<<string6.index(string7);
////测试替换函数
//    String string8 = "luuuu";
//    String string9 = "uuuu";
//    String string10 = "ddd";
//    string8.replace(string9,string10);
//    cout<<endl;
//    string8.outPut();

    String string1 = "0000000000000000000000000000123456789100000001";
    String string2 = "00000000001";

    time_t tBegin,tEnd;
    int repeats = 10000000;

    //测试Sunday算法,用时6秒
//    char S[]="00000000000000000000000000000000001";
//    char T[]="00000000001";
    char S[]="0000000000000000000000000000123456789100000001";
    char T[]="00000000001";
    char G[] ="123456789";
    time(&tBegin);
    int b;
    for(int i=0;i < repeats;i++)
    b = Index_Sunday(S,T,0);
    time(&tEnd);
    cout<<"Sunday查找结果:"<<b<<endl;
    cout<<"Sunday算法耗时:"<<tEnd-tBegin<<endl;

    //测试KMP算法,用时5秒
    time(&tBegin);
    for(int i=0;i < repeats;i++)
    b = string1.index_KMP(string2);
    time(&tEnd);
    cout<<"KMP查找结果:"<<b<<endl;
    cout<<"KMP算法耗时"<<tEnd-tBegin<<endl;

    //测试简单匹配算法,用时14秒
     time(&tBegin);
     for(int i=0;i < repeats;i++)
    b=string1.Index(string2,0);
    time(&tEnd);
    cout<<"简单匹配查找结果:"<<b<<endl;
    cout<<"简单匹配算法"<<tEnd-tBegin<<endl;
   int c;
   cin>>c;






    return 0;
}
