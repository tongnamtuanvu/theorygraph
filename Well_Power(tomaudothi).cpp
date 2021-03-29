#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max 50
int a[Max][Max];
int tong_bac_dinh[Max];
int dinh[Max];
int n;
//khai bao dang khuon mau cua ham hoan vi
template<class KDL>
void hoanvi(KDL &a,KDL&b)
{
	KDL temp;
	temp=a;
	a=b;
	b=temp;
}
 void docfile();
 void mang_dinh();
 void tong_bac();
 void sapxepdinh_giam();
 int chonmau(int g[],int l);
 int kiemtramau(int maudato[],int somau,int mau);
 void tomau();
 void xuat();
 
 int main()
 {
 	docfile();
 	printf("noi dung file:\n");
 	xuat();
 	tong_bac();
 	mang_dinh();
 	sapxepdinh_giam();
 	printf("\n");
 	tomau();
 	getch();
 }
 void docfile()
{
	char tenfile[30];
	printf(" nhap duong dan file:");
	gets(tenfile);
	int i,j;
	FILE *fp;
	fp=fopen(tenfile,"rt");
	if(fp==NULL)
	{
		printf("file khong ton tai!\n");
		exit(0);
	}
	else
	{
		fscanf(fp,"%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			fscanf(fp,"%d",&a[i][j]);
	}
}
void xuat()
{
	int i,j;
	printf("so dinh: %d\n\n\t",n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%d",a[i][j]);
		printf("\n\t");
	}
}
// ham dua cac dinh vao mang "mang_dinh" nhap muc dich sap xep lai cac dinh 
// theo bac giam dan
void mang_dinh()
{
	int i;
	int dem=1;
	for(i=1;i<=n;i++)
		dinh[i]=dem++;
}
//ham tinh tong bac cua cac dinh
 void tong_bac()
 {
 	int i,j;
	for(i=1;i<=n;i++)
	{
		tong_bac_dinh[i]=0;
		for(j=1;j<=n;j++)
			tong_bac_dinh[i]=tong_bac_dinh[i]+a[i][j];
	}
 }
 // sap xep lai cac dinh theo thu tu bac giam dan
 void sapxepdinh_giam()
 {
 	int i,j;
 	for(i=1;i<=n;i++)
 		for(j=i+1;j<=n;j++)
 			if(tong_bac_dinh[i]<tong_bac_dinh[j])
 			{
 				hoanvi(tong_bac_dinh[i],tong_bac_dinh[j]);
 				hoanvi(dinh[i],dinh[j]);
			}
 }
 // kiem tra mau trung
 int kiemtramau(int maudato[],int somau,int mau)
{
	int i;
	for(i=1;i<=somau;i++)
	if(mau==maudato[i])
	return 1;
	return 0;
}
// chon mau phu hop de to
 int chonmau(int g[],int l)
 {
 		int mau=1;
	
	do{
	if(kiemtramau(g,l,mau)==0)
	{
	return mau;
	break;
	}
	else
	mau++;
	}while(1);
 }
 // to mau cho cac dinh cua do thi
 void tomau()
{
	int i,j,t;
	int mau=1;
	int maudinh[Max], mauphu[Max],dinhtruoc[Max];
	int k, l;
 	i=l=1;
 	t=1;
 	j=2;
 	maudinh[dinh[i]]=mau;			// to mau dinh thu nhat
 	dinhtruoc[l]=dinh[i];			//gan dinh thu nhat vao mang dinh truoc;
 	//mauphu[0]=mau;					// dua mau da to vao mang mau phu
	 	do{
	 		for(int kb=1;kb<=l;kb++)
	 			if(a[dinh[j]][dinhtruoc[kb]]==1)
	 				mauphu[t++]=maudinh[dinhtruoc[kb]];		//dua mau dinh da to ma ke voi dinh dang xet vao mang mau phu
 			maudinh[dinh[j]]=chonmau(mauphu,t);	  			
			l++;
			dinhtruoc[l]=dinh[j]; // dua dinh da xet vao mang dinh truoc;
		 	j++;				 // chuyen sang xet dinh ke tiep den khi dinh cuoi cung duoc xet
		 	t=1;
	 	}while(j<=n);
 	 for(i=1;i<=n;i++)
 		printf("Mau dinh%3d: %5d\n",i,maudinh[i]);		
 }
