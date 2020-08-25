#include "Three.h"
#include <math.h>

Three::Three(SDL_Renderer* renderer, int startX, int startY, int startLength, int iterations, double scale)
    : m_renderer(renderer), m_angle1(0), m_angle2(0), m_length(startLength), m_y(startY), m_x(startX),
    m_scale(scale)
{

}

void Three::draw(double _angle1, double _angle2) {
    m_angle1 = _angle1;
    m_angle2 = _angle2;
    m_draw(m_x, m_y, m_length, m_angle1, {255,255,255,255});
    m_draw(m_x, m_y, m_length, m_angle2, {255,255,255,255});
}

void Three::m_draw(int x, int y, int length, double angle, SDL_Color color) {
    int x2 = x,y2 = y;

    x2 += sin(angle)*length;
    y2 += -cos(angle)*length;

    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(m_renderer, x, y, x2, y2);

    if(abs(x2-x) <= 1 && abs(y2-y) <= 1)
        return;

    SDL_Color c1 = color;
    SDL_Color c2 = color;

    double scale = 9.0/10.0;

    c1.r *= scale;
    c1.g *= scale;
    c2.b *= scale;
    c2.g *= scale;


    m_draw(x2, y2, length*m_scale, angle + m_angle1, c1);
    m_draw(x2, y2, length*m_scale, angle + m_angle2, c2);
}

void Three::changeScale(double value) {
    m_scale += value;
}

void Three::changeStartLength(int value) {
    m_length += value;
    if(m_length < 10)
        m_length = 10;
}
