#include <stdio.h>
#include <string.h>
char checknine(char *b,int i)
{
  if (b[i+1]=='9'){
    b[i+1]='0';
    checknine(b,i+1);
  } else b[i+1]++;
}
int main()
{
  char starta[1000000],startb[1000000]/*,c[1000000]*/,a[1000000],b[1000000];
  scanf("%s",starta);
  scanf("%s",startb);
  int lena=strlen(starta)-1;
  int lenb=strlen(startb)-1;
  for(int i=0;i<lena+1;i++) {
    a[i]=starta[lena-i];
  }
  for(int i=0;i<lenb+1;i++) {
    b[i]=startb[lenb-i];
  }
  if (lena>lenb) {
    int start=lenb+1;
    a[lena+1]='0';
    for (int i = 0; i <start ; i++) {
      if(a[i]+b[i]-'0'*2>9) {
        a[i]=(a[i]+b[i])-'0'*2-10+'0';
        /* a[i+1]++; */
        checknine(a,i);
      } else
        a[i]=(a[i]+b[i])-'0'*2+'0';
    }
    for (int i=strlen(a);-1<i;i--)
    {
      printf("%c",a[i]);
    }
    printf("\n");
  }
  else {
    int start=lena+1;
    b[lenb+1]='0';
    for (int i = 0; i <start ; i++) {
      if(a[i]+b[i]-'0'*2>9) {
        b[i]=(a[i]+b[i])-'0'*2-10+'0';
        /*if (b[i+1]-'0'==9) {
          b[i+1]='0';
          b[i+2]++;
        }*/
        checknine(b,i);
        /* b[i+1]++; */
      } else
        b[i]=(a[i]+b[i])-'0'*2+'0';
    }
    for (int i=strlen(b);-1<i;i--)
    {
      printf("%c",b[i]);
    }
    printf("\n");
  }
  return 0;
}
