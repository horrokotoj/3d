#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y, z;
} v3;

typedef struct {
    float x1, x2, x3, y1, y2, y3, z1, z2, z3;
} m3;

void clear(uint32_t *buffer, uint32_t colour)
{
    size_t n = 320*200;
    for(int i = 0; i < n; i++)
    {
        buffer[i] = colour;
    }
}

void pixel(uint32_t *buffer, int x, int y, uint32_t colour)
{
    buffer[y*320 + x] = colour;
}

float randf()
{
    return (float)rand()/(float)(RAND_MAX);
}

m3 matrix_multi_three(m3 a, m3 b)
{
    m3 c;
    c.x1 = a.x1*b.x1 + a.x2*b.y1 + a.x3*b.z1;
    c.x2 = a.x1*b.x2 + a.x2*b.y2 + a.x3*b.z2;
    c.x3 = a.x1*b.x3 + a.x2*b.y3 + a.x3*b.z3;
    c.y1 = a.y1*b.x1 + a.y2*b.y1 + a.y3*b.z1;
    c.y2 = a.y1*b.x2 + a.y2*b.y2 + a.y3*b.z2;
    c.y3 = a.y1*b.x3 + a.y2*b.y3 + a.y3*b.z3;
    c.z1 = a.z1*b.x1 + a.z2*b.y1 + a.z3*b.z1;
    c.z2 = a.z1*b.x2 + a.z2*b.y2 + a.z3*b.z2;
    c.z3 = a.z1*b.x3 + a.z2*b.y3 + a.z3*b.z3;
    return c;
}

v3 transformation_three(m3 a, v3 b)
{
    v3 c;
    c.x = a.x1*b.x + a.x2*b.y + a.x3*b.z;
    c.y = a.y1*b.x + a.y2*b.y + a.y3*b.z;
    c.z = a.z1*b.x + a.z2*b.y + a.z3*b.z;
    return c;
}

int main()
{
    uint32_t buffer[320*200];
    v3 points[50];
    for (int i = 0; i < 50; i++)
    {
        points[i].x = randf() - 0.5;
        points[i].y = randf() - 0.5;
        points[i].z = randf() - 0.5;

    }
    for(size_t frame = 0; ; frame++)
    {
        clear(buffer, 0xffdceaf5);
        for (int i = 0; i < 50; i++)
        {
            int x = (int) (points[i].x*50 + 320/2);
            int y = (int) (points[i].y*50 + 200/2);
            pixel(buffer, x, y, 0xff005e5a);
        }
        
        
        fwrite(buffer, sizeof(buffer), 1, stdout);
    }

    return 0;
}