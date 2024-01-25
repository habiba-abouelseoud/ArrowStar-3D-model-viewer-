//Cell.h
//Copyright © Habibatallah Abuelseoud.
//Created by Habibatallah Abouelseoud 19/12/2021.

/**@file
Cell.h
The header file for source file of the Cell , in which the code structure uses the inheritance
as class can be derived from more than one classes, which means it can inherit data and functions
from multiple base classes.this file conatins the defintions  of the Parent class (the class of the Cell)
and the child classes (tetrahedron, hexahedron and pyramid ).
the Cell class has the value of vertices of the cell  as private member
*/

#ifndef Cell_h
#define Cell_h

// The libraries will be used :
#include "vector_3D.h"
#include <vector>
#include "Material.h"

class Cell {
public:
	//Constructor and destructor
	/** @brief Blank constructor
	*/
	Cell(void);

	/** @brief Blank destructor
	*/
	~Cell(void);

	//-------------------------------------------------------------------
	//Custom std::cout function
	/** @brief By using the material and vector class display functions , std::cout function
	 * is able to display the material and vertices of the cell
	 */
	friend std::ostream& operator<< (std::ostream& Output, const Cell& aCell);

	/** @brief Checks by returning true if two cells are equel to each other
	 */
	bool operator==(Cell& aCell);


	//Custom operator function
	Cell& operator= (const Cell& aCell);


	//Set and Get functions 
	
	/** @brief Sets the Vertices of cell
	 */
	void Set_Vertices(const std::vector<vector_3D>& a_vert);

	/** @brief Returns the Vertices of cell
        */
	std::vector<vector_3D> Get_Vertices(void);

	/** @brief Sets the OrderOf_Vectors of cell
	 */
	void Set_OrderOf_Vectors(const std::vector<int>& aOrderOfVectors);

	/** @brief Returns the OrderOf_Vectors of cell
        */
	std::vector<int> Get_OrderOf_Vectors(void);

	/** @brief Sets the Material of cell
	 */
	void Set_Cell_Material(const Material& aCellMaterial);

	/** @brief Returns the Material of cell
	 */
	Material Get_Cell_Material(void);

	//-------------------------------------------------------------------

	// The functions to calculate the Volume , Weight and the centre of 
	//gravity of the cell object 

	virtual double Get_VolumeOfCellObject(void);
	/**@brief the function will be able to do the calculations to get the volume
	 *of the cell object
	 *this function will be coustumised depend on
	 *the properties of the other classses and it will be defined again for every sub-class
	 */

	virtual double Get_CentreOfGravity(void);
	/**@brief
	* this function is able to estimate the centre of gravity
	* The center of gravity is the average location of the weight of an object
	* it can completely describe the motion of any object through space in terms of
	* the translation of the center of gravity of the cell object from one place to another
	* this function will be coustumised depend on
	* the properties of the other classses and it will be defined again
	*/

	virtual double Get_WeightOfCellObject(void);
	/**@brief
	* this function is used to etimate the weight of the cell object and return the 3d vectors
	* this function will be coustumised depend on
	* the properties of the other classses and it will be defined again
	*/

	// the private members inside the class
private:

	std::vector<vector_3D>Vertices;  // member variable that conatins the deatails of the list of vectors as vertices , corners that the cell object contained 
	Material  CellMaterial;  // member variable that contains the material that the cell object made of 
	std::vector<int>& OrderOfVectors;

};




//---------------------------------------------------------------------------------------------------------------------------
// Tetrahedron cell class
//----------------------------------------------------------------------------------------------------------------------------

/**@class Tetrahedron Cell.hpp "Cell.hpp"
* @brief the tetrahedron class is child class that inherted the private members from the cell class (the parent class)
* this class will be able to estimate the volume , centre of gravity and the weight of the tetrahedron cell
*/

class Tetrahedron : public Cell {  // declaring that the tetrahedron class will inhert from the Cell class 

public:
	//Constructors and destructor
	Tetrahedron(void);
	/** @brief
         * Another construnctor function to be declared to contruct the vertices size of tetrahedron which is 4
         * and the order of these vertices and the material of the tetrahedron cell
	 */
	Tetrahedron(const std::vector<vector_3 > & a_vert, const std::vector<int>&aOrderOfVectors, const Material & aCellMaterial);
	~Tetrahedron(void);



    // The functions to calculate the Volume , Weight and the centre of 
   //gravity of the cell object

