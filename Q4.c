#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159
#define POWER 2

double distancexy(double x1, double x2, double y1, double y2);

double trigo(double a1, double b1);

double circleRadius(double radius);

double circlePerimeter(double radius);

int rectangelArea(int rectSide1, int rectSide2);

int squareArea(int sideOfSquare);

int main(void)
{
  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;
  double a1 = 0;
  double b1 = 0;
  double radius = 0;
  int rectSide1 = 0;
  int rectSide2 = 0;
  int sideOfSquare = 0;

  enum calcOption
  {
    DISTANCE = 1,
    HYPOTENUSE,
    CIRCLEAREAPERIMETER,
    RECTANGELAREA,
    QUAREAREA,
    EXIT
  };

  enum calcOption option;
  option = 0;
aaaaaaaaaaaaaaaaaaaaaa
  do
  {

    printf("\n\nWelcome to my calculator!\nchoose option:\n1 - Calc distance between 2 points\n2 - Calc hypotenuse of triangel\n3 - Calc area and perimeter of circle\n4 - Calc area of rectangel\n5 - Calc area of square\n6 - Exit\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("enter point1 coordinates: ");
      scanf("%lf %lf", &x1, &y1);

      printf("enter point2 coordinates: ");
      scanf("%lf %lf", &x2, &y2);
      getchar();

      printf("Distance is %.2lf", distancexy(x1, x2, y1, y2));
      break;

    case 2:
      printf("Enter 2 sides of the triangle: ");
      scanf("%lf %lf", &a1, &b1);
      printf("Hypotenuse is: %.2lf\n", trigo(a1, b1));
      break;

    case 3:
      printf("Enter circle radius: ");
      scanf("%lf", &radius);
      printf("perimeter: %.2lf\n", circlePerimeter(radius));
      printf("area: %.2lf\n", circleRadius(radius));
      break;

    case 4:
      printf("Enter rectangel length: ");
      scanf("%d", &rectSide1);
      printf("Enter rectangel width: ");
      scanf("%d", &rectSide2);

      printf("the area of the rectangel is %d", rectangelArea(rectSide1, rectSide2));
      break;

    case 5:
      printf("Enter length of square side: ");
      scanf("%d", &sideOfSquare);
      printf("the area of the square is: %d\n", squareArea(sideOfSquare));
      break;

    }
  } while (option != 6);

  if (option == 6)
  {
    printf("Goodbye!");
  }

  return 0;
}

//Function's HERE!

// case 1
// distance between 2 point's
// input : point cordinates
// output : distance between them

double distancexy(double x1, double x2, double y1, double y2)
{
  double x3 = 0;
  double y3 = 0;
  double ansx3 = 0;
  double ansy3 = 0;
  double final = 0;
  double end = 0;

  x3 = x2 - x1;
  ansx3 = pow(x3, POWER);

  y3 = y2 - y1;
  ansy3 = pow(y3, POWER);

  final = ansy3 + ansx3;
  end = sqrt(final);
  return end;
}

//  case 2
// calc the c in the triangel (a^2 + b^2 = c^2)
// input : side a , side b of triangel
// output : side c of the triangel

double trigo(double a1, double b1)
{
  double ansa = 0;
  double ansb = 0;
  double final = 0;
  double end = 0;

  ansa = pow(a1, POWER);
  ansb = pow(b1, POWER);

  final = ansa + ansb;
  end = sqrt(final);
  return end;
}

// case 3
// circle perimeter and area caclculation

// area calculation
// area (R^2 * PI)

// input : radius of the circle
// output : the area of the circle

double circleRadius(double radius)
{
  double area = 0;

  area = radius * radius * PI;
  return area;
}

//perimeter calculation
// perimeter (R * 2 * PI)

// input : radius of the circle
// output : the length of the perimter of the circle

double circlePerimeter(double radius)
{
  double perimeter = 0;

  perimeter = radius * POWER * PI;
  return perimeter;
}


// case 4
// rectangel area caclculation (one side * second side)

// input : two sides of the rectangel
// output : the area of the rectangel

int rectangelArea(int rectSide1, int rectSide2)
{
  int final = 0;

  final = rectSide1 * rectSide2;

  return final;
}



// case 5
// square area caclculation (side * side)

// input : one side of square
// output : the area of the square

int squareArea(int sideOfSquare)
{
  int final = 0;

  final = sideOfSquare * sideOfSquare;

  return final;
}
