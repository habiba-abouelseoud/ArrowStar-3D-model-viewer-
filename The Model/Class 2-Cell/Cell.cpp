//Cell.cpp
//Copyright © Habibatallah Abuelseoud.
// Created by Habibatallah Abouelseoud 19/12/2021.
// updated by Habibatallah Abouelseoud 5/3/2022
// This file contains  the objects and  member functions definations 
// for the Cell, Tetrahedron, Pyramid and Hexahedron classes

#include "Cell.h"
#include <cmath>
#include "vectors_3D.h"
#include "Matrix.h"
#include "Material.h"



//-------------------------------------------------------------------------
// Member functions of the Cell
//-------------------------------------------------------------------------

//Constructor and  Destructor#
Cell::Cell(void) { }
Cell::~Cell(void) { }

//--------------------------------------------------------------------------

//Custom std::cout function
std::ostream& operator<< (std::ostream& Output, const Cell& aCell)
{
	for (unsigned int i = 0; i < aCell.Vertices.size(); i++)
	{
		Output << "" << i << " " << aCell.Vertices[i];
	}

	Output << " " << aCell.Material;

	return Output;
}





//the Custom operator function
Cell& Cell::operator = (const Cell& aCell)
{
	if (&aCell == this)
		return *this;

	else
	{
		Vertices = aCell.Vertices;
		OrderOfVectors = aCell.OrderOfVectors;
		CellMaterial = aCell.CellMaterial;

		return *this;
	}
}




