#include <iostream>
#include <cmath>
using namespace std;

class VECTOR3D {
public:
    float x, y, z;

    VECTOR3D() : x(0), y(0), z(0) {}
};

class MATRIX {
public:
    MATRIX() :ele{ 0 }{}

    MATRIX Transpose();
    MATRIX Inverse();
    float Determinant();

    MATRIX operator+(MATRIX m);
    MATRIX operator-(MATRIX m);
    MATRIX operator*(MATRIX m);
    MATRIX operator*(float m);
    VECTOR3D operator*(VECTOR3D v);

    float ele[3][3];
};

MATRIX MATRIX::operator+(MATRIX m) {
    MATRIX result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result.ele[i][j] = ele[i][j] + m.ele[i][j];
    return result;
}

MATRIX MATRIX::operator-(MATRIX m) {
    MATRIX result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result.ele[i][j] = ele[i][j] - m.ele[i][j];
    return result;
}

MATRIX MATRIX::operator*(MATRIX m) {
    MATRIX result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                result.ele[i][j] += ele[i][k] * m.ele[k][j];
    return result;
}

MATRIX MATRIX::operator*(float scalar) {
    MATRIX result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result.ele[i][j] = ele[i][j] * scalar;
    return result;
}

VECTOR3D MATRIX::operator*(VECTOR3D v) {
    VECTOR3D result;
    result.x = ele[0][0] * v.x + ele[0][1] * v.y + ele[0][2] * v.z;
    result.y = ele[1][0] * v.x + ele[1][1] * v.y + ele[1][2] * v.z;
    result.z = ele[2][0] * v.x + ele[2][1] * v.y + ele[2][2] * v.z;
    return result;
}

MATRIX MATRIX::Transpose() {
    MATRIX result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result.ele[i][j] = ele[j][i];
    return result;
}

MATRIX MATRIX::Inverse() {
    MATRIX result;
    float det = Determinant();
    if (fabs(det) < 1e-6) {
        return result;
    }

    result.ele[0][0] = (ele[1][1] * ele[2][2] - ele[1][2] * ele[2][1]) / det;
    result.ele[0][1] = (ele[0][2] * ele[2][1] - ele[0][1] * ele[2][2]) / det;
    result.ele[0][2] = (ele[0][1] * ele[1][2] - ele[0][2] * ele[1][1]) / det;
    result.ele[1][0] = (ele[1][2] * ele[2][0] - ele[1][0] * ele[2][2]) / det;
    result.ele[1][1] = (ele[0][0] * ele[2][2] - ele[0][2] * ele[2][0]) / det;
    result.ele[1][2] = (ele[0][2] * ele[1][0] - ele[0][0] * ele[1][2]) / det;
    result.ele[2][0] = (ele[1][0] * ele[2][1] - ele[1][1] * ele[2][0]) / det;
    result.ele[2][1] = (ele[0][1] * ele[2][0] - ele[0][0] * ele[2][1]) / det;
    result.ele[2][2] = (ele[0][0] * ele[1][1] - ele[0][1] * ele[1][0]) / det;

    return result;
}

float MATRIX::Determinant() {
    return ele[0][0] * (ele[1][1] * ele[2][2] - ele[1][2] * ele[2][1]) -
           ele[0][1] * (ele[1][0] * ele[2][2] - ele[1][2] * ele[2][0]) +
           ele[0][2] * (ele[1][0] * ele[2][1] - ele[1][1] * ele[2][0]);
}

void printMatrix(const MATRIX& m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m.ele[i][j] << " ";
        }
        cout << endl;
    }
}

void printVector(const VECTOR3D& v) {
    cout << v.x << " " << v.y << " " << v.z << endl;
}

int main() {
    MATRIX a, b;
    a.ele[0][0] = 1.0f; a.ele[0][1] = -1.0f; a.ele[0][2] = 2.0f;
    a.ele[1][0] = 1.0f; a.ele[1][1] = -1.0f; a.ele[1][2] = 2.0f;
    a.ele[2][0] = 1.0f; a.ele[2][1] = -1.0f; a.ele[2][2] = 2.0f;

    b.ele[0][0] = 1.0f; b.ele[0][1] = 2.0f; b.ele[0][2] = 3.0f;
    b.ele[1][0] = 1.0f; b.ele[1][1] = 2.0f; b.ele[1][2] = 3.0f;
    b.ele[2][0] = 1.0f; b.ele[2][1] = 2.0f; b.ele[2][2] = 3.0f;

    float t = 3;
    VECTOR3D v;
    v.x = 2; v.y = 4; v.z = 6;

    MATRIX addition = a + b;
    MATRIX subtraction = a - b;
    MATRIX scalarMultiplication = a * t;
    VECTOR3D vectorMultiplication = a * v;

    cout << "Matrix addition of a + b:" << endl;
    printMatrix(addition);
    cout << endl;

    cout << "Matrix subtraction of a - b:" << endl;
    printMatrix(subtraction);
    cout << endl;

    cout << "Scalar t multiplication of a:" << endl;
    printMatrix(scalarMultiplication);
    cout << endl;

    cout << "Matrix a & vector v multiplication:" << endl;
    printVector(vectorMultiplication);
    cout << endl;

    cout << "Matrix transpose of a:" << endl;
    printMatrix(a.Transpose());
    cout << endl;

    cout << "Matrix inverse of a (simplified):" << endl;
    printMatrix(a.Inverse());
    cout << endl;

    cout << "Matrix determinant of a (simplified): " << a.Determinant() << endl;
    cout << endl;

    return 0;
}
