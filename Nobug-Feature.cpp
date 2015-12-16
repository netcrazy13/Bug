#include<stdio.h>
#include<conio.h>
#include<string>
#include<iostream>
#include <string.h> 


using namespace std;
class Data
{
      public:
       //string PreCondition;
       //string FixPatched;
       char PreCondition[20];
       char FixPatched[20];
       int time;
      
      public: 
      void cleardata()
      {
          time = 0;
       }
       
      void input()
      {
           scanf("%d %s %s",&time,&PreCondition,&FixPatched);
           fflush(stdout);
      }
      
      void display()
      {
           //printf("%d %s %s",time,PreCondition,FixPatched);
           cout << time << " " << PreCondition << " " << FixPatched << endl;
       }
};
int mindata = 0;
int noBugSize =0;
int noPatch = 0;
Data Patch[100];
void CalData(int, char[], char[]);  
bool CheckPre(char[],char[]);
void FixBug(char[],char[],char *);
bool isNoBug(char[]);
 
        int main()
        {
            do
            {
                  
                cout << "Input Data (No.Patch Bug)\n";  
                scanf ("%d %d",&noPatch,&noBugSize);
                
                if(noBugSize != 0 && noPatch != 0)
                {
                      for(int m = 0; m < 100; m++)
                      {
                              Patch[m].cleardata();
                      } 
                      cout << "Input:\nTime PreCondition Patch\n";
                      for(int i =0; i < noPatch ; i++)
                      {
                          Patch[i].input();
                          //Patch[i].display();
                      }
                      //string initial = "";
                      char initial[20];
                      //cal data 
                      for(int j = 0; j < noBugSize ; j++)
                      {
                          //initial=initial + "+";
                          initial[j] = '+';
                      }
                      mindata= 0;
                      CalData(0,initial,"");
                      if(mindata != 0)
                                 cout << "Mininum time for solve this bug is "<< mindata <<" second."<<endl;
                      else cout << "Cannot solve this bug." << endl;
                }
                else
                {
                    cout << "End Program" << endl;
                }
            
            }while(noBugSize != 0 && noPatch !=0);
            getch();      
            return 10;
        }


void CalData(int totalTime, char input[], char preCond[])
{
     for(int i = 0 ; i < noPatch ; i++)
     {
             if(strcmp(preCond,Patch[i].PreCondition) != 0)
             {
                  //check value
                  if(CheckPre(input,Patch[i].PreCondition))
                  {
                         //exchange value
                         char result[20];
                         FixBug(input,Patch[i].FixPatched,result);
                         if(isNoBug(result))
                         {
                               if(mindata > totalTime+Patch[i].time || mindata == 0)
                                          mindata = totalTime+Patch[i].time;
                         }
                         else if(totalTime < 1000)
                         {
                             CalData(totalTime+Patch[i].time, result,Patch[i].PreCondition);
                         }
                  }
             }   
     }
}

bool CheckPre(char input[],char cond[])
{
     int m = 0;
     for(int i = 0; i < noBugSize ; i++)
     {
             if(input[i] == cond[i])
             {
                         m++;
             }
             else if( cond[i] == '0')
             {
                  m++;
              }
     }
     if(m == noBugSize)
          return true;
     else return false;
 }
void FixBug(char input[],char patch[], char* result)
{
       for(int i = 0; i < noBugSize; i++)
       {
               if(patch[i] != '0')
                      result[i] = patch[i];
               else   result[i] = input[i];
       }
}

bool isNoBug(char input[])
{
     int m = 0;
     for(int i = 0; i < noBugSize; i++)
     {
             if(input[i] == '-')
                         m++;
     }

     if(m == noBugSize)
          return true;
     else return false;
 }
