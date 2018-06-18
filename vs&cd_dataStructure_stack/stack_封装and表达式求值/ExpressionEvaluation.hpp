#include"Stack.hpp"
#include <cmath>

int getPriority(char opt) {
	//��������������ȼ�,Խ�����ȼ�Խ��
	int priority;
	switch (opt)
	{
		case '+':
		priority = 0;
		break;
		case '-':
			priority = 0;
			break;
		case '*':
			priority = 1;
			break;
		case '/':
			priority = 1;

			break;
		case '(':
			priority = 3;
			break;
		case')':
			priority = -1;
			break;
		case '#':
			priority = -2;
			break;
		case '^':
			priority = 2;break;
		default:
			cout << "δ���������";
			return -1;
	}
	return priority;
}

int compare(char optA, char optB) {
	//��������ȼ��ȽϺ���,����ֵ���ڵ���С�ڷֱ�Ϊ����,��,����
	return getPriority(optA) - getPriority(optB);
}

double cacalate(double v1, double v2, char opt) {
	switch (opt)
	{
	case '+':return v1 + v2;
	case '-':return v1 - v2;
	case '*':return v1 * v2;
	case '/':return v1 / v2;
	case '^':return pow(v1, v2);


	
	default:cout << "δ���������";
		break;
	}

}

double evaluate(const char *expression) {
	//��һ�����ʽ��ֵ
	Stack<float> values;
	Stack<char> operators;
	int i = 0;
	char ch;
	while ((ch = expression[i]) != '\0') {
		i++;
		if (ch >= '0'&&ch <= '9') {
			if (i >= 2 && (expression[i-2] >= '0'&&expression[i-2] <= '9'))
			{
				int item = values.pop();
				item = item * 10 + (ch - '0');
				values.push(item);

			}
			else
			values.push(ch - '0');
		}
		else {
			
			if (operators.peek()==')') {
				operators.pop();
				operators.pop();

			}
			
				while (operators.top > 0 && compare(ch, operators.peek()) <= 0) {
					if (operators.peek() == '(')break;
						float a = values.pop();
						float b = values.pop();
						double c = cacalate(b, a, operators.pop());
						values.push(c);

					

				}
			
				
				

			
			

			
			operators.push(ch);
		}
		
		

	}



	return values.pop();
}