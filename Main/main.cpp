//
//  main.cpp
//  MenuGnome
//
//  Created by Grant Guenther on 6/1/23.
//
//=======================================================================================
//---------------------------------------------------------------------------------------

#include "TestMenus.hpp"

#include <stdio.h>

//---------------------------------------------------------------------------------------

int main(int argc, const char * argv[]) 
{
	MenuDeckGnome				menu_deck;
	
	TestMenu_Main				*main_menu = new TestMenu_Main();
	TestMenu_Inner				*inner_menu = new TestMenu_Inner();
	
	int							user_action;
	
	menu_deck.addMenuToDeck(main_menu);
	menu_deck.addMenuToDeck(inner_menu);
	
	menu_deck.setMenu(main_menu->menuID());
	
	do
		{
		user_action = menu_deck.run();
		
		switch( user_action )
			{
			case 0:
				{
				//  Exit the app
				break;
				}
				
			case 10:
				{
				menu_deck.setMenu(inner_menu->menuID());
				break;
				}
				
			case 100:
				{
				menu_deck.setMenu(main_menu->menuID());
				break;
				}
				
			case knMenuGnome_InvalidChoice:
				{
				printf("\n\7Invalid user choice detected!\n");
				break;
				}
				
			case knMenuGnome_EmptyChoice:
				{
				break;
				}
				
			default:
				{
				printf("\n\7Undefined action value (%d) requested\n", user_action);
				}
			}
			
		printf( "\n" );
		}
	while ( 0 != user_action ) ;
	
	return 0;
}

//---------------------------------------------------------------------------------------
//=======================================================================================
