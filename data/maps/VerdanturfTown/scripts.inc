.set LOCALID_TWIN, 2
.set LOCALID_WALLY, 5
.set LOCALID_WALLYUNCLE, 6
.set LOCALID_SCOTT, 7


VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end


VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanTurf_EventScript_WallyCatchUp0::
	setvar VAR_VERDANTURF_WALLY_POS, 0
	playse SE_PIN
	delay 30
	playbgm MUS_DP_ENCOUNTER_BOY, FALSE 
	msgbox VerdanturfTown_Text_WallyWaitUp, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkBackwards
	goto VerdanTurf_EventScript_SetupWallyApproach0

VerdanTurf_EventScript_WallyCatchUp1::
	setvar VAR_VERDANTURF_WALLY_POS, 1
	playse SE_PIN
	delay 30
	playbgm MUS_DP_ENCOUNTER_BOY, FALSE 
	msgbox VerdanturfTown_Text_WallyWaitUp, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkBackwards
	goto VerdanTurf_EventScript_SetupWallyApproach1

VerdanTurf_EventScript_WallyCatchUp2::
	setvar VAR_VERDANTURF_WALLY_POS, 2
	playse SE_PIN
	delay 30
	playbgm MUS_DP_ENCOUNTER_BOY, FALSE 
	msgbox VerdanturfTown_Text_WallyWaitUp, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkBackwards
	goto VerdanTurf_EventScript_SetupWallyApproach2

VerdanTurf_EventScript_WallyCatchUp3::
	setvar VAR_VERDANTURF_WALLY_POS, 3
	playse SE_PIN
	delay 30
	playbgm MUS_DP_ENCOUNTER_BOY, FALSE 
	msgbox VerdanturfTown_Text_WallyWaitUp, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkBackwards
	goto VerdanTurf_EventScript_SetupWallyApproach3

VerdanTurf_EventScript_WallyCatchUp4::
	setvar VAR_VERDANTURF_WALLY_POS, 4
	playse SE_PIN
	delay 30
	playbgm MUS_DP_ENCOUNTER_BOY, FALSE 
	msgbox VerdanturfTown_Text_WallyWaitUp, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkBackwards
	goto VerdanTurf_EventScript_SetupWallyApproach4

VerdanTurf_EventScript_WallyCatchUp5::
	setvar VAR_VERDANTURF_WALLY_POS, 5
	playse SE_PIN
	delay 30
	playbgm MUS_DP_ENCOUNTER_BOY, FALSE 
	msgbox VerdanturfTown_Text_WallyWaitUp, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkBackwards
	goto VerdanTurf_EventScript_SetupWallyApproach5


VerdanTurf_EventScript_SetupWallyApproach0:
	addobject LOCALID_WALLY
	addobject LOCALID_WALLYUNCLE
	applymovement LOCALID_WALLY, WallyApproach0
	applymovement LOCALID_WALLYUNCLE, WallyUncleApproach0
	waitmovement 0
	goto VerdanTurf_EventScript_WallyEncounter

VerdanTurf_EventScript_SetupWallyApproach1:
	addobject LOCALID_WALLY
	addobject LOCALID_WALLYUNCLE
	applymovement LOCALID_WALLY, WallyApproach1
	applymovement LOCALID_WALLYUNCLE, WallyUncleApproach1
	waitmovement 0
	goto VerdanTurf_EventScript_WallyEncounter

VerdanTurf_EventScript_SetupWallyApproach2:
	addobject LOCALID_WALLY
	addobject LOCALID_WALLYUNCLE
	applymovement LOCALID_WALLY, WallyApproach2
	applymovement LOCALID_WALLYUNCLE, WallyApproach2
	waitmovement 0
	goto VerdanTurf_EventScript_WallyEncounter

VerdanTurf_EventScript_SetupWallyApproach3:
	addobject LOCALID_WALLY
	addobject LOCALID_WALLYUNCLE
	applymovement LOCALID_WALLY, WallyApproach3
	applymovement LOCALID_WALLYUNCLE, WallyUncleApproach3
	waitmovement 0
	goto VerdanTurf_EventScript_WallyEncounter

VerdanTurf_EventScript_SetupWallyApproach4:
	addobject LOCALID_WALLY
	addobject LOCALID_WALLYUNCLE
	applymovement LOCALID_WALLY, WallyApproach4
	applymovement LOCALID_WALLYUNCLE, WallyUncleApproach4
	waitmovement 0
	goto VerdanTurf_EventScript_WallyEncounter

