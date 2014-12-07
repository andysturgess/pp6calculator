// PP6Day3MuonAnalysis.cpp : Definition of PP6Day3MuonAnalysis functions

#include "MuClassAnalysis.hpp"
#include <iostream>
#include "FileReader.hpp"
#include "PP6Math.hpp"
#include "Particle.hpp"

//!====================================================================
//! Firstly define the getPDGID function; when it sees the string
//! mu+, mu-, it returns the correct PDG code!
//!====================================================================

int getPDGID(const std::string& partname) {
  if (partname == "mu-") {return 13;}
  else if (partname == "mu+" ) {return -13; }
  return 0;
}

//!==================================================================
//! Following Ben Morgan's example, contain all needed quantities
//! inside a struct, then have functions calling instances
//!==================================================================

struct Events {
  size_t size;
  int *ids;
  Particle *particles;
};

//!=================================================================
//! This is the create Events function, which has members size,
//! ids and particles; one refers to event number, the other to
//! the properties we assign to particles (using Particle class)
//!=================================================================


Events* createEvents(const size_t mag) {
  Events* p = new Events;
  p->size = mag;
  p->ids = new int[mag];
  p->particles = new Particle[mag];
  return p;
}

//!=================================================================
//! This is the related destroy events function; it then deletes
//! the instance of the Events pointer, deletes in member arrays
//! and nulls them
//!================================================================
void destroyEvents(Events *&p) {
  if (p) {
    p->size = 0;
    delete [] p->ids;
    p->ids = 0;
    delete [] p->particles;
    p->particles = 0;
    delete p;
    p = 0;
  }
}

//!==================================================================
//! In day two, made arrays big enough to fit all combos of muons,
//! classes allow more subtlety. This function uses FileReader to
//! load the information into strings; if the runId and particle name
//! match what we want (run4, mu+/-), then it adds to a counter
//! this will then later tell us how many muon/antimuons we have
//!==================================================================

int countParticles(const std::string& File, const std::string& particle,
		   const std::string& runId, size_t& count) {
 
  FileReader line(File);
  if (!line.isValid()) {
    std::cerr << "[countParticles:error] "  << std::endl;
    return 1;
  }

  count = 0;
  std::string particleName, dataID;

  while (line.nextLine()) {
    line.getFieldAsInt(1);
    particleName = line.getFieldAsString(2);
    dataID = line.getFieldAsString(6);
    if (dataID == runId) {
      if (particleName == particle) count++;
    }
  }
  return 0;
}

//!======================================================================
//! This goes one step further; as number is then known, can use this fn
//! to obtain the kinematics from columns 3,4,5, and then store the data
//! in our structure instance members;
//!======================================================================

Events* createParticles(const std::string& File, const size_t knownNumber,
			const std::string& particle, const double mass, 
			const std::string& runId) {

  FileReader line(File);
  if (!line.isValid()) {
    std::cerr << "[createParticles:error]"<< std::endl;
    return 0;
  }

  Events* Properties = createEvents(knownNumber);
  std::string partName, dataID;
  int eventId(0),pdgID(0),currentPart(0);
  double px(0.0), py(0.0), pz(0.0);

  while (line.nextLine()) {
    eventId = line.getFieldAsInt(1);
    partName = line.getFieldAsString(2);
    dataID = line.getFieldAsString(6);

    if (dataID == runId) {
      if (partName == particle) {
	px = line.getFieldAsDouble(3);
	py = line.getFieldAsDouble(4);
	pz = line.getFieldAsDouble(5);

	pdgID = getPDGID(particle);
	(Properties->ids)[currentPart] = eventId;
	(Properties->particles)[currentPart] = Particle(pdgID, mass, px, py, pz);
	++currentPart;
      }
    }
  }
  return Properties;
}

//!===================================================================
//! This function uses countParticles to then allow us to set the size
//! of our arrays - a more intelligent way of using the classes. It
//! then returns a createParticles of the desired form!
//!===================================================================

Events* readParticles(const std::string& file,
			  const std::string& particle,
			  const double mass, const std::string& runId) {
  int resultCode(0);
  size_t numberOf(0);
  resultCode = countParticles(file, particle, runId, numberOf);
  if (resultCode) {
    std::cerr << "ERROR " << std::endl;
    return 0;
  }
  return createParticles(file, numberOf, particle, mass, runId);
}


//!===================================================================
//! This is where the analysis actually happens. Very similar to before
//! create a mu instance of ReadParticles and amu. Works out N combin
//! -ations to make a flat index D, then uses nested for loops to do
//! the combinations. As I used std::sort before, couldn't get it to
//! work this time, so I used BM's associate_sort.
//!===================================================================

int muonanalysis_day3() {
  double muonMass = 0.105658366; // GeV
  Events* mu = readParticles("ObsPart.dat", "mu-", muonMass, "run4.dat");
  Events* amu = readParticles("ObsPart.dat", "mu+", muonMass, "run4.dat");
  int combo = mu->size * amu->size;
  double *invMasses = new double[combo];

  int *indices = new int[combo];
  for (size_t i(0); i < amu->size; ++i) {
    for (size_t j(0); j < mu->size; ++j) {
      int D = i * mu->size + j;
      indices[D] = D;
      invMasses[D] = invariant_mass(amu->particles[i],mu->particles[j]);
    }
  }
 
  associative_sort(invMasses, indices, combo);

  //!========================================================================
  //! Now we present the results in this section;
  //"=======================================================================

  std::cout << "The Results for ObsPart.dat" << std::endl;
  std::cout << "====================================================" << std::endl;
  std::cout << "Number of Muons = " << mu->size << std::endl;
  std::cout << "Number of AntiMuons = " << amu->size << std::endl;
  std::cout << "====================================================" << std::endl;
  for (int i(0); i < 10; ++i) {
    int muonIndex(indices[i] % mu->size);
    int antimuonIndex((indices[i] - muonIndex) / mu->size);
    std::cout << "The Invariant mass for muon " <<  mu->ids[muonIndex] 
	      << " and antimuon " << amu->ids[antimuonIndex] << std::endl;
    std::cout << "is " << invMasses[indices[i]] << " GeV" << std::endl;
    std::cout << "=================================================" << std::endl;
  }

  destroyEvents(mu);
  destroyEvents(amu);
  delete [] invMasses;
  delete [] indices;
  return 0;
}
