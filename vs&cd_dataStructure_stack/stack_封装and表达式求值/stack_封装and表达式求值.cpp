// stack_封装and表达式求值.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include"ExpressionEvaluation.hpp"



int main()
{	//测试栈的基本操作
	//Stack<char> stack;
	//stack.push('A');//测试入栈
	//stack.push('B');
	//stack.push('C');
	//stack.output();//测试输出
	//cout << stack.peek();
	//cout << stack.pop();//测试出栈
	//cout << stack.peek();

	//cout << getPriority('+');//测试优先级获取
	//cout << getPriority('*');

	//cout << cacalate(2, 3, '*');//测试二目运算
	
	/*cout << evaluate("5*2+6/2-1#")<<endl;
	cout << evaluate("3-4+5*6/2#") << endl;
	cout << evaluate("5*2-2+6/2#") << endl;*/
	
	/*cout << evaluate("3+5^2#")<<endl;
	cout << evaluate("3+5^2*3/2#") << endl;*/
	cout << evaluate("(2*(2+2))+4#")<<endl;
	cout << evaluate("2*(2+2)/(4+2)#") << endl;
	
	cout << evaluate("10*20*(10+10)#")<<endl;
	cout << evaluate("10^2*20*(10+10)#");
    return 0;
}

