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
#include <chrono>


using namespace std;
using namespace std::chrono;


//PARSE
//Structure for sink
struct sink
{
int sno;
int xc;
int yc;
int load_cap;
};
//Structure for  blockages
struct bl
{
int coord1;
int coord2;
int coord3;
int coord4;
};
//Structure for wire types
struct wire_type
{
 int type;
 float unit_res;
 float unit_cap;
};
//Structure for buffer types
struct buf_type
{
    int type;
    string subckt_name;
    int inverted;
    float input_load_cap;
    float output_parasitic_cap;
    float output_res;
};

//CLASS FOR INPUT
class input
{
 public:
int x1,y1,x2,y2;
string source;
int sink_val;
int num_wire;
float volt1,volt2;
float lim_slew;
float lim_cap;
int num_block;
int num_buf;
vector<sink>rect = vector<sink>(1000);
vector<bl>block = vector<bl>(100);
vector<wire_type>wire = vector<wire_type>(2);
vector<buf_type>buf = vector<buf_type>(10);


//FUNCTION FOR PARSING THE INPUT FILE AND STORING THE VALUES IN AN OBJECT OF INPUT CLASS
input parse_file(input obj)
{
fstream newfile;
string line;
string s1 = "source";
string s2 = "num sink";
string s3 = "num wirelib";
string s4 = "simulation vdd";
string s5 = "limit slew";
string s6 = "limit cap";
string s7 = "num blockage";
string s8 = "num buflib";
int x=0;
newfile.open("/home/hp/major_project/input3",ios::in);
if(!newfile)
{
cout<<"no such file";
}
else
{
char ch;
while(!newfile.eof())
{
getline(newfile,line);

if(x==0)
{
 int val1;
 int val2;
 int val3;
 int val4;

 std::stringstream ss(line);
 ss >> obj.x1 >> obj.y1 >> obj.x2 >> obj.y2;

cout << obj.x1 << endl;
cout << obj.y1 << endl;
cout << obj.x2 << endl;
cout << obj.y2 << endl;
x=1;
}

if(!line.find(s1)) {
obj.source = line;
cout<<obj.source<<endl;
}

if(!line.find(s2)) {
string tmp;
int value;
string c;
std::stringstream ss(line);
ss >> tmp >> c >> value;
obj.sink_val = value;
cout << obj.sink_val << endl;

for(int i=0;i<obj.sink_val;i++)
{
 getline(newfile,line);
 std::stringstream ss(line);
 ss >> obj.rect[i].sno >> obj.rect[i].xc >> obj.rect[i].yc >> obj.rect[i].load_cap;
 cout << obj.rect[i].sno <<endl;
 cout << obj.rect[i].xc << endl;
 cout << obj.rect[i].yc << endl;
cout << obj.rect[i].load_cap << endl;

}
}

if(!line.find(s3)) {
string tmp;
int value;
string c;
std::stringstream ss(line);
ss >> tmp >> c >> value;
obj.num_wire = value;
cout << obj.num_wire << endl;
for(int i=0;i<obj.num_wire;i++)
{
 getline(newfile,line);
 std::stringstream ss(line);
 ss >> obj.wire[i].type >> obj.wire[i].unit_res >> obj.wire[i].unit_cap;

 cout << obj.wire[i].type << endl;
 cout << obj.wire[i].unit_res << endl;
 cout << obj.wire[i].unit_cap << endl;
}

}

if(!line.find(s8)) {
string tmp;
int value;
string c;
std::stringstream ss(line);
ss >> tmp >> c >> value;
obj.num_buf = value;
cout << obj.num_buf << endl;
for(int i=0;i<obj.num_buf;i++)
{
 getline(newfile,line);
 std::stringstream ss(line);
 ss >> obj.buf[i].type >> obj.buf[i].subckt_name >> obj.buf[i].inverted >> obj.buf[i].input_load_cap >> obj.buf[i].output_parasitic_cap >> obj.buf[i].output_res;
 cout << obj.buf[i].type << endl;
 cout << obj.buf[i].subckt_name << endl;
 cout << obj.buf[i].inverted << endl;
 cout << obj.buf[i].input_load_cap << endl;
 cout << obj.buf[i].output_parasitic_cap << endl;
 cout << obj.buf[i].output_res << endl;

}
}

if(!line.find(s4)) {
string tmp1;
string tmp2;
float val1;
float val2;
std::stringstream ss(line);
ss >> tmp1 >> tmp2 >> val1 >> val2;
obj.volt1 = val1;
obj.volt2 = val2;
cout << obj.volt1 << endl;
cout << obj.volt2 << endl;
}

if(!line.find(s5)) {
string tmp1;
string tmp2;
float val;
std::stringstream ss(line);
ss >> tmp1 >> tmp2 >> val;
obj.lim_slew = val;
cout << obj.lim_slew << endl;
}

if(!line.find(s6)) {
string tmp1;
string tmp2;
float val;
std::stringstream ss(line);
ss >> tmp1 >> tmp2 >> val;
obj.lim_cap = val;
cout << obj.lim_cap << endl;
}

if(!line.find(s7)) {
string tmp;
int value;
string c;
std::stringstream ss(line);
ss >> tmp >> c >> value;
obj.num_block = value;
cout << obj.num_block << endl;
if(obj.num_block != 0)
{
for(int i=0;i<obj.num_block;i++)
{
 getline(newfile,line);
 std::stringstream ss(line);
 ss >> obj.block[i].coord1 >> obj.block[i].coord2 >> obj.block[i].coord3 >> obj.block[i].coord4;
 cout <<obj.block[i].coord1 << endl;
 cout << obj.block[i].coord2 << endl;
 cout << obj.block[i].coord3 << endl;
 cout << obj.block[i].coord4 << endl;

}

}
else{
;
}
}
}
}
newfile.close();

return obj;

}

};





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

        bool operator==(const point & obj2)
{

if((this->getX()==obj2.getX()) && (this->getY()==obj2.getY()) )
return true;
else
return false;
}
    };
    std::ostream& operator<<(std::ostream& out, const point& obj)
    {  return out << obj.getX() << " " << obj.getY();  }




    //FUNCTION TO SORT W.R.T X OR Y

    int sort_func(char ch, std::vector<point> &list, std::vector<point> &list_u, std::vector<point> &list_v)
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
point p1;
if(ch=='x')
{
for(const point& it: list){
           if(median > it.getX())
           {
           p1.setx(it.getX());
           p1.sety(it.getY());

           list_u.push_back(p1);
           }
           else
           {
           p1.setx(it.getX());
           p1.sety(it.getY());

           list_v.push_back(p1);
           }
         }
}
else
{
for(const point& it: list){
           if(median > it.getY())
           {
           p1.setx(it.getX());
           p1.sety(it.getY());

           list_u.push_back(p1);
           }
           else
           {
           p1.setx(it.getX());
           p1.sety(it.getY());

           list_v.push_back(p1);
           }
         }
}



       return 0;
    }


