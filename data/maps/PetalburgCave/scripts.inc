PetalburgCave_MapScripts::
	.byte 0


PetalburgCave_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ROCK_BLAST, PetalburgCave_EventScript_ReceivedRockBlast
	msgbox PetalburgCave_Text_RockBlast, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_BLAST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_BLAST
	release
	end

PetalburgCave_EventScript_PlasmaCuck::
	msgbox PetalburgCave_Plasma, MSGBOX_NPC
	end

PetalburgCave_EventScript_ReceivedRockBlast::
	msgbox PetalburgCave_Text_IWonder, MSGBOX_DEFAULT
	release
	end

PetalburgCave_Text_RockBlast:
	.string "There were some scary grunts outside\n"
	.string "earlier. Luckily I'm always packin!\p"
	.string "They couldn't handle my\n"
	.string "Rock Blast technique!\p"
	.string "Here, you can try it too,\n"
	.string "Rock Blast packs some power!$"

PetalburgCave_Text_IWonder:
	.string "Those grunts went farther into the cave.\n"
	.string "I wonder what they're doing down there?$"

PetalburgCave_Plasma:
	.string "Get out of here nerd!$"