bool Cell::operator == (Cell& aCell)
{
	if (Material == aCell.Get_Material())
	{
		if (Vertices.size() == aCell.Get_Vertices().size())
		{
			if (OrderOfVectors.size() == aCell.Get_OrderOfVectors().size())
			{
				for (unsigned int i = 0; i < Vertices.size(); i++)
				{
					if (Vertices[i] == aCell.Get_Vertices()[i])
					{
					}
					else
						return false;
				}
				for (unsigned int i = 0; i < OrderOfVectors.size(); i++)
				{
					if (OrderOfVectors[i] == aCell.Get_OrderOfVectors()[i])
					{
					}
					else
						return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
	return true;
}


//Set and get  functions
void Cell::Set_Vertices(const std::vector<vector_3D>& aVertices) { Vertices = aVertices; }
std::vector<vector_3D> Cell::Get_Vertices(void) { return Vertices; }

void Cell::Set_OrderOf_Vectors(const std::vector<int>& aOrderOf_Vectors) { OrderOf_Vectors = aOrderOf_Vectors; }
std::vector<int> Cell::Get_OrderOf_Vectors(void) { return OrderOf_Vectors; }

void Cell::Set_Material(const Material& aMaterial) { Material = aMaterial; }
Material Cell::Get_Material(void) { return Material; }






//-------------------------------------------------------------------
// The functions to calculate the Volume , Weight and the centre of 
//gravity of the cell object 
double Cell::Get_VolumeOfCellObject(void)
{
	std::cout << "Error, The data for the volume of the cell object isn't availbe  " << std::endl;

	return -1; // the -1 means it will return error

	double Cell::Get_CentreOfGravity(void)
	{
		std::cout << "Error, The data for the centre of the gravity of the cell object isn't availbe" << std::endl;


		return -1;
	}

	double Cell::Get_WeightOfCellObject(void)
	{
		std::cout << "Error, The data for the weight of the cell object isn't availbe" << std::endl;

		return -1;
	}

	void Cell::cell_Reneder(double in_degrees_render, char render_axis, vectors_3D rotation_centre)
	{



	}


	//-----------------------------------------------------//
		///THE BELOW CODE NOT UPDATED YET//
	//-----------------------------------------------------//	

	//---------------------------------------------------------------------------------------------------------------------------
	// Terahedron cell class
	//----------------------------------------------------------------------------------------------------------------------------

	//Constructors 
	Tetrahedron::Tetrahedron(void)
	{

		std::vector<vector_3D> temporary_vert;
		vector_3D temporary_vect;
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);

		Set_Vertices(temporary_vert);
	}

	Tetrahedron::Tetrahedron(const std::vector<vector_3 > & a_vert, const std::vector<int>&aOrderOfVectors, const Material & aCellMaterial)
	{


		Set_Vertices(aVertices);
		Set_OrderOf_Vectors(aOrderOf_Vectors);
		Set_CellMaterial(aCellMaterial);

	}

	/*
	Tetrahedron::Tetrahedron(const Tetrahedron & aTetrahedron)
	{
		V0 = aTetrahedron.V0;
		V1 = aTetrahedron.V1;
		V2 = aTetrahedron.V2;
		V3 = aTetrahedron.V3;
		OrderOfVectors = aTetrahedron.aOrderOfVectors;
		CellMaterial = aTetrahedron.aCellMaterial;
	}
	*/
	// destructor
	Tetrahedron::~Tetrahedron(void) { }


	


	// The functions to calculate the Volume , Weight and the centre of 
	//gravity of the cell object

	double Tetrahedron::Get_VolumeOfCellObject(void)
	{

		// The volume of the cell of tetrahedron will be calculated 
		//A tetrahedron is 16 of the volume of the parallelipiped formed by
		//x,y ,z. The volume of the parallelepiped is the scalar triple 
		//product |x.(y*z)|. Thus, the volume of a tetrahedron is V=1/6|x.(y*z)|
		std::vector<vector_3D>temporary_vert = Get_Vertices();
		Vectors x =  temporary_vert[3] - temporary_vert[0];   //Vertex 3 - Vertex 0
		Vectors y =  temporary_vert[2] - temporary_vert[0];  //Vertex 2 - Vertex 0;
		Vectors z =  temporary_vert[1] - temporary_vert[0]; //Vertex 1 - Vertex 0;

		return((1 / 6) * abs(x.ScalarProduct(y * z)));


	}

	double Tetrahedron::Get_WeightOfCellObject(void)
	{

		return (MaterialOfCellObject.get_DensityOfCellObject() * get_VolumeOfCellObject);
	}

	double Tetrahedron::Get_CentreOfGravity(void)
	{
		//getting the average of every coordinate for calculating the centre of gravity of the cell 


		vector_3D centre_of_gravity;

		centre_of_gravity.set_x_coordinate((temporary_vert[0].get_x_coordinate() + temporary_vert[1].get_x_coordinate() + temporary_vert[2].get_x_coordinate() + temporary_vert[3].get_x_coordinate()) / 4);
		centre_of_gravity.set_y_coordinate((temporary_vert[0].get_y_coordinate() + temporary_vert[1].get_y_coordinate() + temporary_vert[2].get_y_coordinate() + temporary_vert[3].get_y_coordinate()) / 4);
		centre_of_gravity.set_z_coordinate((temporary_vert[0].get_z_coordinate() + temporary_vert[1].get_z_coordinate() + temporary_vert[2].get_z_coordinate() + temporary_vert[3].get_z_coordinate()) / 4);
		return  centre_of_gravity;


	}


	//---------------------------------------------------------------------------------------------------------------------------
	//Pyramid cell class
	//----------------------------------------------------------------------------------------------------------------------------

	//Constructors 
	Pyramid::Pyramid(void) 
	{
		std::vector<vector_3D> temporary_vert;
		vector_3D temporary_vect;
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		Set_Vertices(temporary_vert);
	}

	Pyramid::Pyramid(const std::vector<vector_3 >& a_vert, const std::vector<int>& aOrderOfVectors, const Material& aCellMaterial)
	{

		Set_Vertices(aVertices);
		Set_OrderOf_Vectors(aOrderOf_Vectors);
		Set_CellMaterial(aCellMaterial);
	}

	

	// destructor
	Pyramid::~Pyramid(void) { }






	// The functions to calculate the Volume , Weight and the centre of 
	//  gravity of the cell object

	double Pyramid::Get_VolumeOfCellObject(void)
	{
		// the volume of the pyramid can be calculate using using the volume of tetrahedron cell 
		// as the volume of pyramid cell equel to the volume of two tetrahedron cell hence 
		// by getting the volume of 2 tetrahedron and adding together will be equel to 
		// the volume of the pyramid cell 

		std::vector<vector_3D>temporary_vert = Get_Vertices();
		std::vector<vector_3D>firstTetrahedron;

		firstTetrahedron.push_back(temporary_vert[3]);
		firstTetrahedron.push_back(temporary_vert[4]);
		firstTetrahedron.push_back(temporary_vert[2]);
		firstTetrahedron.push_back(temporary_vert[0]);

		std::vector<vector_3D>secondTetrahedron;

		secondTetrahedron.push_back(temporary_vert[1]);
		secondTetrahedron.push_back(temporary_vert[2]);
		secondTetrahedron.push_back(temporary_vert[4]);
		secondTetrahedron.push_back(temporary_vert[0]);
	

		Tetrahedron first(firstTetrahedron, Get_OrderOfVectors(), Get_CellMaterial());
		Tetrahedron second(secondTetrahedron, Get_OrderOfVectors(),Get_CellMaterial());

		return first.Get_VolumeOfCellObject() + second.Get_VolumeOfCellObject();

	}

	double Pyramid::Get_WeightOfCellObject(void)
	{
		return	(MaterialOfCellObject.Get_DensityOfCellObject() * Get_VolumeOfCellObject);
	}


	double Pyramid::Get_CentreOfGravity(void)
	{
		// the centre of gravity of pyramid cell is equel to the cenra of gravity of eachof the 2 tetrahedron cell 
		// which means by creating 2 tetrahedron that has equel volume and weight will have same centre of gravity hence 
		// the middle of the 2 centre of gravity of tetrahedrons will be the centre of gravity of the pyramid


		std::vector<vector_3D>temporary_vert = Get_Vertices();
		std::vector<vector_3D>firstTetrahedron;

		firstTetrahedron.push_back(temporary_vert[3]);
		firstTetrahedron.push_back(temporary_vert[4]);
		firstTetrahedron.push_back(temporary_vert[2]);
		firstTetrahedron.push_back(temporary_vert[0]);

		std::vector<vector_3D>secondTetrahedron;

		secondTetrahedron.push_back(temporary_vert[1]);
		secondTetrahedron.push_back(temporary_vert[2]);
		secondTetrahedron.push_back(temporary_vert[4]);
		secondTetrahedron.push_back(temporary_vert[0]);


		Tetrahedron first(firstTetrahedron, Get_OrderOfVectors(), Get_CellMaterial());
		Tetrahedron second(secondTetrahedron, Get_OrderOfVectors(), Get_CellMaterial());



	
		vector_3D firstTetrahedron_centre_of_gravity = firstTetrahedron.Get_CentreOfGravity();
		vector_3D secondTetrahedron_centre_of_gravity = secondTetrahedron.Get_CentreOfGravity();

		double Total_dist = firstTetrahedron_centre_of_gravity.Get_Distance_To(secondTetrahedron_centre_of_gravity);
		double i_distance = Total_dist / (first.Get_WeightOfCellObject() / second.Get_WeightOfCellObject() + 1.0);

		Vectors aTob = secondTetrahedron_centre_of_gravity - firstTetrahedron_centre_of_gravity;
		Vectors newCOG = firstTetrahedron_centre_of_gravity + (aTob * (i_distance / Total_dist));

		return newCOG;

		

	}


	//---------------------------------------------------------------------------------------------------------------------------
	//Hexahedron cell class
	//----------------------------------------------------------------------------------------------------------------------------



	//Constructors 
	Hexahedron::Hexahedron(void)
	{
		std::vector<vector_3D> temporary_vert;
		vector_3D temporary_vect;
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		temporary_vert.push_back(temporary_vect);
		Set_Vertices(temporary_vert);
	}

	Hexahedron::Hexahedron(const std::vector<vector_3 >& a_vert, const std::vector<int>& aOrderOfVectors, const Material& aCellMaterial)

		Set_Vertices(aVertices);
		Set_OrderOf_Vectors(aOrderOf_Vectors);
		Set_CellMaterial(aCellMaterial);

	}


	// destructor
	Hexahedron::~Hexahedron(void) {}



	





	// The functions to calculate the Volume , Weight and the centre of 
	//gravity of the cell object

	double Hexahedron::Get_VolumeOfCellObject(void)
	{
		// the volume of hexahedron is equel to the volume of 3 pyramids hence by 
		// finding volume of 3 pyramids and adding them togther the volume of hexahedron 
		// will be determined 


		std::vector<vector_3D>temporary_vert = Get_Vertices();
		std::vector<vector_3D>firstPyramid;

		firstPyramid.push_back(temporary_vert[3]);
		firstPyramid.push_back(temporary_vert[0]);
		firstPyramid.push_back(temporary_vert[1]);
		firstPyramid.push_back(temporary_vert[2]);
		firstPyramid.push_back(temporary_vert[5]);

		std::vector<vector_3D>secondPyramid;

		secondPyramid.push_back(temporary_vert[3]);
		secondPyramid.push_back(temporary_vert[0]);
		secondPyramid.push_back(temporary_vert[4]);
		secondPyramid.push_back(temporary_vert[7]);
		secondPyramid.push_back(temporary_vert[5]);


		std::vector<vector_3D> thirdPyramid;

		thirdPyramid.push_back(temporary_vert[3]);
		thirdPyramid.push_back(temporary_vert[2]);
		thirdPyramid.push_back(temporary_vert[6]);
		thirdPyramid.push_back(temporary_vert[7]);
		thirdPyramid.push_back(temporary_vert[5]);



		Pyramid first(firstPyramid, Get_OrderOfVectors(), Get_CellMaterial());
		Pyramid second(secondPyramid, Get_OrderOfVectors(), Get_CellMaterial());
		Pyramid third(thirdPyramid, Get_OrderOfVectors(), Get_CellMaterial());

		return first.Get_VolumeOfCellObject() + second.Get_VolumeOfCellObject() + third.Get_VolumeOfCellObject();


	}

	double Hexahedron::Get_WeightOfCellObject(void)
	{
		return	(MaterialOfCellObject().Get_DensityOfCellObject() * Get_VolumeOfCellObject);

	}


	double Hexahedron::Get_CentreOfGravity(void)
	{
		// the centre of gravity of Hexahedron cell is equel to the centra of gravity of each of the 3 pyramids cell 
		// which means by creating 3 pyramids that has equel volume and weight will have same centre of gravity hence 
		// the middle of the 3 centre of gravities of pyramids will be the centre of gravity of the hexahedron


		Pyramid firstPyramid(V3, V0, V1, V2, V5, OrderOfVectors, CellMaterial);
		Pyramid secondPyramid(V3, V0, V4, V7, V5, OrderOfVectors, CellMaterial);
		Pyramid thirdPyramid(V3, V2, V6, V7, V5, OrderOfVectors, CellMaterial);

		vector_3D  centre_of_gravity = ((firstPyramid.Get_CentreOfGravity + secondPyramid.Get_CentreOfGravity + thirdPyramid.Get_CentreOfGravity) / 3);
		return centre_of_gravity;





		std::vector<vector_3D>temporary_vert = Get_Vertices();
		std::vector<vector_3D>firstPyramid;

		firstPyramid.push_back(temporary_vert[3]);
		firstPyramid.push_back(temporary_vert[0]);
		firstPyramid.push_back(temporary_vert[1]);
		firstPyramid.push_back(temporary_vert[2]);
		firstPyramid.push_back(temporary_vert[5]);

		std::vector<vector_3D>secondPyramid;

		secondPyramid.push_back(temporary_vert[3]);
		secondPyramid.push_back(temporary_vert[0]);
		secondPyramid.push_back(temporary_vert[4]);
		secondPyramid.push_back(temporary_vert[7]);
		secondPyramid.push_back(temporary_vert[5]);


		std::vector<vector_3D> thirdPyramid;

		thirdPyramid.push_back(temporary_vert[3]);
		thirdPyramid.push_back(temporary_vert[2]);
		thirdPyramid.push_back(temporary_vert[6]);
		thirdPyramid.push_back(temporary_vert[7]);
		thirdPyramid.push_back(temporary_vert[5]);



		Pyramid first(firstPyramid, Get_OrderOfVectors(), Get_CellMaterial());
		Pyramid second(secondPyramid, Get_OrderOfVectors(), Get_CellMaterial());
		Pyramid third(thirdPyramid, Get_OrderOfVectors(), Get_CellMaterial());




		vector_3D firstPyramid_centre_of_gravity = firstPyramid.Get_CentreOfGravity();
		vector_3D secondPyramid_centre_of_gravity = secondPyramid.Get_CentreOfGravity();
		vector_3D thirdPyramid_centre_of_gravity = thirdPyramid.Get_CentreOfGravity();

		double Total_dist = firstPyramid_centre_of_gravity.Get_Distance_To(secondPyramid_centre_of_gravity);

		double i_distance = Total_dist / (firstPyramid_centre_of_gravity.Get_WeightOfCellObject() + secondPyramid_centre_of_gravity.Get_WeightOfCellObject() /secondPyramid_centre_of_gravity.Get_WeightOfCellObject() );

		Vector_3D aTob = secondPyramid_centre_of_gravity - firstPyramid_centre_of_gravity;
		Vector_3D newCOG = firstPyramid_centre_of_gravity + (aTob * (i_distance / Total_dist));



		Total_dist = newCOG.Get_Distance_To(thirdPyramid_centre_of_gravity);
		double Sum = (firstPyramid_centre_of_gravity.Get_WeightOfCellObject() + secondPyramid_centre_of_gravity.Get_WeightOfCellObject());
		i_distance = Total_dist / ((Sum / thirdPyramid_centre_of_gravity.Get_WeightOfCellObject()) + 1.0);
		vector_3D newCOGToc = thirdPyramid_centre_of_gravity - newCOG;
		newCOG = newCOG + (newCOGToc * (i_distance / Total_dist));

		return newCOG;


	}
