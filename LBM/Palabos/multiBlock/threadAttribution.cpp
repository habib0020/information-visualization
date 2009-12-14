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
 * Attribution of block id to thread for parallel execution -- implementation.
 */

#include "parallelism/mpiManager.h"
#include "multiBlock/threadAttribution.h"

namespace plb {

bool SerialThreadAttribution::isLocal(plint id) const {
    return true;
}

bool SerialThreadAttribution::allBlocksAreLocal() const {
    return true;
}

ThreadAttribution* SerialThreadAttribution::clone() const {
    return new SerialThreadAttribution;
}


bool OneToOneThreadAttribution::isLocal(plint id) const {
    return id == global::mpi().getRank();
}

bool OneToOneThreadAttribution::allBlocksAreLocal() const {
    return false;
}

ThreadAttribution* OneToOneThreadAttribution::clone() const {
    return new OneToOneThreadAttribution;
}

}  // namespace plb
