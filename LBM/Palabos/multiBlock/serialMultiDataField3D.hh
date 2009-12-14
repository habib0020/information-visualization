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
 * Serial access to elements of a scalar/tensor field -- generic implementation.
 */
#ifndef SERIAL_MULTI_DATA_FIELD_3D_HH
#define SERIAL_MULTI_DATA_FIELD_3D_HH

#include "serialMultiDataField3D.h"

/* *************** Class SerialScalarAccess3D ************************ */

namespace plb {
template<typename T>
SerialScalarAccess3D<T>::SerialScalarAccess3D()
    : locatedBlock(0)
{ }

template<typename T>
T& SerialScalarAccess3D<T>::getDistributedScalar (
            plint iX, plint iY, plint iZ,
            MultiBlockManagement3D const& multiBlockManagement,
            std::vector<ScalarField3D<T>*>& fields )
{
    plint localX, localY, localZ;
#ifdef PLB_DEBUG
    bool ok = multiBlockManagement.findInLocalBulk (
            iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
    PLB_PRECONDITION( ok );
#else
    multiBlockManagement.findInLocalBulk(iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
#endif
    return fields[locatedBlock] -> get(localX,localY,localZ);
}

template<typename T>
T const& SerialScalarAccess3D<T>::getDistributedScalar (
            plint iX, plint iY, plint iZ,
            MultiBlockManagement3D const& multiBlockManagement,
            std::vector<ScalarField3D<T>*> const& fields ) const
{
    plint localX, localY, localZ;
#ifdef PLB_DEBUG
    bool ok = multiBlockManagement.findInLocalBulk(iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
    PLB_PRECONDITION( ok );
#else
    multiBlockManagement.findInLocalBulk(iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
#endif
    return fields[locatedBlock] -> get(localX,localY,localZ);
}


template<typename T>
SerialScalarAccess3D<T>* SerialScalarAccess3D<T>::clone() const {
    return new SerialScalarAccess3D(*this);
}


/* *************** Class SerialTensorAccess3D ************************ */

template<typename T, int nDim>
SerialTensorAccess3D<T,nDim>::SerialTensorAccess3D()
    : locatedBlock(0)
{ }

template<typename T, int nDim>
Array<T,nDim>& SerialTensorAccess3D<T,nDim>::getDistributedTensor (
            plint iX, plint iY, plint iZ,
            MultiBlockManagement3D const& multiBlockManagement,
            std::vector<TensorField3D<T,nDim>*>& fields )
{
    plint localX, localY, localZ;
#ifdef PLB_DEBUG
    bool ok = multiBlockManagement.findInLocalBulk(iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
    PLB_PRECONDITION( ok );
#else
    multiBlockManagement.findInLocalBulk(iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
#endif
    return fields[locatedBlock] -> get(localX,localY,localZ);
}

template<typename T, int nDim>
Array<T,nDim> const& SerialTensorAccess3D<T,nDim>::getDistributedTensor (
            plint iX, plint iY, plint iZ,
            MultiBlockManagement3D const& multiBlockManagement,
            std::vector<TensorField3D<T,nDim>*> const& fields ) const
{
    plint localX, localY, localZ;
#ifdef PLB_DEBUG
    bool ok = multiBlockManagement.findInLocalBulk(iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
    PLB_PRECONDITION( ok );
#else
    multiBlockManagement.findInLocalBulk(iX,iY,iZ, locatedBlock, localX, localY, localZ, locatedBlock);
#endif
    return fields[locatedBlock] -> get(localX,localY,localZ);
}


template<typename T, int nDim>
SerialTensorAccess3D<T,nDim>* SerialTensorAccess3D<T,nDim>::clone() const {
    return new SerialTensorAccess3D(*this);
}

}

#endif  // SERIAL_MULTI_DATA_FIELD_3D_HH
