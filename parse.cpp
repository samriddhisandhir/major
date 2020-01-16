#include<fstream>
#include<iostream>
#include <regex> 
#include<string.h>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Structure for sink
struct sink
{
int sno;
int xc;
int yc;
int load_cap;
};
//Structure for blockages
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
vector<sink>rect = vector<sink>(4);
vector<bl>block = vector<bl>(4);
vector<wire_type>wire = vector<wire_type>(2);

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

int x=0;
newfile.open("/home/hp/major_project/input.txt",ios::in);
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


}
}
newfile.close();




}
};

//MAIN FUNCTION
int main()
{
input obj1;
//CALL FOR FUNCTION 
obj1.parse_file(obj1);

return 0;
}



