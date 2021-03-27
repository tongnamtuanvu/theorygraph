//
//  main.cpp
//  WEEK1-BAI2
//
//  Created by Vũ Tống on 2/24/21.
//  Copyright © 2021 Vũ Tống. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
void ghiFile(FILE *fptr,int **a,int row)
{   int i,j;
   
         
         printf("Nhap ma tran: ");
       for(i=0;i<row;i++)
       {
           for(j=0;j<row;j++){
               scanf("%d",&a[i][j]);
               fprintf(fptr,"%d",a[i][j]);
           }
           fprintf(fptr,"\n");

       }
}
void xuatMaTran(int **a,int row)
{   int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<row;j++){
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}
void tinhBacCacDinh(int **a, int row)
{
    int i,j;
    int arr[]={1};
      int size = sizeof(arr) / sizeof(arr[0]);
           int count=0;
       int k;
            //vong lap cot trong ma tran
            for( i=0; i<row; i++){
               //vong lap mang
               for( k=0 ; k<size ; k++){
                  
                   int temp = arr[k];
                  //vong lap dong
                  for( j = 0; j<row; j++){
                      
                     if(temp == a[i][j]){
                         
                        count++;
                     }
                  }
               }
               
                cout<<" + Cac bac cua dinh "<< i + 1 <<" la: " << count << endl;
                count=0;
               
                
            }
}
void tinhBacRaBacVao(int **a,int row)
{
    //hien tri tren ma tran nxn thi hang ngang = bac ra con hang doc = bac vao
    int i,j;
    int bacra;
    int sum1=0;
      for(i = 0; i < row; i++){
          bacra = 0;
          for( j = 0; j < row; j++){
            bacra += a[i][j];
              
          }
          printf("+ Ban bac ra (deg-) cua %d la: %d\n", (i+1), bacra);
          sum1+=bacra;
      }
    int bacvao;
    int sum2=0;
      
      for( i = 0; i < row; i++){
          bacvao = 0;
          for( j = 0; j < row; j++){
            bacvao += a[j][i];
              
          }
          printf("+ Ban bac vao (deg+) cua %d la: %d\n", (i+1), bacvao);
          sum2+=bacvao;
      }
    
    int sum=sum1+sum2;
    printf("tong ban bac ra va vao la %d:",sum);
    cout<<endl;
}
void timBacCaoBacThapNhat(int** a,int row)
{    int i,j;
   int arr[]={1};
     int size = sizeof(arr) / sizeof(arr[0]);
          int count=0;
      int max = 0;
      int min =0;
      int k;
           //vong lap cot trong ma tran
           for( i=0; i<row; i++){
              //vong lap mang
              for( k=0 ; k<size ; k++){
                 
                  int temp = arr[k];
                 //vong lap dong
                 for( j = 0; j<row; j++){
                     
                    if(temp == a[i][j]){
                        
                       count++;
                    }
                 }
              }
              if(max<count)
                            {
                                max=count;
                            }
                            if(min>count)
                            {
                                min=count;
                            }
               
               count=0;
              
               
           }
    cout<<"dinh co bac cao nhat la: "<<max;
    cout<<endl;
     cout<<"dinh  co bac thap nhat la: "<<min;
     cout<<endl;
}

int main() {
   FILE *fptr;
     fptr = fopen("bai2-test.txt","w");
   
     if(fptr == NULL)
     {
        printf("Error!");
        exit(1);
     }
 
    //cap phat dong ma tran
     //cap phat dong
    int row,i,j;
    cout<<"vui long nhap so dinh can tao: ";
    cin>>row;
    int** a=NULL;
     a = new int*[row];
     
     for( i = 0; i < row; i++)
          a[i] = new int[row];
     
    //kiem tra cap phat dong
    
    //dat linh canh
     bool flag=true;
     for( i = 0; i < row; i++)
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
    

   //goi lai ham
    ghiFile(fptr,a,row);
    xuatMaTran(a, row);
    tinhBacCacDinh(a, row);
    tinhBacRaBacVao(a, row);
    timBacCaoBacThapNhat(a,row);
    
    //giai phong bo nho
           fclose(fptr);
      for(int i = 0; i < row; i++)
      {
          delete[] a[i];
      }

      delete[] a;
       
       
       return 0;
}

