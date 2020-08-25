#pragma once
#include <SDL.h>

class Three {
public:
    Three(SDL_Renderer* renderer, int startX, int startY, int startLength, int iterations, double scale);

    void draw(double _angle1, double _angle2);
    void changeScale(double value);
    void changeStartLength(int value);
private:

    void m_draw(int x, int y, int length, double angle, SDL_Color color);

    int m_x,m_y,m_length;

    double m_angle1;
    double m_angle2;
    double m_scale;
    SDL_Renderer* m_renderer;
};
