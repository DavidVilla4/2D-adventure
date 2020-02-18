#ifndef __COLLISION_H__
#define __COLLISION_H__
#include "gfc_vector.h"
#include "gf2d_shape.h"

int collide_rect(Shape r1, Shape r2);
int collide_circle(Vector2D p1, float r1, Vector2D p2, float r2);
#endif