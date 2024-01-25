#include <iostream>
#include <limits> //std::numeric_limits

//prototyping class

class vector_3D;


using namespace std;

/**
 * @brief The vector_3D class
 * This class performs vector oprtations of addition, subtraction, dot product and cross product
 */
class vector_3D
{
    private:
        /**
         * @brief x_coord
         */
        double x_coord;

        /**
         * @brief y_coord
         */
        double y_coord;

        /**
         * @brief z_coord
         */
        double z_coord;

    public:
        //constructor
        /**
         * @brief vector_3D
         * This function is a constructor
         */
        vector_3D();

        /**
         * @brief ~vector_3D
         * This function is a destructor
         */
        ~vector_3D();

        //mutators (setters)
        /**
         * @brief set_x_coord
         * @param x_coord is a double that is used to store the x coord
         */
        void set_x_coord(double x_coord);

        /**
         * @brief set_y_coord
         * @param y_coord is a double that is used to store the y coord
         */
        void set_y_coord(double y_coord);

        /**
         * @brief set_z_coord
         * @param z_coord is a double that is used to store the z coord
         */
        void set_z_coord(double z_coord);


        //accessors (getters)
        /**
         * @brief get_x_coord
         * This functiom finds the x coord
         * @return returns x coord
         */
        double get_x_coord();

        /**
         * @brief get_y_coord
         * This functiom finds the y coord
         * @return returns y coord
         */
        double get_y_coord();

        /**
         * @brief get_z_coord
         * This functiom finds the z coord
         * @return returns z coord
         */
        double get_z_coord();

        //functions to perform basic vector operations
        /**
         * @brief vector_addition
         * @param second is a vector to add
         * @return returns the sun of two vectors
         */
        vector_3D vector_addition(vector_3D second);

        /**
         * @brief vector_subtraction
         * @param second is a vector to subtract to
         * @return returns the difference of two vectors
         */
        vector_3D vector_subtraction(vector_3D second);

        /**
         * @brief dot_product
         * @param second is a vector to dot with
         * @return returns the dot product of two vectors
         */
        double dot_product(vector_3D second);

        /**
         * @brief cross_product
         * @param second is a vector to cross with
         * @return returns the cross product of two vectors
         */
        vector_3D cross_product(vector_3D second);

};
