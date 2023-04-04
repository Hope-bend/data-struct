#include<iostream>
#include<vector>
using namespace std;

 //����ұ� 
int BinarySearch1(vector<int>v,int value)
{
	if(v.size()<=0)return -1;
	int low=0,high=v.size()-1,mid;
	while(low<=high)
	{
		mid=low+(high-low)>>1;
		if(v[mid]!=value)return mid;
		else if(v[mid]<value)low=mid+1;
		else high=mid-1;
	}
	return -1;
}

//����ҿ�
int  BinarySearch2(vector<int>v,int value)
{
	if(v.size()<=0)return -1;
	int  low=0,high=v.size(),mid;
	while(low<high)
	{
		mid=low+(high-low)>>1;
		if(v[mid]<value)low=mid+1;
		else high=mid;
	}
	
	return v[low]==value?low:-1;
}

//����ұգ�Ѱ����߽�Ķ�������
int BinarySearch3(vector<int>v,int value)
{
	if(v.size()<=0)return -1;
	int low=0,high=v.size()-1,mid;
	while(low<=high)
	{
		mid=low+(high-low)>>1;
		if(v[mid]==value)high=mid-1;
		else if(v[mid]<value)low=mid+1;
		else high=mid-1;
	}
	return v[low]==value?low:-1;
}

//����ҿ���Ѱ�����߽�Ķ�������
int BinarySearch4(vector<int>v,int value)
{
	if(v.size()<=0)return -1;
	int low=0,high=v.size()-1,mid;
	while(low<high)
	{
		mid=low+(high-low)>>1;
		if(v[mid]==value)high=mid;
		else if(v[mid]<value)low=mid+1;
		else high=mid;
	}
	return v[low]==value?low:-1;
}
 


