	virtual double Get_VolumeOfCellObject(void);
	/** @brief this function return the volume of tetrahedron cell
	 * using the scalar product operation from Vector class
	 */
	virtual double Get_CentreOfGravity(void);
	/** @brief this function return the centre of gravity of tetrahedron
         * cell by using centroid formula as that the average of each coordinate is
         * the density
         */

	virtual double Get_WeightOfCellObject(void);
	/** @brief this function return the weight of tetrahedron cell
	*the weight can be determined by the multipication of the
	*volume of pyramid and the density as the tetrahedron cell
	*as tetrahedron is a triangular pyramid with all 4 faces as triangles
	*/


};


//---------------------------------------------------------------------------------------------------------------------------
//Pyramid cell class
//----------------------------------------------------------------------------------------------------------------------------

/** @class Pyramid Cell.hpp "Cell.hpp"
*@brief the Pyramid class is child class that inherted the private members from the cell class (the parent class)
* this class will be able to estimate the volume , centre of gravity and the weight of the Pyramid cell
*/

class Pyramid :public Cell { // declaring that the Pyramid class will inhert from the Cell class
public:
	//Constructors and destructor
	/**@brief
	* Another construnctor function to be declared to contruct the vertices size of Pyramid which is 5
	* and the order of these vertices and the material of the Pyramid cell
	*/
	Pyramid(void);

	Pyramid(const std::vector<vector_3 > & a_vert, const std::vector<int>&aOrderOfVectors, const Material & aCellMaterial);

	/** @brief Standard empty destructor
	 */
	~Pyramid(void);





	// The functions to calculate the Volume , Weight and the centre of 
   //  gravity of the cell object

	virtual double Get_VolumeOfCellObject(void);
	/**@brief this function return the volume of Pyramid cell
	 * using the volume of 2 tetrahedron and adding them togther will return the
	 * volume pf pyramid
	 */

	virtual double Get_CentreOfGravity(void); 
	/**@brief this function return the centre of gravity of  Pyramid
	 * by dividing the pyramid into 2 and it will result 2 tetrahedron
	 * hence the centre of gravity of the 2 tetrahedron can be determined then
	 * the pyramid will have the midpoint of the 2 tetrahedrons as the centre of gravity
	 */

	virtual double Get_WeightOfCellObject(void);  	
	/**@brief this function return the weight of Pyramid cell
         *the weight can be determined by the multipication of the
         * volume of pyramid and the density
         */




};



//---------------------------------------------------------------------------------------------------------------------------
//Hexahedron cell class
//----------------------------------------------------------------------------------------------------------------------------

/** @class Hexahedron Cell.hpp "Cell.hpp"
* @brief the Hexahedron class is child class that inherted the private members from the cell class (the parent class)
* this class will be able to estimate the volume , centre of gravity and the weight of the Hexahedron cell
*/


class Hexahedron :public Cell { // declaring that the Hexahedron class will inhert from the Cell class
public:
	//Constructors and destructor
	Hexahedron(void);

	/**@brief Another construnctor function to be declared to contruct the vertices size of Hexahedron which is 8
	* and the order of these vertices and the material of the hexahedron cell
	*/
	Hexahedron(const std::vector<vector_3 > & a_vert, const std::vector<int>&aOrderOfVectors, const Material & aCellMaterial);


	/** @brief Standard empty destructor
		*/
	~Hexahedron(void);



         // The functions to calculate the Volume , Weight and the centre of
	//  gravity of the cell object
	virtual double Get_VolumeOfCellObject(void);
	/**@brief this function return the volume of hexahedron cell
	* by dividing the hexahedron into 3 pyramids and using the volume of
        *  3 pyramids and adding them togther will return the
	* volume pf hexahedron
	*/

	virtual double Get_CentreOfGravity(void); 
	/**@brief this function return the centre of gravity of  hexahedron
	* by dividing the hexahedron by 3 and it will result 3 pyramids
	* hence the centre of gravity of the 3 pyramids can be determined then
	* the hexahedron will have the midpoint of the 3 pyramids as the centre of gravity
	*/

	virtual double Get_WeightOfCellObject(void);
	/**@brief this function return the weight of Pyramid cell
	* the weight can be determined by the multipication of the
	* volume of hexahedron and the density
	*/



};

#endif 

////////////////////////////////////////////////////////////////////////////////////////////////////////

