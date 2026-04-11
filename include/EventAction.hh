#include "G4UserEventAction.hh"
#include "G4Event.hh"

class G4Event;

class EventAction : public G4UserEventAction {
    public:
        EventAction();
        ~EventAction() override;

        void BeginOfEventAction(const G4Event*) override; 
        void EndOfEventAction(const G4Event*) override; 

    private:
        G4double KE = 0.; 
};