.set LOCALID_GRUNT, 1
.set LOCALID_DEVON_EMPLOYEE, 2
.set LOCALID_BOY, 6

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherFarLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerFarLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BW_ENCOUNTER_PLASMA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherFarLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerFarLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT_ID, MUGSHOT_PLASMAGRUNT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitFarLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BW_ENCOUNTER_PLASMA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT_ID, MUGSHOT_PLASMAGRUNT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BW_ENCOUNTER_PLASMA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0	
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT_ID, MUGSHOT_PLASMAGRUNT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattleRight
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherFarRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerFarRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BW_ENCOUNTER_PLASMA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherFarRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerFarRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayerFarRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT_ID, MUGSHOT_PLASMAGRUNT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattleFarRight
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitFarRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	setflag FLAG_WOODSGRUNT
	setflag FLAG_HIDE_CAVEGRUNTS
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherPostBattleRight::
	setflag FLAG_WOODSGRUNT
	setflag FLAG_HIDE_CAVEGRUNTS
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAwayRight
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherPostBattleFarRight::
	setflag FLAG_WOODSGRUNT
	setflag FLAG_HIDE_CAVEGRUNTS
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAwayFarRight
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitFarLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerFarLeft:
	delay_16
	face_player
	walk_left
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_right
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerFarRight:
	delay_16
	face_player
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherExitFarRight:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerFarLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerFarRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherFarLeft:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaRunAwayRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaRunAwayFarRight:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	step_end

PetalburgWoods_Movement_AquaApproachResearcherFarRight:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_Movement_AquaApproachPlayerFarRight:
	walk_right
	walk_in_place_faster_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy1Trigger1::
	lockall
	setvar VAR_GET_REPELLANT, 1
	playse SE_PIN
	applymovement LOCALID_BOY, BoyMove11
	waitmovement 0
	msgbox TakeRepellant, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_POKEREPELLANT
	applymovement LOCALID_BOY, BoyMove12
	waitmovement 0
	releaseall
	end

PetalburgWoods_EventScript_Boy1Trigger2::
	lockall
	setvar VAR_GET_REPELLANT, 1
	playse SE_PIN
	applymovement LOCALID_BOY, BoyMove21
	waitmovement 0
	msgbox TakeRepellant, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_POKEREPELLANT
	applymovement LOCALID_BOY, BoyMove22
	waitmovement 0
	releaseall
	end

BoyMove11:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

BoyMove12:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	face_down
	step_end

BoyMove21:
	walk_down
	walk_down
	walk_left
	walk_down
	step_end

BoyMove22:
	walk_up
	walk_right
	walk_up
	walk_up
	face_down
	step_end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_GymSign::
	msgbox PetalburgWoods_Text_GymSign, MSGBOX_SIGN
	end

PetalburgWoods_Gymkeeper_Closed::
	msgbox PetalburgWoods_Text_GymClosed, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_Gymkeeper_Open::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, PetalburgWoods_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgWoods_Text_GymOpen, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_Gym_EventScript_GymGuidePostVictory::
	msgbox PetalburgWoods_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end






PetalburgWoods_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, PetalburgWoods_Gym_Text_JoshIntro, PetalburgWoods_Gym_Text_JoshDefeat, PetalburgWoods_Gym_EventScript_JoshDefeated
	msgbox PetalburgWoods_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end


PetalburgWoods_Gym_EventScript_JoshDefeated::
	addvar VAR_BUGSY_GYM, 1 
	release
	end


PetalburgWoods_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, PetalburgWoods_Gym_Text_TommyIntro, PetalburgWoods_Gym_Text_TommyDefeat, PetalburgWoods_Gym_EventScript_TommyDefeated
	msgbox PetalburgWoods_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end


PetalburgWoods_Gym_EventScript_TommyDefeated::
	addvar VAR_BUGSY_GYM, 1 
	release
	end


PetalburgWoods_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, PetalburgWoods_Gym_Text_MarcIntro, PetalburgWoods_Gym_Text_MarcDefeat, PetalburgWoods_Gym_EventScript_MarcDefeated
	msgbox PetalburgWoods_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end


PetalburgWoods_Gym_EventScript_MarcDefeated::
	addvar VAR_BUGSY_GYM, 1 
	release
	end

