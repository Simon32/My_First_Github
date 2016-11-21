#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define Equal 1
#define Up 2
#define Left 3
/*##########Print_LC��������LCS�ă��ݴ�ӡ����##########*/
void Print_LCS(char *str,int**b,int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==Equal) 
	{
	    Print_LCS(str,b,i-1,j-1);      
		printf("%c",str[i-1]);
		 
	}
	else if(b[i][j]==Up)
		Print_LCS(str,b,i-1,j);
	else
		Print_LCS(str,b,i,j-1); 
}
/*#####################################################*/

int main()
{
int i,j,strlen1,strlen2;
char str1[20],str2[20];
int**c,**b;
void Print_LCS(char *str,int**b,int i,int j); 
/******************ݔ��ɂ��ַ���****************************/ 
printf("input the first string str1 that you want to input:\n");
//char str1[20];
scanf("%s",&str1);
strlen1=strlen(str1);

printf("input the second string str2 that you wnat to input:\n");
//char str2[20];
scanf("%s",&str2);
strlen2=strlen(str2);

/*******����ݔ��ăɂ�string�Ĵ�С�ӑB�������S���M **********/ 
//�ӑB�����������Mc 
//int**c;
c=(int**)malloc(sizeof(int*)*(strlen1+1));//ע����Ո�rָᘵĸ�ʽ
for(i=0;i<=strlen1;i++)
    c[i]=(int*)malloc(sizeof(int)*(strlen2+1)); 

//�ӑB�����������Mb
//int**b;
b=(int**)malloc(sizeof(int*)*(strlen1+1));//ע����Ո�rָᘵĸ�ʽ
for(i=0;i<=strlen1;i++)
    b[i]=(int*)malloc(sizeof(int)*(strlen2+1));
     
//��c[][],b[][]�M�г�ʼ��
for(i=0;i<=strlen1;i++)
{
	for(j=0;j<=strlen2;j++)
	{	
	c[i][j]=0;
	b[i][j]=0;
	}	
}

/************************************************************/
//����һ�к͵�һ���O��0 
for(i=1;i<=strlen1;i++)
c[i][0]=0;
for(j=0;j<=strlen2;j++)
c[0][j]=0;

// �����S�ľ���M���䣬���c[][]��b[][] 

for(i=1;i<=strlen1;i++)
{
	for(j=1;j<=strlen2;j++)
	{
		if(str1[i-1]==str2[j-1])
		{
		 	c[i][j]=c[i-1][j-1]+1;
	     	b[i][j]=Equal;
		}
		else if(c[i-1][j]>=c[i][j-1])
		{
			c[i][j]=c[i-1][j];
			b[i][j]=Up;
		}
		else
		{
			c[i][j]=c[i][j-1];
			b[i][j]=Left;
		}
	}
}

//return c[i][j];
printf("The length of the LCS is %d\n",c[strlen1][strlen2]);

//�{��Print_LCS��������LCS��ӡ���� 
printf("The LCS is:");
Print_LCS(str1,b,strlen1,strlen2);

/*ጷ�ָᘣ���ֹ�ȴ曪© */
for ( i = 0; i <= strlen1; i++)  //ע���̎ጷŃȴ����򣬏ă������M�Ѓȴ��ጷţ����� 
    {  
        free(c[i]);  
        free(b[i]);  
    }  
    free(c);  
    free(b);  
/*-----------------------*/

system("pause");
}
