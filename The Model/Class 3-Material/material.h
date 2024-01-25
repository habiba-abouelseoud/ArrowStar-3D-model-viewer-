// Copyright Edwin Cockeye-Brown 
// Material.h
// This file defines the material class itself as well as its required member
// variables and/or functions. This is part os a series of interlinked classes, 
// however, this class specificallly defines a material, which must hold the 
// following properties:  ID, Name, Colour and Density.

#ifndef MATERIAL_H
#define MATERIAL_H

class material;

class material {
public:


    //Accessor functions
    void setID_no(int ID_no);
    void setColour(char &colour);
    void setName(char &name);
    void setDensity(float density);

    int getID_no() const;
    char getColour() const;
    char getName() const;
    float getDensity() const;

private:
    //Member Variables
    int ID_no;
    char colour[30];
    char name[50];
    float density;

};