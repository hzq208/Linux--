#include"stdio.h" 
#include"stdlib.h" 
#include"string.h" 
#define Pquantity 3 
#define MAX 1000 
#define N 5 
int k=0; 
 /*�ṹ������*/ 
typedef struct 
{ int num;/*���*/ 
 char name[20];/*����*/ 
 char author[20];/*����*/ 
 char press[20];/*������*/ 
 float price;/*�۸�*/ 
 int quantity;/*����*/ 
 
 
}STUDENTS; 
 
int read_file(STUDENTS stu[]) 
{ FILE *fp; 
 int i=0; 
 if((fp=fopen("stu.txt","rt"))==NULL) 
 {printf("\n\n��������������ļ������ڣ��봴"); 
 return 0; 
 } 
 while(feof(fp)!=1) 
 { 
 fread(&stu[i],sizeof(STUDENTS),1,fp); 
 if(stu[i].num==0) 
 break; 
 else 
 i++; 
 } 
 fclose(fp); 
 return i; 
} 
void save_file(STUDENTS stu[],int sum) 
{FILE*fp; 
 int i; 
 if((fp=fopen("stu.txt","wb"))==NULL) 
 {printf("д�ļ�����!\n"); 
 return; 
 } 
 for(i=0;i<sum;i++) 
 if(fwrite(&stu[i],sizeof(STUDENTS),1,fp)!=1) 
 printf("д�ļ�����!\n"); 
 fclose(fp); 
} 
 
 
/*����ͼ����Ϣ*/ 
int input(STUDENTS stu[]) 
{ int i,x; 
 for(i=0;i<1000;i++) 
 { 
 system("cls"); 
 printf("\n\n  ¼��ͼ����Ϣ (���%d��)\n",MAX); 
 printf(" ----------------------------\n"); 
 
 printf("\n  ��%d��ͼ��",k+1); 
 printf("\n ������ͼ��ı��:"); 
 scanf("%d",&stu[k].num); 
 printf("\n ������ͼ�������:"); 
 scanf("%s",stu[k].name); 
 printf("\n ������ͼ�������:"); 
 scanf("%s",stu[k].author); 
 printf("\n ������ͼ��ĳ�����:"); 
 scanf("%s",stu[k].press); 
 printf("\n ������ͼ��ļ۸�:"); 
 scanf("%f",&stu[k++].price); 
 printf("\n ������ͼ�������:"); 
 scanf("%d",&stu[i].quantity); 
 printf("\n �밴1�����ز˵���0����������"); 
 scanf("%d",&x); 
 if(x) 
 break; 
 } 
 
 return k; 
} 
 
 
/*ɾ��ͼ����Ϣ*/ 
void deletel(STUDENTS stu[]) 
 { system("cls"); 
 char Stuname2[20]; 
 int i,j; 
 printf("������ͼ��������"); 
 scanf("%s",Stuname2); 
 printf("\n"); 
 for(i=0;i<k;i++) 
 if(strcmp(stu[i].name,Stuname2)==0) 
 for(j=0;j<20;j++) 
 stu[i].name[j]=stu[i+1].name[j]; 
 k--; 
 
 
 printf("ɾ���ɹ�\n"); 
 printf("��������ӻس��������˵�!"); 
 scanf("%d",&i); 
 getchar(); 
} 
 
/*��ӡͼ����Ϣ*/                
void output(STUDENTS stu[]) 
{ system("cls"); 
 int i; 
 for(i=0;i<k;i++) 
 printf("��ţ�%d,������%s,���ߣ�%s,�����磺%s,�۸�: %.2f,������%d\n",stu[i].num,stu[i].name, 
 stu[i].author,stu[i].press,stu[i].price,stu[i].quantity); 
 printf("��������ӻس��������˵�!"); 
 scanf("%d",&i); 
 getchar(); 
} 
 
/*��ѯͼ����Ϣ*/ 
void inquire(STUDENTS stu[]) 
 { int i; 
 char name[20]; 
 system("cls"); 
 printf(" \n\n��������Ҫ���ҵ�ͼ���������"); 
 scanf("%s",&name); 
 for(i=0;i<k;i++) 
 if(strcmp(name,stu[i].name)==0) 
 printf("\n\n\n��ţ�%d,������%s,���ߣ�%s,�����磺%s,�۸�: %.2f,������%d\n",stu[i].num,stu[i].name, 
 stu[i].author,stu[i].press,stu[i].price,stu[i].quantity); 
 printf("��������ӻس��������˵�!"); 
 scanf("%d",&i); 
 getchar(); 
 } 
 
 
