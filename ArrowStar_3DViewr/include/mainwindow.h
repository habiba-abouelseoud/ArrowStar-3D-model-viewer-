
//----------------------------------------------------------------------
// Computing Project
// Created by HABIBATALLA ABOUELSEOUD on 28/4/2022.
// Copyright HABIBATALLA ABOUELSEOUD
//-----------------------------------------------------------------------

/** @file This file contains all the function for mainwindow design requied for compiling the software
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStatusBar>
#include <QMainWindow>
#include <QColorDialog>
#include <QDebug>           
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QComboBox>



#include <array>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <vtkNamedColors.h>
#include <vtkAxesActor.h>
#include <vtkUnstructuredGrid.h>
#include <vtkCubeAxesActor.h>
#include <vtkDelaunay2D.h>
#include <vtkDistanceRepresentation.h>
#include <vtkDistanceWidget.h>
#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkSTLReader.h>
#include <vtkPlane.h>
#include <vtkSmartPointer.h>
#include <vtkShrinkFilter.h>
#include <vtkClipPolyData.h>
#include <vtkPolyData.h>
#include <vtkClipDataSet.h>
#include <vtkCubeSource.h>
#include <vtkSphereSource.h>
#include <vtkAlgorithm.h>
#include <vtkCylinderSource.h>
#include <vtkColor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkPoints.h>
#include <vtkDelaunay2D.h>
#include <vtkDistanceRepresentation.h>
#include <vtkDistanceWidget.h>
#include <vtkSTLWriter.h>
#include <vtkLight.h>
#include <vtkSmartPointer.h>
#include <vtkTetra.h>
#include <vtkHexahedron.h>
#include <vtkPyramid.h>
#include <vtkPentagonalPrism.h>
#include <vtkPolyhedron.h>
#include <vtkConeSource.h>
#include <vtkCylinderSource.h>

// the other window library but it is commented as it has errors
//#include "modify_light.h"  


// library classes from semster1 project but it is commented as it 
// is not updated only cell.h is the updated class

/*
#include "The_Model_Class.h"
#include "vectorClass.h"
#include "Cell.h"
#include <cmath>
#include "vectors_3D.h"
#include "Matrix.h"
#include "Material.h"
*/






namespace Ui {
	class MainWindow;
}

/** @class MainWindow MainWindow.h "mainwindow.h"
 *  @brief This is the main window that all the loaded models will be displayed at and it contains the design 
 *  of the software features
 */

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    /** @brief Blank constructor (empty)
     */
	explicit MainWindow(QWidget* parent = 0);
	/** @brief Blank destructor (empty)
         */
	~MainWindow();


