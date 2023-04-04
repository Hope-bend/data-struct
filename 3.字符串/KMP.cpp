#include<iostream>
using namespace std;

void GetNext(int next[], string t)
{
   int i = 0, j = -1, len = t.length();
   next[0] = -1;
   while(i < len - 1)
   {
      if(j == -1 || t[i] == t[j])
      {
         i++,j++;
         next[i] = j;
      }
      else j = next[j];
   }
}

void GetnextVal(int nextval[], string t)
{
   int i = 0, j = -1, len = t.size();
   nextval[0] = -1;
   while(i < len - 1)
   {
      if(j == -1 || t[i] == t[j])
      {
         i++,j++;
         if(t[i] == t[j]) nextval[i] = nextval[j];
         else nextval[i] = j;
      }
         else j = nextval[j]; 
   }



   // int j=0,k=-1;
   // next[0]=-1;
   // while(j<t.size() - 1)
   // {
   //    if(k == -1 || t[j] == t[k])
   //    {
   //       j++;k++;
   //       if(t[j] == t[k]) next[j] = next[k];
   //    }
   //    else k = next[k];//此语句是这段代码最反人类的地方，如果你一下子就能看懂，那么请允许我称呼你一声大神！
   // }
}

void KMP(string s, string p)
{
   int lens = s.size(), lenp = p.size();
   int nextval[lenp];
   GetnextVal(nextval, p);

   int i = 0, j = 0;
   while(i < lens && j < lenp)
   {
      if(j == -1 || s[i] == p[j]) i++,j++;
      else j = nextval[j]; 

      if(j == lenp)
      {
         cout << "The place of mathc are:" << i - lenp << " ";
         i = i - lenp + 1;
         j = 0;
      }
   }
   cout << endl;
}



int main()
{
   //  string t = "abcaabbcabcaabdab";
   // string t = "abaabcac";
   string t = "aaaab";
   int len = t.length();
   int next[len], nextval[len] = {0};
   GetNext(next, t);


   cout << "The array of next:" << endl;
   for(int i = 0; i < len; i++)
      cout << next[i] << " ";
   cout << endl;

   GetnextVal(nextval, t);
   cout << "The array of nextval:" << endl;
   for(int i = 0; i < len; i++)
      cout << nextval[i] << " ";
   cout << endl;

   string s = "jNNPw9NNNNnNMANTNHGNjNNNNjNNNN";
   string p = "jNNNNjNNNN";
   KMP(s, p);







}




// #include<iostream>
// using namespace std;

// int main()
// {
//    string a = "123";
//    int len = a.length();
//    cout << "The lenght of a:" << len << endl;
//    int len1 = a.size();
//    cout << "The size of a:" << len1 << endl;


//    for(int i = 0; i < len; i++)
//       cout << a[i] << " ";
//    // cout << len;



// }




























