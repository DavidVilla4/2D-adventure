#include "gfc_vector.h"
#include "gf2d_shape.h"
#include "simple_logger.h"

int collide_circle(Vector2D p1, float r1, Vector2D p2, float r2)
{
	if (vector2d_magnitude_squared(vector2d(p2.x - p1.x, p2.y - p1.y)) < ((r2 + r1)*(r2 + r1)))
	{
		return 1;
	}
	return 0;
}


int collide_rect(Shape *r1, Shape *r2)
{
	Shape a= *r1;
	Shape b = *r2;
	if (((a.x + a.w) < b.x) ||
		((b.x + b.w) < a.x) ||
		((a.y + a.h) < b.y) ||
		((b.y + b.h) < a.y))
	{
		
		return 0;
	}
	return 1;
}