// @HEADER
// ************************************************************************
//
//               Rapid Optimization Library (ROL) Package
//                 Copyright (2014) Sandia Corporation
//
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact lead developers:
//              Drew Kouri   (dpkouri@sandia.gov) and
//              Denis Ridzal (dridzal@sandia.gov)
//
// ************************************************************************
// @HEADER

/*! \file  pde.hpp
    \brief Implements the local PDE interface for the Poisson control problem.
*/

#ifndef PDEOPT_TOOLS_BOUNDARY_CELLS_HPP
#define PDEOPT_TOOLS_BOUNDARY_CELLS_HPP

#include "Intrepid_FieldContainer.hpp"
#include "Teuchos_RCP.hpp"
#include <vector>

template <class Real>
class BoundaryCells {
private:
// boundary_type_:
// 0 dirichlet
// 1 neumann
// 2 robin

  const int boundaryID_;
  const int boundaryType_;
  const std::vector<int> localCellIndex_;
  const Teuchos::RCP<Intrepid::FieldContainer<Real> > cellNodes_;
  const int localCellSideID_;

public:

  BoundaryCells(const int boundaryID,
                const int boundaryType,
                const std::vector<int> localCellIndex,
                const Teuchos::RCP<Intrepid::FieldContainer<Real> > cellNodes,
                const int localCellSideID)
    : boundaryID_(boundaryID),
      boundaryType_(boundaryType),
      localCellIndex_(localCellIndex),
      cellNodes_(cellNodes),
      localCellSideID_(localCellSideID) {}
  
  const int getBoundaryID(void) const {
    return boundaryID_; 
  }
   
  const int getBoundaryType(void) const {
    return boundaryType_; 
  }
  
  const std::vector<int> getBoundaryCellLocalIndex(void) const {
    return localCellIndex_; 
  }

  const Teuchos::RCP<Intrepid::FieldContainer<Real> > getCellNodes(void) const {
    return cellNodes_; 
  }

  const int getLocalCellSideID(void) const {
    return localCellSideID_;
  }
  
};
#endif