#include <iostream>
#include<cstring>
using namespace std;
#define max 256
bool compare(char arr1[], char arr2[])
{
    for (int i=0; i<MAX; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}
void search(char patt[],char txt[])
{
	 int m=strlen(patt);
	 int n=strlen()
	 char countp[max]={0};
	 char countnw[max]={0};
	 int i=0;
	 for(i=0;i<m;i++)
	 {
	 	countp[patt[i]]++;
	 	
	 }
	 for(i=0;i<n;i++)
	 {
	 	countnw[txt[i]]++;
	 }
	 for(int i=m,i<n;i++)
	 {
	 	if(compare(countp,countnw))
	 		prinft("%d\n",i-m);
	 	countp[txt[i]]++;
	 	countnw[txt[i-m]]--;
	 }
	 if(compare(countp,countnw))
	 		prinft("%d\n",i-m);
	 
	 
}
int main() {
	// your code goes here
	return 0;
}
