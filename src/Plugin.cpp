#include "API/ARK/Ark.h"

#include <fstream>
#include <ArkPermissions.h>
#include <Points.h>

#include "Plugin.h"

#include "Utils.h"

// other functions includes
#include "Tests.h"

#include "Hooks.h"

#include "Timer.h"

#include "Commands.h"

#pragma comment(lib, "ArkApi.lib")
#pragma comment(lib, "Permissions.lib")
#pragma comment(lib, "ArkShop.lib")





// Called when the server is ready, do post-"server ready" initialization here
void OnServerReady()
{
    Log::GetLog()->info("Hello, world!");

    LoadConfig();
    AddRemoveCommands();
}

// Hook that triggers once when the server is ready
DECLARE_HOOK(AShooterGameMode_BeginPlay, void, AShooterGameMode*);
void Hook_AShooterGameMode_BeginPlay(AShooterGameMode* _this)
{
    AShooterGameMode_BeginPlay_original(_this);

    OnServerReady();
}

// Called by ArkApi when the plugin is loaded, do pre-"server ready" initialization here
extern "C" __declspec(dllexport) void Plugin_Init()
{
    Log::Get().Init(PROJECT_NAME);

    ArkApi::GetHooks().SetHook("AShooterGameMode.BeginPlay()", Hook_AShooterGameMode_BeginPlay,
        &AShooterGameMode_BeginPlay_original);

    if (ArkApi::GetApiUtils().GetStatus() == ArkApi::ServerStatus::Ready)
        OnServerReady();
}

// Called by ArkApi when the plugin is unloaded, do cleanup here
extern "C" __declspec(dllexport) void Plugin_Unload()
{
    ArkApi::GetHooks().DisableHook("AShooterGameMode.BeginPlay()", Hook_AShooterGameMode_BeginPlay);

    AddRemoveCommands(false);
}