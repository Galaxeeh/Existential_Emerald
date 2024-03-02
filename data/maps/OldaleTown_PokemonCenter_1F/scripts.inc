.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_ResourceNPC::
	lock
	faceplayer
	message OldaleTown_ResourceNPC_Text
	multichoice 0, 0, MULTI_RESOURCE_NPC, 0
	closemessage
	switch VAR_RESULT
	case 0, OldaleTown_ResourceNPC_PreStatus
	case 1, OldaleTown_ResourceNPC_PreDamage
	case 2, OldaleTown_ResourceNPC_IV
	case 3, OldaleTown_ResourceNPC_Nature
	case 4, OldaleTown_ResourceNPC_Nickname
	case 5, OldaleTown_ResourceNPC_Information
	case MULTI_B_PRESSED, OldaleTown_ResourceNPC_ComeAgain

OldaleTown_ResourceNPC_PreStatus::
	message OldaleTown_ChooseStatus_Text
	multichoice 0, 0, MULTI_PRESTATUS, 0
	closemessage
	switch VAR_RESULT
	case 0, OldaleTown_ResourceNPC_Burn
	case 1, OldaleTown_ResourceNPC_Freeze
	case 2, OldaleTown_ResourceNPC_Poison
	case 3, OldaleTown_ResourceNPC_Paralysis
	case 4, OldaleTown_ResourceNPC_Sleep
	case MULTI_B_PRESSED, OldaleTown_ResourceNPC_ComeAgain

OldaleTown_ResourceNPC_PreDamage::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC
	special PreDamage
	waitstate
	releaseall
	end


OldaleTown_ResourceNPC_IV::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, NoHeartScale
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC_ChooseIV
	end

OldaleTown_ResourceNPC_ChooseIV::
	message OldaleTown_ChooseIV_Text
	multichoice 0, 0, MULTI_IVS, 0
	closemessage
	switch VAR_RESULT
	case 0, OldaleTown_ResourceNPC_MaxHP
	case 1, OldaleTown_ResourceNPC_MaxAtk
	case 2, OldaleTown_ResourceNPC_MaxDef
	case 3, OldaleTown_ResourceNPC_MaxSpAtk
	case 4, OldaleTown_ResourceNPC_MaxSpDef
	case 5, OldaleTown_ResourceNPC_MaxSpd
	case MULTI_B_PRESSED, OldaleTown_ResourceNPC_ComeAgain

OldaleTown_ResourceNPC_MaxHP::
	specialvar VAR_RESULT, ScriptGetPartyMonHP
	goto_if_eq VAR_RESULT, 31, OldaleTown_ResourceNPC_NoEffect
	msgbox OldaleTown_ConfirmHp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_ResourceNPC_ChooseIV
	special MaxHpIV
	playse SE_SAVE
	removeitem ITEM_HEART_SCALE
	release
	end

NoHeartScale::
	msgbox NoHeartScale_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleTown_ResourceNPC_MaxAtk::
	specialvar VAR_RESULT, ScriptGetPartyMonAtk
	goto_if_eq VAR_RESULT, 31, OldaleTown_ResourceNPC_NoEffect
	msgbox OldaleTown_ConfirmAtk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_ResourceNPC_ChooseIV
	special MaxAtkIV
	playse SE_SAVE
	removeitem ITEM_HEART_SCALE
	release
	end

OldaleTown_ResourceNPC_MaxDef::
	specialvar VAR_RESULT, ScriptGetPartyMonDef
	goto_if_eq VAR_RESULT, 31, OldaleTown_ResourceNPC_NoEffect
	msgbox OldaleTown_ConfirmDef, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_ResourceNPC_ChooseIV
	special MaxDefIV
	playse SE_SAVE
	removeitem ITEM_HEART_SCALE
	release
	end

OldaleTown_ResourceNPC_MaxSpd::
	specialvar VAR_RESULT, ScriptGetPartyMonSpd
	goto_if_eq VAR_RESULT, 31, OldaleTown_ResourceNPC_NoEffect
	msgbox OldaleTown_ConfirmSpd, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_ResourceNPC_ChooseIV
	special MaxSpdIV
	playse SE_SAVE
	removeitem ITEM_HEART_SCALE
	release
	end

OldaleTown_ResourceNPC_MaxSpAtk::
	specialvar VAR_RESULT, ScriptGetPartyMonSpAtk
	goto_if_eq VAR_RESULT, 31, OldaleTown_ResourceNPC_NoEffect
	msgbox OldaleTown_ConfirmSpAtk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_ResourceNPC_ChooseIV
	special MaxSpAtkIV
	playse SE_SAVE
	removeitem ITEM_HEART_SCALE
	release
	end

