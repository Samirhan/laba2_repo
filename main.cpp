#include <iostream>
#include <windows.h>


using namespace std;



class Point{
protected:
    int x,y;
public:
    Point(){
        cout << "Point()" << endl;
        x = 0;
        y = 0;
    }

    Point(int x, int y){
        cout << "Point(int x, int y)" << endl;
        this->x = x;
        this->y = y;
    }

    Point(const Point &p){
        cout << "Point(const Point &p)" << endl;
        x = p.x;
        y = p.y;
    }

    ~Point(){
        cout << "~Point()" << endl;
        cout << x << ", " << y << endl;
    }
    void move(int dx, int dy){
        x = x + dx;
        y = y + dy;
    }
    void reset();
};

void Point::reset() {
    x = 0;
    y = 0;
}

class ColoredPoint : public Point{
protected:
    int color;
public:
    ColoredPoint() : Point(){
        cout << "ColoredPoint()" << endl;
        color = 0;
    }

    ColoredPoint(int x, int y, int color) : Point(x, y){
        cout << "ColoredPoint(int x, int y, int color)" << endl;
        this->color = color;
    }

    ColoredPoint(const ColoredPoint &p){
        cout << "ColoredPoint(const ColoredPoint &p)" << endl;
        x = p.x;
        y = p.y;
    }

    ~ColoredPoint(){
        cout << "~ColoredPoint()" << endl;
        cout << x << ", " << y << ", " << color << endl;
    }
    void change_color(int new_color){
        color = new_color;
    }

};


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
//    cout << "Статически" << endl;
//    {
//        Point p1;
//        Point p2(50, 100);
//        Point p3(p2);
//    }
//    cout << "\nДинамически" << endl;
//
//    Point *p = new Point();
//    Point *p2 = new Point(30,60);
//    Point *p3 = new Point(*p2);
//    delete p;
//    delete p2;
//    delete p3;

    //Метод у Point
    //К полям обратиться не можем, но можем вызвать публичный метод (поля - привате)
//    Point *p = new Point(1,2);
////    p->reset();
//    p->move(100,200);
//    delete p;

    // НАСЛЕДОВАНИЕ
    ColoredPoint *p = new ColoredPoint(1,2,52);
    delete p;




    return 0;
}