/*�޸�ͼ����Ϣ*/ 
void change(STUDENTS stu[]) 
 { int num,i,choice; 
 system("cls"); 
 printf("\n\n\n ��������Ҫ�޸ĵ�ͼ��ı��"); 
 scanf("%d",&num); 
 for(i=0;i<k;i++) 
 { if(num==stu[i].num) 
 printf("\n��ţ�%d,������%s,���ߣ�%s,�����磺%s,�۸�: %.2f,������%d\n",stu[i].num,stu[i].name, 
 stu[i].author,stu[i].press,stu[i].price,stu[i].quantity); 
 
 printf("\n\n\n ********����������Ҫ�޸ĵ�����********\n\n"); 
 printf(" 1. ���\n\n"); 
 printf(" 2. ����\n\n"); 
 printf(" 3. ����\n\n"); 
 printf(" 4. ������\n\n"); 
 printf(" 5. �۸�\n\n"); 
 printf(" 6. ����\n\n"); 
 printf("  ��ѡ��1-6��:"); 
 scanf("%d",&choice); 
 switch(choice) 
 {case 1:{ 
 printf("\n ��������ĵ��±��"); 
 scanf("%d",&stu[i].num); 
 break; 
 } 
 case 2:{ 
 printf("\n ��������ĵ�������"); 
 scanf("%s",stu[i].name); 
 break; 
 } 
 case 3:{ 
 printf("\n ��������ĵ�������"); 
 scanf("%s",stu[i].author); 
 break; 
 } 
 case 4:{ 
 printf("\n ��������ĵ��³�����"); 
 scanf("%s",stu[i].press); 
 break; 
 } 
 case 5:{ 
 printf("\n ��������ĵ��¼۸�"); 
 scanf("%f",&stu[i].price); 
 break; 
 case 6:{ 
 printf("\n ��������ĵ�������"); 
 scanf("%d",&stu[i].quantity); 
 break; 
 } 
 } 
 } 
 
 printf("��ţ�%d,������%s,���ߣ�%s,�����磺%s,�۸�: %.2f,������%d\n",stu[i].num,stu[i].name, 
 stu[i].author,stu[i].press,stu[i].price,stu[i].quantity); 
 printf("��������ӻس��������˵�!"); 
 scanf("%d",&i); 
 break; 
 } 
} 
 
 
/*ͼ��۸���Ϣ����*/ 
void sort(STUDENTS stu[]) 
 { int i,j,n=1,x; 
 system("cls"); 
 int t; 
 for(i=0;i<k-1;i++) 
 for(j=i+1;j<k;j++) 
 if(stu[i].price<stu[j].price) 
 { t=stu[i].price; 
 stu[i].price=stu[j].price; 
 stu[j].price=t; 
 t=stu[i].num; 
 stu[i].num=stu[j].num; 
 stu[j].num=t; 
 
 } 
 for(i=0;i<k;i++) 
 printf("���� ��� �۸�\n %d %d %.2f\n",n++,stu[i].num,stu[i].price); 
 printf("��������ӻس��������˵�!"); 
 scanf("%d",&x); 
 getchar(); 
 } 
 
void pquantitydis() 
{ 
 printf(" \n\n\n  **********************************\n"); 
 printf("  *  *\n"); 
 printf("  *  *\n"); 
 printf("  *  *\n"); 
 printf("  * ��ӭ����ͼ����Ϣ����ϵͳ *\n"); 
 printf("  *  *\n"); 
 printf("  *  *\n"); 
 printf("  *  *\n"); 
 printf("  **********************************\n"); 
 
} 
void check() 
{ 
 char userName[5];/*�û���*/ 
 char userPWD[5];/*����*/ 
 int i,sum; 
 system("color 0B"); 
 for(i = 1; i < 4; i++) 
 { 
 /*�û����������Ϊabcde;*/ 
 printf("  (�û����������Ϊabcde)\n\n"); 
 printf("\n �����������û���:"); 
 gets(userName); 
 
 printf("\n ��������������:"); 
 gets(userPWD); 
 
 if ((strcmp(userName,"abcde")==0) && (strcmp(userPWD,"abcde")==0))/*��֤�û���������*/ 
 { 
 printf("\n  *�û�����������ȷ����ʾ���˵�*"); 
 return; 
 } 
 else 
 { 
 if (i < 3) 
 { 
 printf("�û��������������ʾ�û���������"); 
 printf("�û����������������������!"); 
 } 
 else 
 { 
 printf("����3������û��������룬�˳�ϵͳ��"); 
 printf("��������3�ν��û������������ϵͳ���˳�!"); 
 exit(1); 
 } 
 } 
 } 
} 
void menu() 
{ 
 STUDENTS stu[20]; 
 int choice,k,sum; 
 sum=read_file(stu); 
 if(sum==0) 
 { printf("����¼����������Ϣ�����س�����롪��������\n"); 
 sum=input(stu); 
 } 
 
 do 
 { system("cls"); 
 printf("\n\n\n ********ͼ����Ϣ����ϵͳ********\n\n"); 
 printf("  1. ����ͼ����Ϣ\n\n"); 
 printf("  2. ��ӡͼ����Ϣ\n\n"); 
 printf("  3. ��ѯͼ����Ϣ\n\n"); 
 printf("  4. �޸�ͼ����Ϣ\n\n"); 
 printf("  5. ɾ��ͼ����Ϣ\n\n"); 
 printf("  6. ͼ��۸���Ϣ����\n\n"); 
 printf("  0. �˳�ϵͳ\n\n"); 
 printf("  ��ѡ��0-6��:"); 
 scanf("%d",&choice); 
 switch(choice) 
 { 
 case 1: k=input(stu); break;/*����ͼ����Ϣ*/ 
 case 2: output( stu) ; break;/*��ӡͼ����Ϣ*/ 
 case 3: inquire(stu); break;/*��ѯͼ����Ϣ*/ 
 case 4: change(stu); break;/*�޸�ͼ����Ϣ*/ 
 case 5: deletel(stu); break;/*ɾ��ͼ����Ϣ*/ 
 case 6: sort(stu); break;/*ͼ��۸���Ϣ����*/ 
 case 0: break; 
 } 
 }while(choice!=0); 
 save_file(stu,sum); 
} 
int main() 
{ 
 int i,sum; 
 pquantitydis(); 
 check(); 
 menu(); 
} 