point mid_point(point x1, point x2)
{
float x,y,w,z,resultx,resulty;
x=x1.getX();
y=x1.getY();
w=x2.getX();
z=x2.getY();
   point mid;
   resultx = (x + w) /2;
   resulty = (y + z) /2;
   mid.setx(resultx);
   mid.sety(resulty);
   return mid;
}
int addedge(point x1, point x2, std::vector<point> &list)
{
list.push_back(x1);
list.push_back(x2);

fstream newfile;
       newfile.open("/home/hp/major_project/output_file.txt", ios::app);
      newfile << fixed << x1 << "\t" << x2 << endl;
      newfile.close();

return 0;
}


// FUNCTION TO IMPLEMENT THE MMM ALGORITHM

point mmm(std::vector<point> &list_a, std::vector<point> &list_b, std::vector<point> &list_c, bool d, std::vector<point> &list_mid, std::vector<point> &list_new)
{

char ch;
point m,n,o;
std::vector<point> list_u;
std::vector<point> list_v;
      if(list_b.size()==1)
     return list_b.front();
   
      // based on D sort points and split B in 2 lists u,v
         
         

         if(d)
           ch='x';
else
           ch='y';
 
sort_func(ch,list_b,list_u,list_v);
    m = mmm(list_a,list_u,list_c,!d,list_mid,list_new);
    n = mmm(list_a,list_v,list_c,!d,list_mid,list_new);
    o = mid_point(m,n);
    list_a.push_back(o);
    list_mid.push_back(o);
    list_new.push_back(o);
    addedge(m,o,list_c);
    addedge(n,o,list_c);
    return o;

}

//OUTPUT FILE FUNCTION

void output_func(std::vector<point> &v, input obj, std::vector<point> &list, std::vector<point> &list_new)
{
fstream testfile;
fstream newfile;
newfile.open("/home/hp/major_project/output", ios::app);
newfile << "sourcenode 0 0" << endl;
newfile << "num node" << " " << list_new.size() << endl;
        int count = 0;
        for(const point& it: list_new){
count++;
newfile << fixed << count << " " << it.getX() << " " << it.getY() << endl;
}

         

newfile << "num sinknode" << " " << obj.sink_val << endl;
for(int i=0;i<obj.sink_val;i++)
{
count++;
newfile << count << " " << obj.rect[i].sno << endl;
}

newfile << "num wire" << " " << count << endl;
int i=0, index=0;
for (const point& it: list) {
   if (std::find(v.begin(), v.end(), it) != v.end()) {
   auto c = std::find(v.begin(), v.end(), it);
      index = std::distance(v.begin(),c);
     index++;

if(i==0)
{
newfile << index << " ";
i=1;
}
else
{
newfile << index << " 0" << endl;
i=0;
}

}
 
}

newfile << "0 " << index << " 0" << endl;
newfile << "num buffer 0" << endl;

        newfile.close();

}

int main()
{
    input obj1;
//CALL FOR FUNCTION
obj1 = obj1.parse_file(obj1);
std::vector<point> list_a, list_b, list_c, list_u, list_v, list_mid, list_new;
       int x, y ;
       point p1;
bool d = true;
  cout << obj1.sink_val << endl;
      for(int i=0; i<obj1.sink_val; i++)
       {
x = obj1.rect[i].xc;
y = obj1.rect[i].yc;
          p1.setx(x);
          p1.sety(y);
          list_a.push_back(p1);
          list_b.push_back(p1);
      }

      //FUNCTION CALL

auto start = high_resolution_clock::now();
      mmm(list_a, list_b, list_c, d, list_mid, list_new);
auto stop = high_resolution_clock::now();

for(int i=0; i<obj1.sink_val; i++)
       {
         x = obj1.rect[i].xc;
         y = obj1.rect[i].yc;
          p1.setx(x);
          p1.sety(y);
          list_mid.push_back(p1);
      }

output_func(list_mid, obj1, list_c, list_new);

   auto duration = duration_cast<microseconds>(stop - start);
cout << "\n\n" << endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
return 0;

    }
