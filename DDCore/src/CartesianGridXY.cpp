//==========================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------------
// Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
// All rights reserved.
//
// For the licensing terms see $DD4hepINSTALL/LICENSE.
// For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
//
// Author     : M.Frank
//
//==========================================================================

// Framework include files
#include "DD4hep/Segmentations.h"
#include "DD4hep/CartesianGridXY.h"
#include "DDSegmentation/CartesianGridXY.h"

// C/C++ include files

using namespace std;
using namespace DD4hep::Geometry;

/// Copy Constructor from segmentation base object
CartesianGridXY::CartesianGridXY(const Segmentation& e) : Handle<Object>()
{
  m_element = Segmentation::get<Object>(e.ptr());
}

/// determine the position based on the cell ID
Position CartesianGridXY::position(const CellID& id) const   {
  return Position(access()->position(id));
}

/// determine the cell ID based on the position
DD4hep::CellID CartesianGridXY::cellID(const Position& local,
                                       const Position& global,
                                       const VolumeID& volID) const
{
  return access()->cellID(local, global, volID);
}

/// access the grid size in X
double CartesianGridXY::gridSizeX() const {
  return access()->gridSizeX();
}

/// access the grid size in Y
double CartesianGridXY::gridSizeY() const {
  return access()->gridSizeY();
}

/// access the coordinate offset in X
double CartesianGridXY::offsetX() const {
  return access()->offsetX();
}

/// access the coordinate offset in Y
double CartesianGridXY::offsetY() const {
  return access()->offsetY();
}

/// access the field name used for X
const string& CartesianGridXY::fieldNameX() const {
  return access()->fieldNameX();
}

/// access the field name used for Y
const string& CartesianGridXY::fieldNameY() const {
  return access()->fieldNameY();
}

/** \brief Returns a vector<double> of the cellDimensions of the given cell ID
    in natural order of dimensions, e.g., dx/dy/dz, or dr/r*dPhi

    Returns a vector of the cellDimensions of the given cell ID
    \param cellID is ignored as all cells have the same dimension
    \return vector<double> size 2:
    -# size in x
    -# size in y
*/
vector<double> CartesianGridXY::cellDimensions(const CellID& id) const  {
  return access()->cellDimensions(id);
}