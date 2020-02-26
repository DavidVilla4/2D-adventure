#ifndef __COLLISION_H__
#define __COLLISION_H__
#include "gfc_vector.h"
#include "gf2d_shape.h"

int collide_rect(Rect r1, Rect r2);
int collide_level_rect(Rect r1, Rect r2);
int collide_top_bot(Rect r1, Rect r2);
int collide_predict(Rect r1, Rect r2);
int collide_side(Rect r1, Rect r2);
int collide_circle(Vector2D p1, float r1, Vector2D p2, float r2);
#endif