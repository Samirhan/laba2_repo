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

    virtual ~Point(){
        cout << "~Point(): " << x << ", " << y << endl;

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

    ColoredPoint(const ColoredPoint& p) : Point(p) {
        color = p.color;
        cout << "ColoredPoint(const ColoredPoint& p)" << endl;
    }

    ~ColoredPoint(){
        cout << "~ColoredPoint(): " << x << ", " << y << ", " << color<< endl;
    }
    void change_color(int new_color){
        color = new_color;
    }

};

class Section{
protected:
    Point *p1;
    Point *p2;
public:
    Section(){
        cout << "Section()" << endl;
        p1 = new Point();
        p2 = new Point();
    }

    Section(int x1, int y1, int x2, int y2){
        cout << "Section(int x1, int y1, int x2, int y2)" << endl;
        p1 = new Point(x1,y1);
        p2 = new Point (x2,y2);
    }

    Section(const Section &s){
        cout << "Section(const Section &p)" << endl;
        p1 = new Point(*(s.p1));
        p2 = new Point(*(s.p2));
    }

    virtual ~Section(){
        cout << "~Section()" << endl;
        delete p1;
        delete p2;

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
//    Point *p1 = new Point();
//    Point *p2 = new Point(30,60);
//    Point *p3 = new Point(*p2);
//    delete p1;
//    delete p2;
//    delete p3;

    //Метод у Point
    //К полям обратиться не можем, но можем вызвать публичный метод (поля - привате)
//    Point *p = new Point(1,2);
////    p->reset();
//    p->move(100,200);
//    delete p;

    // НАСЛЕДОВАНИЕ
//    ColoredPoint *p = new ColoredPoint(1,2,52);
//    delete p;

    //Колоред поинт как поинт
//    Point *p = new ColoredPoint(1, 2 ,42);
//    delete p;



    return 0;
}