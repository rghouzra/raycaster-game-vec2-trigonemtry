#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdlib.h>
# define ADD 0
# define SUB 1
# define MUL 2
# define DIV 3

typedef struct s_cord{
	double x;
	double y;
}t_cord;

typedef struct s_vec2{
	t_cord cord;
}t_vec2;
t_vec2 normalize_vector(t_vec2 vector, size_t length);
size_t veclength(t_vec2 vector);
t_vec2 scaleVec(t_vec2 vector, double scale);
t_vec2 op_two_vectors(t_vec2 vec1 , t_vec2 vec2, uint16_t op);
t_vec2 rotate_vec(t_vec2 vec, double angle);
#endif