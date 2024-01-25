cmake_minimum_required(VERSION 3.22)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

project( ArrowStar )

include(CTest)

if(WIN32)
   set(CPACK_GENERATOR "NSIS")
   else()
   set(CPACK_GENERATOR "ZIP")
endif()

include(CPack)

find_package(VTK COMPONENTS 
  vtkCommonColor
  vtkCommonCore
  vtkCommonDataModel
  vtkCommonExecutionModel
  vtkFiltersCore
  vtkFiltersGeneral
  vtkFiltersGeometry
  vtkFiltersSources
  vtkIoImage
  vtkFiltersModelling
  vtkGuiSupport
  vtkIoGeometry
  vtkInteractionStyle
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  QUIET
)

# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )

# This allows CMake to run one of Qt's build tools called moc
# if it is needed. moc.exe can be found in Qt's bin directory.
# We'll look at what moc does later.
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

# Find the Qt widgets package. This locates the relevant include and
# lib directories, and the necessary static libraries for linking.
find_package( Qt6Widgets )
find_package( Qt6 REQUIRED COMPONENTS Widgets
Gui
Core
 )

set( UIS mainwindow.ui )
qt6_wrap_ui( UI_Srcs ${UIS} )

set( ICONS Icons/icons.qrc )
qt6_add_resources( QRC_Srcs ${ICONS} )


# Also link to VTK
find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )

# Define the executable output and its sources
add_executable( ArrowStar MACOSX_BUNDLE
				main.cpp mainwindow.cpp 
				mainwindow.h 
				mainwindow.ui
				${UI_Srcs}
				${QRC_Srcs}
				)

# if ( ${BUILD_ArrowStar} OR ${BUILD_INSTALLERS} )
# These two lines set the path for the transfer of the libraries needed to run the application it varies from system to system.
  
# endif()

set(QT_DIR "C:/Qt/6.2.2/msvc2019_64") 
set(VTK_DIR "C:/Users/ecb/Source Code/VTK/VTK-9.1.0/Visual_Studio_Build")
set(ArrowStar_SOURCE_DIR "C:/Users/ecb/Desktop/2020_GROUP_04/ArrowStar_3DViewr")

# Installer code

install(TARGETS ArrowStar
RUNTIME DESTINATION Applications
COMPONENT Applications
        )

install(FILES
        ${QT_DIR}/bin/Qt6Cored.dll
        ${QT_DIR}/bin/Qt6Guid.dll
        ${QT_DIR}/bin/Qt6Widgetsd.dll
        
        ${VTK_DIR}/bin/Debug/vtkRenderingGL2PSOpenGL2-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonColor-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonComputationalGeometry-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonDataModel-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonExecutionModel-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonMath-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonMisc-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonSystem-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkCommonTransforms-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkDICOMParser-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkdoubleconversion-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersExtraction-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersGeneral-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersGeometry-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersHybrid-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersModeling-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersSources-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkFiltersStatistics-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkfreetype-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkgl2ps-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkglew-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkGUISupportQt-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingColor-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingFourier-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingGeneral-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingHybrid-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkImagingSources-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkInteractionStyle-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkInteractionWidgets-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkIOCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkIOGeometry-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkIOImage-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkjpeg-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtklz4-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtklzma-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkmetaio-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkpng-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingAnnotation-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingCore-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingFreeType-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingGL2PSOpenGL2-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkRenderingOpenGL2-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtksys-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtktiff-9.1d.dll
        ${VTK_DIR}/bin/Debug/vtkzlib-9.1d.dll
       
        C:/Windows/System32/MSVCP140D.dll 
        C:/Windows/System32/VCRUNTIME140D.dll 
        C:/Windows/System32/GDI32.dll
        C:/Windows/System32/KERNEL32.dll
        C:/Windows/System32/OLE32.dll 
        C:/Windows/System32/SHELL32.dll
        C:/Windows/System32/ADVAPI32.dll
        C:/Windows/System32/COMCTL32.dll
        C:/Windows/System32/USER32.dll
	
        DESTINATION bin
        COMPONENT libraries
        )


    install(FILES 
        "C:/Users/ecb/Desktop/2020_GROUP_04/The Model/Class 2-Cell/Cell.h"
        "C:/Users/ecb/Desktop/2020_GROUP_04/The Model/Class 2-Cell/Cell.cpp"
        "C:/Users/ecb/Desktop/2020_GROUP_04/The Model/Class 3-Material/material.h"
        "C:/Users/ecb/Desktop/2020_GROUP_04/The Model/Class 3-Material/material.cpp"
        "C:/Users/ecb/Desktop/2020_GROUP_04/The Model/Class 4-Model/The_Model_Class.cpp"
        "C:/Users/ecb/Desktop/2020_GROUP_04/The Model/Class 4-Model/include"
      
        DESTINATION include
        COMPONENT headers
        )

  install(FILES 
        ${ArrowStar_SOURCE_DIR}/Example_Models/a-10-thunderbolt-mk2.stl
        ${ArrowStar_SOURCE_DIR}/Example_Models/airbus_a400m.stl
        ${ArrowStar_SOURCE_DIR}/Example_Models/he111.stl
        ${ArrowStar_SOURCE_DIR}/Example_Models/ExampleModel1.mod
        ${ArrowStar_SOURCE_DIR}/Example_Models/ExampleModel2.mod
        ${ArrowStar_SOURCE_DIR}/Example_Models/ExampleModel3.mod

        DESTINATION Models
        COMPONENT Models
        )


set(CPACK_PACKAGE_NAME "ArrowStar")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "ArrowStar")


 # Define components and their display names
    set(CPACK_COMPONENTS_ALL Applications Models libraries headers)
    set(CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "Applications")
    set(CPACK_COMPONENT_MODELS_DISPLAY_NAME "Model Files")
    set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
    set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "Header Files")

   # Define dependencies between components
    set(CPACK_COMPONENT_APPLICATIONS_DEPENDS libraries)
    set(CPACK_COMPONENT_HEADERS_DEPENDS libraries)

    # Define groups
    set(CPACK_COMPONENT_APPLICATIONS_GROUP "Runtime")
    set(CPACK_COMPONENT_MODEL_FILES_GROUP "Runtime")
    set(CPACK_COMPONENT_LIBRARIES_GROUP "Runtime")
    set(CPACK_COMPONENT_HEADERS_GROUP "Development")

 # Define NSIS installation types
    set(CPACK_ALL_INSTALL_TYPES Everything "Applications With Libraries" Developer)
    set(CPACK_COMPONENT_APPLICATIONS_INSTALL_TYPES Everything "Applications With Libraries")
    set(CPACK_COMPONENT_MODEL_FILES_INSTALL_TYPES Everything)
    set(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES Everything "Applications With Libraries" Developer)
    set(CPACK_COMPONENT_HEADERS_INSTALL_TYPES Everything Developer)
    
# Tell CMake that the executable depends on the Qt::Widget libraries.
target_link_libraries( ArrowStar Qt6::Widgets
Qt6::Gui
Qt6::Core
 )

# Tell CMake that the executable depends on the VTK libraries
target_link_libraries( ArrowStar ${VTK_LIBRARIES} )

    include(InstallRequiredSystemLibraries)
