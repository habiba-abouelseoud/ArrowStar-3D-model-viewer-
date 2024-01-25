//----------------------------------------------------------------------
// Computing Project
// Created by HABIBATALLA ABOUELSEOUD on 28/4/2022.
// Copyright HABIBATALLA ABOUELSEOUD
//-----------------------------------------------------------------------

#include "modify_light.h"
#include "ui_modify_light.h"
#include <QColorDialog>
#include <QDebug>      

Modify_Light::Modify_Light(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::Modify_Light)
{
	ui->setupUi(this);
}

Modify_Light::~Modify_Light()
{
	delete ui;
}




void modify_light::on_X_Axis_Origin_valueChanged(int arg1);
{
	double* light_at_origin = light_Local->light->GetPosition();
	light_Local->light->SetPosition(double(arg1), light_at_origin[1], light_at_origin[2]);
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

}


void modify_light::on_Y_Axis_Origin_valueChanged(int arg1);
{
	double* light_at_origin = light_Local->light->GetPosition();
	light_Local->light->SetPosition(light_at_origin[0], double(arg1), light_at_origin[2]);
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

}



void modify_light::on_Z_Axis_Origin_valueChanged(int arg1);
{
	double* light_at_origin = light_Local->light->GetPosition();
	light_Local->light->SetPosition(light_at_origin[0], light_at_origin[1], double(arg1));
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

}



void modify_light::on_X_Axis_Focussing_valueChanged(int arg1);
{
	double* light_at_focussing_point = light_Local->light->GetFocalPoint();
	light_Local->light->SetFocalPoint(double(arg1), light_at_focussing_point[1], light_at_focussing_point[2]);
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

}




void modify_light::on_Y_Axis_Focussing_valueChanged(int arg1);
{
	double* light_at_focussing_point = light_Local->light->GetFocalPoint();
	light_Local->light->SetFocalPoint(light_at_focussing_point[0], double(arg1), light_at_focussing_point[2]);
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

}



void modify_light::on_Z_Axis_Focussing_valueChanged(int arg1);
{
	double* light_at_focussing_point = light_Local->light->GetFocalPoint();
	light_Local->light->SetFocalPoint(light_at_focussing_point[0], light_at_focussing_point[1], double(arg1));
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

}

void modify_light::Open_Dialog(vtkSmartPointer<vtkGenericOpenGLRenderWindow>& I_Window)
{

	renderWindow = I_Window;

	ui->Apex_angle_Light_slider->setValue(int(light_Local->light->GetApex_Angle()));
	ui->Intensity_Of_Light_slider->setValue(int((light_Local->light->GetLight_Intensity()) * 100));
	ui->Light_ON_OFF->setCheckState((light_Local->Check_State()));

	double* light_at_focussing_point = light_Local->light->GetFocalPoint();
	ui->X_Axis_Focussing->setValue(int(Focal_Point[0]));
	ui->Y_Axis_Focussing->setValue(int(Focal_Point[1]));
	ui->Z_Axis_Focussing->setValue(int(Focal_Point[2]));

	double* light_at_origin = light_Local->light->GetPosition();
	ui->on_X_Axis_Origin->setValue(int(Origin[0]));
	ui->on_Y_Axis_Origin->setValue(int(Origin[1]));
	ui->on_Z_Axis_Origin->setValue(int(Origin[2]));


}

void Edit_Light::on_Apex_angle_Light_slider_valueChanged(int Light_Apex_Angle)
{
	light_Local->light->SetApex_Angle(double(Light_Apex_Angle));
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

void modify_light::on_Intensity_Of_Light_slider_valueChanged(int value)
{
	double Light_Intensity = double(value) / 100.00;
	light_Local->light->SetIntensity(Light_Intensity);
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

void modify_light::on_Specular_colour_released()
{
	QColor Color = QColorDialog::getColor(Qt::white, this, "Please choose Specular Light Filter to be applied on Model");
	if (Color.isValid())
	{
		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		light_Local->light->SetSpecularColor(red, green, blue);
	}
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

void modify_light::on_Ambient_colour_released()
{
	QColor Color = QColorDialog::getColor(Qt::white, this, " Please choose Ambient Light Filter to be applied on Model");
	if (Color.isValid())
	{
		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		light_Local->light->SetAmbientColor(red, green, blue);
	}
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

void modify_light::on_Diffuse_colour_released()
{
	QColor Color = QColorDialog::getColor(Qt::white, this, "Please choose Diffuse Light Filter to be applied on Model");
	if (Color.isValid())
	{
		double red = Color.redF();
		double green = Color.greenF();
		double blue = Color.blueF();
		light_Local->light->SetDiffuseColor(red, green, blue);
	}
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}


void modify_light::on_Light_ON_OFF_toggled(bool checked)
{
	if (checked == true)
	{
		light_Local->light->SwitchOn();
	}
	else
	{
		light_Local->light->SwitchOff();
	}
	renderWindow->Render();
	ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}