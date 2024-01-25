//----------------------------------------------------------------------
// Computing Project
// Created by HABIBATALLA ABOUELSEOUD on 28/4/2022.
// Copyright HABIBATALLA ABOUELSEOUD
//-----------------------------------------------------------------------

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

	ui->setupUi(this);


	// Connect the released() signal of each action object to the action slot in each object
	connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);
	connect(ui->actionSave, &QAction::triggered, this, &MainWindow::handleSaveButton);
	connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::handleOpenButton);
	connect(ui->actionHelp, &QAction::triggered, this, &MainWindow::handleHelpButton);
	connect(ui->actionPrint, &QAction::triggered, this, &MainWindow::handlePrintButton);


	vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
	ui->qvtkWidget->SetRenderWindow(renderWindow);


	renderer = vtkSmartPointer<vtkRenderer>::New();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);


}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::handleOpenButton() {
	//Code to load a STL file of the user's choice
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open CAD File"), "/home", tr("CAD Files (*.stl)"));
	//Convert QString to standard C string
	QByteArray ba = fileName.toLocal8Bit();
	const char* c_fileName = ba.data();
	General = reader;
	reader->SetFileName(c_fileName);
	reader->Update();


	//Code to display the STL file data
	mapper->SetInputConnection(reader->GetOutputPort());

	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();
	ui->qvtkWidget->GetRenderWindow()->Render();


	emit statusUpdateMessage(QString("CAD File has been opened"), 0);
}


void MainWindow::handleSaveButton() {
	//Insert Code
}


void MainWindow::handleHelpButton() {
	//Insert Code
}


void MainWindow::handlePrintButton() {
	//Insert Code
}

void MainWindow::on_Change_Object_Color_released()
{
	//ui->statusBar->showMessage("Change Object Color Button was clicked", 3000);


	QColor Color = QColorDialog::getColor(Qt::white, this, "Choose Color");
	//validation of color selected 
	if (Color.isValid())
	{

		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		actor->GetProperty()->SetColor(red, green, blue);
	}
	//rerenders the window after the color change
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
	emit statusUpdateMessage(QString("Change Object Color Button was clicked"), 0);
}


void MainWindow::on_Change_Back_Ground_Color_released()
{
	//ui->statusBar->showMessage("Change Color Back Ground Button was clicked", 3000);
	QColor Color = QColorDialog::getColor(Qt::white, this, "Choose Back Ground Color");
	if (Color.isValid())
	{
		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		renderer->SetBackground(red, green, blue);
	}
	//rerenders the window after the color change
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
	emit statusUpdateMessage(QString("Change Color Back Ground Button was clicked"), 0);
}

void MainWindow::on_Shrink_Filter_toggled(bool Shrink_Filter_Status)
{
	if (Shrink_Filter_Status == true)
	{
		//when shrink is applied no other filter is applied
		emit statusUpdateMessage(QString("Shrink filter applied"), 3000);

		//checked_Box_Status_Updater(1);
		Shrink_Filter->SetInputConnection(General->GetOutputPort());
		Shrink_Filter->SetShrinkFactor(.5);
		Shrink_Filter->Update();

		//mapper = vtkSmartPointer<vtkMapper>::New();
		mapper->SetInputConnection(Shrink_Filter->GetOutputPort());

		/*renderer->RemoveAllViewProps();
		actor = vtkSmartPointer<vtkActor>::New();
		actor->SetMapper(mapper);
		renderer->AddActor(actor);*/
	}
	else
	{
		mapper->SetInputConnection(General->GetOutputPort());
	}
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
}


void MainWindow::on_Clipper_Filter_toggled(bool Clipper_Filter_Status)
{
	if (Clipper_Filter_Status == true)
	{
		//checked_Box_Status_Updater(2);
		emit statusUpdateMessage(QString("Clip filter applied"), 3000);

		planeLeft->SetOrigin(0.0, 0.0, 0.0);
		planeLeft->SetNormal(-1.0, 0.0, 0.0);

		Clipper_Filter->SetInputConnection(General->GetOutputPort());
		Clipper_Filter->SetClipFunction(planeLeft.Get());
		mapper->SetInputConnection(Clipper_Filter->GetOutputPort());
	}
	else
	{
		mapper->SetInputConnection(General->GetOutputPort());
	}
	renderWindow->Render();
	//reader->Update();
	ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_cube_released()
{



	// Now use the VTK libraries to render something. To start with you can copy-paste the cube example code, there are comments to show where the code must be modified.
	//--------------------------------------------- Code From Example 1 --------------------------------------------------------------------------
	// Create a cube using a vtkCubeSource
	vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();
	General = cubeSource;
	// Create a mapper that will hold the cube's geometry in a format suitable for rendering

	mapper->SetInputConnection(cubeSource->GetOutputPort());

	// Create an actor that is used to set the cube's properties for rendering and place it in the window

	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Create a renderer, and render window

	//vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();		// ###### We've already created the renderWindow this time ######
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

	// Link a renderWindowInteractor to the renderer (this allows you to capture mouse movements etc)  ###### Not needed with Qt ######
	//vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//renderWindowInteractor->SetRenderWindow( ui->vtkWidget->GetRenderWindow() );				

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();


	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

	emit statusUpdateMessage(QString("Cube displayed"), 0);
	//--------------------------------------------- /Code From Example 1 -------------------------------------------------------------------------*/

}

void MainWindow::on_cone_released()
{

	
	vtkSmartPointer<vtkConeSource> coneSource = vtkSmartPointer<vtkConeSource>::New();
	General = coneSource;
	mapper->SetInputConnection(coneSource->GetOutputPort());



	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);									

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();

	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

	emit statusUpdateMessage(QString("Cone displayed"), 0);
	

}


