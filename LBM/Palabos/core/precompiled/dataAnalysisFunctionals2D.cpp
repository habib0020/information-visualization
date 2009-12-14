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
#include "core/dataAnalysisFunctionals2D.h"
#include "core/dataAnalysisFunctionals2D.hh"
#include "latticeBoltzmann/nearestNeighborLattices2D.h"
#include "latticeBoltzmann/nearestNeighborLattices2D.hh"

namespace plb {

/* *************** PART I ******************************************** */
/* *************** Analysis of the block-lattice ********************* */
/* ******************************************************************* */

template class ExtractLatticeSubDomainFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxSumRhoBarFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxSumEnergyFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxDensityFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxRhoBarFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxKineticEnergyFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxVelocityComponentFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxVelocityNormFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxVelocityFunctional2D<double, descriptors::D2Q9Descriptor>;
template class BoxPopulationFunctional2D<double, descriptors::D2Q9Descriptor>;


/* *************** PART II ******************************************* */
/* *************** Analysis of the scalar-field ********************** */
/* ******************************************************************* */

template class BoxScalarSumFunctional2D<double>;
template class BoundedBoxScalarSumFunctional2D<double>;

template class BoxScalarMinFunctional2D<double>;
template class BoxScalarMaxFunctional2D<double>;

template class ExtractScalarSubDomainFunctional2D<double>;

template class A_plus_alpha_functional2D<double>;
template class A_minus_alpha_functional2D<double>;
template class Alpha_minus_A_functional2D<double>;
template class A_times_alpha_functional2D<double>;
template class A_dividedBy_alpha_functional2D<double>;
template class Alpha_dividedBy_A_functional2D<double>;

template class A_plus_alpha_inplace_functional2D<double>;
template class A_minus_alpha_inplace_functional2D<double>;
template class A_times_alpha_inplace_functional2D<double>;
template class A_dividedBy_alpha_inplace_functional2D<double>;

template class A_plus_B_functional2D<double>;
template class A_minus_B_functional2D<double>;
template class A_times_B_functional2D<double>;
template class A_dividedBy_B_functional2D<double>;

template class A_plus_B_inplace_functional2D<double>;
template class A_minus_B_inplace_functional2D<double>;
template class A_times_B_inplace_functional2D<double>;
template class A_dividedBy_B_inplace_functional2D<double>;


/* *************** PART III ****************************************** */
/* *************** Analysis of the tensor-field ********************** */
/* ******************************************************************* */

template class ExtractTensorSubDomainFunctional2D<double,2>;
template class ExtractTensorComponentFunctional2D<double,2>;
template class ComputeNormFunctional2D<double,2>;
template class ComputeNormSqrFunctional2D<double,2>;
template class BoxBulkVorticityFunctional2D<double,2>;
template class BoxVorticityFunctional2D<double,2>;

template class Tensor_A_plus_B_functional2D<double,2>;
template class Tensor_A_minus_B_functional2D<double,2>;
template class Tensor_A_times_B_functional2D<double,2>;
template class Tensor_A_dividedBy_B_functional2D<double,2>;

template class Tensor_A_plus_B_inplace_functional2D<double,2>;
template class Tensor_A_minus_B_inplace_functional2D<double,2>;
template class Tensor_A_times_B_inplace_functional2D<double,2>;
template class Tensor_A_dividedBy_B_inplace_functional2D<double,2>;

}