OldaleTown_ResourceNPC_MaxSpDef::
	specialvar VAR_RESULT, ScriptGetPartyMonSpDef
	goto_if_eq VAR_RESULT, 31, OldaleTown_ResourceNPC_NoEffect
	msgbox OldaleTown_ConfirmSpDef, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_ResourceNPC_ChooseIV
	special MaxSpDefIV
	playse SE_SAVE
	removeitem ITEM_HEART_SCALE
	release
	end

OldaleTown_ResourceNPC_NoEffect::
	msgbox OldaleTown_ResourceNPC_NoEffect_Text, MSGBOX_DEFAULT
	waitmessage
	release
	end



OldaleTown_ResourceNPC_Nature::
	release
	end

OldaleTown_ResourceNPC_Nickname::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_NameRatersHouse_EventScript_RateMonNickname
	end

OldaleTown_ResourceNPC_Information::
	msgbox OldaleTown_Info, MSGBOX_DEFAULT
	waitmessage
	goto OldaleTown_ResourceNPC
	release
	end

OldaleTown_ResourceNPC_Burn::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC_PreStatus
	setmonstatus STATUS1_BURN
	playse SE_M_EMBER
	msgbox BurnHeal, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleTown_ResourceNPC_Freeze::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC_PreStatus
	setmonstatus STATUS1_FREEZE
	playse SE_M_ICY_WIND
	msgbox Cold, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleTown_ResourceNPC_Poison::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC_PreStatus
	setmonstatus STATUS1_POISON
	playse SE_M_TOXIC
	msgbox Toxic, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleTown_ResourceNPC_Paralysis::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC_PreStatus
	setmonstatus STATUS1_PARALYSIS
	playse SE_M_THUNDER_WAVE
	msgbox Para, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleTown_ResourceNPC_Sleep::
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OldaleTown_ResourceNPC_PreStatus
	setmonstatus STATUS1_SLEEP
	playse SE_M_YAWN
	msgbox Sleep, MSGBOX_DEFAULT
	closemessage
	release
	end

OldaleTown_ResourceNPC_ComeAgain::
	msgbox OldaleTown_ResourceNPC_ComeAgain_Text, MSGBOX_DEFAULT
	waitmessage
	release
	end


OldaleTown_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, OldaleTown_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_NameRatersHouse_EventScript_PlayerNotMonsOT
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_NameRatersHouse_EventScript_ChangeNickname
	end

OldaleTown_NameRatersHouse_EventScript_CantRateEgg::
	msgbox OldaleTown_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

OldaleTown_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox OldaleTown_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

OldaleTown_NameRatersHouse_EventScript_ChangeNickname::
	msgbox OldaleTown_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	release
	end

NoHeartScale_Text:
	.string "You don't have any heart scales!$"

BurnHeal:
	.string "You better have Burn Heal!$"

Cold:
	.string "Now that's cold!$"

Toxic:
	.string "Don't you know that you're Toxic?$"

Para:
	.string "Shocking!$"

Sleep:
	.string "Sleep well, sweet prince.$"

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

OldaleTown_ResourceNPC_Text:
	.string "What can I do for you?$"

OldaleTown_ChooseStatus_Text:
	.string "What status do you need?$"

OldaleTown_ChooseIV_Text:
	.string "What stat would you like to maximize?$"

OldaleTown_ChooseNature_Text:
	.string "What nature would you like?$"

OldaleTown_ResourceNPC_ComeAgain_Text:
	.string "Have a nice day!$"

OldaleTown_ResourceNPC_NoEffect_Text:
	.string "It would have no effect.$"

OldaleTown_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "What shall the new nickname be?$"

OldaleTown_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "You can't nickname an EGG!$"

OldaleTown_NameRatersHouse_Text_MagnificentName:
	.string "It would be rude to change\n"
	.string "this Pokémon's name!$"

OldaleTown_ConfirmHp:
	.string "Maximize HP?$"

OldaleTown_ConfirmAtk:
	.string "Maximize Attack?$"

OldaleTown_ConfirmDef:
	.string "Maximize Defense?$"

OldaleTown_ConfirmSpAtk:
	.string "Maximize Sp.Atk?$"

OldaleTown_ConfirmSpDef:
	.string "Maximize Sp.Def?$"

OldaleTown_ConfirmSpd:
	.string "Maximize Speed?$"

OldaleTown_NoScales:
	.string "You do not have enough Heart Scales.$"

OldaleTown_Info:
	.string "PreStatus and nickname services\n"
	.string "free of charge.\p"
	.string "If you have a Heart Scale I can\n"
	.string "maximize one of your Pokémon's stats!\p"
	.string "For 2 Heart Scales, I can even\n"
	.string "change your Pokémon's nature!$"