void MainWindow::on_sphere_released()
{


	vtkSmartPointer<vtkSphereSource> SphereSource = vtkSmartPointer<vtkSphereSource>::New();
	General = SphereSource;


	mapper->SetInputConnection(SphereSource->GetOutputPort());



	actor->SetMapper(mapper);
	actor->GetProperty()->EdgeVisibilityOn();

	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
	actor->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());

	// Create a renderer, and render window

	//vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();		// ###### We've already created the renderWindow this time ######
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

	// Link a renderWindowInteractor to the renderer (this allows you to capture mouse movements etc)  ###### Not needed with Qt ######
	//vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//renderWindowInteractor->SetRenderWindow( ui->vtkWidget->GetRenderWindow() );				

	// Add the actor to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("Silver").GetData());

	// Setup the renderers's camera
	renderer->ResetCamera();
	renderer->GetActiveCamera()->Azimuth(30);
	renderer->GetActiveCamera()->Elevation(30);
	renderer->ResetCameraClippingRange();



	// Render and interact
	//renderWindow->Render();					// ###### Not needed with Qt ######
	//renderWindowInteractor->Start();			// ###### Not needed with Qt ######
	// 
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();

	emit statusUpdateMessage(QString("Sphere displayed"), 0);
}


///-----------------------------------------------------------------------------------------------------------------
///                        Modify Model Geomtry
/// ----------------------------------------------------------------------------------------------------------------


void MainWindow::on_Ruler_PushButton_released()
{

	distanceWidget = vtkSmartPointer<vtkDistanceWidget>::New();
	distanceWidget->SetInteractor(ui->qvtkWidget->GetRenderWindow()->GetInteractor());
	distanceWidget->CreateDefaultRepresentation();
	distanceWidget->On();
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
	emit statusUpdateMessage(QString("Ruler Added"), 0);

}

void MainWindow::on_Delete_Ruler_PushButton_released()
{
	distanceWidget->Off();
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
	emit statusUpdateMessage(QString("Ruler Removed"), 0);
}


void MainWindow::on_Axes_PushButton_released()
{

	if (LoadedFileType == true)
	{
		AxesActor->SetBounds(actor->GetBounds());
	}
	else
	{
		AxesActor->SetBounds(polydata->GetBounds());
	}

	AxesActor->SetCamera(renderer->GetActiveCamera());

	//X_AXIS
	AxesActor->DrawXGridlinesOn();
	AxesActor->GetXAxesGridlinesProperty()->SetColor(0.5, 0.5, 0.5);
	AxesActor->XAxisMinorTickVisibilityOff();

	//Y_AXIS
	AxesActor->DrawYGridlinesOn();
	AxesActor->GetYAxesGridlinesProperty()->SetColor(0.5, 0.5, 0.5);
	AxesActor->YAxisMinorTickVisibilityOff();

	//Z_AXIS
	AxesActor->DrawZGridlinesOn();
	AxesActor->GetZAxesGridlinesProperty()->SetColor(0.5, 0.5, 0.5);
	AxesActor->ZAxisMinorTickVisibilityOff();
	AxesActor->SetGridLineLocation(2);

	renderer->AddActor(AxesActor);
	renderWindow->Render();

	ui->qvtkWidget->GetRenderWindow()->Render();

	emit statusUpdateMessage(QString("Model Axis Displayed"), 0);

}

void MainWindow::on_delete_Axes_PushButton_released()
{
	renderer->RemoveActor(AxesActor);
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->Render();
	emit statusUpdateMessage(QString("Model Axis Deleted"), 0);
}

///-----------------------------------------------------------------------------------------------------------------
/// ----------------------------------------------------------------------------------------------------------------