VerdanTurf_EventScript_SetupWallyApproach5:
	addobject LOCALID_WALLY
	addobject LOCALID_WALLYUNCLE
	applymovement LOCALID_WALLY, WallyApproach5
	applymovement LOCALID_WALLYUNCLE, WallyUncleApproach5
	waitmovement 0
	goto VerdanTurf_EventScript_WallyEncounter


VerdanTurf_EventScript_WallyEncounter::
	lockall
	msgbox VerdanTurf_Text_WallyIntro, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MUGSHOT_ID, MUGSHOT_WALLY
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, VerdanturfTown_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox VerdanturfTown_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox VerdanturfTown_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox VerdanturfTown_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_BEAT_WALLY_V
	switch VAR_VERDANTURF_WALLY_POS
	case 0, Verdanturf_WallyExit0
	case 1, Verdanturf_WallyExit1 
	case 2, Verdanturf_WallyExit2
	case 3, Verdanturf_WallyExit3
	case 4, Verdanturf_WallyExit4
	case 5, Verdanturf_WallyExit5
	end

Verdanturf_WallyExit0::
	applymovement LOCALID_WALLY, WallyExit0
	applymovement LOCALID_WALLYUNCLE, WallyUncleExit0
	waitmovement 0
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYUNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	addobject LOCALID_SCOTT
	releaseall

Verdanturf_WallyExit1::
	applymovement LOCALID_WALLY, WallyExit1
	applymovement LOCALID_WALLYUNCLE, WallyUncleExit1
	waitmovement 0
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYUNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	addobject LOCALID_SCOTT
	releaseall

Verdanturf_WallyExit2::
	applymovement LOCALID_WALLY, WallyExit2
	applymovement LOCALID_WALLYUNCLE, WallyUncleExit2
	waitmovement 0
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYUNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	addobject LOCALID_SCOTT
	releaseall

Verdanturf_WallyExit3::
	applymovement LOCALID_WALLY, WallyExit3
	applymovement LOCALID_WALLYUNCLE, WallyUncleExit3
	waitmovement 0
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYUNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	addobject LOCALID_SCOTT
	releaseall

Verdanturf_WallyExit4::
	applymovement LOCALID_WALLY, WallyExit4
	applymovement LOCALID_WALLYUNCLE, WallyUncleExit4
	waitmovement 0
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYUNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	addobject LOCALID_SCOTT
	releaseall

Verdanturf_WallyExit5::
	applymovement LOCALID_WALLY, WallyExit5
	applymovement LOCALID_WALLYUNCLE, WallyUncleExit5
	waitmovement 0
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYUNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_VERDANTURF_TOWN_STATE, 1
	addobject LOCALID_SCOTT
	goto Verdanturf_ScottEntrance
	end

Verdanturf_ScottEntrance::
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	goto_if_eq VAR_VERDANTURF_WALLY_POS, 0, Verdanturf_Scott0
	goto_if_eq VAR_VERDANTURF_WALLY_POS, 1, Verdanturf_Scott1
	goto_if_eq VAR_VERDANTURF_WALLY_POS, 2, Verdanturf_Scott2
	goto_if_eq VAR_VERDANTURF_WALLY_POS, 3, Verdanturf_Scott3
	goto_if_eq VAR_VERDANTURF_WALLY_POS, 4, Verdanturf_Scott4
	goto_if_eq VAR_VERDANTURF_WALLY_POS, 5, Verdanturf_Scott5
	end

Verdanturf_Scott0::
	applymovement LOCALID_SCOTT, ScottApproach0
	waitmovement 0
	msgbox Verdanturf_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	applymovement LOCALID_SCOTT, ScottExit0
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

Verdanturf_Scott1::
	applymovement LOCALID_SCOTT, ScottApproach1
	waitmovement 0
	msgbox Verdanturf_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	applymovement LOCALID_SCOTT, ScottExit1
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

Verdanturf_Scott2::
	applymovement LOCALID_SCOTT, ScottApproach2
	waitmovement 0
	msgbox Verdanturf_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	applymovement LOCALID_SCOTT, ScottExit2
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

Verdanturf_Scott3::
	applymovement LOCALID_SCOTT, ScottApproach3
	waitmovement 0
	msgbox Verdanturf_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	applymovement LOCALID_SCOTT, ScottExit3
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

