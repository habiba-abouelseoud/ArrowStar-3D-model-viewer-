//Testing_CodeForCell.cpp
//Copyright © Habibatallah Abuelseoud.
// Created by Habibatallah Abouelseoud 19/12/2021.
// 
// This file contains  the test code for the functionality  
// of the Cell, Tetrahedron, Pyramid and Hexahedron classes



#include "vectors_3D.h"
#include "Cell.h"
#include "Material.h"

int main()
{
	std::cout << "-------------------------------\n" << std::endl;
	std::cout << "The Testing Code for Cell Class\n " << std::endl;
	std::cout << "-------------------------------\n" << std::endl;



	vector_3D vector_1(1, 2, 3);
	vector_3D vector_2(4, 5, 6);
	vector_3D vector_3(7, 8, 9);
	vector_3D vector_4(10, 11, 12);
	vector_3D vector_5(13, 14, 15);
	vector_3D vector_6(16, 17, 18);
	vector_3D vector_7(16, 17, 18);
	vector_3D vector_8(22, 23, 24);
	std::vector<int> RandomOrderVector;
	Material Cooper(0, 8960, "b87373", "copper");





	std::cout << "-------------------------------\n" << std::endl;
	std::cout << "The Testing Code for Tetrahedron Cell \n " << std::endl;
	std::cout << "-------------------------------\n" << std::endl;

	Tetrahedron atetrahedron;
	std::cout << "Testing empty Constructor\n" << atetrahedron << std::endl;

	atetrahedron.Set_V0(vector_1);
	atetrahedron.Set_V1(vector_2);
	atetrahedron.Set_V2(vector_3);
	atetrahedron.Set_V3(vector_4);
	atetrahedron.Set_Cell_Material(Cooper);


	Tetrahedron CopyConstTetrahedron(atetrahedron);
	std::cout << "Testing the Copy constructor\n" << CopyConstTetrahedron << std::endl;

	vector_3D Tetravector_0(0, 2, 1);
	vector_3D Tetravector_1(-1, 1, 1);
	vector_3D Tetravector_2(1, 2, 0);
	vector_3D Tetravector_3(4, 1, 3);

	Material Aluminium(1, 2700, "bcbcbc", "aluminium");

	std::cout << "Testing Set and get functions\n V0 = " << atetrahedron.Get_V0()
		<< "V1 = " << atetrahedron.Get_V1() << "V2 = " << atetrahedron.Get_V2()
		<< "V3 = " << atetrahedron.Get_V3() << "Material " << atetrahedron.Get_Cell_Material() << "\n" << std::endl;


	Tetrahedron _Tetrahedron(Tetravector_0, Tetravector_1, Tetravector_2, Tetravector_3, RandomOrderVector, Aluminium);
	std::cout << "Testing constructor with arguments \n" << _Tetrahedron << std::endl;

	atetrahedron = _Tetrahedron;
	std::cout << "The Operator=\n" << atetrahedron << std::endl;

	std::cout << "The Volume of Tetrahedron Cell\t" << atetrahedron.Get_VolumeOfCellObject() << std::endl;

	std::cout << "The Weight of Tetrahedron Cell\t" << atetrahedron.Get_WeightOfCellObject() << std::endl;

	std::cout << "The Centre of gravity of Tetrahedron Cell\t" << atetrahedron.Get_CentreOfGravity();

	std::cout << "---------------------------------------------------\n" << std::endl;





	std::cout << "-------------------------------\n" << std::endl;
	std::cout << "The Testing Code for Pyramid Cell \n " << std::endl;
	std::cout << "-------------------------------\n" << std::endl;

	Pyramid apyramid;
	std::cout << "Testing empty Constructor\n" << apyramid << std::endl;

	apyramid.Set_V0(vector_1);
	apyramid.Set_V1(vector_2);
	apyramid.Set_V2(vector_3);
	apyramid.Set_V3(vector_4);
	apyramid.Set_V4(vector_5);
	apyramid.Set_Cell_Material(Cooper);


	Pyramid CopyConstPyramid(apyramid);
	std::cout << "Testing the Copy constructor\n" << CopyConstPyramid << std::endl;

	vector_3D Pyramidvector_0(2.5, 6, 2.5);
	vector_3D Pyramidvector_1(0, 0, 5);
	vector_3D Pyramidvector_2(5, 0, 5);
	vector_3D Pyramidvector_3(5, 0, 0);
	vector_3D Pyramidvector_4(0, 0, 0);
	Material Titanium(1, 1500, "64FF15", "Titanium");

	std::cout << "Testing Set and get functions\n V0 = " << apyramid.Get_V0()
		<< "V1 = " << apyramid.Get_V1() << "V2 = " << apyramid.Get_V2()
		<< "V3 = " << apyramid.Get_V3() << "V4 = " << apyramid.Get_V4()
		<< "Material " << apyramid.Get_Cell_Material() << "\n" << std::endl;


	Pyramid _Pyramid(Pyramidvector_0, Pyramidvector_1, Pyramidvector_2, Pyramidvector_3, Pyramidvector_4, RandomOrderVector, Titanium);
	std::cout << "Testing constructor with arguments \n" << _Pyramid << std::endl;

	apyramid = _Pyramid;
	std::cout << "The Operator=\n" << apyramid << std::endl;

	std::cout << "The Volume of Pyramid Cell\t" << apyramid.Get_VolumeOfCellObject() << std::endl;

	std::cout << "The Weight of Pyramid Cell\t" << apyramid.Get_WeightOfCellObject() << std::endl;

	std::cout << "The Centre of gravity of Pyramid Cell\t" << apyramid.Get_CentreOfGravity();

	std::cout << "---------------------------------------------------\n" << std::endl;






	std::cout << "-------------------------------\n" << std::endl;
	std::cout << "The Testing Code for Hexahedron Cell \n " << std::endl;
	std::cout << "-------------------------------\n" << std::endl;

	Hexahedron ahexahedron;
	std::cout << "Testing empty Constructor\n" << ahexahedron << std::endl;

	ahexahedron.Set_V0(vector_1);
	ahexahedron.Set_V1(vector_2);
	ahexahedron.Set_V2(vector_3);
	ahexahedron.Set_V3(vector_4);
	ahexahedron.Set_V4(vector_5);
	ahexahedron.Set_V5(vector_6);
	ahexahedron.Set_V6(vector_7);
	ahexahedron.Set_V7(vector_8);
	ahexahedron.Set_Cell_Material(Cooper);


	Hexahedron CopyConstHexahedron(ahexahedron);
	std::cout << "Testing the Copy constructor\n" << CopyConstHexahedron << std::endl;

	vector_3D Hexahedronvector_0(0, 10, 10);
	vector_3D Hexahedronvector_1(10, 10, 10);
	vector_3D Hexahedronvector_2(10, 10, 0);
	vector_3D Hexahedronvector_3(0, 10, 0);
	vector_3D Hexahedronvector_4(0, 0, 10);
	vector_3D Hexahedronvector_5(10, 0, 10);
	vector_3D Hexahedronvector_6(10, 0, 0);
	vector_3D Hexahedronvector_7(0, 0, 0);
	Material Iron(2, 7310, "EF5690", "Iron");


	std::cout << "Testing Set and get functions\n V0 = " << ahexahedron.Get_V0()
		<< "V1 = " << ahexahedron.Get_V1() << "V2 = " << ahexahedron.Get_V2()
		<< "V3 = " << ahexahedron.Get_V3() << "V4 = " << ahexahedron.Get_V4()
		<< "V5 = " << ahexahedron.Get_V5() << "V6 = " << ahexahedron.Get_V6()
		<< "V7 = " << ahexahedron.Get_V7() << "Material " << ahexahedron.Get_Cell_Material()
		<< "\n" << std::endl;


	Hexahedron _Hexahedron(Hexahedronvector_0, Hexahedronvector_1, Hexahedronvector_2, Hexahedronvector_3, Hexahedronvector_4
		, Hexahedronvector_5, Hexahedronvector_6, Hexahedronvector_7, RandomOrderVector, Iron);
	std::cout << "Testing constructor with arguments \n" << _Hexahedron << std::endl;

	ahexahedron = _Hexahedron;
	std::cout << "The Operator=\n" << ahexahedron << std::endl;

	std::cout << "The Volume of Hexahedron Cell\t" << ahexahedron.Get_VolumeOfCellObject() << std::endl;

	std::cout << "The Weight of Hexahedron Cell\t" << ahexahedron.Get_WeightOfCellObject() << std::endl;

	std::cout << "The Centre of gravity of Hexahedron Cell\t" << ahexahedron.Get_CentreOfGravity();

	std::cout << "---------------------------------------------------\n" << std::endl;
