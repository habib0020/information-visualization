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
 * Geometric operations on collections of 2D domains -- implementation file.
 */

#include "multiBlock/domainManipulation2D.h"
#include "core/plbDebug.h"

namespace plb {

std::vector<DomainAndId2D> getNonOverlapingBlocks(std::vector<DomainAndId2D> const& domainsWithId) {
    std::vector<DomainAndId2D> nonOverlapingBlocks;
    // Start with the first domain, which is taken without modification.
    if (!domainsWithId.empty()) {
        nonOverlapingBlocks.push_back(domainsWithId[0]);
    }
    // All subsequent domains get special treatment, as their overlap
    //   with previously adopted domains are cut out.
    for (pluint iDomain=1; iDomain<domainsWithId.size(); ++iDomain) {
        std::vector<Box2D> newDomains;
        newDomains.push_back(domainsWithId[iDomain].domain);
        for (pluint iPrevious=0; iPrevious<iDomain; ++iPrevious) {
            std::vector<Box2D> exceptedDomains;
            for (pluint iNewPart=0; iNewPart<newDomains.size(); ++iNewPart) {
                except(newDomains[iNewPart], domainsWithId[iPrevious].domain, exceptedDomains);
            }
            newDomains.swap(exceptedDomains);
        }
        for (pluint iNew=0; iNew<newDomains.size(); ++iNew) {
            nonOverlapingBlocks.push_back(DomainAndId2D( newDomains[iNew],
                                                         domainsWithId[iDomain].id) );
        }
    }
    return nonOverlapingBlocks;
}

void intersectDomainsAndIds(std::vector<std::vector<DomainAndId2D> > const& domainsWithId,
                                   std::vector<Box2D>& finalDomains,
                                   std::vector<std::vector<plint> >& finalIds)
{
    if (domainsWithId.empty()) {
        return;
    }

    // Copy the first collection without modification, as a starting
    //   point for future intersections.
    for (pluint iDomain=0; iDomain<domainsWithId[0].size(); ++iDomain) {
        finalDomains.push_back(domainsWithId[0][iDomain].domain);
        finalIds.resize(finalDomains.size());
        finalIds.back().push_back(domainsWithId[0][iDomain].id);
    }

    // Then, intersect with all following collections.
    for (pluint iCollection=1; iCollection<domainsWithId.size(); ++iCollection) {
        std::vector<Box2D> nextDomains;
        std::vector<std::vector<plint> > nextIds;
        // For each domain of the next collection ...
        for (pluint iNewDomain=0; iNewDomain<domainsWithId[iCollection].size(); ++iNewDomain) {
            // ... and for each domain found so far ...
            for (pluint iOldDomain=0; iOldDomain<finalDomains.size(); ++iOldDomain) {
                Box2D intersection;
                // ... compute the common intersections ...
                if (intersect(domainsWithId[iCollection][iNewDomain].domain, finalDomains[iOldDomain], intersection)) {
                    // ... and store them.
                    nextDomains.push_back(intersection);
                    // As for the IDs, we need not only the ID of the newest block, but those of all
                    //   the previous blocks as well.
                    nextIds.push_back(finalIds[iOldDomain]);
                    nextIds.back().push_back(domainsWithId[iCollection][iNewDomain].id);
                }
            }
        }
        // Replace the old collections of intersections and IDs by the newest version.
        finalDomains.swap(nextDomains);
        finalIds.swap(nextIds);
    }
}

}  // namespace plb
