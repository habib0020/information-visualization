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

#ifndef DYNAMIC_SMAGORINSKY_PROCESSOR_3D_H
#define DYNAMIC_SMAGORINSKY_PROCESSOR_3D_H

#include "core/globalDefs.h"
#include "atomicBlock/dataProcessorWrapper3D.h"

namespace plb {

template<typename T, template<typename U> class Descriptor> 
class ComputeSmagoViscosityFunctional3D : public BoxProcessingFunctional3D_L<T,Descriptor>
{
public:
    ComputeSmagoViscosityFunctional3D(T omega0_, T cSmago_);
    virtual void process(Box3D domain, BlockLattice3D<T,Descriptor>& lattice);
    virtual ComputeSmagoViscosityFunctional3D<T,Descriptor>* clone() const;
    virtual void getModificationPattern(std::vector<bool>& isWritten) const;
    virtual BlockDomain::DomainT appliesTo() const;
private:
    static T computePreFactor(T omega0, T cSmago);
private:
    T omega0;    //< "Laminar" relaxation parameter, used when the strain-rate is zero.
    T preFactor; //< A factor depending on the Smagorinky constant, used to compute the effective viscosity.
};

} // namespace plb

#endif  // DYNAMIC_SMAGORINSKY_PROCESSOR_3D_H
