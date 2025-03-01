/*=========================================================================

  Program:   Visualization Toolkit
  Module:    TestGLTFReaderGeometry.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkGLTFReader.h"

int TestGLTFReaderGeometryNoBin(int argc, char* argv[])
{

  if (argc <= 1)
  {
    std::cout << "Usage: " << argv[0] << " <gltf file>" << std::endl;
    return EXIT_FAILURE;
  }

  vtkNew<vtkGLTFReader> reader;
  reader->SetFileName(argv[1]);

  // This test expects an error message, but we can't catch it via an error handler
  // because it's emmited by an internal object, so let's just deactivate the error logging.
  auto previousWarningLevel = vtkObject::GetGlobalWarningDisplay();
  vtkObject::SetGlobalWarningDisplay(0);

  reader->Update();

  vtkObject::SetGlobalWarningDisplay(previousWarningLevel);

  return EXIT_SUCCESS;
}
