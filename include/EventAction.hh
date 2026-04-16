#ifndef EventAction_HH
#define EventAction_HH 1

#include "G4UserEventAction.hh"
#include "G4Event.hh"

class G4Event;

class EventAction : public G4UserEventAction {
    public:
        EventAction();
        ~EventAction() override;

        void BeginOfEventAction(const G4Event*) override; 
        void EndOfEventAction(const G4Event*) override; 

        void addKE(G4double ke); 

    private:
        G4double KE = 0.; 
};

inline void EventAction::addKE(G4double ke){
    KE += ke;
}

#endif