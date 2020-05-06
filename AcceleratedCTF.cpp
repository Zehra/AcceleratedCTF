// AcceleratedCTF.cpp
//

#include "bzfsAPI.h"

class AcceleratedCTF : public bz_Plugin
{
public:
  virtual const char* Name () {return "AcceleratedCTF";}
  virtual void Init(const char* config);
  virtual void Event(bz_EventData *eventData);
};

BZ_PLUGIN(AcceleratedCTF)

void AcceleratedCTF::Init( const char* /*commandLine*/ ) {
  Register(bz_eAllowFlagGrab);
}

void AcceleratedCTF::Event ( bz_EventData *eventData )
{
    if (eventData->eventType != bz_eAllowFlagGrab)
        return;

    bz_AllowFlagGrabData_V1* allowFlagGrab = (bz_AllowFlagGrabData_V1*)eventData;

    bz_eTeamType playerTeam = bz_getPlayerTeam(allowFlagGrab->playerID);

    if (playerTeam == eRedTeam) {
        if (strcmp(allowFlagGrab->flagType, "R*") == 0) {
            allowFlagGrab->allow = false;
        }
    } else if (playerTeam == eGreenTeam) {
        if (strcmp(allowFlagGrab->flagType, "G*") == 0) {
            allowFlagGrab->allow = false;
        }
    } else if (playerTeam == eBlueTeam) {
        if (strcmp(allowFlagGrab->flagType, "B*") == 0) {
            allowFlagGrab->allow = false;
        }
    } else if (playerTeam == ePurpleTeam) {
        if (strcmp(allowFlagGrab->flagType, "P*") == 0) {
            allowFlagGrab->allow = false;
        }
    }
}

