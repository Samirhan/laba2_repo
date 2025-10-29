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
    cout << "Point reset()" << endl;
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
    void reset() {
        cout << "ColoredPoint reset()\n";
        Point::reset();
        color = 0;
    }


};

class PoorPoint : public Point{};

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

class SectionPP {
protected:
    Point p1;
    Point p2;
public:
    SectionPP() {
        cout << "SectionPP()" << endl;
        // создаются два Point по умолчанию
    }

    SectionPP(int x1, int y1, int x2, int y2) {
        cout << "SectionPP(int x1, int y1, int x2, int y2)" << endl;
        p1 = Point(x1, y1);
        p2 = Point(x2, y2);
    }

    SectionPP(const SectionPP &s) {
        cout << "SectionPP(const SegmentDirect &s)" << endl;
        p1 = s.p1;
        p2 = s.p2;
    }

    ~SectionPP() {
        cout << "~SectionPP()" << endl;
    }

    void move(int dx, int dy) {
        p1.move(dx, dy);
        p2.move(dx, dy);
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
    //К полям обратиться не можем, но можем вызвать публичный метод (поля - протектед)
//    Point *p = new Point(1,2);
//    p->reset();
//    p->move(100,200);
//    delete p;

    // НАСЛЕДОВАНИЕ
//    ColoredPoint *p = new ColoredPoint(1,2,52);
//    delete p;

    //Колоред поинт как поинт
//    Point *p = new ColoredPoint(1, 2 ,42);
//    delete p;


    //переопределение род метода в потомке
//    {
//
//        ColoredPoint cp(1,2,7);
//
//        cout << "Вызов через ColoredPoint: ";
//        cp.reset(); // вызовется ColoredPoint::reset()
//
//        Point* p = &cp;
//        cout << "Вызов через Point: ";
//        p->reset(); //
//    }


    //класс с точками не указателями а прям объектами  vs класс с указателями
//    cout << "\nSection (c указателями)\n" << endl;
//    {
//        Section s1(10, 20, 30, 40);
//    }
//
//    cout << "\nSegmentPP (без указателей)\n" << endl;
//    {
//        SectionPP s2(10, 20, 30, 40);
//    }


    //копирование обьекта в объект  и указатель в указатель
//    cout << "\nКопирование объект в объект" << endl;
//    {
//        Point a(1, 2);
//        Point b;
//        b = a;
//        a.move(100, 200);
//    }
//
//    cout << "\nКопирование указатель в указатель" << endl;
//    {
//        Point* p1 = new Point(10, 20);
//        Point* p2 = p1;;
//        p2->move(50, 50);
//        delete p1;
//        delete p2;
//    }
//    cout << "Потомок без конструкторов и деструкторов" << endl;
//    {
//        PoorPoint pp;
//    };
    //что не так со второй командой
//    cout << "Потеря" << endl;
//    {
//        Point p = ColoredPoint(1,2,3); //создается поинт по факту
//
//    }
    return 0;
}