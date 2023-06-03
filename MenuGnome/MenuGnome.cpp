//
//  MenuGnome.cpp
//  MenuGnome
//
//  Created by Grant Guenther on 6/1/23.
//
//=======================================================================================
//---------------------------------------------------------------------------------------

#include "MenuGnome.hpp"

#include <stdio.h>
#include <stdlib.h>		//  for calloc() and free()
#include <string.h>
#include <ctype.h>		//  for toupper()

//---------------------------------------------------------------------------------------

char *convertStrToUpper( const char origStr[], bool bShouldStopAtNewline )
{
	char			*strAsUpper = (char *)calloc(strlen(origStr) + 1, sizeof(char)),
					*currentChar;
	strncpy( strAsUpper, origStr, strlen(origStr) );
	
	currentChar = strAsUpper;
	while ( *currentChar )
		{
		if ( bShouldStopAtNewline && ('\n' == *currentChar ) )
			{
			*currentChar = NULL;
			return( strAsUpper );
			}
		else
			*currentChar = toupper(*currentChar);
			
		currentChar++;
		}
		
	return( strAsUpper );
}

//---------------------------------------------------------------------------------------

MenuDeckGnome::MenuDeckGnome()
{
	this->current_menu = NULL;
	this->menus = NULL;
}

//---------------------------------------------------------------------------------------

MenuDeckGnome::~MenuDeckGnome()
{
	MenuGnome					*menu_to_free,
								*next_menu = this->menus;
								
	while (NULL != next_menu)
		{
		menu_to_free = next_menu;
		next_menu = next_menu->next;
		
		delete menu_to_free;
		}
}

//---------------------------------------------------------------------------------------
		
void MenuDeckGnome::addMenuToDeck( MenuGnome *menu )
{
	MenuGnome				*old_next = this->menus;
	
	menu->createMenu();
	
	if ( NULL == old_next )
		{
		this->menus = menu;
		return;
		}
	
	while ( NULL != old_next->next )
		old_next = old_next->next;
		
	old_next->next = menu;
}

//---------------------------------------------------------------------------------------
		
void MenuDeckGnome::setMenu( int menuID )
{
	MenuGnome				*current_menu = this->menus;
	
	while ( (NULL != current_menu) && (menuID != current_menu->menuID()) )
		current_menu = current_menu->next;
		
	this->current_menu = current_menu;
}

//---------------------------------------------------------------------------------------
		
void MenuDeckGnome::print( void )
{
	if ( NULL != this->current_menu )
		this->current_menu->print();
}

//---------------------------------------------------------------------------------------

int MenuDeckGnome::run( void )
{
	this->print();
	this->presentUserPrompt( this->user_choice );
	
	if ( !strlen(this->user_choice) || ('\n' == this->user_choice[0]) )
		return(knMenuGnome_EmptyChoice);
		
	return(this->reactToUserChoice());
}

//---------------------------------------------------------------------------------------

const char *MenuDeckGnome::presentUserPrompt( char szUserChoice[] )
{
	if ( NULL != this->current_menu )
		{
		printf( "\n" );
		printf( "%s", this->current_menu->user_prompt );
		
		fgets( this->user_choice, sizeof(this->user_choice), stdin );
		return( this->user_choice );
		}
		
	return( NULL );
}

//---------------------------------------------------------------------------------------

