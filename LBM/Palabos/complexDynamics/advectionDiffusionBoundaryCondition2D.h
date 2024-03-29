/* This file is part of the Palabos library.
 * Copyright (C) 2009 Jonas Latt
 * E-mail contact: jonas@lbmethod.org
 * The most recent release of Palabos can be downloaded at 
 * <http://www.lbmethod.org/palabos/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Main author: Orestis Malaspinas
 */

/** \file A helper for initialising 2D boundaries -- header file.  */
#ifndef ADVECTION_DIFFUSION_BOUNDARY_CONDITION_2D_H
#define ADVECTION_DIFFUSION_BOUNDARY_CONDITION_2D_H

#include "core/globalDefs.h"
#include "core/blockLatticeBase2D.h"
#include "complexDynamics/advectionDiffusionDynamics.h"

#include <vector>
#include <list>

namespace plb {

template<typename T, template<typename U> class Descriptor>
class OnLatticeAdvectionDiffusionBoundaryCondition2D {
public:
    virtual ~OnLatticeAdvectionDiffusionBoundaryCondition2D() { }

    virtual void addTemperatureBoundary0N(Box2D domain, BlockLatticeBase2D<T,Descriptor>& lattice) =0;
    virtual void addTemperatureBoundary0P(Box2D domain, BlockLatticeBase2D<T,Descriptor>& lattice) =0;
    virtual void addTemperatureBoundary1N(Box2D domain, BlockLatticeBase2D<T,Descriptor>& lattice) =0;
    virtual void addTemperatureBoundary1P(Box2D domain, BlockLatticeBase2D<T,Descriptor>& lattice) =0;
    
    virtual void addTemperatureCornerNN(plint x, plint y, BlockLatticeBase2D<T,Descriptor>& lattice) =0;
    virtual void addTemperatureCornerNP(plint x, plint y, BlockLatticeBase2D<T,Descriptor>& lattice) =0;
    virtual void addTemperatureCornerPN(plint x, plint y, BlockLatticeBase2D<T,Descriptor>& lattice) =0;
    virtual void addTemperatureCornerPP(plint x, plint y, BlockLatticeBase2D<T,Descriptor>& lattice) =0;

    void setTemperatureConditionOnBlockBoundaries(BlockLatticeBase2D<T,Descriptor>& lattice);
};

//////  Factory function for Zou-He Thermal BC

template<typename T, template<typename U> class Descriptor>
OnLatticeAdvectionDiffusionBoundaryCondition2D<T,Descriptor>*
    createLocalAdvectionDiffusionBoundaryCondition2D();
    
//////  Factory function for Regularized Thermal BC
    
template<typename T, template<typename U> class Descriptor>
OnLatticeAdvectionDiffusionBoundaryCondition2D<T,Descriptor>*
    createLocalRegularizedAdvectionDiffusionBoundaryCondition2D();

} //namespace plb

#endif
