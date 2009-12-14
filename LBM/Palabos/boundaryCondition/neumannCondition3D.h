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
 * Neumann boundary conditions -- header file.
 */
#ifndef NEUMANN_CONDITION_3D_H
#define NEUMANN_CONDITION_3D_H

#include "core/globalDefs.h"
#include "core/blockLatticeBase3D.h"
#include "atomicBlock/blockLattice3D.h"
#include "atomicBlock/dataProcessorWrapper3D.h"

namespace plb {

template<typename T, template<typename U> class Descriptor, int direction, int orientation>
class CopyUnknownPopulationsFunctional3D : public BoxProcessingFunctional3D_L<T,Descriptor>
{
public:
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual CopyUnknownPopulationsFunctional3D<T,Descriptor,direction,orientation>* clone() const;
    virtual void getModificationPattern(std::vector<bool>& isWritten) const;
    virtual BlockDomain::DomainT appliesTo() const;
};

template<typename T, template<typename U> class Descriptor, int normalX, int normalY, int normalZ>
class CopyAllPopulationsFunctional3D : public BoxProcessingFunctional3D_L<T,Descriptor>
{
public:
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual CopyAllPopulationsFunctional3D<T,Descriptor,normalX,normalY,normalZ>* clone() const;
    virtual void getModificationPattern(std::vector<bool>& isWritten) const;
    virtual BlockDomain::DomainT appliesTo() const;
};

template<typename T, template<typename U> class Descriptor, int normalX, int normalY, int normalZ>
class CopyVelocityFunctional3D : public BoxProcessingFunctional3D_L<T,Descriptor>
{
public:
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual CopyVelocityFunctional3D<T,Descriptor,normalX,normalY,normalZ>* clone() const;
    virtual void getModificationPattern(std::vector<bool>& isWritten) const;
    virtual BlockDomain::DomainT appliesTo() const;
};

template<typename T, template<typename U> class Descriptor, int normalX, int normalY, int normalZ>
class CopyTangentialVelocityFunctional3D : public BoxProcessingFunctional3D_L<T,Descriptor>
{
public:
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual CopyTangentialVelocityFunctional3D<T,Descriptor,normalX,normalY,normalZ>* clone() const;
    virtual void getModificationPattern(std::vector<bool>& isWritten) const;
    virtual BlockDomain::DomainT appliesTo() const;
};

template<typename T, template<typename U> class Descriptor, int normalX, int normalY, int normalZ>
class CopyNormalVelocityFunctional3D : public BoxProcessingFunctional3D_L<T,Descriptor> {
public:
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual CopyNormalVelocityFunctional3D<T,Descriptor,normalX,normalY,normalZ>* clone() const;
    virtual void getModificationPattern(std::vector<bool>& isWritten) const;
    virtual BlockDomain::DomainT appliesTo() const;
};

template<typename T, template<typename U> class Descriptor, int normalX, int normalY, int normalZ>
class CopyDensityFunctional3D : public BoxProcessingFunctional3D_L<T,Descriptor>
{
public:
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual CopyDensityFunctional3D<T,Descriptor,normalX,normalY,normalZ>* clone() const;
    virtual void getModificationPattern(std::vector<bool>& isWritten) const;
    virtual BlockDomain::DomainT appliesTo() const;
};

}  // namespace plb

#endif  // NEUMANN_CONDITION_3D_H