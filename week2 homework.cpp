#include <iostream>
#include <cmath>

using namespace std; // 네임스페이스 추가

class VECTOR3D
{
public:
    VECTOR3D()
    : x(0.0f), y(0.0f), z(0.0f) {}

    VECTOR3D(float x, float y, float z)
    : x(x), y(y), z(z) {}

    float Magnitude();
    float InnerProduct(VECTOR3D v);
    VECTOR3D CrossProduct(VECTOR3D v);
    void Normalize();

    VECTOR3D operator+(VECTOR3D v);
    VECTOR3D operator-(VECTOR3D v);
    VECTOR3D operator*(float val);

    float x, y, z;
};

VECTOR3D VECTOR3D::operator+(VECTOR3D v)
{
    return VECTOR3D(x+v.x, y+v.y, z+v.z);
}

VECTOR3D VECTOR3D::operator-(VECTOR3D v)
{
    return VECTOR3D(x-v.x, y-v.y, z-v.z);
}

VECTOR3D VECTOR3D::operator*(float val)
{
    return VECTOR3D(x*val, y*val, z*val);
}

float VECTOR3D::Magnitude()
{
    return sqrt(x*x + y*y + z*z);
}

float VECTOR3D::InnerProduct(VECTOR3D v)
{
    return x*v.x + y*v.y + z*v.z;
}

VECTOR3D VECTOR3D::CrossProduct(VECTOR3D v)
{
    return VECTOR3D(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

void VECTOR3D::Normalize()
{
    float mag = Magnitude();
    x /= mag;
    y /= mag;
    z /= mag;
}

int main()
{
    float x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    VECTOR3D a(x1, y1, z1), b(x2, y2, z2);

    VECTOR3D addition = a + b;
    VECTOR3D subtraction = a - b;
    VECTOR3D scalarMultiplication = a * 5.0f;
    a.Normalize();
    float magnitudeA = a.Magnitude();
    float dotProduct = a.InnerProduct(b);
    VECTOR3D crossProduct = a.CrossProduct(b);

    cout << "Addition: (" << addition.x << ", " << addition.y << ", " << addition.z << ")\n";
    cout << "Subtraction: (" << subtraction.x << ", " << subtraction.y << ", " << subtraction.z << ")\n";
    cout << "Scalar Multiplication (5*a): (" << scalarMultiplication.x << ", " << scalarMultiplication.y << ", " << scalarMultiplication.z << ")\n";
    cout << "Normalization of a: (" << a.x << ", " << a.y << ", " << a.z << ")\n";
    cout << "Magnitude of a: " << magnitudeA << "\n";
    cout << "Dot product of a and b: " << dotProduct << "\n";
    cout << "Cross product of a and b: (" << crossProduct.x << ", " << crossProduct.y << ", " << crossProduct.z << ")\n";

    return 0;
}