int MenuDeckGnome::reactToUserChoice( void )
{
	if ( NULL != this->current_menu )
		return( this->current_menu->reactToUserChoice(this->user_choice) );
		
	return( knMenuGnome_InvalidChoice );
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------

MenuGnome::MenuGnome( int menuID, const char szTitle[], const char userPrompt[] )
{
	this->menu_id = menuID;
	this->choices = NULL;
	
	strncpy(this->user_prompt, userPrompt, strlen(userPrompt));
	this->user_prompt[strlen(userPrompt)] = 0;
	
	strncpy(this->title, szTitle, strlen(szTitle));
	this->title[strlen(szTitle)] = 0;
	
	this->next = NULL;
}

//---------------------------------------------------------------------------------------

MenuGnome::~MenuGnome()
{
	MenuGnome_UserChoice		*choice_to_free = this->choices;
	while (NULL != this->choices)
		{
		choice_to_free = this->choices;
		this->choices = this->choices->next;
		
		free( choice_to_free->menu_option );
		free( choice_to_free->menu_option_full );
		
		delete choice_to_free;
		}
}

//---------------------------------------------------------------------------------------

void MenuGnome::addUserChoice( MenuGnome_UserChoice *userChoice )
{
	MenuGnome_UserChoice				*old_next = this->choices;
	
	if ( NULL == old_next )
		{
		this->choices = userChoice;
		return;
		}
	
	while ( NULL != old_next->next )
		old_next = old_next->next;
		
	old_next->next = userChoice;
}

//---------------------------------------------------------------------------------------

void MenuGnome::addEmptyUserChoice( void )
{
	MenuGnome_UserChoice			*user_choice = this->createUserChoice(0, "", "" );
	this->addUserChoice( user_choice );
	
}

//---------------------------------------------------------------------------------------

MenuGnome_UserChoice *MenuGnome::createUserChoice( int nActionValue, 
														const char szMenuOption[],
														const char szMenuOptionFull[] )
{
	MenuGnome_UserChoice					*wNewUserChoice = new MenuGnome_UserChoice;
	
	wNewUserChoice->menu_option = (char *)calloc(strlen(szMenuOption) + 1, sizeof(char));
	strncpy(wNewUserChoice->menu_option, szMenuOption, strlen(szMenuOption));
	
	wNewUserChoice->menu_option_full = (char *)calloc(strlen(szMenuOptionFull) + 1, sizeof(char));
	strncpy(wNewUserChoice->menu_option_full, szMenuOptionFull, strlen(szMenuOptionFull));
	
	wNewUserChoice->action_value = nActionValue;
	
	return( wNewUserChoice );
}

//---------------------------------------------------------------------------------------


int MenuGnome::reactToUserChoice( const char szUserChoice[] )
{
	MenuGnome_UserChoice		*choice_to_check = this->choices;
	
	char						*szUserChoiceUpper,
								*szMenuOptionUpper;
								
	szUserChoiceUpper = convertStrToUpper( szUserChoice, true );
	
	while (NULL != choice_to_check)
		{
		if (strlen(choice_to_check->menu_option))
			{
			szMenuOptionUpper = convertStrToUpper( choice_to_check->menu_option, false );
			
			if ( (strlen(szUserChoiceUpper) == strlen(szMenuOptionUpper)) &&
					!strncmp(szMenuOptionUpper, szUserChoiceUpper, strlen(szUserChoiceUpper)) )
				{
				free(szUserChoiceUpper);
				free(szMenuOptionUpper);
				return( choice_to_check->action_value );
				}
				
			free(szMenuOptionUpper);
			}
							
		choice_to_check = choice_to_check->next;
		}
		
	free(szUserChoiceUpper);
		
	return( knMenuGnome_InvalidChoice );
}

//---------------------------------------------------------------------------------------

void MenuGnome::print( void )
{
	printf("====================================================================================\n");
	printf("|                                                                                  |\n");
	printf("|  %-32s                                                |\n", this->title);
	printf("|                                                                                  |\n");
	
	MenuGnome_UserChoice					*current_choice;
	for (current_choice = this->choices;  NULL != current_choice;  current_choice = current_choice->next )
		printf("|  %-32s                                                |\n", current_choice->menu_option_full);
	
	printf("|                                                                                  |\n");
	printf("====================================================================================\n");
	printf("\n");
}

//---------------------------------------------------------------------------------------

int MenuGnome::menuID( void )
{
	return( this->menu_id );
}

//---------------------------------------------------------------------------------------
//=======================================================================================
