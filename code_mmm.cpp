#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
   using namespace std;
    class point
    {
    private:
       float x;
       float y;
    public:
       point() = default;
       ~point(){}
       void setx(float xn){ x = xn;}
       void sety(float yn) { y = yn; }

       bool operator<(const point& obj)
       {  return this->y < obj.y;  }
       const float& getX()const { return x; }
       const float& getY()const { return y; }
       // overload operator<< to print the object of this class
       friend std::ostream& operator<<(std::ostream& out, const point& obj);
    };
    std::ostream& operator<<(std::ostream& out, const point& obj)
    {  return out << obj.getX() << " " << obj.getY();  }

    //FUNCTION TO SORT W.R.T X OR Y

    float sor(char ch, int n, std::vector<point> &list)
    {
      float median;

      if(ch == 'y' || ch == 'Y')
       {
       std::cout <<"sorting w.r.t Y" <<std::endl;
       std::sort(list.begin(), list.end());
       for(const point& it: list)
       std::cout << it << std::endl;
       if(list.size()%2!=0)
      {
       point p1;
       p1 = list[(list.size()/2)];
    //   cout << p1 = list[list.size()/2] << endl;
       median = p1.getY();
       cout << median << endl;
       }
       else 
       {
	       point p1,p2;
	       p1=list[(list.size()/2)-1];
	       p2=list[(list.size()/2)];
	       median = (p1.getY() + p2.getY())/2;
	      // cout << median = (p1.getY() + p2.getY() - 1)/2 << endl;
	       cout << median << endl;
       }
    }
     if(ch == 'x' || ch == 'X')
      {
       std::cout <<"sorting w.r.t X" <<std::endl;
       std::sort(list.begin(), list.end(),[](const point& lhs, const point& rhs)->bool
       {  return lhs.getX() < rhs.getX(); });

       for(const point& it: list)
       std::cout << it << std::endl;
    

     if(list.size()%2!=0)
     {
       point p1;
       p1 = list[(list.size()/2)];
      // cout <<p1 = list[list.size()/2] << endl;
       median = p1.getX();
       cout << median << endl;
       }
       else
       {
               point p1,p2;
               p1=list[(list.size()/2)-1];
               p2=list[(list.size()/2)];
               median = (p1.getX() + p2.getX())/2;
            //  cout << median = (p1.getX() + p2.getX() - 1)/2 << endl;
	       cout << median << endl;
       }
      }

       return median;
    }


// FUNCTION TO IMPLEMENT THE MMM ALGORITHM

int  funion(int n, std::vector<point> &list)
{
      vector<point> leftlistx;
      vector<point> rightlistx;
      vector<point> leftlisty;
      vector<point> rightlisty;
float median_x,median_y;
int countxl=0, countxr=0, countyl=0, countyr=0;
char ch = 'x';
point p1;
    median_x=	sor(ch,n,list);
char cha = 'y';
    median_y=	sor(cha,n,list);
	//compare and divide in left and right
       fstream newfile;     
       newfile.open("/home/hp/practice/output_file.txt", ios::app);
      newfile << median_x << "\t" << median_y << endl;
      newfile.close();
       
      for(const point& it: list){ 
           if(median_x > it.getX())
           {
           p1.setx(it.getX());
	   p1.sety(it.getY());

	   leftlistx.push_back(p1);
	   countxl++;
           }
	   else 	    
           {
           p1.setx(it.getX());
	   p1.sety(it.getY());

           rightlistx.push_back(p1);
	   countxr++;
	   }
	 }
	 

   	for(const point& it: list){
           if(median_y > it.getX())
	    {
	    p1.setx(it.getX());
	    p1.sety(it.getY());

            leftlisty.push_back(p1);
	    countyl++;
            }
	    else
	    {
            p1.setx(it.getX());
	    p1.sety(it.getY());

            rightlisty.push_back(p1);
	    countyr++;
	    }
	}
      if(countxl>1) 
	    funion(countxl,leftlistx);
      else 
	      return 1;
      if(countxr>1)
            funion(countxr,rightlistx);
      else
	     return 1; 
	
	return 0;
           
}

 //output_function()
//{



//}

       int main()
{
	std::vector<point> list;
       int x, y, n;
       point p1;
    //  char ch;

       std::cin >> n;
  //     std::cin >> ch;
      for(int i=0; i<n; i++)
       {
          std::cin >> x >> y;
          p1.setx(x);
          p1.sety(y);
          list.push_back(p1);
       
      }
      //FUNCTION CALL

        funion(n,list);
//	float test = sor(ch,n,list);
//	cout << "median is " << test << endl;
	return 0;

    }
