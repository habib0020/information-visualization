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

/** \file
 * A collection of dynamics classes (e.g. BGK) with which a Cell object
 * can be instantiated -- template instantiation.
 */
#include "boundaryCondition/boundaryDynamics.h"
#include "boundaryCondition/boundaryDynamics.hh"
#include "latticeBoltzmann/nearestNeighborLattices2D.h"
#include "latticeBoltzmann/nearestNeighborLattices2D.hh"

namespace plb {

    template class BoundaryCompositeDynamics<double, descriptors::D2Q9Descriptor>;
    template class StoreDensityDynamics<double, descriptors::D2Q9Descriptor>;
    template class StoreVelocityDynamics<double, descriptors::D2Q9Descriptor>;
    template class StoreDensityAndVelocityDynamics<double, descriptors::D2Q9Descriptor>;
    template class StoreTemperatureAndVelocityDynamics<double, descriptors::D2Q9Descriptor>;

    template class VelocityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 0, 1>;
    template class VelocityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 0, -1>;
    template class VelocityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 1, 1>;
    template class VelocityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 1, -1>;

    template class DensityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 0, 1>;
    template class DensityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 0, -1>;
    template class DensityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 1, 1>;
    template class DensityDirichletBoundaryDynamics<double, descriptors::D2Q9Descriptor, 1, -1>;

}
