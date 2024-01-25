
//----------------------------------------------------------------------
// Computing Project
// Created by HABIBATALLA ABOUELSEOUD on 28/4/2022.
// Copyright HABIBATALLA ABOUELSEOUD
//-----------------------------------------------------------------------

/** @file This file contains a list of functions  that are connected
 * to the buttons and slots on the modify_light.ui window. 
 * These function on the object
 * that is presentedon MainWindow. 
 * This file is desgined to allow for future updates and addtions.
 * 
 */

#ifndef MODIFY_LIGHT_H
#define MODIFY_LIGHT_H

#include <QMainWindow>

namespace Ui {
	class Modify_Light;
}

/** @class Modify_light modify_light.h "modify_light"
* @ breif 	This class open new window for all the modification of the user models  
*               requirments as the class has spceifc features to  edit the light applied on model 
*/

class Modify_Light : public QMainWindow
{
	Q_OBJECT

public:
    /** @brief Blank construtor
     */
	explicit Modify_Light(QWidget* parent = nullptr);
	~Modify_Light();
    /** @brief This function enables the rendering process fron a second window
     */
	void Open_Dialog(vtkSmartPointer<vtkGenericOpenGLRenderWindow>& PassedWindow);

private slots:

	/** @brief  this allow the the light of x-axis to be changed on  focussing point
	 */
	void on_X_Axis_Focussing_valueChanged(int arg1);

	/** @briefthis allow the the light of 	Y-axis to be changed on  focussing point
	 */
	void on_Y_Axis_Focussing_valueChanged(int arg1);
	/** @brief  allow the the light of 	Z-axis to be changed on  focussing point
	 */
	void on_Z_Axis_Focussing_valueChanged(int arg1);

	/** @brief allow the the light of X-axis to be changed on  origin point
	 */
	void on_X_Axis_Origin_valueChanged(int arg1);
	/** @briefallow the the light of Y-axis to be changed on  origin point
	 */
	 
	void on_Y_Axis_Origin_valueChanged(int arg1);
	/** @briefthe the light of Z-axis to be changed on  origin point
	 */
	void on_Z_Axis_Origin_valueChanged(int arg1);

	/** @brief toggle button switch on or off
	 */
	void on_Light_ON_OFF_toggled(bool checked);
	/** @brief This function allow the moficication of light along cone angle
          */
	void on_Apex_angle_Light_slider_valueChanged(int value);
	/** @brief This function if allowing user to state the intensitiy of light by sliding the bar
	 */
	void on_Intensity_Of_Light_slider_valueChanged(int value);
	/** @brief This function all the specular colour light to be applied  on light 
	 */
	void on_Specular_colour_released();
	/** @brief  This function all the Diffuse colour light to be applied  on light 
	 */
	void on_Diffuse_colour_released();
	/** @brief  This function all the Ambient colour light to be applied  on light 
	 */
	void on_Ambient_colour_released();

private:
	Ui::Modify_Light* ui; ///<@brief User interface
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New(); ///< @brief 

};

#endif // MODIFY_LIGHT_H
