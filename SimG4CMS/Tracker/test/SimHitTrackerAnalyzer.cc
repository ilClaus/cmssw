// -*- C++ -*-
//
// Package:    SimHitTrackerAnalyzer
// Class:      SimHitTrackerAnalyzer
// 
/**\class SimHitTrackerAnalyzer SimHitTrackerAnalyzer.cc test/SimHitTrackerAnalyzer/src/SimHitTrackerAnalyzer.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Tommaso Boccali
//         Created:  Tue Jul 26 08:47:57 CEST 2005
// $Id: SimHitTrackerAnalyzer.cc,v 1.3 2005/10/18 19:50:54 fambrogl Exp $
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DetectorDescription/Core/interface/DDCompactView.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/TrackerBaseAlgo/interface/GeometricDet.h"
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/TrackingGeometry.h"


//
//
// class decleration
//

class SimHitTrackerAnalyzer : public edm::EDAnalyzer {
   public:
      explicit SimHitTrackerAnalyzer( const edm::ParameterSet& );
      ~SimHitTrackerAnalyzer();


      virtual void analyze( const edm::Event&, const edm::EventSetup& );
   private:
      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
SimHitTrackerAnalyzer::SimHitTrackerAnalyzer( const edm::ParameterSet& iConfig )
{
   //now do what ever initialization is needed

}


SimHitTrackerAnalyzer::~SimHitTrackerAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
SimHitTrackerAnalyzer::analyze( const edm::Event& iEvent, const edm::EventSetup& iSetup )
{
   using namespace edm;

   std::vector<PSimHit> thePixelHits;


   edm::Handle<edm::PSimHitContainer> PixelBarrelHitsLowTof;
   edm::Handle<edm::PSimHitContainer> PixelBarrelHitsHighTof;
   edm::Handle<edm::PSimHitContainer> PixelEndcapHitsLowTof;
   edm::Handle<edm::PSimHitContainer> PixelEndcapHitsHighTof;
   edm::Handle<edm::PSimHitContainer> TIBHitsLowTof;
   edm::Handle<edm::PSimHitContainer> TIBHitsHighTof;
   edm::Handle<edm::PSimHitContainer> TIDHitsLowTof;
   edm::Handle<edm::PSimHitContainer> TIDHitsHighTof;
   edm::Handle<edm::PSimHitContainer> TOBHitsLowTof;
   edm::Handle<edm::PSimHitContainer> TOBHitsHighTof;
   edm::Handle<edm::PSimHitContainer> TECHitsLowTof;
   edm::Handle<edm::PSimHitContainer> TECHitsHighTof;


   iEvent.getByLabel("r","TrackerHitsPixelBarrelLowTof", PixelBarrelHitsLowTof);
   iEvent.getByLabel("r","TrackerHitsPixelBarrelHighTof", PixelBarrelHitsHighTof);
   iEvent.getByLabel("r","TrackerHitsPixelEndcapLowTof", PixelEndcapHitsLowTof);
   iEvent.getByLabel("r","TrackerHitsPixelEndcapHighTof", PixelEndcapHitsHighTof);
   iEvent.getByLabel("r","TrackerHitsTIBLowTof", TIBHitsLowTof);
   iEvent.getByLabel("r","TrackerHitsTIBHighTof", TIBHitsHighTof);
   iEvent.getByLabel("r","TrackerHitsTIDLowTof", TIDHitsLowTof);
   iEvent.getByLabel("r","TrackerHitsTIDHighTof", TIDHitsHighTof);
   iEvent.getByLabel("r","TrackerHitsTOBLowTof", TOBHitsLowTof);
   iEvent.getByLabel("r","TrackerHitsTOBHighTof", TOBHitsHighTof);
   iEvent.getByLabel("r","TrackerHitsTECLowTof", TECHitsLowTof);
   iEvent.getByLabel("r","TrackerHitsTECHighTof", TECHitsHighTof);


   thePixelHits.insert(thePixelHits.end(), PixelBarrelHitsLowTof->begin(), PixelBarrelHitsLowTof->end()); 
   thePixelHits.insert(thePixelHits.end(), PixelBarrelHitsHighTof->begin(), PixelBarrelHitsHighTof->end());
   thePixelHits.insert(thePixelHits.end(), PixelEndcapHitsLowTof->begin(), PixelEndcapHitsLowTof->end()); 
   thePixelHits.insert(thePixelHits.end(), PixelEndcapHitsHighTof->begin(), PixelEndcapHitsHighTof->end());
   thePixelHits.insert(thePixelHits.end(), TIBHitsLowTof->begin(), TIBHitsLowTof->end()); 
   thePixelHits.insert(thePixelHits.end(), TIBHitsHighTof->begin(), TIBHitsHighTof->end());
   thePixelHits.insert(thePixelHits.end(), TIDHitsLowTof->begin(), TIDHitsLowTof->end()); 
   thePixelHits.insert(thePixelHits.end(), TIDHitsHighTof->begin(), TIDHitsHighTof->end());
   thePixelHits.insert(thePixelHits.end(), TOBHitsLowTof->begin(), TOBHitsLowTof->end()); 
   thePixelHits.insert(thePixelHits.end(), TOBHitsHighTof->begin(), TOBHitsHighTof->end());
   thePixelHits.insert(thePixelHits.end(), TECHitsLowTof->begin(), TECHitsLowTof->end()); 
   thePixelHits.insert(thePixelHits.end(), TECHitsHighTof->begin(), TECHitsHighTof->end());


   edm::ESHandle<TrackingGeometry> pDD;
   
   iSetup.get<TrackerDigiGeometryRecord> ().get(pDD);
   
   std::map<unsigned int, std::vector<PSimHit>,std::less<unsigned int> > SimHitMap;

   for (std::vector<PSimHit>::iterator isim = thePixelHits.begin();
	isim != thePixelHits.end(); ++isim){
     SimHitMap[(*isim).detUnitId()].push_back((*isim));
     std::cout<<" SimHit position  x = "<<isim->localPosition().x() <<" y = "<<isim->localPosition().y() <<" z = "<< isim->localPosition().z()<<std::endl;
   }
}

//define this as a plug-in
DEFINE_FWK_MODULE(SimHitTrackerAnalyzer)
