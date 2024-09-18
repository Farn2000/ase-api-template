



void AddRemoveCommands(bool addCmd = true)
{
    // COMMANDS
    const FString Test = GetText<std::string>("Commands", "TestCMD", "").c_str();
    if (!Test.IsEmpty())
    {
        if (addCmd)
        {
            ArkApi::GetCommands().AddChatCommand(Test, &TestCallback);
        }
        else
        {
            ArkApi::GetCommands().RemoveChatCommand(Test);
        }
    }

    // RELOADS
    FString reload(FString(PROJECT_NAME) + ".Reload");
    if (!reload.IsEmpty())
    {
        if (addCmd)
        {
            ArkApi::GetCommands().AddConsoleCommand(reload, &ReloadConfig);
            ArkApi::GetCommands().AddRconCommand(reload, &ReloadConfigRcon);
        }
        else
        {
            ArkApi::GetCommands().RemoveConsoleCommand(reload);
            ArkApi::GetCommands().RemoveRconCommand(reload);
        }
    }

    // HOOKS
    /*
    if (addCmd)
    {
        ArkApi::GetHooks().SetHook("AShooterCharacter.SampleHook()", &Hook_AShooterCharacter_SampleHook,
            &AShooterCharacter_SampleHook_original);
    }
    else
    {
        ArkApi::GetHooks().DisableHook("AShooterCharacter.SampleHook()", &Hook_AShooterCharacter_SampleHook);
    }
    */

    // TIMERS
    /*
    if (addCmd)
    {
        ArkApi::GetCommands().AddOnTimerCallback("TimerTick", &TimerCallback);
    }
    else
    {
        ArkApi::GetCommands().RemoveOnTimerCallback("TimerTick");
    }
    */
    

}