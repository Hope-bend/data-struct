#include<iostream>
#include<vector>
using namespace std;

 //×ó±ÕÓÒ±Õ 
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

//×ó±ÕÓÒ¿ª
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

//×ó±ÕÓÒ±Õ£¬Ñ°ÕÒ×ó±ß½çµÄ¶þ·ÖËÑË÷
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

//×ó±ÕÓÒ¿ª£¬Ñ°ÕÒ×ó²à±ß½çµÄ¶þ·ÖËÑË÷
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
 


















