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
 * Operations on the 2D multiblock -- header file.
 */
#ifndef ATOMIC_BLOCK_OPERATIONS_2D_H
#define ATOMIC_BLOCK_OPERATIONS_2D_H

#include "core/globalDefs.h"
#include "atomicBlock/dataProcessor2D.h"
#include "atomicBlock/atomicBlock2D.h"
#include <vector>

namespace plb {

template<typename T>
void executeDataProcessor( DataProcessorGenerator2D<T> const& generator,
                           std::vector<AtomicBlock2D<T>*> objects );


template<typename T>
void executeDataProcessor( ReductiveDataProcessorGenerator2D<T>& generator,
                           std::vector<AtomicBlock2D<T>*> objects );

template<typename T>
void addInternalProcessor( DataProcessorGenerator2D<T> const& generator,
                           std::vector<AtomicBlock2D<T>*> objects, plint level=0 );

} // namespace plb

#endif
