//
//  main.cpp
//  week1
//
//  Created by Vũ Tống on 2/21/21.
//  Copyright © 2021 Vũ Tống. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

void docFile(FILE*fp, int **a,int row)
{   int i,j;
    // doc noi dung ma tran------------------------------------------------
 for (i = 0; i < row; i++) {
     for (j = 0; j < row; j++) {
         fscanf(fp, "%d\n", &a[i][j]);
     }
}
}
void xuatFile(int **a,int row)
{   int i,j;
     //xuat ma tran--------------------------------------------------------
         printf("\nMa tran: \n");
         for (i = 0; i < row; i++) {
              for (j = 0; j < row; j++) {
                  printf("%d ", a[i][j]);
              }
              printf("\n");
         }
    
}
void tinhTongBac(int **a,int row){
    int k;
    int i,j;
    int sum=0;
         int arr[]={1};
    int size = sizeof(arr) / sizeof(arr[0]);
         int count=0;
          //vong lap cot trong ma tran
          for( i=0; i<row; i++){
             //vong lap mang
             for( k=0 ; k<size ; k++){
                
                 int temp = arr[k];
                //vong lap dong--------------------------------------------------
                for( j = 0; j<row; j++){
                    
                   if(temp == a[i][j]){
                       
                      count++;
                   }
                }
             }
            
             cout<<" + Cac bac cua dinh "<< i + 1 <<" la: " << count << endl;
              //tong cac bac-----------------------------------------------------
              
              
              if(count%2==0)  {
                  cout<<" - dinh "<<i+1<<" nay la bac: Chan"<<endl;
              }
              else{
                  cout<<" - dinh "<<i+1<<" nay la bac: Le"<<endl;
              }
              
              sum+=count;
              count=0;
          }
    cout<<"-------------------------------------"<<endl;
    cout<<"tong bac cua do thi: "<<sum<<endl;
}
void kiemTraDaDoThi(int** a,int row)

{   int i,j;
    //kiem tra do thi vo huong hay da huong----------------------------------------
    int k;
    int count1=0;
    int arr[30];
    for (i = 0; i < row; i++) {
        
                  for( k=0 ; k<row ; k++){
                  int temp1 = arr[k];
                      if(temp1==a[i][i])
                  {
                      
                      count1++;
                  }
                  }
                  count1=0;
                  }
       cout<<"-------------------------------------"<<endl;
         if((count1)!=0)
         {
             cout<<"do thi nay la da do thi vo huong"<<endl;
             cout<<"so luong khuyen co trong do thi la: "<<count1<<endl;
             
         }
         else{
             cout<<"do thi nay la don do thi vo huong"<<endl;
             cout<<"so luong khuyen co trong do thi la: "<<count1<<endl;
         }
        cout<<"-------------------------------------"<<endl;
        cout<<"duong cheo chinh ma tran la:"<<endl;
        for (i = 0; i < row; i++)
        {
            cout<<a[i][i]<<" ";
        }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;
}
void timDinhKe(int** a,int row)
{   int i,j;
    //tim dinh ke voi dinh-------------------------------------------
       
       for(i=0;i<row;i++){
       
       for(j=0;j<row;j++)
       {
           if(a[i][j]>=1)
               
               cout<<"dinh "<<i+1<<" ke dinh "<<j+1<<endl;
       }
       }
       cout<<"-------------------------------------"<<endl;
}
int main()
{
int i,j;
FILE *fp;
int row;
    fp = fopen("matran.txt", "r");
    if(fp!=NULL)
    {
        cout<<"[+++ Mo file thanh cong!! +++]"<<endl;
    }
    else
    {
        cout<<"Mo that bai!!"<<endl;
        exit(1);
    }
    // doc so hang cua ma tran--------------------------------------------------
      fscanf(fp, "%d\n", &row);
      printf("So hang va cot cua ma tran: %d\n", row);
      printf("so dinh cua do thi: %d\n", row);
     
    //cap phat dong-------------------------------------------------------------
    int** a;
    a = new int*[row];
    
    for(int i = 0; i < row; i++)
         a[i] = new int[row];
    //kiem tra cap phat dong
    bool flag=true;
    for(int i = 0; i < row; i++)
    {
        if (a[i] != nullptr){
            flag=true;
    }
    }
    if(flag==true){
        cout<<"[ --- cap phat dong ma tran thanh cong --- ]"<<endl;
    }
    else
        cout<<"[ Warning *** cap phat ko thanh cong *** ]"<<endl;
    cout<<"********************************************"<<endl;
    cout<<"-------------------------------------"<<endl;
        //tinh bac cac dinh------------------------------------------------
    
    string filename("vu.png");
    cout<<filename<<endl;
    
    //goi lai ham
    docFile(fp,a,row);
    xuatFile(a,row);
    tinhTongBac(a,row);
    kiemTraDaDoThi(a,row);
    
   //dong file----------------------------------------------------------
    
    fclose(fp);
   
    //giai phong bo nho--------------------------------------------------
    
   for(int i = 0; i < row; i++)
   {
       delete[] a[i];
   }

   delete[] a;
    
    
    return 0;
}

