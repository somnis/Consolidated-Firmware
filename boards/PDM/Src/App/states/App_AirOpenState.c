#include "states/App_AirOpenState.h"

#include "App_SharedMacros.h"

static void AirOpenStateRunOnEntry(struct StateMachine *const state_machine)
{
    struct PdmWorld *world = App_SharedStateMachine_GetWorld(state_machine);
    struct PdmCanTxInterface *can_tx_interface = App_PdmWorld_GetCanTx(world);
    App_CanTx_SetPeriodicSignal_STATE(
        can_tx_interface, CANMSGS_PDM_STATE_MACHINE_STATE_AIR_OPEN_CHOICE);
}

static void AirOpenStateRunOnTick(struct StateMachine *const state_machine)
{
    UNUSED(state_machine);
}

static void AirOpenStateRunOnExit(struct StateMachine *const state_machine)
{
    UNUSED(state_machine);
}

const struct State *App_GetAirOpenState(void)
{
    static struct State air_open_state = {
        .name         = "AIR OPEN",
        .run_on_entry = AirOpenStateRunOnEntry,
        .run_on_tick  = AirOpenStateRunOnTick,
        .run_on_exit  = AirOpenStateRunOnExit,
    };

    return &air_open_state;
}
