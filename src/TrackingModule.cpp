#include "TrackingModule.h"
#include "Player.h"
#include "tm_config.h"

#define SPELL_MULTITRACK 12345 // Replace this with the spell ID

void TrackingModule::Initialize()
{
    sEventMgr->AddEvent(TrackingModule::OnPlayerLogin, TrackingModule::GetInstance(), EVENT_PLAYER_LOGIN, 0, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
}

void TrackingModule::Shutdown()
{
    sEventMgr->RemoveEvents(TrackingModule::GetInstance(), EVENT_PLAYER_LOGIN);
}

void TrackingModule::CastDoubleGather(Player* player)
{
    for (GameObject* gameObject : player->GetNearbyGameObjects(100.0f))
    {
        if (gameObject->IsHerb() || gameObject->IsMineral())
        {
            player->AddTrackedGameObject(gameObject->GetGUID());
        }
    }
}

void TrackingModule::CheckAndGrantSpell(Player* player)
{
    bool hasMining = player->HasSkill(SKILL_MINING);
    bool hasHerbalism = player->HasSkill(SKILL_HERBALISM);
    bool spellEnabled = GetOption<bool>("TrackingModule.EnableSpell");

    uint32 spellID = GetOption<uint32>("TrackingModule.SpellID");

    if (spellEnabled && hasMining && hasHerbalism)
    {
        if (!player->HasSpell(spellID))
        {
            player->LearnSpell(spellID, false);
            player->SendChatMessage("You have learned the multi-gather spell to track both herbs and mining nodes.");
        }
    }
    else
    {
        if (player->HasSpell(spellID))
        {
            player->RemoveSpell(spellID, false);
            player->SendChatMessage("You have forgotten the multi-gather spell.");
        }
    }
}

void TrackingModule::OnPlayerLogin(Player* player)
{
    CheckAndGrantSpell(player);
}

bool TrackingModule::IsMultiGatherSpellEnabled(Player* player)
{
    return GetOption<bool>("TrackingModule.EnableSpell");
}

bool TrackingModule::ToggleMultiGatherSpell(Player* player)
{
    uint32 spellID = GetOption<uint32>("TrackingModule.SpellID");
    if (player->HasSpell(spellID))
    {
        player->RemoveSpell(spellID, false);
        player->SendChatMessage("You have turned off the multi-gather spell.");
        return false;
    }
    else
    {
        player->LearnSpell(spellID, false);
        player->SendChatMessage("You have turned on the multi-gather spell.");
        return true;
    }
}