///-----------------------------------------------------------------------------------------------------------------
///        an attempt for :   Model Statistics 
/// ----------------------------------------------------------------------------------------------------------------

// Note : this is an attempt for model statistics function it wont work as the integration of semster one classes 
// is not attemted only cell class is updated 
// hence the objects of classes are assumed in the below function

/*
void MainWindow::on_View_Statistics_of_Model_released()
{
	if (LoadedFileType == false)
	{
		QMessageBox statistics;
		statistics.setWindowTitle("The Statistics of the Model");
		QString Volume_of_Model = QString::number(model_statistics.Get_Volume_of_Model());
		QString Weight_of_Model = QString::number(model_statistics.Get_Weight_of_Model());
		QString Density_of_Model = QString::number(model_statistics.Get_Weight_of_Model() / model_statistics.Get_Volume_of_Model());


		vectors_3D Model_Geometric_Centre = model_statistics.Get_Model_Geometric_Centre();
		QString geometric_Centre = (
			"X: " + QString::number(Model_Geometric_Centre.get_x_coord()) + " " +"Y: " + QString::number(Model_Geometric_Centre.get_y_coord()) + " " +"Z: " + QString::number(Model_Geometric_Centre.get_z_coord()));

		vectors_3D Model_Gravity_Centre = model_statistics.Get_Model_Gravity_Centre();
		QString gravity_Centre = (
			"X: " + QString::number(Model_Gravity_Centre.get_x_coord()) + " " +"Y: " + QString::number(Model_Gravity_Centre.get_y_coord()) + " " +"Z: " + QString::number(Model_Gravity_Centre.get_z_coord()));


		vectors_3D Model_Total_Dimension = model_statistics.Get_Model_Total_Dimension();
		QString total = (
			"X: " + QString::number(Model_Total_Dimension.get_x_coord()) + " " +"Y: " + QString::number(Model_Total_Dimension.get_y_coord()) + " " +"Z: " + QString::number(Model_Total_Dimension.get_z_coord()));

		statistics.setText(
			" Model Volume: " + Volume_of_Model + "\n\n" +
			" Model Weight: " + Weight_of_Model + "\n\n" +
			"Model Density : " + Density_of_Model + "\n\n" +
			"Model Geometric Centre: " + geometric_Centre + "\n\n"+
			"Model   Centre Of Gravity: " + gravity_Centre + "\n\n" +
			"Model Total Dimensions: " + total);
		statistics.exec();
	}
}

*/
//---------------------------------------------------------------------------------------------------------


///-----------------------------------------------------------------------------------------------------------------
/// Camera for Model & Modify position Groupbox
/// ----------------------------------------------------------------------------------------------------------------


	///////////////////////////////////////////////////////////////////////////////////
	////NOTE::
	/// THE BELOW Function work but need to click on window after applying any of them 
	////////////////////////////////////////////////////////////////////////////////////


void MainWindow::on_X_Plane_Position_valueChanged(int value)
{
	static int Last_Value_Azimuth = 0.0;
	int Temp = value;
	value = value - Last_Value_Azimuth;
	renderer->GetActiveCamera()->Azimuth(double(value));
	Last_Value_Azimuth = Temp;
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	emit statusUpdateMessage(QString("Model X-Axis Value changed "), 0);

}

///////////////////////////////////////////////////////////////////////////////////
	////NOTE::
	/// THE BELOW Function work but need to click on window after applying any of them 
	////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_Y_Plane_Position_valueChanged(int value)
{
	static double Last_Value_Roll = 0.0;
	int Temp = value;
	value = value - Last_Value_Roll;
	renderer->GetActiveCamera()->Roll(double(value));
	Last_Value_Roll = Temp;
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	emit statusUpdateMessage(QString("Model Y-Axis Value changed "), 0);
}

///////////////////////////////////////////////////////////////////////////////////
	////NOTE::
	/// THE BELOW Function work but need to click on window after applying any of them 
	////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_Z_Plane_Position_valueChanged(int value)
{
	static double Last_Value_Elevation = 0.0;
	int Temp = value;
	value = value - Last_Value_Elevation;
	renderer->GetActiveCamera()->Elevation(double(value));
	Last_Value_Elevation = Temp;
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	emit statusUpdateMessage(QString("Model Z-Axis Value changed "), 0);
}
void MainWindow::on_Shift_vertically_valueChanged(int arg1)
{
	static double Last_Value_Pitch = 0.0;
	int Temp = arg1;
	if ((arg1 == 0) && (abs(Last_Value_Pitch) == 1.0))
	{
		renderer->GetActiveCamera()->Pitch(double(Last_Value_Pitch));

	}
	else if ((arg1 == 0) && (Last_Value_Pitch == !0.0))
	{
		renderer->GetActiveCamera()->Pitch(double(arg1));

	}

	else
	{
		arg1 = arg1 - Last_Value_Pitch;
		renderer->GetActiveCamera()->Pitch(double(-arg1));

	}
	Last_Value_Pitch = Temp;
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

	emit statusUpdateMessage(QString("The Model had been shifted Vertically "), 0);
}

