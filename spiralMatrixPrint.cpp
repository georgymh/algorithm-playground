#include <iostream>
#include <string>

#define R 5
#define C 5

using namespace std;

// Spiral traverse through a matrix, beginning from the top right and moving inwards.
void spiralMatrixPrint(int a[R][C], int n, int m) {
    int left = 0;
    int right = m;
    int top = 0;
    int bottom = n;
    
    while ( (right > left) && (bottom > top) ) {
        // Top to bottom on right column
        for (int r = top; r < bottom; r++)
            cout << a[r][right-1] << " ";    
        right--;
        
        // Right to left on bottom row
        for (int c = right-1; c >= left; c--)
            cout << a[bottom-1][c] << " ";
        bottom--;

        // Bottom to top on left column
        if ((bottom > top) && (right - left > 0) ) {
            for (int r = bottom-1; r >= top; r--) 
                cout << a[r][left] << " ";
            left++;
        }
        
        // Left to right on top row
        if ((right > left) && (bottom - top > 0)) {
            for (int c = left; c < right; c++)
                cout << a[top][c] << " ";
            top++;
        }
    }
}

int main()
{ 
    int a[R][C] = { 
        {1,   2,  3, 30, 44},
        {6,   7,  8, 75, 65},
        {44, 12, 13, 99, 90},
        {11, 55, 65,  5, 34},
        {54, 65, 31,  4, 43}
    };
    
    spiralMatrixPrint(a, R, C);
    
    cout << endl;
    return 0;
}