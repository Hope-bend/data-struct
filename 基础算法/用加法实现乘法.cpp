#include<iostream>
using namespace std;

 int get_multi_value(int a, int b)
{
	int res = 0;
	int sign = 1;//���ڼ�¼b���������Ǹ��� 
	if(b < 0)
	{
		b = -b;
		sign = -1;
	}

//ʵ��ԭ��ο�CASPP��70ҳ 
	while(b)
	{
		if(b&1)res+=a;
		a<<=1;
		b>>=1;
	}
 
	return sign==-1?-res:res;

}
 
int main()
{
	cout<<get_multi_value(-5, -6)<<endl;
 
	return 0;
}