///////////////////////////////////////////////////////////////////////////////////
	////NOTE::
	/// THE BELOW Function work but need to click on window after applying any of them 
	////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_Shift_horizontally_valueChanged(int arg1)
{
	static double Last_Value_Yaw = 0.0;
	int Temp = arg1;
	if ((arg1 == 0) && (abs(Last_Value_Yaw) == 1.0))
	{
		renderer->GetActiveCamera()->Yaw(double(-Last_Value_Yaw));
	}
	else if ((arg1 == 0) && (Last_Value_Yaw == !0.0))
	{
		renderer->GetActiveCamera()->Yaw(double(-arg1));
	}
	else
	{
		arg1 = arg1 - Last_Value_Yaw;
		renderer->GetActiveCamera()->Yaw(double(arg1));
	}
	Last_Value_Yaw = Temp;
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	emit statusUpdateMessage(QString("The Model had been shifted Horizontally "), 0);
}


///////////////////////////////////////////////////////////////////////////////////
	////NOTE::
	/// THE BELOW Function work but need to click on window after applying any of them 
	////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_Camera_view_reset_released()
{
	double* CameraLocation = renderer->GetActiveCamera()->GetPosition();
	std::cout << "Camera Location: " << CameraLocation[0] << " " << CameraLocation[1] << " " << CameraLocation[2] << std::endl;
	renderer->ResetCamera();


	ui->X_Plane_Position->setValue(0);
	ui->Y_Plane_Position->setValue(0);
	ui->Z_Plane_Position->setValue(0);
	ui->Shift_horizontally->setValue(0);
	ui->Shift_vertically->setValue(0);
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	emit statusUpdateMessage(QString("The View for Model had beed Reset "), 0);
}


///-----------------------------------------------------------------------------------------------------------------
/// ----------------------------------------------------------------------------------------------------------------


///-----------------------------------------------------------------------------------------------------------------
///                       Apply Light On Model
/// ----------------------------------------------------------------------------------------------------------------

/////////////////////////////////////
/// still has few errors 
/////////////////////////////////////
/*
void MainWindow::on_Apply_Light_released()
{
	vtkSmartPointer<vtkLight> light = vtkSmartPointer<vtkLight>::New();

	// This checks to ensure a name has been given to the light
	// With out this check clicking the cancel button would cause the program to crash
	if (light.GetName().isEmpty() == false)
	{
		// This establishes default settings for an added light
		ui->Light_Box->addItem(light.GetName());
		light.light->SetLightTypeToSceneLight();
		light.light->SetPosition(5, 5, 15);
		light.light->SetPositional(true);
		light.light->SetConeAngle(10);
		light.light->SetFocalPoint(0, 0, 0);
		light.light->SetDiffuseColor(1, 1, 1);
		light.light->SetAmbientColor(1, 1, 1);
		light.light->SetSpecularColor(1, 1, 1);
		light.light->SetIntensity(0.5);
		renderer->AddLight(light.light);
		ui->qvtkWidget->GetRenderWindow()->Render();
	}
}


void MainWindow::on_Light_Box_editTextChanged(const QString& text)
{
	ListOfLights.at(ui->Light_Box->currentIndex());
	ui->Light_Box->setItemText(ui->Light_Box->currentIndex(), ListOfLights.at(ui->Light_Box->currentIndex()));
}

void MainWindow::on_Remove_Light_released()
{

	int LightToDelete = ui->Light_Box->currentIndex();
	if (ui->Light_Box->currentIndex() > 0)
	{
		ui->Light_Box->removeItem(ui->Light_Box->currentIndex());
		ui->Light_Box->update();
		renderer->RemoveLight(ListOfLights.at(LightToDelete));
		ListOfLights.erase(ListOfLights.begin() + LightToDelete);
	}

	renderWindow->Render();
}

void MainWindow::on_Modify_Light_clicked(){

 if(ui->Light_Box->currentIndex() > -1)
	{
		modify_lightDialog =new modify_light(this);
		modify_lightDialog->setWindowTitle(ListOfLights.at(ui->Light_Box->currentIndex()).GetName());
		modify_lightDialog->show();
		modify_lightDialog->Open_Dialog(ListOfLights.at(ui->Light_Box->currentIndex()),renderWindow );
	}
	}

*/
///---------------------------------------------------------------------------------------------------------------
