.set LOCALID_BEN, 4
.set LOCALID_VIVIAN, 3
.set LOCALID_VIVIAN2, 12
.set LOCALID_SHAWN, 2
.set LOCALID_KIRK, 5
.set LOCALID_SHAWN2, 13
.set LOCALID_KIRK2, 14
.set LOCALID_ROXIE, 1
.set LOCALID_SECURITY1, 8
.set LOCALID_SECURITY2, 9
.set LOCALID_LOUDRED1, 11
.set LOCALID_LOUDRED2, 10



MauvilleCity_Gym_MapScripts::
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

Loudred1::
	playmoncry SPECIES_LOUDRED, 0
	msgbox Loudred1Cry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Loudred2::
	playmoncry SPECIES_LOUDRED, 0
	msgbox Loudred2Cry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Security::
	lock
	applymovement LOCALID_SECURITY1, Common_Movement_FacePlayer
	applymovement LOCALID_SECURITY2, Common_Movement_FacePlayer
	msgbox SecurityOnly, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, SecurityDown
	waitmovement 0
	applymovement LOCALID_SECURITY1, SecurityDown1
	applymovement LOCALID_SECURITY2, SecurityDown1
	waitmovement 0	
	release
	end

SecurityGuards_Script::
	goto_if_eq VAR_SECURITY, 1, SecurityGuardsPostRoxie
	msgbox SecurityGuards, MSGBOX_NPC
	end

SecurityGuardsPostRoxie::
	msgbox SecurityGuards2, MSGBOX_NPC
	end

SecurityDown:
	walk_down
	step_end

SecurityDown1:
	walk_in_place_down
	step_end

RoxieStart::
	lock
	setvar VAR_ROXIE_STAGE, 1
	setvar VAR_MUGSHOT_ID, MUGSHOT_ROXIE
	applymovement OBJ_EVENT_ID_PLAYER, WalkToRoxie
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ROXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROXIE, RoxieFace
	waitmovement 0
	msgbox Roxie_Intro, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_ROXIE, RoxieWalkBack
	applymovement OBJ_EVENT_ID_PLAYER, WalkBack
	waitmovement 0
	release
	goto MauvilleCity_Gym_EventScript_Wattson
	end	

RoxieFace:
	walk_in_place_right
	step_end

WalkBack:
	walk_right
	walk_right
	walk_in_place_left
	step_end

RoxieWalkBack:
	walk_left
	walk_left
	walk_in_place_right
	step_end

WalkToRoxie:
	walk_left
	walk_left
	step_end

RoxieToPlayer:
	walk_right
	walk_right
	step_end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

RoxiePostBattle::
	lock
	faceplayer
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	applymovement OBJ_EVENT_ID_PLAYER, WalkToRoxie
	applymovement LOCALID_ROXIE, RoxieToPlayer
	waitmovement 0
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE02_GET
	clearflag FLAG_UNLOCK_WINSTRATES
	clearflag FLAG_HIDE_111_TRAINERS
	setflag FLAG_SHOW_111_TRAINERS
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	setvar VAR_SECURITY, 1
	setvar VAR_KIRKSHAWN, 2
	setvar VAR_BENVIV, 2
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_POISON_JAB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat, KirkShawn
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Kirk2::
	lockall
	applymovement LOCALID_KIRK2, Kirk0
	waitmovement 30
	msgbox MauvilleCity_Gym_Text_KirkPreBattle, MSGBOX_DEFAULT
	applymovement LOCALID_KIRK2, Kirk2
	waitmovement 60
	releaseall
	end
	

MauvilleCity_Gym_EventScript_Shawn2::
	lockall
	applymovement LOCALID_SHAWN2, Shawn0
	waitmovement 30
	msgbox MauvilleCity_Gym_Text_ShawnPreBattle, MSGBOX_DEFAULT
	applymovement LOCALID_SHAWN2, Shawn2
	waitmovement 60
	releaseall
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat, BenViv
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end


VivDissappear::
	addobject LOCALID_VIVIAN2
	hideobjectat LOCALID_VIVIAN, MAP_MAUVILLE_CITY_GYM
	setobjectxy LOCALID_VIVIAN, 0, 14 
	setvar VAR_BENVIV, 1
	end

VivAppear::
	setobjectxy LOCALID_VIVIAN, 0, 17
	showobjectat LOCALID_VIVIAN, MAP_MAUVILLE_CITY_GYM
	removeobject LOCALID_VIVIAN2
	setvar VAR_BENVIV, 0
	end

ShawnDissappear::
	addobject LOCALID_KIRK2
	removeobject LOCALID_KIRK
	addobject LOCALID_SHAWN2
	removeobject LOCALID_SHAWN
	setvar VAR_KIRKSHAWN, 1
	end

ShawnAppear::
	addobject LOCALID_KIRK
	removeobject LOCALID_KIRK2
	addobject LOCALID_SHAWN
	removeobject LOCALID_SHAWN2
	setvar VAR_KIRKSHAWN, 0
	end

BenViv::
	setvar VAR_BENVIV, 2
	end