PetalburgWoods_Gym_EventScript_BugsyStart::
	lock
	faceplayer
	setvar VAR_MUGSHOT_ID, MUGSHOT_BUGSY
	goto_if_eq VAR_BUGSY_GYM, 4, PetalburgWoods_Gym_EventScript_Bugsy
	msgbox PetalburgWoods_BugsyNotReady_Text, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_Gym_EventScript_Bugsy::
	trainerbattle_single TRAINER_ROXANNE_1, PetalburgWoods_Gym_Text_BugsyIntro, PetalburgWoods_Gym_Text_BugsyDefeat, PetalburgWoods_Gym_EventScript_BugsyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_Gym_EventScript_BugsyRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, PetalburgWoods_Gym_EventScript_GiveRockTomb
	msgbox PetalburgWoods_Gym_Text_BugsyPostBattle, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_Gym_EventScript_BugsyDefeated::
	message PetalburgWoods_Gym_Text_ReceivedHiveBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgWoods_Gym_Text_HiveBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 11
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto PetalburgWoods_Gym_EventScript_GiveRockTomb
	end

PetalburgWoods_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_BUG_BITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox PetalburgWoods_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_Gym_EventScript_BugsyRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EncounterShortGrassTrigger::
	setvar VAR_PETALBURG_WOODS_WILD_SET, 0
	end

PetalburgWoods_EncounterLongGrassTrigger::
	setvar VAR_PETALBURG_WOODS_WILD_SET, 1
	end

PetalburgWoods_Text_GymClosed:
	.string "Sorry, Bugsy's not here at the moment.\p"
	.string "I think he might still be packing up\n"
	.string "at the gym in Rustboro.\p"
	.string "Come back later!$"

PetalburgWoods_Text_GymOpen:
	.string "Bugsy, the Gym Leader, is a user\n"
	.string "of bug type Pokémon.\p"
	.string "The bug type is very strong, but\n"
	.string "a little fire and a lot of spirit\l"
	.string "could help you tame the swarm!\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the Gym Leader.\p"
	.string "Well, go for it!$"

PetalburgWoods_Gym_Text_GymGuidePostVictory:
	.string "Whoa! What a breathtaking victory!\n"
	.string "My advice must've worked!\p"
	.string "Great!\n"
	.string "Check your Trainer Card.\p"
	.string "The Hive Badge you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the Championship!\p"
	.string "That's got to feel awesome!$"

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hello, have you seen any Pokémon\n"
	.string "called Shroomish around here?\p"
	.string "I really love that Pokémon.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in Petalburg Woods\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "You! DEVON RESEARCHER!\p"
	.string "Hand over those papers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh!\p"
	.string "You're a Pokémon trainer, aren't you?\n"
	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses Team Plasma\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "You're kidding me! You're tough!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… You've got some nerve\n"
	.string "meddling with Team Plasma!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "Pokémon…\p"
	.string "And, hey, we of Team Plasma are also\n"
	.string "after something in Rustboro.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a Great Ball as\n"
	.string "my thanks!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Didn't that Team Plasma thug say\n"
	.string "they were after something in\l"
	.string "Rustboro, too?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "You're loaded with items.\n"
	.string "I can't give you this Great Ball.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My Bug Pokémon team!$"

PetalburgWoods_Text_ICouldntWin:
	.string "I have all these Pokémon,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "I caught a bunch of Pokémon.\n"
	.string "Now I'm out of Poké Balls.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "If you take Bug Pokémon to school,\n"
	.string "you get to be instantly popular!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "If you have a big Bug Pokémon,\n"
	.string "people respect you for it.$"

PetalburgWoods_Text_IWantRematch1:
	.string "I want a rematch when my Bug\n"
	.string "Pokémon grow up!\p"
	.string "I'm registering you in my Pokénav!$"

PetalburgWoods_Text_IWantRematch2:
	.string "I want a rematch when my Bug \n"
	.string "Pokémon grow up!\p"
	.string "I'm registering you in my Pokénav!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "My Bug Pokémon have grown.\n"
	.string "I'll be popular again.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "You get to be popular if you have\n"
	.string "strong Pokémon, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, there!\n"
	.string "Your Pokémon doing okay?\p"
	.string "If you want to avoid wild Pokémon, just\n"
	.string "use that PokéRepellant I gave you.$"

