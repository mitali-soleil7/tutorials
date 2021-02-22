
#include "FieldMapReadBack.h"


#include <phfield/PHFieldUtility.h>
#include <phfield/PHField.h>

#include <fun4all/Fun4AllReturnCodes.h>

#include <phool/PHCompositeNode.h>

#include <Geant4/G4SystemOfUnits.hh>

//____________________________________________________________________________..
int FieldMapReadBack::InitRun(PHCompositeNode *topNode)
{
  fieldmap = PHFieldUtility::GetFieldMapNode(nullptr,topNode);
  if (fieldmap)
  {
    std::cout << "Found or created fieldmap" << std::endl;
  }
  else
  {
    std::cout << "fieldmap found or created" << std::endl;
  }
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int FieldMapReadBack::process_event(PHCompositeNode *topNode)
{
  double p[4] = {0.,0.,0.,0.};
  double bfield[3];
  fieldmap->GetFieldValue(p,bfield);
  std::cout << "bx: " << bfield[0]/tesla
   << " by: " << bfield[1]/tesla
	    << " bz: " << bfield[2]/tesla
       << std::endl;
  return Fun4AllReturnCodes::EVENT_OK;
}