private slots:
        /** @brief An open icon located in task bar and loads the STL files
	*/
	void handleOpenButton();
	void handleSaveButton();
	void handleHelpButton();
	void handlePrintButton();
	
	 /** @brief This function is for changing the colour of the Model using QColoDialog
	 */
	void on_Change_Object_Color_released();
	
       /** @brief This toggle button is for applying Shrink Filter on the loaded model when
         * the toggle button is checked by the user .
	 * in which shrink filter means Shrinks cells composing an arbitrary data set towards their centroid. The centroid of a 
	 * cell is computed as the average position of the cell points. Shrinking results in disconnecting 
	 * the cells from one another
	 */
	void on_Shrink_Filter_toggled(bool Shrink_Filter_Status);
	
	/** @brief This toggle button is for applying Clip Filter on the loaded model when
         * the toggle button is checked by the user .
	 * in which Clip filter means Clipping means that it actually "cuts" through the cells of 
	 * the dataset, returning everything inside of the specified implicit function 
	 * including "pieces" of a cell. The output
	 * 
	 */
	void on_Clipper_Filter_toggled(bool Clipper_Filter_Status);
	
	/** @brief This cube function cube button in which when the button is clicked 
	  * a cube is displayed on the window it uses VtkcubeSource.h
	  */
	void on_cube_released();
	
	/** @brief This sphere function sphere button in which when the button is clicked 
	  * a sphere is displayed on the window it uses VtksphereSource.h
	  */
	void on_sphere_released();
	
	/** @brief This function view the measurments of the model as length,width and hight
	  */
	void on_Axes_PushButton_released();
	
	/** @brief This Function delete the axis applied on the model to view measurments
	  */
	void on_delete_Axes_PushButton_released();
	/** @brief This function view a ruler to measure the model on main window to the user when the button is clicked 
	*/
	void on_Ruler_PushButton_released();
	/** @brief This Function  delete the ruler when the button is clicked 
	*/
	void on_Delete_Ruler_PushButton_released();
	/** @brief This Function view a cube on main window when the button is clicked 
	*/
	void on_cone_released();
        /** @brief This Function opens QDiolog and allow the user to change the background color of the window
	*/
         void on_Change_Back_Ground_Color_released();

	////////////////////////////////////////////////////////////////////////////////////////////
	// NOTE::THE FUNCTIONS  BELOW  are commented as they have few errors but an attempt for code is made
	 //////////////////////////////////////////////////////////////////////////////////////////
	 // /** @brief This function enable the user to change light name 
	      */
	//  void on_Light_Box_editTextChanged(const QString& text);
	
	    /** @brief This function enable the user to add light on the model loaded using combo box
	      */
	// void on_Apply_Light_released();
	/** @brief This function open another window to let the user edit the light using other detailed features for c
	*   applying the change 
	*/ 
	//void on_Modify_Light_clicked();
	/** @brief This function reset the model from the light applied on it
	*/
	// void on_Remove_Light_released();
	/** @brief  This Function is not implemented
	*/
	 // void on_Change_Back_FaceColor_released();
	 /** @brief This function return the model to its original color befre modifing 
	*/
	 //void on_Reset_Color_released();
	 /** @brief This function to list the weight,volume and density of a model
	*/
	 //  void on_View_Statistics_of_Model_released();
	 /////////////////////////////////////////


	 ///-----------------------------------------------------------------
	  /// Camera for Model & Modify position Groupbox
	 /// ----------------------------------------------------------------
	 /** @brief This function is to allow the user to change the model position along the x-axis
	*/
	void on_X_Plane_Position_valueChanged(int value);
	/** @briefThis function is to allow the user to change the model position along the y-axis
	*/

	void on_Y_Plane_Position_valueChanged(int value);
	/** @briefThis function is to allow the user to change the model position along the z-axis
	*/

	void on_Z_Plane_Position_valueChanged(int value);
	/** @brief This function allow the user to shift the model in a vertical direction 
	* and shift the camera with it origion point
	*/

	void on_Shift_vertically_valueChanged(int arg1);
	/** @brief  This function allow the user to shift the model in a horizontally direction 
	* and shift the camera with it origion point
	*/

	void on_Shift_horizontally_valueChanged(int arg1);
	/** @brief This  function return all camera view and poition to its origion point and reset model position
	*/

	void on_Camera_view_reset_released();

	// ---------------------------------------------------------------------



signals:
	void statusUpdateMessage(const QString& message, int timeout);

	// ---------------------------------------------------------------------

private:
	Ui::MainWindow* ui;
	QString InputQString();
	bool LoadedFileType = true;

	std::vector<std::array<double, 3>> pointCoordinates;
	std::vector<vtkSmartPointer<vtkDataSetMapper>> ListOfMappers;
	std::vector<vtkSmartPointer<vtkUnstructuredGrid>> ListOfUgs;


	// Note: an object class assumed in order to use it to attempt model statistics function
	 /// The_Model_Class model_statistics; 
	 //std::vector<vtkLight> ListOfLights;





	  //--------------------------------------------------------------------------------------------------------


	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkUnstructuredGrid> ug = vtkSmartPointer<vtkUnstructuredGrid>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkClipDataSet> Clipper_Filter = vtkSmartPointer<vtkClipDataSet>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkShrinkFilter> Shrink_Filter = vtkSmartPointer<vtkShrinkFilter>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkAxesActor> axes = vtkSmartPointer<vtkAxesActor>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkDistanceWidget> distanceWidget = vtkSmartPointer<vtkDistanceWidget>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();  ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkCubeAxesActor> AxesActor = vtkSmartPointer<vtkCubeAxesActor>::New();  ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkOrientationMarkerWidget> orientationWidget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();  ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkPolyData> polydata = vtkSmartPointer<vtkPolyData>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkPlane> planeLeft = vtkSmartPointer<vtkPlane>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkAlgorithm>General; ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkSTLWriter> stlWriter = vtkSmartPointer<vtkSTLWriter>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html
	vtkSmartPointer<vtkLight> light = vtkSmartPointer<vtkLight>::New(); ///< @brief For more information on vtk Classes visit https://vtk.org/doc/nightly/html/annotated.html



};

#endif  //MAINWINDOW_H