TakeRepellant:
	.string "Hey!\n"
	.string "There's lot's of scary bugs out here.\p"
	.string "You should take this extra Repellant.\n"
	.string "I was going to give it to my friend,\l"
	.string "but he whimped out and stayed home.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, hey!\n"
	.string "You must be a trainer!\p"
	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "It's a Miracle Seed.\n"
	.string "If a Pokémon holds that item, its\l"
	.string "Grass-type moves become stronger.\p"
	.string "Besides Miracle Seed, I think there are\n"
	.string "other convenient items for Pokémon\l"
	.string "to hold.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TRAINER TIPS\p"
	.string "Any Pokémon that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak Pokémon, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "TRAINER TIPS\p"
	.string "In addition to Hit Points (HP), Pokémon\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a Pokémon runs out of PP, it must be\n"
	.string "taken to a Pokémon Center.$"

PetalburgWoods_Text_GymSign:
	.string "Petalburg Woods Pokémon Gym\n"
	.string "Leader: Bugsy\l"
	.string "“A bug type prodigy!”$"

PetalburgWoods_Gym_Text_JoshIntro:
	.string "Don't take us Gym trainers lightly!\n"
	.string "I'll show you why we're better!$"

PetalburgWoods_Gym_Text_JoshDefeat:
	.string "You were too good for me…$"

PetalburgWoods_Gym_Text_JoshPostBattle:
	.string "You haven't seen anything of the bug\n"
	.string "type's terrifying power!$"

PetalburgWoods_Gym_Text_TommyIntro:
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against Bugsy!$"

PetalburgWoods_Gym_Text_TommyDefeat:
	.string "Wow! You've got some potential!$"

PetalburgWoods_Gym_Text_TommyPostBattle:
	.string "Bugsy is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"

PetalburgWoods_Gym_Text_MarcIntro:
	.string "I love that we moved to the woods,\p"
	.string "Now my bug Pokémon have room to\n"
	.string "rampage!$"

PetalburgWoods_Gym_Text_MarcDefeat:
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"

PetalburgWoods_Gym_Text_MarcPostBattle:
	.string "I have to hand it to our leader.\p"
	.string "It took smarts and sense for him to\n"
	.string "pick the bug type at his young age.$"
	
PetalburgWoods_Gym_Text_BugsyIntro:
	.string "We meet again, I'm Bugsy, the\n"
	.string "Petalburg Woods Pokémon Gym Leader.\p"
	.string "I became a Gym Leader so that I might\n"
	.string "apply what I learned at the Pokémon\l"
	.string "Trainer's School in battle.\p"
	.string "It's gonna take a lot to quell my bug\n"
	.string "type Pokémon!$"

PetalburgWoods_Gym_Text_BugsyDefeat:
	.string "So…\n"
	.string "I lost…\p"
	.string "It seems that I still have much more\n"
	.string "to learn…\p"
	.string "I understand.\p"
	.string "The Pokémon League's rules state\n"
	.string "that trainers are to be given this\l"
	.string "if they defeat a Gym Leader.\p"
	.string "Please accept the official Pokémon\n"
	.string "League Hive Badge.$"

PetalburgWoods_Gym_Text_ReceivedHiveBadge:
	.string "{PLAYER} received the Hive Badge\n"
	.string "from Bugsy.$"

PetalburgWoods_Gym_Text_HiveBadgeInfoTakeThis:
	.string "The Hive Badge increased the power\n"
	.string "ceilling of your Pokémon to level 22.\p"
	.string "It also enables them to use the HM move\n"
	.string "CUT outside of battle.\p"
	.string "Please take this with you, too.$"

PetalburgWoods_Gym_Text_ExplainTM:
	.string "That Technical Machine, TM04,\n"
	.string "contains Bug Bite.\p"
	.string "It not only inflicts damage by biting\n"
	.string "the enemy, it also steals their\l"
	.string "held berry and consumes it.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a Pokémon.\p"


PetalburgWoods_Gym_Text_BugsyPostBattle:
	.string "Since you are so strong, you should\n"
	.string "challenge other Gym Leaders.\p"
	.string "By battling many trainers, you should\n"
	.string "learn many things.$"

PetalburgWoods_BugsyNotReady_Text::
	.string "You'll have to defeat my peers\n"
	.string "before I'll accept your challenge!$"	

