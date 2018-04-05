/*
   This code is developed by yk112
   Yash Kapoor
   05-04-18

   Naive Bayes Classifier in C/C++
*/


/**
   The data.txt file is the data used we can also use the dataset.csv file if required.

   This is a Naive Bayes Classifier for the given data only and tells the probability 
   of the given Tuple and conditions.
**/

#include <bits/stdc++.h>

using namespace std;

string data_set[10][5];

void getData(char buff[])
{
   char *token = strtok(buff,",");
   int counter=0;
   for (int i = 0; i < 10; ++i)
   {
   		for (int j = 0; j < 5; ++j)
   		{	
			   data_set[i][j] = token;
			   token = strtok(NULL,",");
   		}
   }

   cout << "The dataset is : " << endl;
   for (int i = 0; i < 10; ++i)
   {
         for (int j = 0; j < 5; ++j)
            cout << data_set[i][j] << "\t";
         cout << endl;
   }
   cout << endl;

   double total_yes=0,total_no=0;
   double p_yes,p_no;
   int total_color[2]={0};
   int total_type[2]={0};
   int total_origin[2]={0};

   for (int i = 0; i < 10; ++i)
   {
   		for (int j = 0; j < 5; ++j)
   		{
            if(data_set[i][j] == "No")
               total_no++;
            else if(data_set[i][j] == "Yes")
               total_yes++;
   		}
   }

   p_yes = total_yes/(double)10;
   p_no = total_no/(double)10;

   double color[2][2]={{0}};     //0,0 is for red-yes  0,1 is for red-no    1,0 is for yellow-yes      1,1 is for yellow-no
   double type[2][2]={{0}};      //0,0 is for Sports-yes  0,1 is for Sports-no    1,0 is for SUV-yes      1,1 is for SUV-no
   double origin[2][2]={{0}};    //0,0 is for Domestic-yes  0,1 is for Domestic-no    1,0 is for Imported-yes      1,1 is for Imported-no


   for (int i = 0; i < 10; ++i)
   {
         if(data_set[i][1] == "Red")
         {
            if(data_set[i][4] == "Yes")
               color[0][0]++;
            else
               color[0][1]++;
         }
         else
         {
            if(data_set[i][4] == "Yes")
               color[1][0]++;
            else
               color[1][1]++;
         }


         if(data_set[i][2] == "Sports")
         {
            if(data_set[i][4] == "Yes")
               type[0][0]++;
            else
               type[0][1]++;
         }
         else
         {
            if(data_set[i][4] == "Yes")
               type[1][0]++;
            else
               type[1][1]++;
         }


         if(data_set[i][3] == "Domestic")
         {
            if(data_set[i][4] == "Yes")
               origin[0][0]++;
            else
               origin[0][1]++;
         }
         else
         {
            if(data_set[i][4] == "Yes")
               origin[1][0]++;
            else
               origin[1][1]++;
         }
   }

   color[0][0]/=total_yes;
   color[1][0]/=total_yes;
   color[0][1]/=total_no;
   color[1][1]/=total_no;

   type[0][0]/=total_yes;
   type[1][0]/=total_yes;
   type[0][1]/=total_no;
   type[1][1]/=total_no;


   origin[0][0]/=total_yes;
   origin[1][0]/=total_yes;
   origin[0][1]/=total_no;
   origin[1][1]/=total_no;


   //Now id the sample x is <Red,SUV,Domestic>  then calculate P(Stolen) and P(Not Stolen)

   double final_yes = p_yes*color[0][0]*type[1][0]*origin[0][0];
   double final_no = p_no*color[0][1]*type[1][1]*origin[0][1];



   cout << "Color matrix" << endl;
   for (int i = 0; i < 2; ++i)
   {
      for (int j = 0; j < 2; ++j)
         cout << color[i][j] << " " ;
      cout << endl;
   }

   cout << "Type matrix" << endl;
   for (int i = 0; i < 2; ++i)
   {
      for (int j = 0; j < 2; ++j)
         cout << type[i][j] << " " ;
      cout << endl;
   }


   cout << "Origin matrix" << endl;
   for (int i = 0; i < 2; ++i)
   {
      for (int j = 0; j < 2; ++j)
         cout << origin[i][j] << " " ;
      cout << endl;
   }


   cout << "For the sample <Red , SUV, Domestic> the probabilities are : " << endl;
   cout << "P(Yes) = " << final_yes << endl;
   cout << "P(No) = " << final_no << endl;

}
int main()
{
	FILE *fp = fopen("data.txt","r");
	do
	{
		char buff[259];
		fgets(buff, 259, fp);
	   getData(buff);
	}
	while((getc(fp))!=EOF);
}
	  