KirkShawn::
	setvar VAR_BENVIV, 2
	end

Vivian0:
	walk_in_place_down
	step_end

Vivian2:
	walk_in_place_right
	step_end

Kirk0:
	walk_in_place_left
	step_end

Kirk2:
	walk_in_place_up
	step_end

Shawn0:
	walk_in_place_left
	step_end

Shawn2:
	walk_in_place_down
	step_end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian2::
	lockall
	applymovement LOCALID_VIVIAN2, Vivian0
	waitmovement 30
	msgbox MauvilleCity_Gym_Text_VivianPreBattle, MSGBOX_DEFAULT
	applymovement LOCALID_VIVIAN2, Vivian2
	waitmovement 60
	releaseall
	end


DontTalkToMe::
	lockall
	applymovement LOCALID_VIVIAN, Vivian0
	waitmovement 0
	msgbox MauvilleCity_Gym_Text_VivianPreBattle, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_VIVIAN, Vivian2
	waitmovement 0
	releaseall
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Roxie, the Leader of Mauville\n"
	.string "Gym, uses Poison-type POKéMON.\p"
	.string "If you challenge her with Grass-type\n"
	.string "Pokémon, she'll disintegrate them!\p"
	.string "She's also mandated all battles to\n"
	.string "be doubles, so everyone can rock\l"
	.string "out together!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa, you've got some rhythym!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "My venomous vibe, will leave you\n"
	.string "stupified, whoa-yeahah!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "I think I blew my speakers!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "Pokémon and rock, it's all about heart,\n"
	.string "whoa-yeah!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "I trained under Roxie!\n"
	.string "There ain't no way I'll lose easily!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Unplugged and turned off…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "Roxie, our Gym Leader, has been rocking\n"
	.string "since she could hold a bass.\p"
	.string "It's hard even for me to keep up\n"
	.string "with her tempo.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "This Gym is jammin'!\n"
	.string "Isn't it fun?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "It's no fun to lose…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "Roxie says she loves when people\n"
	.string "jam together.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "With my charm and my pokémon's moves,\n"
	.string "you'll be begging for an antidote!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Your power is sick dude!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "I've heard that Mauville has become\n"
	.string "an attraction for people tuning in to\l"
	.string "Roxie's performances.\p"
	.string "She know's how to rock the crowd!$"

MauvilleCity_Gym_Text_VivianPreBattle:
	.string "Roxie said only double battles!$"

MauvilleCity_Gym_Text_KirkPreBattle:
	.string "I'm not jamming without my band!$"

MauvilleCity_Gym_Text_ShawnPreBattle:
	.string "Kirk would be mad if I started a solo\n"
	.string "sesh!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "These sound waves are off the charts!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "My ears are ringing…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "Mauville Gym's Roxie has a killer\n"
	.string "tune. She's an anomaly!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "Well strap in, cause I'm the best around,\n"
	.string "and this is my stage!$"

Roxie_Intro:
	.string "Music is what I live for, but battling\n"
	.string "is wicked too!\p"
	.string "I'm Roxie, the leader of Mauville Gym.\p"
	.string "So you want to challenge me to a battle\n"
	.string "of the beats huh?$"



MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wow!\n"
	.string "I guess I've got some competition!\p"
	.string "Your tune gave me the goosebumps!\n"
	.string "Take this badge!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} received the Toxic Badge\n"
	.string "from Roxie.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "With the Toxic Badge, pokémon can\n"
	.string "use Rock Smash out of battle.\p"
	.string "Hmm…\n"
	.string "You should take this, too!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "That TM there contains Poison Jab.\p"
	.string "It's a hard hitting move\n"
	.string "that can really corrode your enemies!\p"
	.string "You should head towards Lavaridge.\n"
	.string "Kiawe is eager to fight anyone that\p"
	.string "can best me!$"


MauvilleCity_Gym_Text_RegisteredWattson:
	.string "Registered GYM LEADER WATTSON\n"
	.string "in the POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "I can't wait to jam with you again!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "YEAH!\p"
	.string "Get out there and show 'em what you're\n"
	.string "made of!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "MAUVILLE CITY POKéMON GYM$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "MAUVILLE CITY POKéMON GYM\p"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "I'll make sparks fly from you!\n"
	.string "Don't say I didn't warn you!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Oof…\n"
	.string "Our batteries ran dry…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON: We'll have to recharge our\n"
	.string "batteries again.\p"
	.string "When we're fully charged up, we'll\n"
	.string "gladly accept your challenge.\p"
	.string "So, come back again sometime,\n"
	.string "won't you?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait!\n"
	.string "You've only one POKéMON with you!\p"
	.string "Come see me with two or more\n"
	.string "POKéMON, all right?$"

SecurityOnly:
	.string "Only security allowed past this point.$"

SecurityGuards:
	.string "Enjoy the show.$"

SecurityGuards2:
	.string "What a performance!$"

Loudred1Cry:
	.string "LOU LOU LOUDRED!!!!$"

Loudred2Cry:
	.string "LOUUUUUUUUDRED!!!!$"