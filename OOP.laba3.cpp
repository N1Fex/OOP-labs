#include <iostream>
#include <fstream>
#include <string>
//+=
    
struct Figure {
    std::string stroke;
    std::string fill = "#0";
    double stroke_width = 1;
};

struct Polygon : Figure {
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double x4, y4;
    Polygon(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) :
        x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {};
    Polygon(double x1, double y1, double x2, double y2, double x3, double y3) :
        x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x3), y4(y3) {};
};

struct Rect : Figure {
    double x, y;
    double width, height;
    Rect(double x, double y, double w, double h) : x(x), y(y), width(w), height(h) {};
};
struct Circle : Figure {
    double x, y;
    double radius;
    Circle(double x, double y, double r) :x(x),y(y),radius(r) {};
};

std::ostream& operator << (std::ostream& os, const Rect& r) {
    return os << "<rect x=\"" << r.x << "\" y=\"" << r.y
        << "\" width=\"" << r.width << "\" height=\"" << r.height << "\" fill=\"" << r.fill <<
        "\" stroke = \"" << r.stroke << "\" stroke-width=\"" << r.stroke_width << "\"/>\n";
 
}

std::ostream& operator << (std::ostream& os, const Polygon& p) {
    return os << "<polygon points =\"" << p.x1 <<","<<p.y1 << " " << p.x2 << "," << p.y2 << " " <<
        p.x3 << "," << p.y3 << " " << p.x4 << "," << p.y4 << "\" fill = \"" << p.fill << "\"/>\n";

}

std::ostream& operator << (std::ostream& os, const Circle& c) {
    return os << "<circle cx=\"" << c.x << "\" cy=\"" << c.y << "\" r=\"" << c.radius << "\" fill=\"" << c.fill << "\" />\n";
}
int main()
{
    std::ofstream fout("SVGimage.svg");
    fout << "<svg ViewBox = \"0 0 200 160\">\n"; 

    Rect r(0, 0, 200, 160);
    r.fill = "#F5F0DC";
    r.stroke = "black";
    r.stroke_width = 0;
    fout << r;
        
    Rect r1(10, 10, 179, 139);
    r1.fill = "#F5F0DC";
    r1.stroke = "black";
    r1.stroke_width = 1;
    fout << r1;
    
    Polygon p(130, 10, 189, 10, 189, 149, 78, 149);
    p.fill = "#0";
    fout << p;

    Circle c(133, 86, 40);
    c.fill = "#F5F5dc";
    fout << c;

    Polygon tr1(10, 73, 50, 20, 120, 97);
    tr1.fill = "#AB0000";
    fout << tr1;

    Polygon tr2(68, 98, 80, 94, 110, 99);
    fout << tr2;

    Polygon tr3(79, 103,75, 98.5,110, 99);
    tr3.fill = "#AB0000";
    fout << tr3;

    Polygon p1(25, 124,55, 121,55.5, 124,25.5, 127);
    p1.fill = "#AB0000";
    fout << p1;

    Polygon p2(40, 116,78, 112,78.5, 113.5,40.5, 117.5);
    p2.fill = "#AB0000";
    fout << p2;

    Polygon p3(77, 110,85, 109,85.2, 110,77.2, 111);
    p3.fill = "#AB0000";
    fout << p3;

    Polygon p4(64, 120,70, 124,59, 144,53, 140);
    p4.fill = "#AB0000";
    fout << p4;

    Polygon p5(72, 126,78, 129,77, 130,71, 127);
    p5.fill = "#AB0000";
    fout << p5;

    Polygon p6(69.5, 129,77.5, 133,76.5, 135,68.5, 131);
    p6.fill = "#AB0000";
    fout << p6;

    Polygon p7(70, 135,78, 139,76, 142,68, 138);
    p7.fill = "#AB0000";
    fout << p7;

    fout << "</svg>";
    fout.close();
    

}
 