Verdanturf_Scott4::
	applymovement LOCALID_SCOTT, ScottApproach4
	waitmovement 0
	msgbox Verdanturf_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	applymovement LOCALID_SCOTT, ScottExit4
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

Verdanturf_Scott5::
	applymovement LOCALID_SCOTT, ScottApproach5
	waitmovement 0
	msgbox Verdanturf_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	applymovement LOCALID_SCOTT, ScottExit5
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

ScottApproach0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end

ScottApproach1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

ScottApproach2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ScottApproach3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

ScottApproach4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

ScottApproach5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

ScottExit0:
	walk_down
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left	
	step_end

ScottExit1:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left	
	step_end

ScottExit2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left	
	step_end

ScottExit3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left	
	step_end

ScottExit4:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left	
	step_end

ScottExit5:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left	
	step_end

WallyExit0:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyUncleExit0:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyExit1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyUncleExit1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyExit2:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyUncleExit2:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyExit3:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyUncleExit3:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WallyExit4:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

WallyUncleExit4:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WallyExit5:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WallyUncleExit5:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WallyApproach0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end

WallyUncleApproach0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

WallyApproach1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

WallyUncleApproach1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

WallyApproach2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WallyApproach3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

WallyUncleApproach3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

WallyApproach4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

WallyUncleApproach4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

WallyApproach5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

WallyUncleApproach5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PlayerWalkBackwards:
	walk_left
	step_end

Verdanturf_Text_ScottYouDidntHoldBack:
	.string "Scott: Hehe…\n"
	.string "I was watching that match!\p"
	.string "You're friends with that boy Wally,\n"
	.string "aren't you?\p"
	.string "But you didn't hold anything back\n"
	.string "and beat him impressively.\p"
	.string "Yeah! That's what a real Pokémon\n"
	.string "battle is all about!\p"
	.string "I idolize trainers like that!\p"
	.string "… … … … … …\p"
	.string "I still get a feeling that this isn't\n"
	.string "how things are supposed to be...\p"
	.string "Everyone is just carrying on like normal.\p"
	.string "Team Plasma...\p"
	.string "Team Galactic even...\p"
	.string "I can't explain it... but this isn't\n"
	.string "right.\p"
	.string "Maybe I'm just rambling.\p"
	.string "Keep it up trainer, I'll be watching your\n"
	.string "career with great interest.$"

VerdanturfTown_Text_WallyDefeat:
	.string "Wally: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "I lost…$"

VerdanturfTown_Text_WallyIllGoBackToVerdanturf:
	.string "Wally: Uncle…$"

VerdanturfTown_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, thank you.\n"
	.string "Being a trainer is tough, isn't it?\p"
	.string "It's not enough just to have Pokémon\n"
	.string "and make them battle. That isn't what\l"
	.string "being a real trainer is about.$"

VerdanturfTown_Text_UncleNoNeedToBeDown:
	.string "Uncle: Wally, there's no need to be so\n"
	.string "down on yourself.\p"
	.string "Why, what's keeping you from becoming\n"
	.string "stronger and stronger?\p"
	.string "Come on, let's go home.\n"
	.string "Everyone's waiting for you.$"

VerdanturfTown_Text_WallyWaitUp:
	.string "Wait up!$"

VerdanTurf_Text_WallyIntro:
	.string "Wally: Hey, {PLAYER}!\p"
	.string "My Uncle and I were heading to visit my\n"
	.string "Cousin, and I saw you leaving the tunnel.\p"
	.string "We had to run to catch up to you!\p"
	.string "I'll have you know that I've gotten a lot\n"
	.string "stronger since we met.\p"
	.string "{PLAYER}, I want you and my Uncle to\n"
	.string "understand that.\p"
	.string "Please, will you have a battle with \n"
	.string "me?$"	

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid Pokémon.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"

VerdanturfTown_Text_AirCleanHere:
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "My Pokémon and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my Battle Tent\n"
	.string "debut in this town.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Did you see the cave next to the\n"
	.string "Pokémon Mart?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit Rustboro.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "That cave next to the Pokémon Mart\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new Devon products in Rustboro now.$"

VerdanturfTown_Text_TownSign:
	.string "Verdanturf Town\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_WandasHouse:
	.string "Wanda's House$"

VerdanturfTown_Text_BattleTentSign:
	.string "Battle Tent Verdanturf Site\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "Rusturf Tunnel\n"
	.string "“Linking Rustboro and Verdanturf\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

