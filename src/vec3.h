typedef struct Vec3 Vec3;

struct Vec3 {
    double x;
    double y;
    double z;
};

/** Adds the given vectors and returns a newly allocated vector **/
Vec3 add(Vec3 a, Vec3 b);

/** Subtracts the first vector from the second and returns a newly allocated vector **/
Vec3 subtract(Vec3 a, Vec3 b);

/** Multiplies the given vectors component-wise and returns a newly allocated result vector **/
Vec3 multiply(Vec3 a, Vec3 b);

/** Multplies the given vector with the scalar value **/
Vec3 multiply(double scalar, Vec3 v);

/** Multplies the given vector with the scalar value **/
Vec3 multiply(Vec3 v, double scalar);

/** Divides the given vector by the scalar value **/
Vec3 divide(Vec3 v, double scalar);

/** Calculates the dot product **/
double dot_product(Vec3 vec_a, Vec3 vec_b);

/** Calculates the cross product between the two provided vectors **/
Vec3 cross_product(Vec3 a, Vec3 b);

/** Returns the length of the vector **/
double length(Vec3 v);

/** Returns the squared length of the vector **/
double squared_length(Vec3 v);

/** Returns a normalized copy of the provided vector **/
Vec3 normalize(Vec3 v);

/** Prints the vector **/
void print_vec(Vec3);

/** If vector a is smaller than vector b **/
bool less_then(Vec3 a, Vec3 b);

/** If vector a equals vector b **/
bool equals(Vec3 a, Vec3 b);

/** Clamps the vector between 0 and 1 **/
void clamp(Vec3 v);
