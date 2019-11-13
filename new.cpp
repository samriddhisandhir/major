#include <iostream>
#include <vector>
#include <algorithm>

    class point
    {
    private:
       int x;
       int y;
    public:
       point() = default;
       ~point(){}
       void setx(int xn){ x = xn;}
       void sety(int yn) { y = yn; }

       bool operator<(const point& obj)
       {  return this->y < obj.y;  }
       const int& getX()const { return x; }
       const int& getY()const { return y; }
       // overload operator<< to print the object of this class
       friend std::ostream& operator<<(std::ostream& out, const point& obj);
    };
    std::ostream& operator<<(std::ostream& out, const point& obj)
    {  return out << obj.getX() << " " << obj.getY();  }


    int main()
    {
       std::vector<point> list;
       int x, y, n;
       point p1;
       char ch;

       std::cin >> n;
       std::cin >> ch;
      for(int i=0; i<n; i++)
       {
          std::cin >> x >> y;
          p1.setx(x);
          p1.sety(y);
          list.push_back(p1);
       }
      if(ch == 'y' || ch == 'Y')
       {
       std::cout <<"sorting w.r.t Y" <<std::endl;
       std::sort(list.begin(), list.end());
       for(const point& it: list)
       std::cout << it << std::endl;
    }
     if(ch == 'x' || ch == 'X')
      {
       std::cout <<"sorting w.r.t X" <<std::endl;
       std::sort(list.begin(), list.end(),[](const point& lhs, const point& rhs)->bool
       {  return lhs.getX() < rhs.getX(); });

       for(const point& it: list)
       std::cout << it << std::endl;
    }
       return 0;
    }
